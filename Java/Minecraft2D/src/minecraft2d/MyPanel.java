
package minecraft2d;

import java.awt.Graphics;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class MyPanel extends JPanel {
    
    //atributos
    private ImageIcon icon;
    
    public MyPanel() {
        icon = new ImageIcon("./src/Imagens/Steve.png");
        
    }
    
    public MyPanel(ImageIcon icon) {
        this.icon = icon;
        
    }

    public void setIcon(ImageIcon icon) {
        this.icon = icon;
        repaint();
    }
    
    @Override
    public void paint(Graphics g) {
        g.drawImage(icon.getImage(),0,0,this.getWidth(),this.getHeight(),null);
    }
    
}