#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;

tipoLista lista;

tipoLista criarItem(int valor){

    tipoLista novoItem = (tipoLista) malloc(sizeof(tipoLista));

    if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
    }else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirDireita(int valor, tipoLista lista){
       
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else{
    
    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar->proximo != NULL){
        listaAuxiliar = listaAuxiliar->proximo;
    }
    listaAuxiliar->proximo = novoItem;
    
        return lista;
    }   
}

void exibir(tipoLista lista){

    printf("\n---Lista atual---\n");

    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

        tipoLista listaAuxiliar = lista;

        while(listaAuxiliar != NULL){
            printf("[%d] ",listaAuxiliar->item);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}


int main(void){
    tipoLista lista = NULL;
    tipoLista listaAuxiliar, listaAuxiliar2 = lista;
    int aux = 0;

    printf("   Valores da lista encadeada:\n\n");
    for (int i = 0; i < 10; i++){
        aux =  rand() % 100;
        lista = inserirDireita(aux,lista);
        listaAuxiliar = lista;
    }



    if(lista==NULL){
        printf("\nVazia!\n");
    }else{
        exibir(lista);
    }

    listaAuxiliar2 = listaAuxiliar->proximo;
    tipoLista listaresult;

    while(listaAuxiliar != NULL){
        while(listaAuxiliar2 != NULL){
            if(listaAuxiliar->item > listaAuxiliar2->item){
                aux = listaAuxiliar->item;
                listaAuxiliar->item = listaAuxiliar2->item;
                listaAuxiliar2->item = aux;
            }
            listaAuxiliar2 = listaAuxiliar2->proximo;
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }


    exibir(listaAuxiliar);
    

}