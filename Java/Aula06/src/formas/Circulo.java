
package formas;

public class Circulo {
    //atributos
    double raio;
    
    //Contrutor
    Circulo(){this(0.0);}
    
    Circulo(double raio){
        this.raio=raio;
    }
    
    
    //Metodos
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
