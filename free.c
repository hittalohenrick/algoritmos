#include <stdio.h>
#include <stdlib.h>

int main(){
    // Definição de variáveis do tipo ponteiro
    int numero = 10;
    int *ponteiroInt = &numero; // Ponteiro para um inteiro

    //Exibindo o valor e o endereço da variável 'numero' usando ponteiros
    printf("Valor de numero: %d\n", numero);
    printf("Endereco de numero: %p\n", ponteiroInt);
    printf("Valor apontado por ponteiroInt: %d\n", *ponteiroInt);

    // Alterando o valor da variável 'numero' através do ponteiro
    *ponteiroInt = 20;
    printf("Novo valor de numero apos modificacao pelo ponteiro: %d\n", numero);

    // Características específicas dos ponteiros
    // Alocação dinâmica de memória com malloc
    int *ponteiroDinamico;
    ponteiroDinamico = (int*) malloc(sizeof(int));

    if (ponteiroDinamico == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1; // Sai do programa se a alocação falhar
    }

    // Inicializando o valor alocado dinamicamente e exibindo
    *ponteiroDinamico = 50;
    printf("Valor armazenado na memoria alocada dinamicamente: %d\n", *ponteiroDinamico);

    // Uso correto dos ponteiros na programação
    // Exemplo de uso sefuro de ponteiro com verificação e liberação de memória
    free(ponteiroDinamico); //Libera a memória alocada
    ponteiroDinamico = NULL; // Evita acessos acidentais, tornando o ponteiro inválido

    // Testando o ponteiro após liberar a memória
    if (ponteiroDinamico == NULL){
        printf("Memoria foi liberada corretamente e o ponteiro esta invalido.\n");
    }
    return 0;
}