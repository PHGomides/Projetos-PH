package jogo.corrida.Carro;

import jogo.corrida.Fases.Corrida;
import jogo.corrida.Sons;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.net.URL;
import java.awt.geom.AffineTransform;

public class Carro {

    public int x, y;
    public double velocidade = 10;
    private Image imagemCarro;
    private int teclaCima, teclaBaixo, teclaEsquerda, teclaDireita;
    private boolean movendoCima = false, movendoBaixo = false, movendoEsquerda = false, movendoDireita = false;
    private double angulo = 0; // Ângulo de rotação
    private Rectangle hitbox;

    private Corrida corrida;
    private final int LARGURA_CARRO = 35;
    private final int ALTURA_CARRO = 60;

    // Construtor
    public Carro(int x, int y, String caminhoImagem, int teclaCima, int teclaBaixo, int teclaEsquerda, int teclaDireita, Corrida corrida) {
        this.x = x;
        this.y = y;
        this.teclaCima = teclaCima;
        this.teclaBaixo = teclaBaixo;
        this.teclaEsquerda = teclaEsquerda;
        this.teclaDireita = teclaDireita;
        this.corrida = corrida;
        this.imagemCarro = carregarImagem(caminhoImagem);
        this.hitbox = new Rectangle(x, y, LARGURA_CARRO, ALTURA_CARRO);
    }

    // Carregar imagem do carro
    private Image carregarImagem(String caminho) {
        URL url = this.getClass().getResource(caminho);
        return Toolkit.getDefaultToolkit().getImage(url);
    }

    // Atualizar a posição da hitbox
    private void atualizarHitbox() {
        hitbox.setBounds(x, y, LARGURA_CARRO, ALTURA_CARRO);
    }

    // Desenhar o carro com rotação centralizada
    public void desenhar(Graphics g, Corrida corrida) {
        Graphics2D g2d = (Graphics2D) g;
        AffineTransform originalTransform = g2d.getTransform(); // Salva a transformação original

        // Ponto central para rotação
        int centroX = x + LARGURA_CARRO / 2;
        int centroY = y + ALTURA_CARRO / 2;

        // Rotaciona o carro ao redor do centro
        g2d.rotate(Math.toRadians(angulo), centroX, centroY);

        // Desenha o carro
        g2d.drawImage(imagemCarro, x, y, LARGURA_CARRO, ALTURA_CARRO, corrida);

        // Restaura a transformação original
        g2d.setTransform(originalTransform);
    }

    // Verificar colisão nos quatro cantos da hitbox do carro
    private boolean podeMoverPara(int novoX, int novoY) {
        // Checa os quatro cantos da hitbox (superior esquerdo, superior direito, inferior esquerdo, inferior direito)
        int cantoSuperiorEsquerdoX = novoX;
        int cantoSuperiorEsquerdoY = novoY;

        int cantoSuperiorDireitoX = novoX + LARGURA_CARRO;
        int cantoSuperiorDireitoY = novoY;

        int cantoInferiorEsquerdoX = novoX;
        int cantoInferiorEsquerdoY = novoY + ALTURA_CARRO;

        int cantoInferiorDireitoX = novoX + LARGURA_CARRO;
        int cantoInferiorDireitoY = novoY + ALTURA_CARRO;


        boolean podeMover = corrida.podeMover(cantoSuperiorEsquerdoX, cantoSuperiorEsquerdoY)
            && corrida.podeMover(cantoSuperiorDireitoX, cantoSuperiorDireitoY)
            && corrida.podeMover(cantoInferiorEsquerdoX, cantoInferiorEsquerdoY)
            && corrida.podeMover(cantoInferiorDireitoX, cantoInferiorDireitoY);

        if (!podeMover) {
            velocidade = Math.max(velocidade - 1, 1); // Diminui a velocidade, mas não deixa ser menor que 1
        }

        return  podeMover;
    }
    // Mover o carro baseado nas teclas pressionadas
    public void mover() {
        if (movendoCima) {
            if (podeMoverPara(x, (int) (y - velocidade))) {
                y -= velocidade; // Cima
                atualizarHitbox();
                angulo = 0;
            }
        }
        if (movendoBaixo) {
            if (podeMoverPara(x, (int) (y + velocidade))) {
                y += velocidade; // Baixo
                atualizarHitbox();
                angulo = 180;
            }
        }
        if (movendoEsquerda) {
            if (podeMoverPara((int) (x - velocidade), y)) {
                x -= velocidade; // Esquerda
                atualizarHitbox();
                angulo = 270;
            }
        }
        if (movendoDireita) {
            if (podeMoverPara((int) (x + velocidade), y)) {
                x += velocidade; // Direita
                atualizarHitbox();
                angulo = 90;
            }
        }
    }

    public void aumentarVelocidade() {
        if (velocidade < 20) {
            velocidade += 0.2;
        }
    }

    // Métodos para processar as teclas
    public void processarTeclaPressionada(int keyCode) {
        if (keyCode == teclaCima) {
            movendoCima = true;
        } else if (keyCode == teclaBaixo) {
            movendoBaixo = true;
        } else if (keyCode == teclaEsquerda) {
            movendoEsquerda = true;
        } else if (keyCode == teclaDireita) {
            movendoDireita = true;
        }
    }

    public void processarTeclaSolta(int keyCode) {
        if (keyCode == teclaCima) {
            movendoCima = false;
        } else if (keyCode == teclaBaixo) {
            movendoBaixo = false;
        } else if (keyCode == teclaEsquerda) {
            movendoEsquerda = false;
        } else if (keyCode == teclaDireita) {
            movendoDireita = false;
        }
    }

    // Obter a hitbox para verificar colisão em outras classes
    public Rectangle getHitbox() {
        return hitbox;
    }
}
