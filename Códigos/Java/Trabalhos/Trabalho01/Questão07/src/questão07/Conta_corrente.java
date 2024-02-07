package questão07;

import java.util.List;

public class Conta_corrente {

    int numero, saldo,limite;
    boolean tipo;
    private List<Movimentação> movimentacoes;
    

    public Conta_corrente(int numero,int saldo, int limite, boolean tipo, List<Movimentação> movimentacoes) {
        this.numero = numero;
        this.saldo = saldo;
        this.limite = limite;
        this.tipo = tipo;
        this.movimentacoes = movimentacoes;
    }

    public Conta_corrente() {
    }

    public int getNumero() {
        return numero;
    }

    public void setNum(int numero) {
        this.numero = numero;
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

    public boolean getTipo() {
        return tipo;
    }

    public void setTipo(boolean tipo) {
        this.tipo = tipo;
    }

    public List<Movimentação> getMovimentacoes() {
        return movimentacoes;
    }

    public void setMovimentacoes(List<Movimentação> movimentacoes) {
        this.movimentacoes = movimentacoes;
    }

    @Override
    public String toString() {
        return "\n-----------\nConta: " + numero + "\nSaldo: " + saldo + "\nLimite: " + limite + "\nConta Especial: " + getTipo();
    }
}