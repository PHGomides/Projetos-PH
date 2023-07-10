
package questão01;

public class Calculadoracompleta extends Calculadora{
    

    public Calculadoracompleta(double valor01, double valor02) {
        super(valor01, valor02);
    }
    
    public Calculadoracompleta() {
        super(0, 0);
    }

    public double Raiz(double valor){
       return Math.sqrt(valor);
   }
    public double Quadrado(double valor){
        return Math.pow(valor, 2);
    }
    
   
   public String ToString(){
        return ("Valor01: "+valor01+"\nValor02: "+valor02+"\nSoma: "+Soma(valor01,valor02)+"\nSubtração: "+Subtração(valor01,valor02)+"\nMultiplicação: "+Multiplicação(valor01,valor02)+"\nDivisão: "+Divisão(valor01,valor02)+"\nRaiz-valor01: "+Raiz(valor01)+"\nRaiz-valor02: "+Raiz(valor02)+"\nValor01 ao quadrado: "+Quadrado(valor01)+"\nValor02 ao quadrado: "+Quadrado(valor02));
    }
}
