package br.edu.ufj.aulabackend.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import br.edu.ufj.aulabackend.model.Curso;

public interface CursoDAO extends JpaRepository<Curso, Integer> {

}
