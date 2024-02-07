package view;
import javax.swing.*;
import java.awt.*;
import  javax.swing.border.EmptyBorder;

import model.Cliente;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;



public class Janela extends JFrame implements ActionListener{
    private JButton BtAlterar, BtProximo, BtAnterior, BtSair;
    private JPanel pnBotões, pnCardapio, pnInfos;
    private JTextField tfDia, tfproteina, tfvegano, tfsalada, tfsuco, tffruta;
    public static int dia_semana = 0;
    private String  tgproteina = "PROTEINA:   ", tgvegano = "VEGETARIANO:   ", tgsalada = "SALADA:   ", tgsuco = "SUCO:   ", tgfruta = "FRUTA:   ";
    private  static  Cliente cliente;



    public Janela(){
        //Configurando Imagem
        ImageIcon imagem = new ImageIcon("src/Imagem/logoprincipal.png");
        JLabel imagens = new JLabel(imagem);

        //Configurando componentes

        tfDia = new JTextField(cliente.vetdia[dia_semana]);
        tfDia.setEditable(false);
        Font fonttitulo = new Font("Arial",Font.BOLD,25);
        Font fontcardapio = new Font("Arial",Font.BOLD,12);
        tfDia.setFont(fonttitulo);


        tfproteina = new JTextField();
        tfproteina.setText(tgproteina + cliente.vetproteina[dia_semana]);
        tfproteina.setEditable(false);
        tfproteina.setFont(fontcardapio);

        tfvegano = new JTextField();
        tfvegano.setText(tgvegano + cliente.vetvegano[dia_semana]);
        tfvegano.setEditable(false);
        tfvegano.setFont(fontcardapio);

        tfsalada = new JTextField();
        tfsalada.setText(tgsalada + cliente.vetsalada[dia_semana]);
        tfsalada.setEditable(false);
        tfsalada.setFont(fontcardapio);

        tfsuco = new JTextField();
        tfsuco.setText(tgsuco + cliente.vetsuco[dia_semana]);
        tfsuco.setEditable(false);
        tfsuco.setFont(fontcardapio);

        tffruta = new JTextField();
        tffruta.setText(tgfruta + cliente.vetfruta[dia_semana]);
        tffruta.setEditable(false);
        tffruta.setFont(fontcardapio);

        BtAlterar = new JButton("Alterar");
        BtAlterar.addActionListener(this);

        BtAnterior = new JButton("Anterior");
        BtAnterior.addActionListener(this);

        BtProximo = new JButton("Proximo");
        BtProximo.addActionListener(this);

        BtSair = new JButton("Sair");
        BtSair.addActionListener(this);

        //Configurando Painel
        pnInfos = new JPanel(new GridLayout(2,1));
        pnInfos.add(imagens);
        pnInfos.add(tfDia);

        pnCardapio = new JPanel(new GridLayout(5,2));
        pnCardapio.add(tfproteina);
        pnCardapio.add(tfvegano);
        pnCardapio.add(tfsalada);
        pnCardapio.add(tffruta);
        pnCardapio.add(tfsuco);

        pnBotões = new JPanel(new FlowLayout());
        pnBotões.add(BtAlterar);
        pnBotões.add(BtAnterior);
        pnBotões.add(BtProximo);
        pnBotões.add(BtSair);

        //Configurando Tela
        this.setSize(500,700);
        this.setTitle("Cardapio Universitario");
        this.setVisible(true);
        this.setLocationRelativeTo(null);


        this.setLayout(new BorderLayout());
        this.add(pnInfos,BorderLayout.NORTH);
        this.add(pnCardapio,BorderLayout.CENTER);
        this.add(pnBotões,BorderLayout.SOUTH);

        //Configurando Tela-->Tirando Borda
        tfDia.setBorder(new EmptyBorder(0, 0, 0, 0));
        tffruta.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfproteina.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfvegano.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfsuco.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfsalada.setBorder(new EmptyBorder(0, 0, 0, 0));

        //Configurando Tela-->Cores
        Color color = new Color(30,144,255);
        tfDia.setBackground(color);
        BtSair.setBackground(color);
        BtAlterar.setBackground(color);
        BtProximo.setBackground(color);
        BtAnterior.setBackground(color);

        //Configurando Tela--> Alinhamento
        tfDia.setHorizontalAlignment(JTextField.CENTER);
        tfproteina.setHorizontalAlignment(JTextField.CENTER);
        tfvegano.setHorizontalAlignment(JTextField.CENTER);
        tfsalada.setHorizontalAlignment(JTextField.CENTER);
        tffruta.setHorizontalAlignment(JTextField.CENTER);
        tfsuco.setHorizontalAlignment(JTextField.CENTER);
    }
    //----------------------------------------------------------------------------------------
    //Configurando funcionalidades
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == BtAlterar){
            Alterar alterar = new Alterar();
            dispose();
        }else if (e.getSource() == BtAnterior){
            if (dia_semana > 0) {
                dia_semana--;
                tfDia.setText(cliente.vetdia[dia_semana]);
                tfproteina.setText(tgproteina + cliente.vetproteina[dia_semana]);
                tfvegano.setText(tgvegano + cliente.vetvegano[dia_semana]);
                tfsalada.setText(tgsalada + cliente.vetsalada[dia_semana]);
                tffruta.setText(tgfruta + cliente.vetfruta[dia_semana]);
                tfsuco.setText(tgsuco + cliente.vetsuco[dia_semana]);
            }
        }else if (e.getSource() == BtProximo) {
            if (dia_semana < 4) {
                dia_semana++;
                tfDia.setText(cliente.vetdia[dia_semana]);
                tfproteina.setText(tgproteina + cliente.vetproteina[dia_semana]);
                tfvegano.setText(tgvegano + cliente.vetvegano[dia_semana]);
                tfsalada.setText(tgsalada + cliente.vetsalada[dia_semana]);
                tffruta.setText(tgfruta + cliente.vetfruta[dia_semana]);
                tfsuco.setText(tgsuco + cliente.vetsuco[dia_semana]);
            }
        }else if (e.getSource() == BtSair){
            System.exit(0);
        }
    }
}
