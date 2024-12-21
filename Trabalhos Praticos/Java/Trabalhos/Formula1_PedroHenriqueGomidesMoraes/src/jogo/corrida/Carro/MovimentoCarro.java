package jogo.corrida.Carro;

import jogo.corrida.Carro.Carro;
import jogo.corrida.Fases.Corrida;

public class MovimentoCarro extends Thread {

    private final Carro carro;
    private final Corrida corrida;

    public MovimentoCarro(Carro carro, Corrida corrida) {
        this.carro = carro;
        this.corrida = corrida;
    }

    @Override
    public void run() {
        while (true) {
            carro.mover();
            corrida.repaint(); // Atualizar a tela
            try {
                Thread.sleep(50); // Intervalo entre movimentos
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            carro.aumentarVelocidade();
        }
    }
}