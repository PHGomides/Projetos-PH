
package questão04;

public class Carro extends Veiculo{
    private int portamalas , portas;

    public Carro(String cor, int ano, int potencia, int valor, int portamalas, int portas) {
        super(cor, ano, potencia, valor);
        this.portamalas = portamalas;
        this.portas = portas;
    }

    public int getPortamalas() {
        return portamalas;
    }

    public void setPortamalas(int portamalas) {
        this.portamalas = portamalas;
    }

    public int getPortas() {
        return portas;
    }

    public void setPortas(int portas) {
        this.portas = portas;
    }
    
    @Override
    public String toString() {
        return ("\n-Carro-\nCor: "+getCor()+ "\nValor: " +getValor()+ "\nPotencia: " +getPotencia()+ "Hp\nAno: " +getAno()+ "\nPorta-Malas: " + portamalas + "L\nPortas: " + portas);
    }
    
    
}
