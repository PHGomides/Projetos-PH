
package questão01;

public abstract class Calculadora {
   protected double valor01, valor02;

    Calculadora(double valor01, double valor02) {
        this.valor01 = valor01;
        this.valor02 = valor02;
    }

    public double getValor01() {
        return valor01;
    }

    public void setValor01(double valor01) {
        this.valor01 = valor01;
    }

    public double getValor02() {
        return valor02;
    }

    public void setValor02(double valor02) {
        this.valor02 = valor02;
    }
   
    
   public double Soma(double valor01, double valor02){
       return valor01 + valor02;
   }
   
   public double Subtração(double valor01, double valor02){
       return valor01 - valor02;
   }
   
   public double Divisão(double valor01, double valor02){
       return valor01/valor02;
   }
   
   public double Multiplicação(double valor01, double valor02){
       return valor01*valor02;
   }
   
}
