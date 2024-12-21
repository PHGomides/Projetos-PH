package jogo.corrida.Telas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import jogo.corrida.Sons;

public class TelaSelecaoFases extends JFrame {

    public TelaSelecaoFases() {
        setTitle("Escolha o circuito");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        // Definir a imagem do mapa como fundo da tela
        JLabel background = new JLabel(new ImageIcon(getClass().getResource("/Imagens/Mapa1_preview.png")));
        background.setLayout(new BorderLayout()); // Usar BorderLayout para o fundo
        setContentPane(background);

        // Painel para os botões
        JPanel painelBotoes = new JPanel();
        painelBotoes.setLayout(new GridLayout(1, 2, 10, 10)); // Layout com dois botões e espaçamento
        painelBotoes.setOpaque(false); // Torna o painel transparente para manter o fundo visível

        // Botão da Fase 1 com imagem e tamanho aumentado
        JButton fase1Button = new JButton(new ImageIcon(getClass().getResource("/Imagens/monaco.png")));
        fase1Button.setFocusPainted(false);
        fase1Button.setContentAreaFilled(false);  // Remove o fundo do botão
        fase1Button.setBorderPainted(false);      // Remove as bordas
        fase1Button.setPreferredSize(new Dimension(300, 100)); // Aumenta o tamanho do botão
        fase1Button.addActionListener(e -> {
            new Sons("/Sons/Seleçao.wav"); // Toca som ao clicar
            new TelaSelecaoDeCarro("/Mapas/Mapa1.txt"); // Abre a tela de seleção de carros com o mapa selecionado
            dispose(); // Fecha a tela de seleção de fases
        });

        // Efeito hover para Fase 1
        fase1Button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                fase1Button.setIcon(new ImageIcon(getClass().getResource("/Imagens/monaco2.png"))); // Mudar para imagem hover
                background.setIcon(new ImageIcon(getClass().getResource("/Imagens/Mapa1_preview.png"))); // Mudar o fundo
                new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
            }

            @Override
            public void mouseExited(MouseEvent e) {
                fase1Button.setIcon(new ImageIcon(getClass().getResource("/Imagens/monaco.png"))); // Voltar à imagem original
            }
        });
        painelBotoes.add(fase1Button);

        // Botão da Fase 2 com imagem e tamanho aumentado
        JButton fase2Button = new JButton(new ImageIcon(getClass().getResource("/Imagens/Zandvoort.png")));
        fase2Button.setFocusPainted(false);
        fase2Button.setContentAreaFilled(false);  // Remove o fundo do botão
        fase2Button.setBorderPainted(false);      // Remove as bordas
        fase2Button.setPreferredSize(new Dimension(300, 100)); // Aumenta o tamanho do botão
        fase2Button.addActionListener(e -> {
            new Sons("/Sons/Seleçao.wav"); // Toca som ao clicar
            new TelaSelecaoDeCarro("/Mapas/Mapa2.txt"); // Abre a tela de seleção de carros com o mapa selecionado
            dispose(); // Fecha a tela de seleção de fases
        });

        // Efeito hover para Fase 2
        fase2Button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                fase2Button.setIcon(new ImageIcon(getClass().getResource("/Imagens/Zandvoort2.png"))); // Mudar para imagem hover
                background.setIcon(new ImageIcon(getClass().getResource("/Imagens/Mapa2_preview.png"))); // Mudar o fundo
                new Sons("/Sons/Seleçao.wav"); // Toca som ao passar o mouse
            }

            @Override
            public void mouseExited(MouseEvent e) {
                fase2Button.setIcon(new ImageIcon(getClass().getResource("/Imagens/Zandvoort.png"))); // Voltar à imagem original
            }
        });
        painelBotoes.add(fase2Button);

        // Adiciona o painel de botões à parte superior da tela para subir os botões
        add(painelBotoes, BorderLayout.NORTH);

        setVisible(true);
    }

    public static void main(String[] args) {
        new TelaSelecaoFases(); // Inicializa a tela de seleção de fases
    }
}