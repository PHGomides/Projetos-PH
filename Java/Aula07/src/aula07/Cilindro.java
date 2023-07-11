
package aula07;

public class Cilindro{
    
    //atributos
    private Circulo circulo;
    private double altura;
    
    
    //construtores
    public Cilindro (Circulo circulo, double altura){
        this.circulo = circulo;
        this.altura = altura;
    }
    public Cilindro (double raio, double altura){
        circulo = new Circulo(raio);
        this.altura = altura;
    }   
    
    public Cilindro(){
        this.altura = 0;
        circulo = new Circulo(0);
    }
    
    public double getRaio(){
        return circulo.getRaio();
    }
    
    public double getAltura(){
        return altura;
    }
    
    public void setRaio(double raio){
        circulo.setRaio(raio);
    }
    
    //metodos
    public double getVolume(){
        return(circulo.getRaio()*altura);
    }
    
    @Override
    public String toString(){
        return("\nCilindro \n- raio: "+circulo.getRaio()+"\n- altura: "+altura+"\n- volume: "+getVolume());
    }
}
