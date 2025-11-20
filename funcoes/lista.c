#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


//função para inicializar a lista - vazio 
void inicializar(lista_t *lista) {

    lista->inicio = NULL;

};

//função para inserir um valor no inicio da lista e apontar o novo inicio.
void inserirNoInicio(lista_t *lista, int valor) {

    nodo_t *novo = (nodo_t *) malloc(sizeof(nodo_t)); //alocação dinamica

    novo->valor = valor;  //colocando o valor naquele "slot"
    novo->prox = lista->inicio;   //criando a "corrente" entre o elemento anterior e o novo
    lista->inicio = novo;  //mudando o localizador do inicio para referenciar ao novo "slot"

}


//Comentário Luis: Tive certa dificuldade em entender como funciona essa pois além de tratar com várias
// hipoteses ele tem que fazer a alocação do prox / inicio de acordo com ela. 


//função para remover um elemento , contando com multiplas possibilidades de localização do elemento.
void remover(lista_t *lista, int valor) {

    if (lista->inicio == NULL) {
        printf("Lista vazia. Nada a remover.\n");

        return;
    }

    nodo_t *atual = lista->inicio;
    nodo_t *anterior = NULL;  // "âncora" para religar a lista


    // Procurar o valor na lista
    while (atual != NULL && atual->valor != valor) {  // atual for diferente de nulo e valor atual for diferente do valor buscado continua

        anterior = atual;  //ancora o atual
        atual = atual->prox; //segue para o proximo

    }

    //aqui se for null é porque não achou no laço anterior
    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
    }

    // Caso 1: elemento está no início
    if (anterior == NULL) {
        lista->inicio = atual->prox;   // pega o inicio da lista e fala q é = o elemento do incio.
    }
    // Caso 2: elemento está no meio/fim
    else {
        anterior->prox = atual->prox;   // aqui vai meio que "tirar" um ligação para fazer a realocação para outra pois o elemento vai ser tirado.
    }


    printf("Removendo %d da lista.\n", atual->valor);

    free(atual);  // remove atual que foi alocado com malloc.
}


//Comentário Luis: fiz essa parte pensando e fazendo na mão e fui conferir com o gemini com isso achei uma sugestão interessante do uso do 
//"return (lista->inicio == NULL); " de uma vez pois ele já ia retornar "0" ou "1", como feito a baixo , mas economizado código.

int estaVazio(lista_t *lista){

    if(lista->inicio == NULL){
        return 1;
    }else{
        return 0;
    }

}

void mostrarTudo(lista_t *lista){

    nodo_t *atual = lista->inicio; 

    printf("Lista: \n");

    while(atual != NULL){

        printf("%d -> ", atual->valor);


        atual=atual->prox;

    }

    printf("\nFim da lista.\n");

}

void inserirOrdenado(lista_t *lista, int valor){

    
    nodo_t *novo = (nodo_t *) malloc(sizeof(nodo_t));

    novo->valor = valor; 



    nodo_t *atual = lista->inicio;
    nodo_t *anterior = NULL;

    while(atual != NULL && valor > atual->valor){

        anterior = atual;
        atual = atual->prox;

    }

    //no inicio da lista.
    if(anterior == NULL){

        novo->prox = lista->inicio;
        lista->inicio = novo;

    }else{ //meio e fim

        novo->prox=atual;
        anterior->prox=novo;

        // Comentário Luis: nessa parte usei IA para correção, pois tinha feito com a ordem invertida da linha 132 e 133, 
        // e tinha dado problema. 
        // A IA me apontou que seria melhor pois a funções de cada um é:

        // novo->prox = atual:  Preserva a "cauda". O novo nó (novo) passa a 
        // apontar para o nó que viria logo depois dele (atual), mantendo o acesso a todos os nós subsequentes.

        // anterior->prox = novo:  Insere o nó. O nó anterior (anterior) agora aponta para o novo nó (novo), fechando a corrente.

        // Deixado invertido como estava ia dar (Gerado por IA):

        //anterior->prox = novo; (Linha 1 Invertida)

        // O nó anterior agora aponta para novo.

       //  PROBLEMA: A referência para o nó atual (e toda a lista a partir dele) é perdida, pois anterior 
       // era o único que apontava para atual. Você não consegue mais acessar o resto da sua lista!

       // Se você tentar novo->prox = atual; em seguida, o ponteiro atual ainda está lá, mas a 
       // lista principal não tem como alcançá-lo. Você cria um vazamento de memória (memory leak) e a lista fica corrompida.
    }

}
