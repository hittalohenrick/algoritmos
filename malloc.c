#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ponteiro;
    ponteiro = (int*) malloc(5 * sizeof(int));

    if (ponteiro != NULL) {
        int i;
        for (i = 0; i < 5; i++) {
            ponteiro[i] = i + 1;
        }

        for (i = 0; i < 5; i++) {
            printf("%d ", ponteiro[i]);
        }

        free(ponteiro);
    } else {
        printf("Erro na alocacao de memoria.\n");
    }
    return 0;
}