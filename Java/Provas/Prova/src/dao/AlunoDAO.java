
package dao;
import model.Aluno;
import java.util.List;
import java.util.ArrayList;

public class AlunoDAO {
    private List<Aluno> alunos = new ArrayList<>();
    
   
    
    public void gravaAluno(Aluno aluno)
    {
       alunos.add(aluno);
    }
    
    public void excluiAluno(Aluno aluno)
    {
       if(alunos.contains(aluno)){
           alunos.remove(aluno);
       }
     
    }
   
     public List<Aluno> buscaAlunos()
     {
       return alunos;  
     }
    
}
