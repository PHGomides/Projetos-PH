package questão07;

import java.util.List;

public class Banco {
  
    private List<Conta_corrente> contas;
    private Conta_corrente conta;


    public Banco(List<Conta_corrente> contas) {
        this.contas = contas;
    }

    public Banco() {
    }
    
 
    public void Saque(Conta_corrente conta, int valor){
        if(conta.getSaldo()>0 && valor<conta.getSaldo() + conta.getLimite()){
        conta.setSaldo(conta.getSaldo() - valor);
        }
    }
    
    public void Deposito(Conta_corrente conta, int valor){
        conta.setSaldo(conta.getSaldo() + valor);
    }
    
    public void TransfContasDep(Conta_corrente conta1, Conta_corrente conta2, int valor){
        conta2.setSaldo(conta2.getSaldo() + valor);
        conta1.setSaldo(conta1.getSaldo() - valor);
    }
    
    public String getSaldo(Conta_corrente conta){
        return "Seu saldo: " + conta.getSaldo();
    }
    
    public String getExtrato(Conta_corrente conta){
        return "Extrato: " + conta.getMovimentacoes();
    }
    
    @Override
    public String toString() {
        return "Banco" + " \nContas:" + contas;
    }
}