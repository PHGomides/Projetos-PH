#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
    int item;
    struct ITEM *anterior;
    struct ITEM *proximo;
}*tipoLista;

int contador =0;
tipoLista lista_ult = NULL;


tipoLista criarItem(int valor){

    tipoLista novoItem = (tipoLista) malloc(sizeof(tipoLista));

    if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
    }else{
        novoItem->item = valor;
        novoItem->proximo = NULL;
        novoItem->anterior = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista){
       
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }else{
        
        lista->anterior = novoItem;
        novoItem->proximo = lista;

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
    novoItem->anterior = listaAuxiliar;    
        return lista;
    }

    
}

tipoLista removerEsquerda(tipoLista lista){
    
    tipoLista listaAuxiliar = lista;

    if(listaAuxiliar==NULL){
        printf("\nVazia!\n");
    }else{

    if(listaAuxiliar->proximo == NULL){ //apenas um elemento
        free(listaAuxiliar);
        listaAuxiliar = NULL;

    }else{
        listaAuxiliar = lista->proximo;
        listaAuxiliar->anterior = NULL;

    free(lista);
    lista = NULL;
        
    }

    }
    return listaAuxiliar;
}

tipoLista removerDireita(tipoLista lista){
    
    tipoLista listaAuxiliar = lista;

    if(listaAuxiliar==NULL){
        printf("\nVazia!\n");
    }else{

    if(listaAuxiliar->proximo == NULL){ //apenas um elemento
        free(listaAuxiliar);
        listaAuxiliar = NULL;
    }else{

    while(listaAuxiliar->proximo != NULL){
        listaAuxiliar = listaAuxiliar->proximo;
    }

    tipoLista itemDescartar;
    itemDescartar = listaAuxiliar;

    listaAuxiliar->anterior->proximo = NULL;
    itemDescartar->anterior = NULL;

    free(itemDescartar);
	itemDescartar = NULL;

    return lista;

    }
    
    }

    return listaAuxiliar;
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
                listaAuxiliar->proximo->anterior = novoItem;
                novoItem->proximo = listaAuxiliar->proximo;
                listaAuxiliar->proximo = novoItem;
                novoItem->anterior = listaAuxiliar;
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
                listaAux2 = listaAuxiliar;
                listaAux2->anterior->proximo = listaAuxiliar->proximo;
                listaAux2->proximo->anterior = listaAuxiliar->anterior;
                free(listaAuxiliar);
            }  
        }
        listaAuxiliar = listaAuxiliar->proximo;
    }
    return listaAux2;
}

void MoverMenor(tipoLista Lista){
    tipoLista listaAuxiliar = Lista;
    int menor = -100000000;
    while(listaAuxiliar != NULL){
        if(listaAuxiliar->item < menor){
            menor = listaAuxiliar->item;
        }
    }
    lista_ult = removermeio(menor,lista_ult);
    lista_ult = inserirEsquerda(menor,lista_ult);
}


int main(){

    int opcao=-1;
    int valor=0;
    int pesq = 0;

    while (opcao!=0)
    {
        exibir(lista_ult);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Remover no inicio\n");
        printf("4: Remover no final\n");
        printf("5: Pesquisar\n");
        printf("6: Inserir no meio\n");
        printf("7: Remover no meio\n");
        printf("8: Usar funcao moverMenor\n -->");



        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista_ult = inserirEsquerda(valor,lista_ult);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            lista_ult = inserirDireita(valor,lista_ult);
            break;

        case 3:
            lista_ult = removerEsquerda(lista_ult);
            break;

        case 4:
            lista_ult = removerDireita(lista_ult);
            break;

        case 5:
            printf("Digite um valor\n");
            scanf("%d",&valor);
            pesquisar(valor, lista_ult);
            
            break;
        
         case 6:
             printf("Digite um valor\n");
            scanf("%d",&valor);
            printf("Digite um valor que deseja ao lado\n");
            scanf("%d",&pesq);
            lista_ult = inserirmeio(valor,lista_ult,pesq);
            break;

        case 7:
            printf("Digite um valor para remover\n");
            scanf("%d",&valor);
            lista_ult = removermeio(valor,lista_ult);
            break;

        case 8:
            MoverMenor(lista_ult);
            
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}