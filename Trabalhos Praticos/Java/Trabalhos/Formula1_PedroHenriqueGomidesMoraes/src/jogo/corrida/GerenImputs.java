package jogo.corrida;

import jogo.corrida.Carro.Carro;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class GerenImputs implements KeyListener {

    private Carro carro1, carro2;

    public GerenImputs(Carro carro1, Carro carro2) {
        this.carro1 = carro1;
        this.carro2 = carro2;
    }

    @Override
    public void keyPressed(KeyEvent e) {
        carro1.processarTeclaPressionada(e.getKeyCode());
        carro2.processarTeclaPressionada(e.getKeyCode());
    }

    @Override
    public void keyReleased(KeyEvent e) {
        carro1.processarTeclaSolta(e.getKeyCode());
        carro2.processarTeclaSolta(e.getKeyCode());
    }

    @Override
    public void keyTyped(KeyEvent e) {}
}
