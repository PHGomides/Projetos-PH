
package minecraft2d;

import java.awt.GridLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.ImageIcon;
import javax.swing.JFrame;


public class Janela extends JFrame implements KeyListener{
    
    private final int size = 400;
    private final int cols = 20;
    private final int rows = 20;
    
    private final String avatar = "./src/Imagens/Steve.png";
    private final String madeira = "./src/Imagens/Madeira.png";
    private final String terra = "./src/Imagens/Terra.png";
    private final String ceu = "./src/Imagens/Ceu.png";
    private final String flor = "./src/Imagens/Flor.png";
    private final String folha = "./src/Imagens/Folha.png";
    
    
    private MyPanel myPanel[];
    
    private int[] tipoblocos;
    
    private ImageIcon av;
    private ImageIcon fundo;
    private ImageIcon bloco1;
    private ImageIcon bloco2;
    private ImageIcon bloco3;
    private ImageIcon bloco4;
    
    private int posAv;
    
    public Janela() {
        
        this.setLayout(new GridLayout(rows,cols));
        
        av = new ImageIcon(avatar);
        fundo = new ImageIcon(ceu);
        bloco1 = new ImageIcon(flor);
        bloco2 = new ImageIcon(terra);
        bloco3 = new ImageIcon(madeira);
        bloco4 = new ImageIcon(folha);
        
        tipoblocos = new int[size];
        
        myPanel = new MyPanel[size];
        
        for(int i = 0; i<size; i++){
            myPanel[i]= new MyPanel(fundo);
            this.add(myPanel[i]);
        }
        
        posAv = 0;
        myPanel[0].setIcon(av);
        
        
        this.addKeyListener(this);
        
        this.setTitle("Minecraft 2D");
        this.setExtendedState(6);
        this.setVisible(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        
        
        
    }
    
    private ImageIcon getIcon(int tipo){
        switch(tipoblocos[tipo]){
            case 1:
                return bloco1;
            case 2:
                return bloco2;
            case 3:
                return bloco3;
            case 4:
                return bloco4;
            default:
                return fundo;
        }
    }
    
    
    

    @Override
    public void keyPressed(KeyEvent key) {
        
        // movimentações
        if (key.getKeyCode() == KeyEvent.VK_RIGHT) {
            myPanel[posAv].setIcon(getIcon(posAv));
            posAv++;
            if (posAv > size-1) posAv = 0;
            myPanel[posAv].setIcon(av);
        }
        
        if (key.getKeyCode() == KeyEvent.VK_LEFT) {
            myPanel[posAv].setIcon(getIcon(posAv));
            posAv--;
            if (posAv < 0) posAv = size-1;
            myPanel[posAv].setIcon(av);
        }
         
         if (key.getKeyCode() == KeyEvent.VK_DOWN) {
            myPanel[posAv].setIcon(getIcon(posAv));
            posAv+=20;
            if (posAv > 399) posAv = posAv - 399;
            myPanel[posAv].setIcon(av);
        }
        
         if (key.getKeyCode() == KeyEvent.VK_UP) {
            myPanel[posAv].setIcon(getIcon(posAv));
            posAv-=20;
            if (posAv < 0) posAv = 399 - (Math.abs(posAv));
            myPanel[posAv].setIcon(av);
        }
        
        // construções
        if (key.getKeyCode() == KeyEvent.VK_1) {
            myPanel[posAv].setIcon(fundo);
            tipoblocos[posAv] = 1;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
        
        if (key.getKeyCode() == KeyEvent.VK_2) {
            myPanel[posAv].setIcon(bloco1);
            tipoblocos[posAv] = 2;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
       
        if (key.getKeyCode() == KeyEvent.VK_3) {
            myPanel[posAv].setIcon(bloco2);
            tipoblocos[posAv] = 3;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
        
        
        if (key.getKeyCode() == KeyEvent.VK_4) {
            myPanel[posAv].setIcon(bloco3);
            tipoblocos[posAv] = 4;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
        
        if (key.getKeyCode() == KeyEvent.VK_SPACE) {
            myPanel[posAv].setIcon(bloco4);
            tipoblocos[posAv] = 0;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
    }  

    @Override
    public void keyTyped(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void keyReleased(KeyEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
