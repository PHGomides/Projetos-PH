
package aula08;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Cliente cliente;
        List<Cliente> clientes = new ArrayList<>();
        
        cliente = new Cliente("Fulano de Tal","32420412931","fulano@gmail.com");
        clientes.add(cliente);
        cliente = new Cliente("Beltrano de Tal","21411453224","Beltrano@gmail.com");
        clientes.add(cliente);
        cliente = new Cliente("Outrani de Tal","64362234242","Outrano@gmail.com");
        clientes.add(cliente);
        cliente = new Cliente("Siclano de Tal","1144523523525","Siclano@gmail.com");
        clientes.add(cliente);
        clientes.forEach(System.out::println);
          
    }   
}
