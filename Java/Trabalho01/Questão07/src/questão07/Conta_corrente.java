package questão07;

import java.util.List;

public class Conta_corrente {
    //Atributos
    int num, saldo,limite;
    boolean isesp;
    private List<Movimentação> movimentacoes;
    
    //Construtores
    public Conta_corrente(int num,int saldo, int limite, boolean isesp, List<Movimentação> movimentacoes) {
        this.num = num;
        this.saldo = saldo;
        this.limite = limite;
        this.isesp = isesp;
        this.movimentacoes = movimentacoes;
    }

    public Conta_corrente() {
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public int getSaldo() {
        return saldo;
    }

    public void setSaldo(int saldo) {
        this.saldo = saldo;
    }

    public int getLimite() {
        return limite;
    }

    public void setLimite(int limite) {
        this.limite = limite;
    }

    public boolean isIsesp() {
        return isesp;
    }

    public void setIsesp(boolean isesp) {
        this.isesp = isesp;
    }

    public List<Movimentação> getMovimentacoes() {
        return movimentacoes;
    }

    public void setMovimentacoes(List<Movimentação> movimentacoes) {
        this.movimentacoes = movimentacoes;
    }

    @Override
    public String toString() {
        return "ContaCorrente{" + "num=" + num + ", saldo=" + saldo + ", limite=" + limite + ", Conta Especial=" + isIsesp();
    }
}