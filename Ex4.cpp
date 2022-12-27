#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct no1 L1;
typedef struct no2 L2;

struct no1 {
    char info;
    struct no1 *prox;
};

struct no2 {
    int info;
    struct no2 *prox;
};

L1 *insereFinalL1(L1 *l1, char letra);
L1 *preencherListaL1(L1 *l2);
L2 *insereOrdenadoL2(L2 *l2, int num);
L2 *preencherListaL2(L2 *l2);
L1 *removerElemento(L1 *l1, int pos);
void mostrarDadosL1(L1 *l1);
void mostrarDadosL2(L2 *l2);
L1 *funcaoRemover(L1 *l1, L2 *l2);

int main() {
    int op, lista;

    L1 *l1 = NULL;
    L2 *l2 = NULL;

    do {
        system("cls");
		
		printf("Lista 1 - Caracteres && Lista 2 - Numerica");
        printf("\n1. Inserir elemento nas listas"
               "\n2. Mostrar listas"
               "\n3. Remover itens da lista 1 com as posicoes da lista 2"
               "\n4. Sair"
               "\nEscolha uma opcao: ");
        scanf("%i", &op);

        system("cls");

        switch (op) {
            case 1:
                printf("Qual lista deseja inserir? \nEscolha: ");
                scanf("%i", &lista);

                switch (lista) {
                    case 1:
                        l1 = preencherListaL1(l1);
                        break;
                    case 2:
                        l2 = preencherListaL2(l2);
                        break;
                    default:
                        printf("Opcao invalida!");
                        getch();
                        break;
                }
                break;
            case 2:
                printf("Lista 1\n");
                mostrarDadosL1(l1);

                printf("\n\nLista 2\n");
                mostrarDadosL2(l2);

                printf("\n\nPressione uma tecla para continuar...");
                getch();
                break;
            case 3:
                l1 = funcaoRemover(l1, l2);
                getch();
                break;
            case 4:
            	printf("Adeus...........\n\n\n");
                break;
            default:
                printf("Opcao invalida!");
                getch();
                break;
        }

    } while (op != 4);

    printf("Programa finalizado!");

    free(l1);
    free(l2);
    getch();
}

L1 *insereFinalL1(L1 *l1, char letra) {

    L1 *aux, *novo;
    novo = (L1 *) malloc(sizeof(L1));
    novo->info = letra;

    if (l1 == NULL) {
        novo->prox = l1;
        l1 = novo;
    } else {
        aux = l1;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l1;
}

L1 *preencherListaL1(L1 *l2) {
    char finalizar, letra;

    do {
        printf("Insira a letra que deseja inserir \nLetra: ");
        fflush(stdin);
        scanf(" %c", &letra);

        l2 = insereFinalL1(l2, letra);

        printf("\nDeseja adicionar mais (s/n)?\nEscolha: ");
        scanf(" %c", &finalizar);
    } while (finalizar == 's' || finalizar == 'S');

    return l2;
}

L2 *insereOrdenadoL2(L2 *l2, int num) {
    L2 *aux, *novo;

    novo = (L2 *) malloc(sizeof(L2));
    novo->info = num;

    if ((l2 == NULL) || (num <= l2->info)) {
        novo->prox = l2;
        l2 = novo;
    } else {
        aux = l2;

        while ((aux->prox != NULL) && (aux->prox)->info <= num) {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    return l2;
}

L2 *preencherListaL2(L2 *l2) {
    char finalizar;
    int num;

    do {
        printf("Digite o numero que deseja inserir \nNumero: ");
        scanf("%i", &num);

        l2 = insereOrdenadoL2(l2, num);

        printf("\nDeseja adicionar outro (s/n)?\nEscolha: ");
        scanf(" %c", &finalizar);
    } while (finalizar == 's' || finalizar == 'S');

    return l2;
}

L1 *removerElemento(L1 *l1, int pos) {
    L1 *aux, *ant;
    int i = 0;

    aux = l1;
    ant = NULL;

    do {
        if (pos != 0) {
            ant = aux;
            aux = aux->prox;
            i++;
        }
    } while ((aux != NULL) && (i != pos));

    if (aux == NULL) {
        return l1;
    }

    if (ant == NULL) { //remover do inicio
        l1 = aux->prox;
    } else { //remover do meio
        ant->prox = aux->prox;
    }

    return l1;
}

void mostrarDadosL1(L1 *l1) {

    L1 *aux;
    aux = l1;

    while (aux != NULL) {
        printf("%c -> ", aux->info);
        aux = aux->prox;
    }

    printf("NULL");
}

void mostrarDadosL2(L2 *l2) {
    L2 *aux;

    aux = l2;

    while (aux != NULL) {
        printf("%i -> ", aux->info);
        aux = aux->prox;
    }

    printf("NULL");
}

L1 *funcaoRemover(L1 *l1, L2 *l2) {

    L2 *aux;
    aux = l2;

    if (l1 == NULL) {
        printf("Lista 1 vazia!");
    } else if (l2 == NULL) {
        printf("Lista 2 vazia!");
    } else {
        while (aux != NULL) { // Percorre os elementos da Lista Char
            l1 = removerElemento(l1, aux->info);
            aux = aux->prox;
        }

        printf(" Os elementos foram removidos"
               "\n\nPressione uma tecla para continuar...");
    }

    return l1;
}
