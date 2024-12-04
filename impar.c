#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[15];
    printf("Ingresa un numero: ");
    scanf("%s", input);

    printf("Gramatica:\n");
    printf("C->F Ex Es|F\n");
    printf("F -> Es . EN | Es\n");
    printf("Es -> S EN\n");
    printf("ES -> DR\n");
    printf("R -> DR| E\n"); // La E colocada antes del salto de linea representa el vacio
    printf("S -> + | - | E\n");
    printf("Ex -> E | e\n");
    printf("C -> F\n");
    printf("Es\n");
    printf("SEN\n");
    printf("ES\n");
    printf("DR\n");

    // Mostrar la derivación paso a paso
    printf("Derivacion:\n");
    int i=0;
    int j=0;
    printf("Derivacion:\n");
    for (i = 0; i < strlen(input); i++) {
        printf("-> ");
        for (j = 0; j <= i; j++) {
            printf("%c",input[j]);
        }
        printf("DR\n");
        if (i < strlen(input) - 1) {
            printf("-> ");
            for (j = 0; j <= i; j++) {
                printf("%c", input[j]);
            }
            printf("R\n");
        }
    }
    // Finalización de la derivación
    printf("-> ");
    for ( j = 0; j < strlen(input); j++) {
        printf("%c", input[j]); // Imprimir el número completo
    }
    printf("\n");

    // Validar si el número es positivo o negativo
    float num;
    sscanf(input, "%f", &num);
    if (num >= 0) {
        printf("Cadena valida\n");
    } else {
        printf("%f\n", num);
        printf("Cadena no valida\n");
    }

    return 0;
}
