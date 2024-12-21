package jogo.corrida.Telas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import jogo.corrida.Fases.Corrida;
import jogo.corrida.Sons;

public class TelaSelecaoDeCarro extends JFrame {
    private int carroSelecionadoPlayer1 = -1; // Carro selecionado pelo Player 1
    private int carroSelecionadoPlayer2 = -1; // Carro selecionado pelo Player 2
    private String mapaSelecionado; // Mapa selecionado

    private JLabel carroSelecionadoLabel1; // Label para exibir o carro selecionado pelo Player 1
    private JLabel carroSelecionadoLabel2; // Label para exibir o carro selecionado pelo Player 2

    // Imagens dos carros (normais e destacados)
    private ImageIcon[] iconesCarrosNormais;
    private ImageIcon[] iconesCarrosDestacados;

    public TelaSelecaoDeCarro(String mapaSelecionado) {
        this.mapaSelecionado = mapaSelecionado; // Armazena o mapa selecionado

        // Configurações da janela
        setTitle("Seleção de Carros");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(null); // Usaremos layout absoluto para customizar a posição dos elementos

        // Fundo em GIF
        JLabel fundoLabel = new JLabel(new ImageIcon(getClass().getResource("/Imagens/fundo2.png")));
        fundoLabel.setBounds(0, 0, 800, 600);
        setContentPane(fundoLabel); // Define o GIF como fundo

        // Array de ícones para os carros (normais e destacados)
        String[] caminhoCarrosNormais = {"/Imagens/carros/carroAmostra1.png", "/Imagens/carros/carroAmostra2.png", "/Imagens/carros/carroAmostra3.png", "/Imagens/carros/carroAmostra4.png"};
        String[] caminhoCarrosDestacados = {"/Imagens/carros/carrohover1.png", "/Imagens/carros/carrohover2.png", "/Imagens/carros/carrohover3.png", "/Imagens/carros/carrohover4.png"};

        // Inicializa as imagens dos carros
        iconesCarrosNormais = new ImageIcon[4];
        iconesCarrosDestacados = new ImageIcon[4];
        for (int i = 0; i < caminhoCarrosNormais.length; i++) {
            iconesCarrosNormais[i] = new ImageIcon(new ImageIcon(getClass().getResource(caminhoCarrosNormais[i])).getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH));
            iconesCarrosDestacados[i] = new ImageIcon(new ImageIcon(getClass().getResource(caminhoCarrosDestacados[i])).getImage().getScaledInstance(100, 100, Image.SCALE_SMOOTH));
        }

        // Área para exibir o carro selecionado pelo Player 1
        carroSelecionadoLabel1 = new JLabel();
        carroSelecionadoLabel1.setBounds(300, 20, 100, 100);
        fundoLabel.add(carroSelecionadoLabel1);

        // Área para exibir o carro selecionado pelo Player 2
        carroSelecionadoLabel2 = new JLabel();
        carroSelecionadoLabel2.setBounds(400, 20, 100, 100);
        fundoLabel.add(carroSelecionadoLabel2);

        // Botões para selecionar os carros (Player 1)
        JButton[] botoesCarrosPlayer1 = new JButton[4];
        for (int i = 0; i < 4; i++) {
            botoesCarrosPlayer1[i] = new JButton(iconesCarrosNormais[i]);
            botoesCarrosPlayer1[i].setBounds(50, 100 + (i * 110), 100, 80); // Ajusta a posição para a borda esquerda
            botoesCarrosPlayer1[i].setBorderPainted(false);
            botoesCarrosPlayer1[i].setContentAreaFilled(false);
            botoesCarrosPlayer1[i].setFocusPainted(false);
            final int index = i;
            botoesCarrosPlayer1[i].addActionListener(e -> {
                carroSelecionadoPlayer1 = index + 1;
                carroSelecionadoLabel1.setIcon(iconesCarrosNormais[index]); // Exibe o carro selecionado
                new Sons("/Sons/Seleçao.wav"); // Toca som ao clicar
            });

            // Efeito hover para botões de carro
            botoesCarrosPlayer1[i].addMouseListener(new MouseAdapter() {
                @Override
                public void mouseEntered(MouseEvent e) {
                    botoesCarrosPlayer1[index].setIcon(iconesCarrosDestacados[index]); // Muda a imagem ao passar o mouse
                    new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
                }

                @Override
                public void mouseExited(MouseEvent e) {
                    botoesCarrosPlayer1[index].setIcon(iconesCarrosNormais[index]); // Volta a imagem padrão
                }
            });

            fundoLabel.add(botoesCarrosPlayer1[i]);
        }

        // Botões para selecionar os carros (Player 2)
        JButton[] botoesCarrosPlayer2 = new JButton[4];
        for (int i = 0; i < 4; i++) {
            botoesCarrosPlayer2[i] = new JButton(iconesCarrosNormais[i]);
            botoesCarrosPlayer2[i].setBounds(650, 100 + (i * 110), 100, 80); // Ajusta a posição para a borda direita
            botoesCarrosPlayer2[i].setBorderPainted(false);
            botoesCarrosPlayer2[i].setContentAreaFilled(false);
            botoesCarrosPlayer2[i].setFocusPainted(false);
            final int index = i;
            botoesCarrosPlayer2[i].addActionListener(e -> {
                carroSelecionadoPlayer2 = index + 1;
                carroSelecionadoLabel2.setIcon(iconesCarrosNormais[index]); // Exibe o carro selecionado
                new Sons("/Sons/Seleçao.wav"); // Toca som ao clicar
            });

            // Efeito hover para botões de carro
            botoesCarrosPlayer2[i].addMouseListener(new MouseAdapter() {
                @Override
                public void mouseEntered(MouseEvent e) {
                    botoesCarrosPlayer2[index].setIcon(iconesCarrosDestacados[index]); // Muda a imagem ao passar o mouse
                    new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
                }

                @Override
                public void mouseExited(MouseEvent e) {
                    botoesCarrosPlayer2[index].setIcon(iconesCarrosNormais[index]); // Volta a imagem padrão
                }
            });

            fundoLabel.add(botoesCarrosPlayer2[i]);
        }

        // Botão Continuar com imagens e efeito hover
        JButton continuarButton = new JButton(new ImageIcon(getClass().getResource("/Imagens/play.png")));
        continuarButton.setBounds(340, 250, 120, 52); // Ajusta as dimensões e centraliza o botão
        continuarButton.setBorderPainted(false);
        continuarButton.setContentAreaFilled(false);
        continuarButton.setFocusPainted(false);

        continuarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                continuarButton.setIcon(new ImageIcon(getClass().getResource("/Imagens/play2.png"))); // Imagem ao passar o mouse
                new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
            }

            @Override
            public void mouseExited(MouseEvent e) {
                continuarButton.setIcon(new ImageIcon(getClass().getResource("/Imagens/play.png"))); // Imagem padrão
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                if (carroSelecionadoPlayer1 != -1 && carroSelecionadoPlayer2 != -1) {
                    new Corrida(carroSelecionadoPlayer1, carroSelecionadoPlayer2, mapaSelecionado); // Inicia a corrida com os carros e o mapa selecionados
                    dispose(); // Fecha a tela de seleção de carros
                } else {
                    // Exibe uma mensagem de erro ou faz outra ação apropriada
                }
            }
        });
        fundoLabel.add(continuarButton);

        // Botão Voltar com imagens e efeito hover
        JButton voltarButton = new JButton(new ImageIcon(getClass().getResource("/Imagens/voltar.png")));
        voltarButton.setBounds(340, 310, 120, 52); // Ajusta as dimensões e centraliza o botão abaixo do botão Continuar
        voltarButton.setBorderPainted(false);
        voltarButton.setContentAreaFilled(false);
        voltarButton.setFocusPainted(false);

        voltarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                voltarButton.setIcon(new ImageIcon(getClass().getResource("/Imagens/voltar2.png"))); // Imagem ao passar o mouse
                new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
            }

            @Override
            public void mouseExited(MouseEvent e) {
                voltarButton.setIcon(new ImageIcon(getClass().getResource("/Imagens/voltar.png"))); // Imagem padrão
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                new Sons("/Sons/Seleçao.wav"); // Toca som ao clicar
                dispose(); // Fecha a tela atual
                new TelaSelecaoFases(); // Abre a tela de seleção de fases
            }
        });
        fundoLabel.add(voltarButton);

        // Tornar a janela visível
        setVisible(true);
    }

    public static void main(String[] args) {
        new TelaSelecaoDeCarro("/Mapas/Mapa1.txt"); // Inicializa a tela de seleção de carros com um mapa padrão
    }
}