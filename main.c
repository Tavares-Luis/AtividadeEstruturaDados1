#include <stdio.h>
#include <stdlib.h>

#include "./funcoes/lista.h"

int main() {
    lista_t listaDeInt;
    inicializar(&listaDeInt);
    
    int opcao;
    int valor;

    do {
        printf("\n--- MENU DE LISTA ORDENADA ---\n");
        printf("1. Inserir Valor (Ordenado)\n"); 
        printf("2. Inserir Valor (Primeiro)\n");
        printf("3. Remover por Valor\n");
        printf("4. Mostrar Lista\n");
        printf("5. SAIR\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1: 

                printf("Digite o valor a ser inserido (Manterá a ordem crescente): ");
                scanf("%d", &valor);

                inserirOrdenado(&listaDeInt, valor);

                printf("Valor %d inserido de forma ordenada.\n", valor);
                break;

            case 2: 

                printf("Digite o valor a ser inserido (No inicio da lista): ");
                scanf("%d", &valor);

                inserirNoInicio(&listaDeInt, valor);

                printf("Valor %d inserido no inicio da lista.\n", valor);

                break;

            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);

                remover(&listaDeInt, valor);

                break;

            case 4:
                mostrarTudo(&listaDeInt);
                break;

            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}