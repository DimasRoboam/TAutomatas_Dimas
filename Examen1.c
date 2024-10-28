#include <stdio.h>
#include <string.h>
#define MAX 100

void potencia(char L[][MAX], int n) {
    printf("(");
    printf("ε");
    int i, j, k;
    for (i = 0; i < n; i++) {
        printf(",%s", L[i]);
        for (j = i + 1; j < n; j++) {
            printf(",%s%s", L[i], L[j]);
            for (k = j + 1; k < n; k++) {
                printf(",%s%s%s", L[i], L[j], L[k]);
            }
        }
    }
    printf(")");
}

int main() {
    int opcion;
    char L1[100]; // potencia
    char L2[100];
    char L3[100];
    char L4[100]; // union
    char L5[100];
    char L6[100];
    int n = strlen(L1);
    char L[3][MAX]; // concatenacion
    char lenguaje[50];
    char complemento[100];
    char *token;
    char conjunto_universal[100];//complemento

    do {
        printf("Selecciona una opcion del menu:\n");
        printf("1. Potencia\n");
        printf("2. Concatenacion\n");
        printf("3. Union\n");
        printf("4. Complemento\n");
        printf("5. Salir\n");
        printf("Opcion:");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el primer conjunto de letras para la potencia (separadas por comas): ");
                scanf("%s", L1);
                token = strtok(L1, ",");
                int i = 0;
                while (token != NULL && i < n) {
                    strcpy(L[i], token);
                    token = strtok(NULL, ",");
                    i++;
                }
                printf("Potencia del primer conjunto:\n");
                potencia(L, i); // Llamada a la función potencia
                printf("\nIngresa el segundo conjunto de letras para la potencia (separadas por comas): ");
                scanf("%s", L2);
                token = strtok(L2, ",");
                i = 0;
                while (token != NULL && i < n) {
                    strcpy(L[i], token);
                    token = strtok(NULL, ",");
                    i++;
                }
                printf("Potencia del segundo conjunto:\n");
                potencia(L, i); // Llamada a la función potencia
                break;
            case 2:
                printf("Ingresa la primera cadena para concatenarseparadas por comas: ");
                scanf("%s", L1);
                printf("Ingresa la segunda cadena para concatenar separadas por comas: ");
                scanf("%s", L2);
                strcpy(L3, L1);
                strcat(L1, L2);
                printf("La concatenacion de las cadenas %s y %s es:\n%s\n", L3, L2, L1);
                break;
            case 3:
                printf("Ingresa el primer conjunto para la union (separadas por comas): ");
                scanf("%s", L4);
                printf("Ingresa el segundo conjunto para la union (separadas por comas): ");
                scanf("%s", L5);
                strcpy(L6, L4);
                if (strlen(L6) > 0 && strlen(L5) > 0) {
                    strcat(L6, ",");
                }
                strcat(L6, L5);
                printf("La unión de los lenguajes '%s' y '%s' es:\n%s\n", L4, L5, L6);
                break;
            case 4:
                   printf("Complemento\n");
                printf("lenguaje 1 universal: ");
                scanf(" %[^\n]", conjunto_universal);
                printf("lenguaje 2 universal: ");
                scanf(" %[^\n]", lenguaje);
                complemento[0] = '\0';
                token = strtok(conjunto_universal, ",");
                while (token != NULL) {
                    if(strstr(lenguaje, token) == NULL) {
                        if(strlen(complemento) > 0) {
                            strcat(complemento, ",");
                        }
                        strcat(complemento, token);
                    }
                    token = strtok(NULL, ",");
                }
                printf("El complemento del lenguaje '%s' respecto al conjunto universal es:\n%s\n",lenguaje,complemento);
                break;
               /* printf("Ingresa el lenguaje para el complemento (separadas por comas): ");
                scanf("%s", lenguaje);
                complemento[0] = '\0';
                token = strtok(universal, ",");
                while (token != NULL) {
                    if (strstr(lenguaje, token) == NULL) {
                        if (strlen(complemento) > 0) {
                            strcat(complemento, ",");
                        }
                        strcat(complemento, token);
                    }
                    token = strtok(NULL, ",");
                }
                printf("El complemento del lenguaje '%s' respecto al conjunto universal es:\n%s\n", lenguaje, complemento);
                break;*/
            case 5:
                printf("Saliendo\n");
                break;
            default:
                printf("La opcion seleccionada no es valida. Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
