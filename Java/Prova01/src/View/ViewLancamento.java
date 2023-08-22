package View;

import Model.Autor;
import Model.Livro;
import dao.LivroDAO;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ViewLancamento extends JFrame implements ActionListener {
    private JButton BtSalvar, BtDeletar;
    private JPanel pnBotões, pnInfos, pnBotoes02;
    private JTextField tftitulo, tfcadastro;
    private JLabel Jlautor, Jltitulo;
    private JComboBox Cbautor;
    private JTable jtable;

    private String item;
    private DefaultTableModel tableModel;

    private Livro livro;
    private Autor autor;

    private LivroDAO livroDAO;

    public ViewLancamento() {
        String[] topo = {"Código", "Titulo", "Autor"};
        tableModel = new DefaultTableModel(topo, 0);

        jtable = new JTable(tableModel);

        JScrollPane scrollPane = new JScrollPane(jtable);

        Jlautor = new JLabel("Autor");
        Jltitulo= new JLabel("Titulo");

        Cbautor = new JComboBox<>();
        Cbautor.addItem("Marcos");
        Cbautor.addItem("Pedro");

        tftitulo = new JTextField();

        tfcadastro = new JTextField("Cadastro de Livro");
        tfcadastro.setEnabled(false);

        BtSalvar = new JButton("Salvar");
        BtSalvar.addActionListener(this);
        BtDeletar = new JButton("Excluir");
        BtDeletar.addActionListener(this);

        pnInfos = new JPanel(new GridLayout(1,1));
        pnInfos.add(tfcadastro);

        pnBotões = new JPanel(new GridLayout(3,3));
        pnBotões.add(Jlautor);
        pnBotões.add(Jltitulo);
        pnBotões.add(Cbautor);
        pnBotões.add(tftitulo);
        pnBotões.add(BtDeletar);
        pnBotões.add(BtSalvar);
        

        this.setLayout(new BorderLayout());
        this.add(pnInfos,BorderLayout.NORTH);
        this.add(pnBotões,BorderLayout.CENTER);

        this.add(scrollPane,BorderLayout.SOUTH);

        this.setSize(700, 900);
        this.setTitle("Biblioteca 1.0");
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(3);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == BtSalvar){

        }else if (e.getSource() == BtDeletar){

        }

    }
}
