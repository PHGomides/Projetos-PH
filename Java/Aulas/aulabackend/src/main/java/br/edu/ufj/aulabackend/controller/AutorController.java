package br.edu.ufj.aulabackend.controller;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.ufj.aulabackend.dao.AutorDAO;
import br.edu.ufj.aulabackend.model.Autor;

@RestController
@RequestMapping("/biblioteca")
public class AutorController {

    @Autowired(required = false)
    private AutorDAO dao;

    @GetMapping("/listar/{id}")
    public Optional<Autor> buscarUm(@PathVariable int id) {
        return dao.findById(id);
    }

    @GetMapping("/listar")
    public List<Autor> buscarTodos() {
        return dao.findAll();
    }

    @PostMapping("/gravar")
    public Autor gravar(@RequestBody Autor obj) {
        return dao.save(obj);
    }
}
