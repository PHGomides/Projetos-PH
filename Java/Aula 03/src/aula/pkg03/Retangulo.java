/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package aula.pkg03;

/**
 *
 * @author pedro
 */
public class Retangulo {
    int base, altura;
    
    //contrutores
    Retangulo(){
        this(0,0);
    }
    
    Retangulo(int base, int altura){
        this.base = base;
        this.altura = altura;
    }
    //Metodos
    
    int getBase(){return base;}
    int getAltura(){return altura;}
    
    void setBase(int base){this.base = base;}
    void setAltura(int altura){this.base = altura;}
    
    public String toString(){
        return("Base:"+base+" - Altura: "+altura+"- Area: "+getArea()+"- Diagonal: "+getDiagonal());
    }
            
            
    int getArea(){
        return base*altura;
    }
    
    double getDiagonal(){
        return Math.sqrt((base*base) + (altura*altura));
    }
}