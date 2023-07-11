
package questão04;

public class Moto extends Veiculo{
    private String modelo;
    private int economia;

    public Moto(String cor, int ano, int potencia, int valor, String modelo, int economia) {
        super(cor, ano, potencia, valor);
        this.modelo = modelo;
        this.economia = economia;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getEconomia() {
        return economia;
    }

    public void setEconomia(int economia) {
        this.economia = economia;
    }

    @Override
    public String toString() {
        return ("-Moto-\nCor: "+getCor()+ "\nValor: " +getValor()+ "\nPotencia: " +getPotencia()+ "Cv\nAno: " +getAno()+ "\nModelo: " + modelo + " \nKm/L: " + economia);
    }
    
    
    
    
}
