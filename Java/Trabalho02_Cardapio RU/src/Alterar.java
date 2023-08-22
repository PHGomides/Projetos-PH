import javax.swing.*;
import java.awt.*;
import  javax.swing.border.EmptyBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class Alterar extends  JFrame implements ActionListener {
    private JButton BtProximo, BtAnterior, BtSair, BtSalvar;
    private JPanel pnBotões, pnCardapio, pnInfos;
    private JTextField lbproteina, lbvegano, lbsalada, lbsuco, lbfruta;
    private JTextField tfDia, tfproteina, tfvegano, tfsalada, tfsuco, tffruta;

    private static Cliente cliente;

    Alterar(){

        //Configuraçao tela_alterar

        //Configurando Imagem
        ImageIcon imagem = new ImageIcon("src/Imagem/logocadastro.png");
        JLabel imagens = new JLabel(imagem);

        //Configurando componentes
        tfDia = new JTextField(cliente.vetdia[cliente.dia_semana]);
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

        tfproteina.setText(cliente.vetproteina[cliente.dia_semana]);
        tfvegano.setText(cliente.vetvegano[cliente.dia_semana]);
        tfsalada.setText(cliente.vetsalada[cliente.dia_semana]);
        tffruta.setText(cliente.vetfruta[cliente.dia_semana]);
        tfsuco.setText(cliente.vetsuco[cliente.dia_semana]);

        BtAnterior = new JButton("Anterior");
        BtAnterior.addActionListener(this);

        BtProximo = new JButton("Proximo");
        BtProximo.addActionListener(this);

        BtSair = new JButton("Voltar");
        BtSair.addActionListener(this);

        BtSalvar = new JButton("Salvar");
        BtSalvar.addActionListener(this);


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


        //----------------------------------------------------------------------------------------


        //Configurando funcionalidades

    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == BtSalvar){
            cliente.vetproteina[cliente.dia_semana] = tfproteina.getText();
            cliente.vetvegano[cliente.dia_semana] = tfvegano.getText();
            cliente.vetsalada[cliente.dia_semana] = tfsalada.getText();
            cliente.vetsuco[cliente.dia_semana] = tfsuco.getText();
            cliente.vetfruta[cliente.dia_semana] = tffruta.getText();
            JOptionPane.showMessageDialog(null,"Cardapio da " +cliente.vetdia[cliente.dia_semana] + " cadastrado com sucesso");
        }else if (e.getSource() == BtProximo){
            if (cliente.dia_semana < 4){
                cliente.dia_semana++;
                tfDia.setText(cliente.vetdia[cliente.dia_semana]);
                tfproteina.setText(cliente.vetproteina[cliente.dia_semana]);
                tfvegano.setText(cliente.vetvegano[cliente.dia_semana]);
                tfsalada.setText(cliente.vetsalada[cliente.dia_semana]);
                tffruta.setText(cliente.vetfruta[cliente.dia_semana]);
                tfsuco.setText(cliente.vetsuco[cliente.dia_semana]);
            }
        }else if (e.getSource() == BtAnterior) {
            if (cliente.dia_semana > 0) {
                cliente.dia_semana--;
                tfDia.setText(cliente.vetdia[cliente.dia_semana]);
                tfproteina.setText(cliente.vetproteina[cliente.dia_semana]);
                tfvegano.setText(cliente.vetvegano[cliente.dia_semana]);
                tfsalada.setText(cliente.vetsalada[cliente.dia_semana]);
                tffruta.setText(cliente.vetfruta[cliente.dia_semana]);
                tfsuco.setText(cliente.vetsuco[cliente.dia_semana]);
            }
        } else if (e.getSource() == BtSair) {
            Janela janela = new Janela();
            dispose();
        }

    }
}
