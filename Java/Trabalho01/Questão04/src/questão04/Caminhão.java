
package questão04;

public class Caminhão extends Veiculo{
    private int carga,eixo;

    public Caminhão(String cor, int ano, int potencia, int valor, int carga, int eixo) {
        super(cor, ano, potencia, valor);
        this.carga = carga;
        this.eixo = eixo;
    }

    public int getCarga() {
        return carga;
    }

    public void setCarga(int carga) {
        this.carga = carga;
    }

    public int getEixo() {
        return eixo;
    }

    public void setEixo(int eixo) {
        this.eixo = eixo;
    }
    
    @Override
    public String toString() {
        return ("\n-Caminhao-\nCor: "+getCor()+ "\nValor: " +getValor()+ "\nPotencia: " +getPotencia()+ "Hp\nAno: " +getAno()+ "\nCarga: " + carga + "T\nEixos: " + eixo);
    }
    
    
    
}
