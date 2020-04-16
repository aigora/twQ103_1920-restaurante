
#include<stdio.h>
#include<string.h>
struct trabajo{
char	registros[100];
int password;
};

struct carta{
	char entrantes[100];
	char menu[100];
	char postres[100];
};

struct fechas{
    int dia;
    int mes;
    int annyo;
};

//void titulo();
void menuPrincipal();
void menuCarta();
void hacerReserva();
void hacerPedido();
void portalEmpleados();

int main(){
	FILE * pfichero;
	int opcion1, opcion2, opcion3, opcion4;
	struct fechas vectorReservas[100];
	int contadorCarta=0, contador=0, i=0;
	char seleccion;
	int seleccion1;
	char opcion;
	int password=1234;
	char Registro[100];
	int existe, correcto=1;	
	int contrasenia;
	struct trabajo empleados[100];
	
	do{
		system("color F1");
		menuPrincipal();
		scanf("%d", &opcion1);
		
	if(opcion1<1||opcion1>5){
		printf("Se ha producido un error\n");
		printf("Vuelva a introducir una opcion\n");
		scanf("%d", &opcion1);
	}	
		
		switch (opcion1) {
 
			case 1:
				menuCarta();
				
				break;
 
			case 2:
				pfichero = fopen("reservas.txt", "r");
	
				if (pfichero == NULL) {
				printf("No se encuentra el fichero\n");
				return 0;
				}
					

				printf("Fechas ya reservadas:\n ");
				while (fscanf(pfichero, "%d %d %d", &vectorReservas[contador].dia, &vectorReservas[contador].mes, &vectorReservas[contador].annyo) != EOF) {
				printf("%d/%d/%d\n", vectorReservas[contador].dia, vectorReservas[contador].mes,  vectorReservas[contador].annyo);
				contador++;
				}
	

				fclose(pfichero);
	

				do {
				printf("\n1 - Introduzca la fecha de su reserva:\n");
				printf("2 - Salir\n");
				scanf("%d", &opcion2);
				switch (opcion2){
				case 1: 
				printf("Introduzca la fecha deseada:\n");
				printf("\t--> Dia:");
				scanf("%d", &vectorReservas[contador].dia);
				printf("\t--> Mes:");
				scanf("%d", &vectorReservas[contador].mes);
				printf("\t--> Annyo:");
				scanf("%d", &vectorReservas[contador].annyo);
				contador++;
				break;
				case 2:
				printf("Su reserva se ha realizado con exito. Muchas gracias!\n");
				printf("Desea volver al menu principal? [S/N]\n");
				fflush(stdin);
				scanf("%c", &seleccion);
				if(seleccion=='s'||seleccion=='S'){
				 menuPrincipal();
				}
				else{
					printf("\n Adios :( ");
					break;
				}
				}
				} while(opcion2 == 1);
	
				pfichero = fopen("reservas.txt", "w");
	
				if (pfichero == NULL) {
					printf("No se ha podido crear el fichero\n");
					return 0;
				}
	
				for (i=0; i < contador; i++) {
					fprintf(pfichero, "%d %d %d\n", vectorReservas[i].dia, vectorReservas[i].mes, vectorReservas[i].annyo);
				}
	
				fclose(pfichero);
				
				
				
				break;
 
			case 3:
				hacerPedido();
				break;
 
			case 4:
	
				contador=0;
				pfichero = fopen("empleados.txt", "r");
				
				if (pfichero == NULL) {
					printf("No se encuentra el fichero\n");
					return 0;
				}
				
				i=0;	
				//leer las palabras del fichero y las va guardando, según el valor de i.
				while(fscanf(pfichero,"%s", empleados[i].registros)!=EOF){
					i++;
				}
				fclose(pfichero);
				existe=1;
				printf("Inroduzca su nombre: \n");
				fflush(stdin);
				
				do{
	
				gets(Registro);
					for(contador=0;contador<i;contador++){
						if(strcmp(Registro,empleados[contador].registros)==0){
							existe=0;
						} 
						else{
							printf("Su nombre no esta registrado, vuelva a introducirlo:\n");
						}
					}
				}while(existe!=0);
				
				printf("Introduzca la password de empleados:");
				do{
					scanf("%d", &contrasenia);

						if(password==contrasenia){
							correcto=0;
		
						}else
							printf("Password incorrecta, vuelva a introducirla por favor:\n");
				}while(correcto!=0);	//AAAAAAAAAAAAAAAAAAAAAAAAAAA
				system("cls");
				
				do{
				system("cls");
				menuEmpleados();
					scanf("%d",&opcion3);
				
				switch (opcion3) {
		
				case 1: 
					pfichero=fopen("carta.txt", "r");
	   				 if (pfichero == NULL) {
	   					 printf("No se encuentra el fichero\n");
	   					 return 0;
					}
					printf("\n\n");
					
	   				while (!feof(pfichero)) {
	  	      			printf("%c",getc(pfichero));
	   				}
	    			fclose(pfichero); 
	   	 			system("pause");
	   	 		
				break;
				case 2: 
				break;
				case 4: 
					pfichero=fopen("empleados.txt", "r");
					if (pfichero == NULL) {
	   					 printf("No se encuentra el fichero\n");
	   					 return 0;
					}
					while (!feof(pfichero)) {
	  	      			printf("%c",getc(pfichero));
	  	      			
	   				}
	   				printf("\n\n");
				    system("pause");
					
					break;
 
				case 5:
				
				return 0;
				break;
				}
			
				}while(opcion3!=5);
				
				break;
 
				case 5:
				printf("Adios :(\n");
				return 0;
				break;
				}
				
			
	}while(opcion1<1||opcion1<5);
		return 0;
}













void menuPrincipal(){
	int opcion;

		system("cls");
 
		printf("\n\t\t\t\t\t\tMENU PRINCIPAL\n\n\n");
		printf("\t\t\t\t\t1- Carta del restaurante\n");
		printf("\t\t\t\t\t2- Hacer una reserva\n");
		printf("\t\t\t\t\t3- Hacer un pedido\n");
		printf("\t\t\t\t\t4- Portal de empleados\n");
		printf("\t\t\t\t\t5- Salir\n");
		printf("\n\t\t\t\t\tIngrese su opcion: [ ]\b\b");

		
}




void menuCarta(){
	char opcion3;
	int seleccion1;
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
		scanf("%d", &seleccion1);
	if(seleccion1=1){
		return menuPrincipal();
	}
	//Queria hacer un else que me sacase del programa con un break pero no me ha dejado
}



void menuEmpleados(){
	printf("\t\t\t\t1-Inventario\n");
				printf("\t\t\t\t\tI2-Aniadir articulos\n");
				printf("\t\t\t\t\tI3-Restar articulos\n");
				printf("\t\t\t\t\tI4-Registro de empleados\n");
				printf("\t\t\t\t\tI5-Salir");
				printf("\t\t\t\t\tI\nIngrese su opcion: [ ]\b\b");
}






void hacerReserva(){
struct fechas vectorReservas[100];
FILE * pfichero;


int contadorCarta=0, contador=0, i=0;
int opcion;
char seleccion;

	pfichero = fopen("reservas.txt", "r");
	
	if (pfichero == NULL) {
		printf("No se encuentra el fichero\n");
	}
	

	printf("Fechas ya reservadas:\n ");
	while (fscanf(pfichero, "%d %d %d", &vectorReservas[contador].dia, &vectorReservas[contador].mes, &vectorReservas[contador].annyo) != EOF) {
		printf("%d/%d/%d\n", vectorReservas[contador].dia, vectorReservas[contador].mes,  vectorReservas[contador].annyo);
		contador++;
	}
	

	fclose(pfichero);
	

	do {
		printf("\n1 - Introduzca la fecha de su reserva:\n");
		printf("2 - Salir\n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1: 
				printf("Introduzca la fecha deseada:\n");
				printf("\t--> Dia:");
				scanf("%d", &vectorReservas[contador].dia);
				printf("\t--> Mes:");
				scanf("%d", &vectorReservas[contador].mes);
				printf("\t--> Annyo:");
				scanf("%d", &vectorReservas[contador].annyo);
				contador++;
				break;
			case 2:
				printf("Su reserva se ha realizado con exito. Muchas gracias!\n");
				printf("Desea volver al menu principal? [S/N]\n");
				fflush(stdin);
				scanf("%c", &seleccion);
				if(seleccion=='s'||seleccion=='S'){
					return menuPrincipal();
				}
				else{
					printf("\n Adios :( ");
					break;
				}
		}
	} while(opcion == 1);
	
	pfichero = fopen("reservas.txt", "w");
	
	if (pfichero == NULL) {
		printf("No se ha podido crear el fichero\n");
	}
	
	for (i=0; i < contador; i++) {
		fprintf(pfichero, "%d %d %d\n", vectorReservas[i].dia, vectorReservas[i].mes, vectorReservas[i].annyo);
	}
	
	fclose(pfichero);
	
	//Podriamos poner tambien que solo se puedan realizar un minimo de reservas con un contador y que se pueda consultar que
	// otras reservas hay leyendo el fichero
	// Aqui no se si se me sale del programa porque la memoria se ha rallado o si funciona bien
	// Ademas no me sale que los datos se hayan guardado en el fichero despues de introducirlos, sera cosa de los fprintf?
	// He pensado que para este menu estaria bien hacer un do-while que te pregunte todo el tiempo si quieres hacer una reserva 
	// y que vuelva a mostrar el menu si pones que si y se vaya al menu principal si dices que no
	// pero no se si me sale porque ya se me esta rallando el ordenador y se me sale del programa siempre
}//*







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
		// queria conseguir que me imprimiese el fichero de la carta pero no funciona
	
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
			printf("No ha seleccionado ningun postre\n\n");
		}
		printf("Su pedido final se compone de:\n");
		puts(entrantes);
		puts(menu);
		puts(postres);
		printf("Desea volver al menu principal? [S/N]|\n");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			return menuPrincipal();
		}
		else{
			printf("Hasta pronto!\n");
		}
}
else if(opcion=='n'||opcion=='N'){
	printf("De acuerdo\n");
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
			printf("No ha seleccionado ningun postre\n\n");
		}
		printf("Su pedido final se compone de:\n");
		puts(entrantes);
		puts(menu);
		puts(postres);
		
		printf("Desea volver al menu principal? [S/N]|\n");
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='s'||opcion=='S'){
			return menuPrincipal();
		}
		else{
			printf("Hasta pronto!\n");
		}
}
	//Aqui pretendia que si no habias seleccionado algo no saliese nada porque gets no habia pillado nada
	// pero salen caracteres raros
	}

