package questão08;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
    Pais brasil = new Pais("Brasil", "Brasilia", "Grande");
    Pais argentina = new Pais("Argentina", "Buenos Aires", "Grande");
    Pais uruguai = new Pais("Uruguai", "Montevideu", "Pequena");

    List<Pais> fronteiraBrasil = new ArrayList<>();
    fronteiraBrasil.add(argentina);
    fronteiraBrasil.add(uruguai);
    brasil.setFronteira(fronteiraBrasil);

    List<Pais> fronteiraArgentina = new ArrayList<>();
    fronteiraArgentina.add(brasil);
    fronteiraArgentina.add(uruguai);
    argentina.setFronteira(fronteiraArgentina);

    List<Pais> fronteiraUruguai = new ArrayList<>();
    fronteiraUruguai.add(brasil);
    fronteiraUruguai.add(argentina);
    uruguai.setFronteira(fronteiraUruguai);

    List<Pais> paisesEmComum = brasil.ComumFronteira(argentina);
    List<Pais> paisesEmComum2 = brasil.ComumFronteira(uruguai);
    List<Pais> paisesEmComum3 = argentina.ComumFronteira(uruguai);
    
    System.out.println(brasil);
    System.out.println(argentina);
    System.out.println(uruguai);

    System.out.println("\n----------------\nFronteiras em comum\n" + "\nBrasil e Argentinan\n" + paisesEmComum + "\nBrasil e Uruguai \n" + paisesEmComum2 + "\nUruguai e Argentina\n" + paisesEmComum3);
   }
}