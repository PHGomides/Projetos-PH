package br.edu.ufj.aulabackend.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import br.edu.ufj.aulabackend.model.Livro;

public interface LivroDAO extends JpaRepository<Livro, Integer> {

}
