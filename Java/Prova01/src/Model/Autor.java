package Model;

import javax.swing.*;
import java.util.ArrayList;

public class Autor {

    private String nome;

    private int CodigoAutor;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCodigoAutor() {
        return CodigoAutor;
    }

    public void setCodigoAutor(int codigoAutor) {
        CodigoAutor = codigoAutor;
    }

    @Override
    public String toString() {
        return "Autor{" +
                "nome='" + nome + '\'' +
                ", CodigoAutor=" + CodigoAutor +
                '}';
    }
}
