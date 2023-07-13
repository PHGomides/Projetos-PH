
package questão08;

import java.util.ArrayList;
import java.util.List;

public class Pais {
    private String nome, capital, dimensao;
    private List<Pais> fronteira;

    public Pais(String nome, String capital, String dimensao) {
        this.nome = nome;
        this.capital = capital;
        this.dimensao = dimensao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCapital() {
        return capital;
    }

    public void setCapital(String capital) {
        this.capital = capital;
    }

    public String getDimensao() {
        return dimensao;
    }

    public void setDimensao(String dimensao) {
        this.dimensao = dimensao;
    }
    
     public boolean equals(final Pais outro){
        if((this.getNome() == outro.getNome()) && (this.getCapital() == outro.capital)){
        return true;
        }else{
        return false;
        }
    }
     
     public void setFronteira(List<Pais> fronteira) {
        this.fronteira = fronteira;
    }

    public List<Pais> getFronteira() {
        return fronteira;
    }
    
    public List<Pais> ComumFronteira(Pais outro) {
    List<Pais> vizinhosComuns = new ArrayList<>();
    if (fronteira != null && outro.getFronteira() != null) {
        for (Pais paisFronteira : fronteira) {
            if (outro.getFronteira().contains(paisFronteira)) {
                vizinhosComuns.add(paisFronteira);
            }
        }
    }
    return vizinhosComuns;
}

    @Override
    public String toString() {
        return "\nNome:" + nome + "\nCapital:" + capital + "\nDimensao:" + dimensao +"\n";
    }
    
    
}

    
    
    

