#include <stdio.h>
#include <string.h>

int main(){
    int num;
    int j=0;
    int i=0; 
    printf("Ingresa un numero: ");
    scanf("%d", &num);

    printf("Gramatica:\n");
    printf("Es -> S EN\n");
    printf("EN -> D R\n");
    printf("R -> D R | E\n");//E representa vacio
    printf("D -> 0...9\n");
    printf("S -> + | - | E\n");
    printf("Derivacion:\n");

    // Convertir el número a cadena para procesarlo carácter por carácter
    char numStr[6];
    sprintf(numStr, "%d", num);
   // int i=0; // Índice para recorrer la cadena
    if(numStr[i] == '+' || numStr[i] == '-'){
        printf("Es -> S EN\n");
        printf("-> %c EN\n", numStr[i]);
        i++; // Avanzar al siguiente carácter
    }else{
        printf("Es -> S EN\n");
        printf("-> E EN\n");
    }
    printf("-> DR\n");
    // Procesar cada dígito y mostrar la derivación
    printf("-> %cR\n", numStr[i]);
    i++;
    while (i < strlen(numStr)){
        printf("-> ");
        for (j = 0; j < i; j++){
            printf("%c", numStr[j]); // Imprimir los dígitos procesados
        }
        printf("DR\n");
        // Añadir el siguiente dígito
        printf("-> ");
        for (j = 0; j <= i; j++){
            printf("%c", numStr[j]); // Imprimir los dígitos procesados con el nuevo
        }
        printf("R\n");
        i++;
    }
    printf("-> ");
    for (j = 0; j < i; j++){
        printf("%c", numStr[j]); // Imprimir todos los dígitos procesados
    }
    printf("R\n");

    // Finalización de la derivación
    printf("-> ");
    for (j = 0; j < i; j++){
        printf("%c", numStr[j]); // Imprimir el número completo
    }
    printf("\n");
    printf("Cadena valida\n");
    return 0;
}
