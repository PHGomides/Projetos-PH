package questão07;

public class Movimentação {

    private String desc;
    private int valor,info;
    
 
    public Movimentação(String desc, int valor, int info) {
        this.desc = desc;
        this.valor = valor;
        this.info = info;
    }

    public Movimentação() {
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public int getValor() {
        return valor;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }

    public String getInfo() {
        if(info>=1){
        return "Credito";
        }else{
        return "Debito";
        }
    }

    public void setInfo(int info) {
        this.info = info;
    }

    @Override
    public String toString() {
        return "\n###########\nMovimentacao\nDescricao: " + desc + "\nValor: " + valor + "\nInfo: " + getInfo();
    }
    
    
}