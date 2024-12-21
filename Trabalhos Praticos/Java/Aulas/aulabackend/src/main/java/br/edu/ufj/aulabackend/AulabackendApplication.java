package br.edu.ufj.aulabackend;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import br.edu.ufj.aulabackend.dao.CursoDAO;
import br.edu.ufj.aulabackend.dao.AlunoDAO;
import br.edu.ufj.aulabackend.model.Curso;
import br.edu.ufj.aulabackend.model.Aluno;

@SpringBootApplication
public class AulabackendApplication implements CommandLineRunner {

	@Autowired
	private CursoDAO cursoDAO;

	@Autowired
	private AlunoDAO alunoDAO;

	public static void main(String[] args) {
		SpringApplication.run(AulabackendApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {

		Curso c1 = new Curso(1, "Calculo3");
		Curso c2 = new Curso(2, "P.O.O");

		cursoDAO.save(c1);
		cursoDAO.save(c2);

		Aluno a1 = new Aluno(1, "Pedro", "Pedro@gmail.com");
		Aluno a2 = new Aluno(2, "Alice", "Alice@gmail.com");
		Aluno a3 = new Aluno(3, "Cleber", "Cleber@gmail.com");
		Aluno a4 = new Aluno(4, "Rafaela", "Rafaela@gmail.com");
		c1.adicionarAluno(a1);
		c1.adicionarAluno(a2);

		c2.adicionarAluno(a3);
		c2.adicionarAluno(a4);
		
		
		alunoDAO.save(a1);
		alunoDAO.save(a2);
		alunoDAO.save(a3);
		alunoDAO.save(a4);

	

		

	}

}
