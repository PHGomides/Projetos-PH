#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;





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

tipoLista colocarFrente(int valor, tipoLista lista){
       
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else{
    
        novoItem->proximo = lista;
    
        return novoItem;
    }
    
}

tipoLista colocarRetaguarda(int valor, tipoLista lista){
       
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

tipoLista retirarFrente(tipoLista lista){
    
    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    tipoLista listaAuxiliar;
    listaAuxiliar = lista;
    lista = lista->proximo;

    free(listaAuxiliar);
	listaAuxiliar = NULL;
    }
    return lista;
}

tipoLista retirarRetaguarda(tipoLista lista){
    
    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    if(lista->proximo == NULL){ //apenas um elemento
        free(lista);
        lista = NULL;
    }else{
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;

    while(listaAuxiliar->proximo->proximo != NULL){ //encontra o penultimo elemento
        listaAuxiliar = listaAuxiliar->proximo;
    }

    tipoLista itemDescartar;
    itemDescartar = listaAuxiliar->proximo;

    free(itemDescartar);
	itemDescartar = NULL;

    listaAuxiliar->proximo = NULL;

    }
    
    }

    return lista;
}

void exibir(tipoLista lista){

    printf("\n---Listas---\n");
    if(lista==NULL){
        printf("\nVazia dinamica!\n");
    }else{

    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){
        printf("[%d] ",listaAuxiliar->item);
        listaAuxiliar = listaAuxiliar->proximo;
    }

    }

}


void pesquisar(int valor, tipoLista lista){

    int contador=0;
    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){

        if( listaAuxiliar->item == valor ){
            contador++;
        }
    listaAuxiliar = listaAuxiliar->proximo;
    }
        printf("\nHouve %d ocorrencia(s) do valor %d\n",contador,valor);
}


tipoLista inserirmeio(int item , tipoLista lista, int valor){
    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){
        if(listaAuxiliar->item == item){
                tipoLista novoItem = criarItem(valor);
                novoItem->proximo = listaAuxiliar->proximo;
                listaAuxiliar->proximo = novoItem;
                return lista;
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }
    return lista;   
}

tipoLista removermeio(int item, tipoLista lista){

    tipoLista listaAux2 = lista;
    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar != NULL){
        if(listaAuxiliar->item == item){
            if(listaAuxiliar->proximo == NULL){
                free(listaAuxiliar);
                listaAuxiliar = NULL;
            }else{
                 while(listaAux2 != listaAuxiliar){
                    listaAux2 = listaAux2->proximo;
                 }
                    listaAux2->proximo = listaAuxiliar->proximo;
                    free(listaAuxiliar);
                    return  listaAux2;


            }  
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }
    return listaAux2;
}


int main(){

    int opcao=-1;
    int valor=0;
    int pesq =0;
    tipoLista lista = NULL;

    while (opcao!=0)
    {
        exibir(lista);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR  -\n");
        printf("1: Inserir no inicio  -\n");
        printf("2: Inserir na fim -\n");
        printf("3: Remover no inicio  -\n");
        printf("4: Remover no fim  -\n");
        printf("5: Pesquisar \n");
        printf("6: Inserir na meio -\n");
        printf("7: Remover no meio  -\n  -->");

        scanf("%d",&opcao);

            switch(opcao)
            {
            case 1:
                printf("Digite um valor\n");
                scanf("%d",&valor);
                lista = colocarFrente(valor,lista);
                break;

            case 2:
                printf("Digite um valor\n");
                scanf("%d",&valor);
                lista = colocarRetaguarda(valor,lista);
                break;

            case 3:
                lista = retirarFrente(lista);
                break;

            case 4:
                lista = retirarRetaguarda(lista);
                break;

            case 5:
                printf("Digite um valor\n");
                scanf("%d",&valor);
                pesquisar(valor, lista);
                
                break;
            
            case 6:
                printf("Digite um valor\n");
                scanf("%d",&valor);
                printf("Digite um valor que deseja ao lado\n");
                scanf("%d",&pesq);
                lista = inserirmeio(valor,lista,pesq);
                break;
            case 7:
                printf("Digite um valor para remover\n");
                scanf("%d",&valor);
                lista = removermeio(valor,lista);
                break;
                
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    
return 0;
}