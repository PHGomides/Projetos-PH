package questão07;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Movimentação> movimentacoes = new ArrayList<>();
       Movimentação m1 = new Movimentação("Deposito para outra conta", -200,0);
        movimentacoes.add(m1);
        
        List<Movimentação> movimentacoes2 = new ArrayList<>();
        Movimentação m2 = new Movimentação("Recebimento de outra conta", +200,0);
        movimentacoes2.add(m2);
        
        List<Conta_corrente> conta = new ArrayList<>();
        Conta_corrente c1 = new Conta_corrente(1,12000,30000,true,movimentacoes);
        Conta_corrente c2 = new Conta_corrente(2,2000,10000,false,movimentacoes2);
        conta.add(c1);conta.add(c2);
        
        Banco banco = new Banco(conta);
        banco.Saque(c1, 2000);
        System.out.println(banco);
        
        banco.Deposito(c1, 3000);
        System.out.println(banco);
        
        banco.TransfContasDep(c2, c1, 200);
        
        System.out.println(banco.getExtrato(c1));
        System.out.println(banco.getSaldo(c1));
        

    }   
}