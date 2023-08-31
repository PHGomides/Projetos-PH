
package model;


public class Curso {
    public static int codigost =1;
    private int Codigo;
    
    private String nome;

    public Curso() {
    }

    public Curso(String nome) {
        this.nome = nome;
    }

    public static int getCodigost() {
        return codigost;
    }

    public static void setCodigost(int codigost) {
        Curso.codigost = codigost;
    }

    public int getCodigo() {
        return Codigo;
    }

    public void setCodigo(int Codigo) {
        this.Codigo = Codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return "Curso{" + "Codigo=" + Codigo + ", nome=" + nome + '}';
    }    
}
