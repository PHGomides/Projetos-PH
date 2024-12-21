package questão02e03;

public class Disciplina {
    private String disciplina;
    
    public Disciplina(String disciplina) {
        this.disciplina = disciplina;
    }
        
    public String getDisciplina() {
        return disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    @Override
    public String toString() {
        return disciplina;
    }
}