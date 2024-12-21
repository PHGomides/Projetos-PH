package br.edu.ufj.biblioteca.dao;
import org.springframework.data.jpa.repository.JpaRepository;
import br.edu.ufj.biblioteca.model.Curso;

public interface CursoDAO extends JpaRepository<Curso, Integer> {
    
}
