#include <stdio.h>

int main() {
    int numero;

    // Entrada de dados
    printf("Digite um numero decimal: ");
    scanf("%d", &numero);

    // Saída dos valores em diferentes bases
    printf("\nRepresentacoes do numero %d:\n", numero);
    printf("Hexadecimal: %X\n", numero); // %X imprime em hexadecimal
    printf("Octal: %o\n", numero);       // %o imprime em octal

    return 0;
}
