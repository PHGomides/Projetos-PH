import javax.swing.*;
import java.awt.*;
import  javax.swing.border.EmptyBorder;
public class Alterar extends  JFrame{
    public static String[] vetdia, vetproteina, vetvegano, vetsalada, vetfruta, vetsuco;

    private JButton BtProximo, BtAnterior, BtSair, BtSalvar;
    private JPanel pnBotões, pnCardapio, pnInfos;
    private JTextField lbproteina, lbvegano, lbsalada, lbsuco, lbfruta;
    private JTextField tfDia, tfproteina, tfvegano, tfsalada, tfsuco, tffruta;

    public static void setVetdia(String[] vetdia) {
        Alterar.vetdia = vetdia;
    }

    public static String[] getVetdia() {
        return vetdia;
    }

    public static String[] getVetproteina() {
        return vetproteina;
    }

    public static String[] getVetvegano() {
        return vetvegano;
    }

    public static String[] getVetsalada() {
        return vetsalada;
    }

    public static String[] getVetfruta() {
        return vetfruta;
    }

    public static String[] getVetsuco() {
        return vetsuco;
    }

    Alterar(){

        //Configuraçao tela_alterar

        //Configurando Imagem
        ImageIcon imagem = new ImageIcon("src/Imagem/logocadastro.png");
        JLabel imagens = new JLabel(imagem);

        //Configurando componentes
        tfDia = new JTextField();
        tfDia.setText("dia");
        tfDia.setEditable(false);
        Font font = new Font("Arial", Font.BOLD, 25);
        Font fontcadastro = new Font("Arial",Font.BOLD,12);
        tfDia.setFont(font);

        lbproteina = new JTextField("PROTEINA: ");
        lbproteina.setFont(fontcadastro);
        lbproteina.setEditable(false);
        lbvegano = new JTextField("VEGANO: ");
        lbvegano.setFont(fontcadastro);
        lbvegano.setEditable(false);
        lbsalada = new JTextField("SALADA: ");
        lbsalada.setFont(fontcadastro);
        lbsalada.setEditable(false);
        lbsuco= new JTextField("SUCO: ");
        lbsuco.setFont(fontcadastro);
        lbsuco.setEditable(false);
        lbfruta = new JTextField("FRUTA: ");
        lbfruta.setFont(fontcadastro);
        lbfruta.setEditable(false);

        tfproteina = new JTextField();

        tfvegano = new JTextField();

        tfsalada = new JTextField();

        tfsuco = new JTextField();

        tffruta = new JTextField();

        BtAnterior = new JButton("Anterior");
        BtProximo = new JButton("Proximo");
        BtSair = new JButton("Sair");
        BtSalvar = new JButton("Salvar");


        //Configurando Painel
        pnInfos = new JPanel(new GridLayout(2, 1));
        pnInfos.add(imagens);
        pnInfos.add(tfDia);

        pnCardapio = new JPanel(new GridLayout(5, 2));
        pnCardapio.add(lbproteina);
        pnCardapio.add(tfproteina);

        pnCardapio.add(lbvegano);
        pnCardapio.add(tfvegano);

        pnCardapio.add(lbsalada);
        pnCardapio.add(tfsalada);

        pnCardapio.add(lbfruta);
        pnCardapio.add(tffruta);

        pnCardapio.add(lbsuco);
        pnCardapio.add(tfsuco);

        pnBotões = new JPanel(new FlowLayout());
        pnBotões.add(BtSalvar);
        pnBotões.add(BtAnterior);
        pnBotões.add(BtProximo);
        pnBotões.add(BtSair);

        //Configurando Tela
        this.setSize(500, 700);
        this.setTitle("Cadastro");
        this.setVisible(true);
        this.setLocationRelativeTo(null);

        this.setLayout(new BorderLayout());
        this.add(pnInfos, BorderLayout.NORTH);
        this.add(pnCardapio, BorderLayout.CENTER);
        this.add(pnBotões, BorderLayout.SOUTH);

        //Configurando Tela-->Tirando Borda
        tfDia.setBorder(new EmptyBorder(0, 0, 0, 0));
        tffruta.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfproteina.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfvegano.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfsuco.setBorder(new EmptyBorder(0, 0, 0, 0));
        tfsalada.setBorder(new EmptyBorder(0, 0, 0, 0));
        lbfruta.setBorder(new EmptyBorder(0, 0, 0, 0));
        lbproteina.setBorder(new EmptyBorder(0, 0, 0, 0));
        lbvegano.setBorder(new EmptyBorder(0, 0, 0, 0));
        lbsuco.setBorder(new EmptyBorder(0, 0, 0, 0));
        lbsalada.setBorder(new EmptyBorder(0, 0, 0, 0));

        //Configurando Tela-->Cores
        Color color = new Color(30, 144, 255);
        tfDia.setBackground(color);
        BtSalvar.setBackground(color);
        BtSair.setBackground(color);
        BtProximo.setBackground(color);
        BtAnterior.setBackground(color);

        //Configurando Tela--> Alinhamento
        tfDia.setHorizontalAlignment(JTextField.CENTER);
        tfproteina.setHorizontalAlignment(JTextField.CENTER);
        tfvegano.setHorizontalAlignment(JTextField.CENTER);
        tfsalada.setHorizontalAlignment(JTextField.CENTER);
        tffruta.setHorizontalAlignment(JTextField.CENTER);
        tfsuco.setHorizontalAlignment(JTextField.CENTER);
        lbproteina.setHorizontalAlignment(JTextField.CENTER);
        lbvegano.setHorizontalAlignment(JTextField.CENTER);
        lbsalada.setHorizontalAlignment(JTextField.CENTER);
        lbfruta.setHorizontalAlignment(JTextField.CENTER);
        lbsuco.setHorizontalAlignment(JTextField.CENTER);
    }

}
