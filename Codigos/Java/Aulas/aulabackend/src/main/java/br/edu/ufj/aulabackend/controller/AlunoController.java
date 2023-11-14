package br.edu.ufj.aulabackend.controller;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.ufj.aulabackend.dao.AlunoDAO;
import br.edu.ufj.aulabackend.model.Aluno;

@RestController
@RequestMapping("/faculdade/alunos")
public class AlunoController {

    @Autowired(required = false)
    private AlunoDAO dao;

    @GetMapping("/listar/{id}")
    public Optional<Aluno> buscarUm(@PathVariable int id) {
        return dao.findById(id);
    }

    @GetMapping("/listar")
    public List<Aluno> buscarTodos() {
        return dao.findAll();
    }

    @PostMapping("/gravar")
    public Aluno gravar(@RequestBody Aluno obj) {
        return dao.save(obj);
    }

    @PostMapping("/gravar/{id}")
    public Aluno alterar(@PathVariable int id, @RequestBody Aluno obj) {
        obj.setCodigo(id);
        return dao.save(obj);
    }

    @DeleteMapping("/excluir/{id}")
    public void excluir(@PathVariable int id) {
        dao.deleteById(id);
    }
}
