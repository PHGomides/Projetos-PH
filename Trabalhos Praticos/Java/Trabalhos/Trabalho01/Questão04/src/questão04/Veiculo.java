
package questão04;

public abstract class Veiculo {
    private String cor;
    private int ano, potencia, valor;

    public Veiculo(String cor, int ano, int potencia, int valor) {
        this.cor = cor;
        this.ano = ano;
        this.potencia = potencia;
        this.valor = valor;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) {
        this.potencia = potencia;
    }

    public int getValor() {
        return valor;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }
    
    
}
