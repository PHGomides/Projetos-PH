
package questão01;

public class Calculadoracompleta extends Calculadora{
    

    public Calculadoracompleta() {
        super(0, 0);
    }
    
    public Calculadoracompleta(double valor01, double valor02) {
        super(valor01, valor02);
        this.valor01 = valor01;
        this.valor02 = valor02;
    }
    
    public double Raiz(double valor){
       return Math.sqrt(valor);
   }
    public double Quadrado(double valor){
        return Math.pow(valor, 2);
    }
    
   @Override
   public String toString(){
        return ("Valor01: "+getValor01()+"\nValor02: "+getValor02()+"\nSoma: "+Soma(valor01,valor02)+"\nSubtracao: "+Subtração(valor01,valor02)+"\nMultiplicacao: "+Multiplicação(valor01,valor02)+"\nDivisao: "+Divisão(valor01,valor02)+"\nRaiz-valor01: "+Raiz(valor01)+"\nRaiz-valor02: "+Raiz(valor02)+"\nValor01 ao quadrado: "+Quadrado(valor01)+"\nValor02 ao quadrado: "+Quadrado(valor02));
    }
}
