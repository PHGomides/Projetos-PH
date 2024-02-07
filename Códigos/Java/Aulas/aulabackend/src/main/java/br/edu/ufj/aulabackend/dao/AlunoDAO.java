package br.edu.ufj.aulabackend.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import br.edu.ufj.aulabackend.model.Aluno;

public interface AlunoDAO extends JpaRepository<Aluno, Integer> {

}
