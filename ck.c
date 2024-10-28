#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void kleene_star(char *s,int n);
void positive_closure(char *s,int n);
void shuffle(char *arr[],int n);

int main() {
    srand(time(NULL));
    char cadena[]="ab";
    char cadena1[]="1a2b";
    int n=4; // Numero de repeticiones 

    kleene_star(cadena,n);
    printf("\n");
    positive_closure(cadena,n);
    kleene_star(cadena1,n);
    printf("\n");
    positive_closure(cadena1,n);

    return 0;
}
void shuffle(char *arr[],int n){
    int i, j;
    for (i=n-1;i>0;--i){
        j = rand() % (i + 1);
        char *temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

void kleene_star(char *s,int n){
    // Cerradura de Kleene
    printf("Cerradura de Kleene:\n");
    char *results[100];
    char result[100];
    int index=0;
    int i, j;
    for (i=0;i<=n;i++){
        result[0]='\0';
        for (j=0;j<i;++j){
            strcat(result,s);
        }
        results[index]=strdup(result);
        index++;
    }
    shuffle(results,index);

    for (i=0;i<index;++i){
        printf("Cadena: '%s',Longitud: %i\n",results[i],strlen(results[i]));
        free(results[i]);
    }
}
void positive_closure(char *s,int n) {
    // Cerradura Positiva
    printf("Cerradura Positiva:\n");
    char *results[100];
    char result[100];
    int index=0;
    int i,j;
    for(i=1;i<=n;++i){
        result[0] = '\0';
        for(j=0;j<i;++j){
            strcat(result,s);
        }
        results[index]=strdup(result);
        index++;
    }
    shuffle(results, index);
    for(i=0;i<index;++i){
        printf("Cadena:'%s', Longitud: %i\n", results[i],strlen(results[i]));
        free(results[i]);
    }
}
