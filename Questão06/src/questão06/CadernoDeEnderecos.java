
package questão06;

public abstract class  CadernoDeEnderecos {
    private String nome, tell, email, dataaniversario, endereço;

    public CadernoDeEnderecos(String nome, String tell, String email, String dataaniversario, String endereço) {
        this.nome = nome;
        this.tell = tell;
        this.email = email;
        this.dataaniversario = dataaniversario;
        this.endereço = endereço;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTell() {
        return tell;
    }

    public void setTell(String tell) {
        this.tell = tell;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getDataaniversario() {
        return dataaniversario;
    }

    public void setDataaniversario(String dataaniversario) {
        this.dataaniversario = dataaniversario;
    }

    public String getEndereço() {
        return endereço;
    }

    public void setEndereço(String endereço) {
        this.endereço = endereço;
    }
    
    
    
}
