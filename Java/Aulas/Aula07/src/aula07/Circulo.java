
package aula07;

public class Circulo {
    //atributos
    protected double raio;
    
    //Contrutor
    Circulo(){this(0.0);}
    
    Circulo(double raio){
        this.raio=raio;
    }
    
    
    //Metodos
    double getRaio(){
        return raio;
    }
    
    public void setRaio(double raio){
        this.raio = raio;
    }
        
    double getArea(){
        return (Math.PI*Math.pow(raio, 2));
    }
    
    double getDiametro(){
        return raio*2;
    }
    
    double getPerimetro(){
        return Math.PI*raio*2;
    }
    
    @Override
    public String toString(){
        return(String.format("Circulo \n- Raio: %.2f \nArea: %.2f \nDiametro: %.2f \nPerimetro: %.2f",raio,getArea(),getDiametro(),getPerimetro()));
    }
}
