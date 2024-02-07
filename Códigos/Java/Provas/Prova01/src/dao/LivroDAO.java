package dao;
import Model.Livro;

import javax.swing.*;
import java.util.List;
import java.util.ArrayList;

public class LivroDAO {
    private String nome;

    public int codigoMAX = 0;
    public List<Livro> livros = new ArrayList<Livro>();


    public void gravaLivro(Livro estoque)
    {
        livros.add(estoque);
        codigoMAX++;
    }
    public void excluiLivro(String descricao)
    {

    }
    public List<Livro> buscaLivros() {
        return livros;
    }

}
