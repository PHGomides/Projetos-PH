package aula05;
public class Triangulo {
    private int base, altura;
    
    public Triangulo(){
        this(0,0);
    }
    
    public Triangulo(int base, int altura){
        this.base = base;
        this.altura = altura;
    }
    public void setBase(int base){this.base = base;}
    public void setAltura(int altura){this.altura = altura;}
    
    public int getBase(){return base;}
    public int getAltura(){return altura;}
    
    @Override
    public String toString(){
        return ("Base: "+base+"\nAltura: "+altura+"\nArea: "+getArea()+"\nHipotenusa: "+getHipotenusa());
    }
              
    double getArea(){
        return ((base*altura)/2.0);
    }
    
    double getHipotenusa(){
        return Math.hypot(base, altura);
    }
}
