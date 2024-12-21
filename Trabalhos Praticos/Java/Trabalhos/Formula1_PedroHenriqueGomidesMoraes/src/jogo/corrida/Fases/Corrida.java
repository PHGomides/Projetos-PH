package jogo.corrida.Fases;

import javax.swing.*;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import jogo.corrida.Carro.Carro;
import jogo.corrida.Carro.MovimentoCarro;
import jogo.corrida.Telas.TelaInicio;
import jogo.corrida.GerenImputs;
import jogo.corrida.Mapa;
import jogo.corrida.Sons;

public class Corrida extends JFrame {

    final int WIDTH = 1920;
    final int HEIGHT = 1080;
    private Mapa mapa;
    private Carro carro1, carro2;
    private BufferedImage buffer;
    private int voltasCarro1 = 0, voltasCarro2 = 0;
    private int checkPointCarro1 = 0, checkPointCarro2 = 0;
    private long cooldownColisaoCarro1 = 0, cooldownColisaoCarro2 = 0;
    private final int TEMPO_COOLDOWN = 1000;

    public Corrida(int carroPlayer1, int carroPlayer2, String caminhoMapa) {

        super("Jogo de Corrida");
        setSize(WIDTH, HEIGHT);
        setLocationRelativeTo(null);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Carrega o mapa com base no caminho fornecido
        mapa = new Mapa(caminhoMapa);

        carro1 = new Carro(100, 460, "/Imagens/carros/carro" + carroPlayer1 + ".png", KeyEvent.VK_W, KeyEvent.VK_S,
                KeyEvent.VK_A,
                KeyEvent.VK_D,
                this);
        carro2 = new Carro(140, 460, "/Imagens/carros/carro" + carroPlayer2 + ".png", KeyEvent.VK_UP, KeyEvent.VK_DOWN,
                KeyEvent.VK_LEFT,
                KeyEvent.VK_RIGHT, this);

        GerenImputs inputManager = new GerenImputs(carro1, carro2);
        addKeyListener(inputManager);
        setVisible(true);

        buffer = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_ARGB);

        new MovimentoCarro(carro1, this).start();
        new MovimentoCarro(carro2, this).start();

    }

    @Override
    public void paint(Graphics g) {

        long tempoAtual = System.currentTimeMillis();

        // Verifica colisão entre carro1 e carro2
        if (carro1.getHitbox().intersects(carro2.getHitbox())) {
            if (tempoAtual - cooldownColisaoCarro1 > TEMPO_COOLDOWN) {
                carro1.velocidade = Math.max(carro1.velocidade - 5, 1);
                carro1.x -= 10;
                carro2.x += 10;
                cooldownColisaoCarro1 = tempoAtual; // Reseta o cooldown
            }
        }

        if (carro2.getHitbox().intersects(carro1.getHitbox())) {
            if (tempoAtual - cooldownColisaoCarro2 > TEMPO_COOLDOWN) {
                carro1.velocidade = Math.max(carro1.velocidade - 5, 1);
                carro1.x -= 5;
                carro2.x += 5;
                cooldownColisaoCarro2 = tempoAtual; // Reseta o cooldown
            }
        }



        if (buffer == null) {
            buffer = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_ARGB);
        }

        if ((carro1.y >= 900 && carro1.y <= 980) && (carro1.x >= 1420 && carro1.x <= 1480) && checkPointCarro1 == voltasCarro1 - 1) {
            checkPointCarro1 += 1;
            System.out.println(checkPointCarro1);
        }
        if ((carro2.y >= 900 && carro2.y <= 980) && (carro2.x >= 1420  && carro2.x <= 1480) && checkPointCarro2 == voltasCarro2 - 1) {
            checkPointCarro2 += 1;
            System.out.println(checkPointCarro2);

        }

        if ((carro1.y >= 420 && carro1.y <= 470) && (carro1.x >= 60  && carro1.x <= 170) && voltasCarro1 == checkPointCarro1) {
            voltasCarro1 += 1;

        }
        if ((carro2.y >= 420 && carro2.y <= 470) && (carro2.x >= 60  && carro2.x <= 170) && voltasCarro2 == checkPointCarro2) {
            voltasCarro2 += 1;

        }

        /* finalizar jogo */
        if (voltasCarro1 - 1 == 3 && (carro1.y >= 420 && carro1.y <= 470) && (carro1.x >= 60  && carro1.x <= 170)) {

            iniciarJogo(1);

        }
        if (voltasCarro2 - 1 == 3 && (carro2.y >= 420 && carro2.y <= 470) && (carro2.x >= 60  && carro2.x <= 170)) {
            iniciarJogo(2);

        }

        Graphics bufferGraphics = buffer.getGraphics();
        bufferGraphics.clearRect(0, 0, WIDTH, HEIGHT);

        mapa.desenhar(bufferGraphics);
        carro1.desenhar(bufferGraphics, this);
        carro2.desenhar(bufferGraphics, this);
        bufferGraphics.setFont(new Font("SansSerif", Font.BOLD, 30));
        bufferGraphics.setColor(Color.BLACK); // Define a cor preta

        if (voltasCarro1 >= 0) {

            bufferGraphics.drawString("LAP " + (voltasCarro1 - 1) + "/3", 790, 100);
            bufferGraphics.drawString("LAP " + (voltasCarro2 - 1) + "/3", 790, 150);

        }

        g.drawImage(buffer, 0, 0, this);
    }

    private void iniciarJogo(int jogador) {

        this.dispose(); // Fecha a tela de início

        new TelaInicio(); // Abre a tela de seleção de fases
        JOptionPane.showMessageDialog(null, "Jogador " + jogador + " Venceu!!!", "Confirmação",
                JOptionPane.INFORMATION_MESSAGE);
    }

    public boolean podeMover(int x, int y) {
        return mapa.podeMover(x, y);
    }
}