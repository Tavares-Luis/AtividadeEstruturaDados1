#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int valor;
    struct nodo *prox;


}nodo_t;

typedef struct{

    nodo_t *inicio;

}lista_t;

void inicializar(lista_t *lista);

void inserirNoInicio(lista_t *lista, int valor);

void remover(lista_t *lista, int valor);

int estaVazio(lista_t *lista);

void mostrarTudo(lista_t *lista);

void inserirOrdenado(lista_t *lista, int valor);

void liberarLista(lista_t *lista);

#endif