#include <stdio.h>

int main(){
	int on=1;//encendido
    int off=0;//apagado
	int opcion;
	
    printf("Selecciona una opcion:\n");
    printf("1.encender la luz\n");
    printf("2.apagar la luz\n");
    printf("Opcion:");
    scanf("%d",&opcion);

    switch(opcion){
        case 1:
            printf("enceder la luz\n");
            scanf("%d",&on);
            if(on==0){
				printf("la luz esta apagada");
			}else{
				printf("la luz esta encendidaapagada");
			}
            break;
        case 2:
            printf("apagar la luz\n");
            scanf("%d",&off);
            if(off==0){
				printf("la luz esta apagada");
			}else{
				printf("la luz esta encendida");
			}
            break;
            default:
            printf("La opcion seleccionada no es valida.\n");
    }
    return 0;
}
