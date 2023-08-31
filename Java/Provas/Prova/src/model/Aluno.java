package model;

import javax.swing.*;
import java.util.ArrayList;

public class Aluno {

    private String nome;
    private String Email;

    public static int codigost =1;
    private int Codigo;
    
    private Curso curso;

    public Aluno() {
    }

    public Aluno(String nome, String Email, Curso curso) {
        this.nome = nome;
        this.Email = Email;
        this.curso = curso;
    }

    public Curso getCurso(){
        return curso;
    }
    
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return Email;
    }

    public void setEmail(String Email) {
        this.Email = Email;
    }

    public static int getCodigost() {
        return codigost;
    }

    public static void setCodigost(int codigost) {
        Aluno.codigost = codigost;
    }

    public int getCodigo() {
        return Codigo;
    }

    public void setCodigo(int Codigo) {
        this.Codigo = Codigo;
    }

    @Override
    public String toString() {
        return "Aluno{" + "nome=" + nome + ", Email=" + Email + ", Codigo=" + Codigo + '}';
    }

}
