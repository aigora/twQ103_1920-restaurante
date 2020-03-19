#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int menu, menu2;

printf("\tBienvenido al Crujiente Crustaceo!\n\n");
printf("\t\t\tMENU PRINCIPAL\n\n");
printf("\t1- Carta del restuarante\n");
printf("\t2- Hacer una reserva\n");
printf("\t3- Hacer un pedido\n");
printf("\t4- Empleados\n");
printf("\t5- Salir\n");

printf("\tIntroduzca a continuacion la opcion deseada:\t");
scanf("%i", &menu);

if(menu<1 || menu>=6){
	
	do{
	printf("\tOpcion no valida\n");
	printf("\tVuelva a introducir la opcion:\t");
	scanf("%i", &menu);
	}while(menu<1 || menu>=6);
}

switch(menu){
	case 1:
		system("cls");
		printf("\t\tC A R T A\n\n");
		printf("\tCangrejo\n");
		printf("\tMerluza\n");
		printf("\tBacalao\n");
		printf("\tPulpo\n");
		printf("\tCalamares\n");
		break;

		case 5: 
		system("cls");
		printf("\tAdios :( ");
		return 0;
		system("pause");
		break;
	}

return 0;
system("pause");
}
