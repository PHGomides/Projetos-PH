#include <stdlib.h>
#include <stdio.h>

typedef struct ITEM{
    int item;
    struct ITEM *proximo;
}*tipoLista;

int vetor[30], contadorvet = 0;



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

    printf("\n---Listas Estatica---\n");
    if(contadorvet == 0){
        printf("\nVazia estatica!\n");
    }else{
        for (int i = 0; i < contadorvet; i++)
        {
            printf(" [%d] ",vetor[i]);
        }
        
    }
    printf("\n---Listas Dinamica---\n");
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

int main(){

    int opcao=-1;
    int valor=0;
    tipoLista lista = NULL;
    int escolha = 0;

    while (opcao!=0)
    {
        exibir(lista);
        valor=0;
       
        printf("\nDIGITE 0 PARA SAIR  -\n");
        printf("1: Inserir na frente  -\n");
        printf("2: Inserir na retarguarda -\n");
        printf("3: Remover na frente  -\n");
        printf("4: Remover na retarguarda  -\n");
        printf("5: Pesquisar \n  -->");

        scanf("%d",&opcao);

        // Aqui podera escolher qual tipo de lista podera usar
        printf("|||Deseja usar lista estatica - (0)   ou     dinamica - (Qualquer outro numero)||| \n   -->");
        scanf("%d",&escolha);

        if(escolha == 0){
            switch(opcao)
            {
            case 1:

                printf("Digite um valor\n");
                scanf("%d",&valor);
                if(contadorvet == 0){
                    vetor[0] = valor;
                    contadorvet ++;
                }else{
                    for (int i = contadorvet - 1; i >= 0; i--){
                        vetor[i+1] = vetor[i]; 
                    }
                    vetor[0]= valor;
                    contadorvet ++;
                }
                
                break;

            case 2:
                printf("Digite um valor\n");
                scanf("%d",&valor);
                 if(contadorvet == 0){
                    vetor[0] = valor;
                    contadorvet ++;
                }else{  
                    vetor[contadorvet] = valor;
                    contadorvet ++;
                }

                
                break;

            case 3:
                if(contadorvet == 0){
                    vetor[0] = 0;
                }else{
                    for (int i = 0; i < contadorvet; i++){
                        vetor[i] = vetor[i+1]; 
                    }
                    contadorvet --;
                }
                break;

            case 4:
                if(contadorvet == 0){
                    vetor[0] = 0;
                }else{
                    vetor[contadorvet-1] = 0;
                    contadorvet --;
                }
                break;

            case 5:
                printf("Digite um valor do local\n");
                scanf("%d",&valor);
                printf("Valor nesse local : %d",vetor[valor]);
                
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }

        }else{

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

            default:
                printf("Opcao invalida!\n");
                break;
            }
        }
    }
    return 0;
}