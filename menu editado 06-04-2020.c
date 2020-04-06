#include<stdio.h>
#include<string.h>

struct carta{
	char entrantes[100];
	char menu[100];
	char postres[100];
};

struct reservas{
    int dia;
    int mes;
    int annyo;
};

//void titulo();
void menuPrincipal();
void menuCarta();
void hacerReserva();
void hacerPedido();
/*void portalEmpleados();*/

int main(){
	menuPrincipal();
	return 0;
}

void menuPrincipal(){
	int opcion;
	do {
		system("cls");
 
		printf("\n\t\t\t\tMENU PRINCIPAL\n");
		printf("1- Carta del restaurante\n");
		printf("2- Hacer una reserva\n");
		printf("3- Hacer un pedido\n");
		printf("4- Portal de empleados\n");
		printf("5- Salir\n");
		printf("\nIngrese su opcion: [ ]\b\b");
		scanf("%d", &opcion);
		
		if(opcion<1||opcion>=5){
			printf("Se ha producido un error\n");
			printf("Vuelva a introducir una opcion\n");
			scanf("%d", &opcion);
		}	
		
		switch (opcion) {
 
			case 1:
				menuCarta();
				break;
 
			case 2:
				hacerReserva();
				break;
 
			case 3:
				hacerPedido();
				break;
 
			/*case 4:
				portalEmpleados();
				break;*/
 
			case 5:
				system("cls");
				printf("Adios :frowning: ");
				system("pause");
				break;
		}
	}while(opcion<1||opcion>=5);	
}

void menuCarta(){
	char opcion;
	int seleccion;
	FILE * pfichero;
	pfichero=fopen("carta.txt", "r");
	printf("\nNuestra carta incluye:\n");
	    if (pfichero == NULL) {
	    printf("No se encuentra el fichero\n");
		}
	    while (!feof(pfichero)) {
	        printf("%c",getc(pfichero));
	    }
	    fclose(pfichero); 
	    /*printf("Desea algun entrante?[S\N]\t");
	    scanf("%c", &opcion);
	    if(opcion=='s'||opcion=='S'){
	    	printf("Introduzca el numero del entrante que desee:\t");
	    	scanf("%d", &entrante);*/
	printf("\n\nSi desea regresar al menu principal para realizar un pedido seleccione 1\n");
	printf("Si no desea continuar seleccione 2\n");
	scanf("%d", &seleccion);
	if(seleccion=1){
		return menuPrincipal();
	}
	//Queria hacer un else que me sacase del programa con un break pero no me ha dejado
}

void hacerReserva(){
	FILE * pfichero;
	
	struct reservas fechas[100];
	int contadorReservas=0, i;
	char opcion;

		printf("\nIntroduzca la fecha en la que desea hacer la reserva:\n ");
		printf("--> Dia:\t");
		scanf("%d", &fechas[contadorReservas].dia);
		printf("--> Mes:\t");
		scanf("%d", &fechas[contadorReservas].mes);
		printf("--> Anno:\t");
		scanf("%d", &fechas[contadorReservas].annyo);
		printf(" Fecha introducida: %d/%d/%d", fechas[contadorReservas].dia, fechas[contadorReservas].mes, fechas[contadorReservas].annyo );
		
		
		pfichero = fopen("reservas.txt", "w");
		if (pfichero == NULL) {
		    printf("No se encuentra el fichero\n");
		    return;
		}
		while (fscanf(pfichero, "%f %f", &fechas[contadorReservas].dia, &fechas[contadorReservas].mes, &fechas[contadorReservas].annyo) != EOF) {
		    printf("%d/%d/%d\n", fechas[contadorReservas].dia, fechas[contadorReservas].mes, fechas[contadorReservas].annyo);
		    contadorReservas++;
		}
	
		for (i=0; i < contadorReservas; i++) {
		    fprintf(pfichero, "%d %d %d\n",fechas[contadorReservas].dia, fechas[contadorReservas].mes, fechas[contadorReservas].annyo); // Escribo los datos en el fichero abierto
		}
		i++;
		    
		printf("\nDesea realizar alguna otra reserva? [S/N]");
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			return hacerReserva();
		}
		else if(opcion=='n'||opcion=='N'){
			return menuPrincipal();
		}
	//Podriamos poner tambien que solo se puedan realizar un minimo de reservas con un contador y que se pueda consultar que
	// otras reservas hay leyendo el fichero
	// Aqui no se si se me sale del programa porque la memoria se ha rallado o si funciona bien
	// Ademas no me sale que los datos se hayan guardado en el fichero despues de introducirlos, sera cosa de los fprintf?
	// He pensado que para este menu estaria bien hacer un do-while que te pregunte todo el tiempo si quieres hacer una reserva 
	// y que vuelva a mostrar el menu si pones que si y se vaya al menu principal si dices que no
	// pero no se si me sale porque ya se me esta rallando el ordenador y se me sale del programa siempre
}

void hacerPedido(){
	
	FILE * pfichero;
	char entrantes[100], menu[100], postres[100];
	char opcion;
	printf("Desea ver la carta mientras pide? [S/N]");
	fflush(stdin);
	scanf("%c", &opcion);
	if(opcion=='s'||opcion=='S'){
		
		pfichero=fopen("carta.txt", "r");
		if (pfichero == NULL) {
	    	printf("No se encuentra el fichero\n");
	    	return;
	    }
		while (!feof(pfichero)) {
	        printf("%c",getc(pfichero));
	    }
	    fclose(pfichero); 
	}	// queria conseguir que me imprimiese el fichero de la carta pero no funciona
	
	else{
		printf("Okay. Continuemos\n");
		printf("Desea algun entrante? [S/N]");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			printf("\tIntroduzca el entrante que desee:");
			fflush(stdin);
			gets(entrantes);
		}
		else if(opcion=='n'||opcion=='N'){
			printf("No ha seleccionado ningun entrante\n");
		}
		printf("Desea algun menu? [S/N]");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			printf("\tIntroduzca el menu que desee:\t");
			fflush(stdin);
			gets(menu);
		}
		else if(opcion=='n'||opcion=='N'){
			printf("No ha seleccionado ningun entrante\n");
		}
		printf("Por ultimo, quiere algun postre? [S/N]");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			printf("\tIntroduzca el postre que desee:\t");
			fflush(stdin);
			gets(postres);
		}
		else if(opcion=='n'||opcion=='N'){
			printf("No ha seleccionado ningun postre\n");
		}
		printf("Su pedido final se compone de:\n");
		puts(entrantes);
		puts(menu);
		puts(postres);
	//Aqui pretendia que si no habias seleccionado algo no saliese nada porque gets no habia pillado nada
	// pero salen caracteres raros
	}

}


