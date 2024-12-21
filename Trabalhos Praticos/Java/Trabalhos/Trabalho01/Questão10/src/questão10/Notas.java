
package questão10;

public class Notas {
    private double trab01, trab02, trab03, trab04, prova01, prova02;
    private double result;

    public Notas(double trab01, double trab02, double trab03, double trab04, double prova01, double prova02) {
        this.trab01 = trab01;
        this.trab02 = trab02;
        this.trab03 = trab03;
        this.trab04 = trab04;
        this.prova01 = prova01;
        this.prova02 = prova02;
    }

    public double getTrab01() {
        return trab01;
    }

    public void setTrab01(double trab01) {
        this.trab01 = trab01;
    }

    public double getTrab02() {
        return trab02;
    }

    public void setTrab02(double trab02) {
        this.trab02 = trab02;
    }

    public double getTrab03() {
        return trab03;
    }

    public void setTrab03(double trab03) {
        this.trab03 = trab03;
    }

    public double getTrab04() {
        return trab04;
    }

    public void setTrab04(double trab04) {
        this.trab04 = trab04;
    }

    public double getProva01() {
        return prova01;
    }

    public void setProva01(double prova01) {
        this.prova01 = prova01;
    }

    public double getProva02() {
        return prova02;
    }

    public void setProva02(double prova02) {
        this.prova02 = prova02;
    }
    
    public String Mediafinal(double trab01, double trab02, double trab03, double trab04, double prova01, double prova02){
        result = (((trab01 + trab02 + prova01) / 3) + ((trab03 + trab04 + prova02) / 3)/ 2);
        if (result >= 6){
            return ("Aprovado :"+result);
        }else{
            return ("Reprovado :"+result);
        }
    }

    @Override
    public String toString() {
        return ("\nNotas:\ntrabalho 01: " + trab01 + "\ntrabalho 02: " + trab02 + "\ntrabalho 03: " + trab03 + "\ntrabalho 04: " + trab04 + "\nprova01: " + prova01 + "\nprova02: " + prova02 + "\nMedia: " + Mediafinal( trab01, trab02, trab03, trab04, prova01, prova02));
    }
    
    
    
    
}
