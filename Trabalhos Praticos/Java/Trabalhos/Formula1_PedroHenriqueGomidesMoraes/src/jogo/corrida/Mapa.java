package jogo.corrida;

import java.awt.Image;
import java.awt.Toolkit;
import java.awt.Graphics;
import java.net.URL;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Mapa {

    private final int TILE_SIZE = 30;
    private Image[] tiles;
    private int[][] mapa;

    public Mapa(String caminhoMapa) {
        carregarTiles();
        carregarMapa(caminhoMapa);
    }

    private void carregarTiles() {
        tiles = new Image[12]; // Alterado para 11 para incluir todos os novos tiles
        tiles[0] = carregarImagem("/Imagens/Pista_1.png");
        tiles[1] = carregarImagem("/Imagens/Grama.png");
        tiles[3] = carregarImagem("/Imagens/Barreira.png");
        tiles[4] = carregarImagem("/Imagens/zebra1.png");
        tiles[5] = carregarImagem("/Imagens/zebra2.png");
        tiles[6] = carregarImagem("/Imagens/cone.png");
    }

    private Image carregarImagem(String caminho) {
        URL url = this.getClass().getResource(caminho);
        return Toolkit.getDefaultToolkit().getImage(url);
    }

    private void carregarMapa(String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(getClass().getResourceAsStream(caminhoArquivo)))) {
            String linha;
            int linhaAtual = 0;
            mapa = new int[36][64]; // Supondo um mapa de 36x64 tiles
            while ((linha = br.readLine()) != null) {
                String[] numeros = linha.split(" ");
                for (int col = 0; col < numeros.length; col++) {
                    mapa[linhaAtual][col] = Integer.parseInt(numeros[col]);
                }
                linhaAtual++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void desenhar(Graphics g) {
        for (int linha = 0; linha < mapa.length; linha++) {
            for (int coluna = 0; coluna < mapa[linha].length; coluna++) {
                g.drawImage(tiles[mapa[linha][coluna]], coluna * TILE_SIZE, linha * TILE_SIZE, TILE_SIZE, TILE_SIZE, null);
            }
        }
    }

    public boolean podeMover(int x, int y) {
        int coluna = x / TILE_SIZE;
        int linha = y / TILE_SIZE;

        // Verifica se está fora dos limites do mapa
        if (linha < 0 || linha >= mapa.length || coluna < 0 || coluna >= mapa[0].length) {
            return false;
        }

        // Verifica se o tile é transitável
        int tipoTile = mapa[linha][coluna];
        // Permitir movimento em:
        // 0: Pista
        // 4, 5, 6, 7, 8, 9, 10: Pista_Canto (todos os tipos de canto)
        return tipoTile == 0 || tipoTile == 4|| tipoTile == 5;
    }
}
