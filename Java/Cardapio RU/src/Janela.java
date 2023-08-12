import javax.swing.*;
import java.awt.*;
import  javax.swing.border.EmptyBorder;
import java.awt.event.ActionListener;
import java.awt.font.TextHitInfo;

public class Janela extends JFrame  {
    private JButton BtAlterar, BtProximo, BtAnterior, BtSair;
    private JPanel pnBotões, pnCardapio, pnInfos;
    private JTextField tfDia, tfproteina, tfvegano, tfsalada, tfsuco, tffruta;
    private String  tgproteina = "PROTEINA: ", tgvegano = "PROTEINA_VEGANA: ", tgsalada = "SALADA: ", tgsuco = "SUCO: ", tgfruta = "FRUTA: ";

    Janela(){
        //Configurando Imagem
        ImageIcon imagem = new ImageIcon("src/Imagem/logoprincipal.png");
        JLabel imagens = new JLabel(imagem);

        //Configurando componentes
        tfDia = new JTextField();
        tfDia.setText("dia");
        tfDia.setEditable(false);
        Font fonttitulo = new Font("Arial",Font.BOLD,25);
        Font fontcardapio = new Font("Arial",Font.BOLD,12);
        tfDia.setFont(fonttitulo);


        tfproteina = new JTextField();
        tfproteina.setText(tgproteina+"Proteina: ");
        tfproteina.setEditable(false);
        tfproteina.setFont(fontcardapio);

        tfvegano = new JTextField();
        tfvegano.setText(tgvegano+"Vegano: ");
        tfvegano.setEditable(false);
        tfvegano.setFont(fontcardapio);

        tfsalada = new JTextField();
        tfsalada.setText(tgsalada+"Salada: ");
        tfsalada.setEditable(false);
        tfsalada.setFont(fontcardapio);

        tfsuco = new JTextField();
        tfsuco.setText(tgsuco+"Suco: ");
        tfsuco.setEditable(false);
        tfsuco.setFont(fontcardapio);

        tffruta = new JTextField();
        tffruta.setText(tgfruta+"Fruta: ");
        tffruta.setEditable(false);
        tffruta.setFont(fontcardapio);

        BtAlterar = new JButton("Alterar");
        BtAnterior = new JButton("Anterior");
        BtProximo = new JButton("Proximo");
        BtSair = new JButton("Sair");


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
        this.setDefaultCloseOperation(3);

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





}
