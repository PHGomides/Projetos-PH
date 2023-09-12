#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ITEM{
    char nome[30];
    int cpf;
    struct ITEM *anterior;
    struct ITEM *proximo;
}*tipoLista;

tipoLista lista_meio;

tipoLista criarItem(int cpf, char nome){

    tipoLista novoItem = (tipoLista) malloc(sizeof(tipoLista));

    if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
    }else{
        novoItem->cpf = cpf;
        strcpy(novoItem->nome, nome);
        novoItem->proximo = NULL;
        novoItem->anterior = NULL;
        return novoItem;
    }
}

tipoLista inserirInicio(int cpf, char nome, tipoLista lista){
       
    tipoLista novoItem = criarItem(cpf,nome);
    if (lista == NULL)
    {
        return novoItem;
    }else{
        lista->anterior = novoItem;
        novoItem->proximo = lista;
        return novoItem;
    }
    
}

tipoLista inserirDireita(int cpf, char nome[30], tipoLista lista){
       
    tipoLista novoItem = criarItem(cpf,nome);
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

tipoLista inserirmeio(int cpf, char nome[30], tipoLista lista){
    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){
        if(strcmp(listaAuxiliar->nome,nome) == 0){
            tipoLista novoItem = criarItem(cpf,nome);
                listaAuxiliar->proximo->anterior = novoItem;
                novoItem->proximo = listaAuxiliar->proximo;
                listaAuxiliar->proximo = novoItem;
                novoItem->anterior = listaAuxiliar;
                return lista;
        }
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

tipoLista removermeio(char nome[30], tipoLista lista){

    tipoLista listaAux2 = lista;
    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar != NULL){
        if(strcmp(listaAuxiliar->nome,nome) == 0){
            if(listaAuxiliar->proximo == NULL){
                free(listaAuxiliar);
                listaAuxiliar = NULL;

            }else{
                listaAux2 = listaAuxiliar;
                listaAux2->anterior->proximo = listaAuxiliar->proximo;
                listaAux2->proximo->anterior = listaAuxiliar->anterior;
                free(listaAuxiliar);
            }  
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
    return listaAux2;
}





void exibir(tipoLista lista){

    printf("\n---Lista atual---\n");

    if(lista==NULL){
        printf("\nVazia!\n");
    }else{

    tipoLista listaAuxiliar = lista;

    while(listaAuxiliar != NULL){
        printf("Cpf:[%d], Nome[%s] ",listaAuxiliar->cpf,listaAuxiliar->nome);
        listaAuxiliar = listaAuxiliar->proximo;
    }

    }

}

void pesquisar(char nome[30], tipoLista lista){

    tipoLista listaAuxiliar = lista;
    while(listaAuxiliar != NULL){

        if(strcmp(listaAuxiliar->nome,nome) == 0){
            break;
        }
    listaAuxiliar = listaAuxiliar->proximo;
    }
    exibir(listaAuxiliar);
}

void mostrartodos(tipoLista lista){

    tipoLista listaAuxiliar = lista;
    printf("\nTodos da lista:");
    while(listaAuxiliar != NULL){
        printf("\n");
        exibir(listaAuxiliar);
            
        listaAuxiliar = listaAuxiliar->proximo;
    }
}


int main(){

    int opcao=-1;
    int valor=0;
    char name[30];
    tipoLista lista = NULL;

    while (opcao!=0)
    {
        exibir(lista);
        valor=0;
        
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no meio\n");
        printf("3: Inserir no final\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no meio\n");
        printf("6: Remover no final\n");
        printf("7: Pesquisar\n");
       

        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um cpf\n");
            scanf("%d",&valor);
            printf("Digite um nome\n");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            lista = inserirInicio(valor, name, lista);
            break;

        case 2:
            printf("Digite um cpf\n");
            scanf("%d",&valor);
            printf("Digite um nome\n");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            lista = inserirmeio(valor,name,lista);
            break;

        case 3:
            printf("Digite um cpf\n");
            scanf("%d",&valor);
            printf("Digite um nome\n");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            lista = inserirDireita(valor,name,lista);
            break;

        case 4:
            lista = removerEsquerda(lista);
            break;
        
        case 5:
            printf("Digite um nome\n");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            removermeio(name, lista);
            break;

        case 6:
            lista = removerDireita(lista);
            break;

        case 7:
            printf("Digite um nome\n");
            fflush(stdin);
            gets(name);
            fflush(stdin);
            pesquisar(name, lista);
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    return 0;
}
