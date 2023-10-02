import model.Cliente;
import view.Janela;

public class Main {
    public static void main(String[] args) {
        Cliente cliente= new Cliente();
        Janela janela = new Janela();
    }
}

/*Comentario do trabalho
O Builder é um padrão de projeto criacional que permite a você construir objetos complexos passo a passo. O padrão Builder permite que você construa,
usando apenas aquelas etapas que você realmente precisa. Você cria uma classe separada para construir o objeto,
essa classe tem um método para cada atributo do objeto que você deseja construir. Para construir o objeto, você chama os métodos da
classe Builder na ordem desejada. Logo, dentro da Classe Cliente eu criei uma classe interna chamada de ClienteBuilder,
que é responsavel por atribuir valores ao contrutor Cliente(int dia, String proteina, String vegano, String salada, String fruta, String suco),
essa atribuição é utilizando seus metodos. Portanto  utilizei o padrão de projeto Builder na funcinalidade de salvar as informações do cardapio,
pois ele possibilita que eu trabalha-lhe com um grande constrututor de forma simples e dinamica. Com isso, consegue torna a funcionalidade
de salvar mais dinamica e facil de alterações futuras caso precise.

Resumindo o porque de usar o padrão Builder foi por tornar a construção de objetos complexos mais simples e intuitiva e por tornar os objetos mais testaveis e facil de alterações.
 */