package br.edu.ufj.biblioteca;

import java.util.Arrays;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import br.edu.ufj.biblioteca.dao.CursoDAO;
import br.edu.ufj.biblioteca.model.Curso;

@SpringBootApplication
public class BibliotecaApplication implements CommandLineRunner {

	@Autowired
	private CursoDAO cursoDAO;

	public static void main(String[] args) {
		SpringApplication.run(BibliotecaApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		Curso c1 = new Curso(1, "Ingles", 64);
		Curso c2 = new Curso(2, "P.O.O", 64);
		Curso c3 = new Curso(3, "Planilha", 64);

		cursoDAO.saveAll(Arrays.asList(c1,c2,c3));
	}

}
