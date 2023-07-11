
package aula08;

public final class Cliente extends Pessoa{
    //atributos
    
    private String cpf;
    
    
    //construtores
    public Cliente(){
        this(null,null,null);
    }
    
    
    public Cliente(String nome, String cpf, String email){
        super(nome,email);
        this.cpf = cpf;
        
    }
    
    // getters e setters
    
    public String getCpf(){return cpf;}
    public void setCpf(String cpf){this.cpf = cpf;}
        
    @Override
    public String toString(){
        return ("ID: "+codigo+"  Cliente: "+nome+"  Cpf: "+cpf+"  Email: "+email);
    }
    
}
