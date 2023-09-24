package br.edu.ufj.aulabackend;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import br.edu.ufj.aulabackend.dao.AutorDAO;
import br.edu.ufj.aulabackend.dao.LivroDAO;
import br.edu.ufj.aulabackend.model.Autor;
import br.edu.ufj.aulabackend.model.Livro;

@SpringBootApplication
public class AulabackendApplication implements CommandLineRunner {
	@Autowired
	private LivroDAO livroDAO;

	@Autowired
	private AutorDAO autorDAO;

	public static void main(String[] args) {
		SpringApplication.run(AulabackendApplication.class, args);
	}

	@Override
	public void run(String... args) throws Exception {
		Autor a1 = new Autor(1, "Pedro");
		Autor a2 = new Autor(2, "Alice");
		autorDAO.save(a1);
		autorDAO.save(a2);

		Livro l1 = new Livro(1, "P.O.O");
		Livro l2 = new Livro(2, "Programação WEB");
		livroDAO.save(l1);
		livroDAO.save(l2);
	}

}
