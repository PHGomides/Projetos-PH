
package aula08;

public abstract class Pessoa {
    
    public static int codigo_st;
    protected int codigo;
    protected String nome, email;

    public Pessoa(String nome, String email) {
        this.codigo = ++codigo_st;
        this.nome = nome;
        this.email = email;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return ("Pessoa: Id: " + codigo + " Nome: " + nome + " Email: " + email);
    }
    
    
    
}
