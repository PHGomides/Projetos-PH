
package questão02e03;

public class Aluno extends Pessoa{
    
    private String curso, disciplina;
    
    

    public Aluno(int codigo, String nome, int cpf, int idade, String curso, String disciplina) {
        super(codigo, nome, cpf, idade);
        this.curso = curso;
        this.disciplina = disciplina;
    }
    
    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public String getDisciplina() {
        return disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    @Override
    public String toString() {
        return ("Codigo: "+getCodigo()+"Nome: "+getNome()+"\n CPF: "+getCpf()+"\n Idade: "+getIdade()+"\n curso: "+curso+"\n disciplina: "+disciplina);
    }
    
    
    
    
}
