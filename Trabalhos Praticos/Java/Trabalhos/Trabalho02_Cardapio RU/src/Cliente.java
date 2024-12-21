public class Cliente {
    public static String[] vetdia, vetproteina, vetvegano, vetsalada, vetfruta, vetsuco;
    public static int dia_semana = 0;

    // Sets e Gets
    public static int getDia_semana() {
        return dia_semana;
    }

    public static void setDia_semana(int dia_semana) {
        Cliente.dia_semana = dia_semana;
    }
    public static String getVetdia() {
        return vetdia[dia_semana];
    }

    public static String getVetproteina() {
        return vetproteina[dia_semana];
    }

    public static String getVetvegano() {
        return vetvegano[dia_semana];
    }

    public static String getVetsalada() {
        return vetsalada[dia_semana];
    }

    public static String getVetfruta() {
        return vetfruta[dia_semana];
    }

    public static String getVetsuco() {
        return vetsuco[dia_semana];
    }

    Cliente(){
        //Configurando vetores
        vetdia = new String[5];
        vetdia[0] = new String("Segunda-Feira");

        vetdia[1] = new String("Terça-Feira");

        vetdia[2] = new String("Quarta-Feira");

        vetdia[3] = new String("Quinta-Feira");

        vetdia[4] = new String("Sexta-Feira");

        vetproteina = new String[5];
        vetvegano = new String[5];
        vetsalada = new String[5];
        vetsuco = new String[5];
        vetfruta = new String[5];

        // Cadastrando cardapio inicial, ( Programa não salva informações em bancos de dados ou arquivo)
        vetproteina[0] = new String("Frango Assado"); vetproteina[1] = new String("Feijoada"); vetproteina[2] = new String("Carne Assada"); vetproteina[3] = new String("Carne de porco"); vetproteina[4] = new String("Escondidinho de frango");
        vetvegano[0] = new String("Ovo frito"); vetvegano[1] = new String("Carne de soja"); vetvegano[2] = new String("Panqueca"); vetvegano[3] = new String("Ovo cozido"); vetvegano[4] = new String("Ovo");
        vetsalada[0] = new String("Alface e tomate"); vetsalada[1] = new String("Alface e beterraba"); vetsalada[2] = new String("Alface e cenoura"); vetsalada[3] = new String("Alface e repolho"); vetsalada[4] = new String("Alface e pepino");
        vetfruta[0] = new String("Banana"); vetfruta[1] = new String("Maça"); vetfruta[2] = new String("Laranja"); vetfruta[3] = new String("Melão"); vetfruta[4] = new String("Melancia");
        vetsuco[0] = new String("Uva"); vetsuco[1] = new String("Laranja"); vetsuco[2] = new String("Manga"); vetsuco[3] = new String("Limão"); vetsuco[4] = new String("Tangerina");
    }


}
