
package questão06;

public class TesteCaderno extends CadernoDeEnderecos{

    public TesteCaderno(String nome, String tell, String email, String dataaniversario, String endereço) {
        super(nome, tell, email, dataaniversario, endereço);
    }

    @Override
    public String toString() {
        return ("-Caderno-\n\nNome: "+getNome()+"\nTelefone: "+getTell()+"\nEmail: "+getEmail()+"\nData_Aniversario: "+getDataaniversario()+"\nEndereco: "+getEndereço());
    }
    
    
    
}
