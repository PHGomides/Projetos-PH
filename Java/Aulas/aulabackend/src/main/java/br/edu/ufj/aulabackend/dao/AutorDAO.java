package br.edu.ufj.aulabackend.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import br.edu.ufj.aulabackend.model.Autor;

public interface AutorDAO extends JpaRepository<Autor, Integer> {

}
