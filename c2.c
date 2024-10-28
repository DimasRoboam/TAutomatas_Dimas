#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char*lenguaje1[]={"a","ab","abc"};
    char*lenguaje2[]={"b","bc","c","ab"};
    char*union_resultante[10];
    int tamanio_union=0;
    int i,j,k;

    for(i=0;i<3;++i){
    union_resultante[tamanio_union++]=lenguaje1[i];
     }
    for(i=0;i<4;++i){
    union_resultante[tamanio_union++]=lenguaje2[i];
    }
    printf("Union:\n");
    for(i=0;i<tamanio_union;i++){
    printf("%s\n",union_resultante[i]);
     }
    char*potencia_resultante[100];
    int tamanio_potencia=0,exp=2;
    for(i=0;i<3;++i){
    potencia_resultante[tamanio_potencia++]=lenguaje1[i];
    }
    for(k=1;k<exp;++k){
        int tamanio_actual=tamanio_potencia;
        for (i=0; i < tamanio_actual;++i) {
            char* cad1 = potencia_resultante[i];
            for (j=0;j<3;++j){
                char* newCadena=(char*) malloc(strlen(cad1) + strlen(lenguaje1[j])+1);
                strcpy(newCadena,cad1);
                strcat(newCadena,lenguaje1[j]);
                potencia_resultante[tamanio_potencia++]=newCadena;
            }
        }
    }
    printf("Potencia:%d\n",exp);
    for (i=0;i<tamanio_potencia;++i){
     printf("%s\n",potencia_resultante[i]);
 }
    return 0;
}
