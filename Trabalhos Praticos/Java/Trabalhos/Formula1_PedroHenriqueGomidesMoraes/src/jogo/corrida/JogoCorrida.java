package jogo.corrida;

import jogo.corrida.Telas.TelaInicio;

public class JogoCorrida {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Iniciar a tela de início
        new TelaInicio();
        new Sons("/Sons/Principal.wav");
    }
}
