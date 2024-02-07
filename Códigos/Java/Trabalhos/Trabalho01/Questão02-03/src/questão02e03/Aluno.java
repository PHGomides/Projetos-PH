
package questão02e03;

import java.util.List;

public class Aluno extends Pessoa{
    
    private String curso;
    private List<Disciplina> disciplina;
    
    
    public Aluno(String nome, int cpf, int idade, String curso,  List<Disciplina> disciplina) {
        super(nome, cpf, idade);
        this.curso = curso;
        this.disciplina = disciplina;
    }
    
    public List<Disciplina> getDisciplina() {
        return disciplina;
    }

    public void setDisciplina(List<Disciplina> disciplina) {
        this.disciplina = disciplina;
    }

    
    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    @Override
    public String toString() {
        return ("\nNome: "+getNome()+"\n CPF: "+getCpf()+"\n Idade: "+getIdade()+"\n Curso: "+curso+"\n Disciplina: "+disciplina);
    }
    
    
    
    
}
