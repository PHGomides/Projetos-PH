package jogo.corrida.Telas;

import jogo.corrida.Sons;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class TelaInicio extends JFrame {

    public TelaInicio() {
        super("Tela de Início");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(null);

        // Definir o background
        JLabel background = new JLabel(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/fundo.jpg"));
        background.setBounds(0, 0, 800, 600);
        add(background);

        // Painel principal para centralizar os elementos
        JPanel panel = new JPanel(new GridBagLayout());
        panel.setOpaque(false);
        panel.setBounds(0, 0, 800, 600);

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = GridBagConstraints.RELATIVE;
        gbc.insets = new Insets(20, 0, 20, 0);
        gbc.anchor = GridBagConstraints.CENTER;

        // Adicionar a logo acima dos botões
        JLabel logoLabel = new JLabel(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/Logo.png"));
        panel.add(logoLabel, gbc);

        // Definir o botão Jogar como imagem
        JButton btnJogar = new JButton(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/play.png"));
        btnJogar.setFocusPainted(false);
        btnJogar.setContentAreaFilled(false);  // Para remover o fundo do botão
        btnJogar.setBorderPainted(false);      // Para remover as bordas do botão
        btnJogar.setPreferredSize(new Dimension(200, 50));

        // Efeito hover para o botão Jogar
        btnJogar.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                btnJogar.setIcon(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/play2.png"));
                new Sons("/Sons/Seleçao.wav");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                btnJogar.setIcon(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/play.png"));
            }
        });

        // Definir o botão Sair como imagem
        JButton btnSair = new JButton(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/exit.png"));
        btnSair.setFocusPainted(false);
        btnSair.setContentAreaFilled(false);
        btnSair.setBorderPainted(false);
        btnSair.setPreferredSize(new Dimension(200, 50));

        // Efeito hover para o botão Sair
        btnSair.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                btnSair.setIcon(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/exit2.png"));
                new Sons("/Sons/Seleçao.wav");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                btnSair.setIcon(new ImageIcon("/home/pedro/Documentos/Computação Gráfica/Jogo Corrida/src/Imagens/exit.png"));
            }
        });

        // Adicionar ações aos botões
        btnJogar.addActionListener(e -> iniciarJogo());
        btnSair.addActionListener(e -> {
            new Sons("/Sons/Seleçao.wav"); // Tocar som ao clicar no botão Sair
            System.exit(0);
        });

        // Adicionar os botões ao painel
        panel.add(btnJogar, gbc);
        panel.add(btnSair, gbc);

        background.setLayout(null);
        background.add(panel);

        setVisible(true);
    }

    private void iniciarJogo() {
        new Sons("/Sons/Seleçao.wav");
        this.dispose();
        new TelaSelecaoFases();
    }

    public static void main(String[] args) {
        new TelaInicio();
    }
}
