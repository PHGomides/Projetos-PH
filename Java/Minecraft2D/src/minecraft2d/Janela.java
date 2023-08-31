
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
    private final String avatar2 = "./src/Imagens/Steve2.png";
    private final String madeira = "./src/Imagens/Madeira.png";
    private final String terra = "./src/Imagens/Terra.png";
    private final String ceu = "./src/Imagens/Azul.png";
    private final String pedra = "./src/Imagens/Pedra.png";
    private final String folha = "./src/Imagens/Folha.png";
    private final String branco = "./src/Imagens/Nuvem.png";
    private  Boolean lado;
    
    
    private MyPanel myPanel[];
    
    private int[] tipoblocos;
    
    private ImageIcon av1;
    private ImageIcon av2;
    private ImageIcon fundo;
    private ImageIcon nuvem;
    private ImageIcon bloco1;
    private ImageIcon bloco2;
    private ImageIcon bloco3;
    private ImageIcon bloco4;
    

    private int posAv;
    
    public Janela() {
        
        this.setLayout(new GridLayout(rows,cols));
        
        av1 = new ImageIcon(avatar);
        av2 = new ImageIcon(avatar2);
        fundo = new ImageIcon(ceu);
        nuvem = new ImageIcon(branco);
        bloco1 = new ImageIcon(pedra);
        bloco2 = new ImageIcon(terra);
        bloco3 = new ImageIcon(madeira);
        bloco4 = new ImageIcon(folha);
        
        tipoblocos = new int[size];
        
        myPanel = new MyPanel[size];
        
        for(int i = 0; i<size; i++){
            myPanel[i]= new MyPanel(fundo);
            this.add(myPanel[i]);
        }
        
        
        // terra e pedra
        for(int i = 0; i<size; i++){
            if((i >= 360) && (i <380)){
                myPanel[i].setIcon(bloco2);
                tipoblocos[i] = 2;
            }else if (i >= 380){
                myPanel[i].setIcon(bloco1);
                tipoblocos[i] = 1;
            }
        }
        
        posAv = 350;
        myPanel[350].setIcon(av1);
        
        // Nuvem
        for(int i = 0; i<size; i++){
            if((i>=22 && i<26) || (i>=28 && i <32) || (i>=34 && i <38)){
                myPanel[i].setIcon(nuvem);
                tipoblocos[i] = 5;
            }
            
            if(i >40 && i <59){
                myPanel[i].setIcon(nuvem);
                tipoblocos[i] = 5;
            }
            
            if((i>=22 && i<26) || (i>=28 && i <32) || (i>=34 && i <38)){
                myPanel[i].setIcon(nuvem);
                tipoblocos[i] = 5;
            }
        }
        
        // Madeira e folha
        for(int i = 0; i<size; i++){
            if(i == 356 || i== 336 || i==316  || i== 344 || i == 324 || i == 304){
                myPanel[i].setIcon(bloco3);
                tipoblocos[i] = 3;
            }
            
            if((i== 295 || i== 296 || i== 297) || (i== 275 || i== 276 || i== 277) || (i== 255 || i== 256 || i== 257 || i == 236)                     ||  (i== 283 || i== 284 || i== 285) ||  (i== 263 || i== 264 || i== 265) ||  (i== 243 || i== 244 || i== 245 || i== 224)){
                myPanel[i].setIcon(bloco4);
                tipoblocos[i] = 4;
            }
            
      
        }
        
        
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
            case 5:
                return nuvem;
            default:
                return fundo;
        }
    }
    
    
    

    @Override
    public void keyPressed(KeyEvent key) {
        
        // movimentações
        // movimentações
        if (key.getKeyCode() == KeyEvent.VK_RIGHT) {
            int nextPos = posAv + 1;
            if (nextPos % cols != 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                myPanel[posAv].setIcon(av1);
                lado = true;
            }
        }

        if (key.getKeyCode() == KeyEvent.VK_LEFT) {
            int nextPos = posAv - 1;
            if (nextPos >= 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                myPanel[posAv].setIcon(av2);
                lado = false;
            }
        }

        if (key.getKeyCode() == KeyEvent.VK_DOWN) {
            int nextPos = posAv + cols;
            if (nextPos < size && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                if (lado){
                    myPanel[posAv].setIcon(av1);
                } else {
                    myPanel[posAv].setIcon(av2);
                }
            }
        }

        if (key.getKeyCode() == KeyEvent.VK_UP) {
            int nextPos = posAv - cols;
            if (nextPos >= 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                if (lado){
                    myPanel[posAv].setIcon(av2);
                } else {
                    myPanel[posAv].setIcon(av1);
                }
            }
        }

        
        // construções
        if (key.getKeyCode() == KeyEvent.VK_1) {
            myPanel[posAv].setIcon(bloco1);
            tipoblocos[posAv] = 1;
            key.setKeyCode(KeyEvent.VK_UP);
            keyPressed(key);
        }
        
        if (key.getKeyCode() == KeyEvent.VK_2) {
            myPanel[posAv].setIcon(bloco2);
            tipoblocos[posAv] = 2;
            key.setKeyCode(KeyEvent.VK_UP);
            keyPressed(key);
        }
       
        if (key.getKeyCode() == KeyEvent.VK_3) {
            myPanel[posAv].setIcon(bloco3);
            tipoblocos[posAv] = 3;
            key.setKeyCode(KeyEvent.VK_UP);
            keyPressed(key);
        }
        
        
        if (key.getKeyCode() == KeyEvent.VK_4) {
            myPanel[posAv].setIcon(bloco4);
            tipoblocos[posAv] = 4;
            key.setKeyCode(KeyEvent.VK_UP);
            keyPressed(key);
        }
        
        
        if (key.getKeyCode() == KeyEvent.VK_SPACE) {
            myPanel[posAv].setIcon(fundo);
            tipoblocos[posAv] = 0;
            key.setKeyCode(KeyEvent.VK_RIGHT);
            keyPressed(key);
        }
        
        if (key.getKeyCode() == KeyEvent.VK_A) {
            int leftPos = posAv - 1;
            if (leftPos >= 0 && tipoblocos[leftPos] != 0) {
                myPanel[leftPos].setIcon(getIcon(posAv));
                tipoblocos[leftPos] = tipoblocos[posAv]; 
                myPanel[leftPos].setIcon(getIcon(leftPos));
            }
            int nextPos = posAv - 1;
            if (nextPos >= 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                myPanel[posAv].setIcon(av2);
                lado = false;
            }
            
        }
        
        if (key.getKeyCode() == KeyEvent.VK_D) {
            int rightPos = posAv + 1;
            if (rightPos >= 0 && tipoblocos[rightPos] != 0) {
                myPanel[rightPos].setIcon(getIcon(posAv));
                tipoblocos[rightPos] = tipoblocos[posAv]; 
                myPanel[rightPos].setIcon(getIcon(rightPos));
            }
            int nextPos = posAv + 1;
            if (nextPos % cols != 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                myPanel[posAv].setIcon(av1);
                lado = true;
            }
        }
        
        if (key.getKeyCode() == KeyEvent.VK_W) {
            int upPos = posAv - 20;
            if (upPos >= 0 && tipoblocos[upPos] != 0) {
                myPanel[upPos].setIcon(getIcon(posAv));
                tipoblocos[upPos] = tipoblocos[posAv]; 
                myPanel[upPos].setIcon(getIcon(upPos));
            }
            int nextPos = posAv - cols;
            if (nextPos >= 0 && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                if (lado){
                    myPanel[posAv].setIcon(av2);
                } else {
                    myPanel[posAv].setIcon(av1);
                }
            }
            
            
            
            
            
            
        }
        
        if (key.getKeyCode() == KeyEvent.VK_S) {
            int downPos = posAv + 20;
            if (downPos >= 0 && tipoblocos[downPos] != 0) {
                myPanel[downPos].setIcon(getIcon(posAv));
                tipoblocos[downPos] = tipoblocos[posAv]; 
                myPanel[downPos].setIcon(getIcon(downPos));
            }
             int nextPos = posAv + cols;
            if (nextPos < size && tipoblocos[nextPos] == 0) {
                myPanel[posAv].setIcon(getIcon(posAv));
                posAv = nextPos;
                if (lado){
                    myPanel[posAv].setIcon(av1);
                } else {
                    myPanel[posAv].setIcon(av2);
                }
            }
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
