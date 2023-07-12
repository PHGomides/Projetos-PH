
package questão02e03;


import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        
        Disciplina disc1 = new Disciplina("Calculo 3");
        Disciplina disc2 = new Disciplina("P.O.O");
        
        List<Disciplina> disciplinas = new ArrayList<>();
        disciplinas.add(disc1);
        disciplinas.add(disc2);
        
        Aluno aluno = new Aluno("pedro", 123,20,"cc",disciplinas);
        System.out.println(aluno);
    }
    
}
