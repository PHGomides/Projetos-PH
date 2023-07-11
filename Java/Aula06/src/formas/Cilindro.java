
package formas;

public class Cilindro extends Circulo {
    
    //atributos
    private double altura;
    
    
    //construtores
    public Cilindro (double raio, double altura){
        super(raio);
        this.altura = altura;
    }   
    
    //metodos
    public double getVolume(){
        return(getArea()*altura);
    }
    
    @Override
    public String toString(){
        return("\nCilindro \n- raio: "+raio+"\n- altura: "+altura+"\n- volume: "+getVolume());
    }
}
