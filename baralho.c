#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_CARTAS 52
#define CARTAS_INICIAIS 5

struct Carta {
    char valor[3];
    char naipe[10];
};

struct Carta baralho[TOTAL_CARTAS];
struct Carta jogador1[52], jogador2[52];
int topoBaralho = 0, topoJ1 = 0, topoJ2 = 0;

char *valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
char *naipes[] = {"Copas", "Ouros", "Paus", "Espadas"};

void criarBaralho() {
    topoBaralho = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(baralho[topoBaralho].valor, valores[j]);
            strcpy(baralho[topoBaralho].naipe, naipes[i]);
            topoBaralho++;
        }
    }
}

void embaralhar() {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        int r = rand() % TOTAL_CARTAS;
        struct Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}

void distribuirCartas() {
    topoJ1 = topoJ2 = 0;
    for (int i = 0; i < CARTAS_INICIAIS; i++) {
        jogador1[topoJ1++] = baralho[--topoBaralho];
        jogador2[topoJ2++] = baralho[--topoBaralho];
    }
}

void mostrarCartas(struct Carta jogador[], int topo, char nome[]) {
    printf("== %s ==\n", nome);
    for (int i = 0; i < topo; i++) {
        printf("[%d] %s de %s\n", i, jogador[i].valor, jogador[i].naipe);
    }
    printf("\n");
}

void mostrarBaralho() {
    printf("== Baralho (%d cartas) ==\n", topoBaralho);
    for (int i = 0; i < topoBaralho; i++) {
        printf("%s de %s\n", baralho[i].valor, baralho[i].naipe);
    }
    printf("\n");
}

void moverCarta(struct Carta origem[], int *topoOrigem, struct Carta destino[], int *topoDestino, int indice) {
    if (indice < 0 || indice >= *topoOrigem) {
        printf("Índice inválido!\n");
        return;
    }

    destino[*topoDestino] = origem[indice];
    (*topoDestino)++;

    for (int i = indice; i < *topoOrigem - 1; i++) {
        origem[i] = origem[i + 1];
    }
    (*topoOrigem)--;
}

int main() {
    int opcao, indice;

    criarBaralho();
    embaralhar();
    distribuirCartas();

    while (1) {
        printf("====== MENU ======\n");
        printf("1 - Ver cartas dos jogadores\n");
        printf("2 - Ver baralho restante\n");
        printf("3 - Mover carta do J1 para J2\n");
        printf("4 - Mover carta do J2 para J1\n");
        printf("5 - Reiniciar jogo\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarCartas(jogador1, topoJ1, "Jogador 1");
                mostrarCartas(jogador2, topoJ2, "Jogador 2");
                break;
            case 2:
                mostrarBaralho();
                break;
            case 3:
                mostrarCartas(jogador1, topoJ1, "Jogador 1");
                printf("Qual carta mover? ");
                scanf("%d", &indice);
                moverCarta(jogador1, &topoJ1, jogador2, &topoJ2, indice);
                break;
            case 4:
                mostrarCartas(jogador2, topoJ2, "Jogador 2");
                printf("Qual carta mover? ");
                scanf("%d", &indice);
                moverCarta(jogador2, &topoJ2, jogador1, &topoJ1, indice);
                break;
            case 5:
                criarBaralho();
                embaralhar();
                distribuirCartas();
                printf("Jogo reiniciado!\n");
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    }

    return 0;
}
