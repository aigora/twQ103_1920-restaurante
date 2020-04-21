//ULTIMA EDICION 21-04-2020


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menuPrincipal();
void menuUsuario();
struct Empleados{
	char empleado[50];
	char nombre[50];
};
struct inventario{
	char nombre[50];
	float precio;
};
struct fechas{
    int dia;
    int mes;
    int annyo;
};
int main() {
	FILE *fichero;
	struct Empleados vector[100];
	int i,j;
	char salir;
	int submenu, menu;
	char empleadoRegistrado[50];
	int esIgual=1,existe; 
	int password=1234;
	int clave, contador;
	//reservas
	char seleccion1;
	struct fechas vectorReservas[100];
	int contadorReserva;
	int opcionReserva;
	//pedido
	char seleccionPedido;
	char menuPedido[50], postre[50], entrante[50];
	int opcionPedido;
	//carta
	int opcionCarta;
	//agregar producto
	struct inventario vectorProducto[100];
	int contadorCarta=0;
	
	do{
	system("cls");
	system("color F6");
	menuPrincipal();
	scanf("%i",&menu);
	fflush(stdin);
	switch(menu){
		
		
		case 1:
		system("cls");
		fichero = fopen("empleados.txt", "r");
		
		if (fichero == NULL) {
			printf("No se ha podido abrir el fichero\n");
			return -1; 
		}
		i=0;
		while (fscanf(fichero, "%s", vector[i].empleado)!=EOF) {
			i++;
		}
	
	
	
		fclose(fichero);
	
		existe=1;
			do{
				printf("Introduzca su usuario:\n");
				gets(empleadoRegistrado);
				
				for(j=0;j<i;j++){
					
					if(strcmp(empleadoRegistrado,vector[j].empleado)==0){
						existe=0;
						
					}
						
				}
				if(existe!=0){
					printf("Su usuario no ha sido registrado aun.\n");
				}
				
				}while(existe!=0);
				fflush(stdin);
				
				existe=1;
				printf("Introduzca la clave de usuario:\n");
					do{
						scanf("%d", &clave);

						if(clave==password){
							existe=0;
		
						}else
							printf("Password incorrecta, vuelva a introducirla por favor:\n");
				}while(existe!=0);
				fflush(stdin);
			
		


	do{
	system("cls");
	menuUsuario();
	scanf("%i", &submenu);	
	switch(submenu){
				
			
	case 1:
	system("cls");
	fichero = fopen("empleados.txt", "r");
				
	if (fichero == NULL) {
	printf("No se ha podido abrir el fichero\n");
	return -1; 
	}
	i=0;
	printf("Empleados registrados:\n");
	while (fscanf(fichero, "%s", vector[i].empleado)!=EOF) {
	printf("Nombre:%s\n", vector[i].empleado);
	i++;
						}
	fclose(fichero);
	printf("Presione una tecla para regresar al menu\n\n");
	system("pause");
	system("cls");
	break;
	
	case 2:
			fichero=fopen("carta.txt", "r");
			
					if(fichero==NULL){
						printf("No se ha encontrado el fichero\n");
						return -1;
					}
			
					printf("Estos son los articulos disponibles en este momento\n");
					while (fscanf(fichero, "%s %f", vectorProducto[contadorCarta].nombre, &vectorProducto[contadorCarta].precio) != EOF) {
					printf("\t\t\t\t\t%s ---> %.2f$\n", vectorProducto[contadorCarta].nombre, vectorProducto[contadorCarta].precio);
					contadorCarta++;
					}
	    			fclose(fichero);
					
					printf("Introduce el producto que desee y el precio para dicho producto:\n");
					fflush(stdin);
					scanf("%s %f", vectorProducto[contadorCarta].nombre, &vectorProducto[contadorCarta].precio);
					printf("De acuerdo, el producto ha sido agregado a la carta.\n");
					contadorCarta++;
						system("pause");
						fichero=fopen("carta.txt", "w");
					if(fichero==NULL){
						printf("No se ha encontrado el fichero\n");
						return -1;
					}	
					for (i=0; i < contadorCarta; i++) {
						fprintf(fichero, "%s %f\n", vectorProducto[i].nombre, vectorProducto[i].precio); 
					}
	
					fclose(fichero);
					break;

	case 3:
			system("cls");
			fichero = fopen("empleados.txt", "r");
		
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
		i=0;
		while (fscanf(fichero, "%s",vector[i].empleado)!=EOF) {
		i++;
		}
	
	
	fclose(fichero);

		printf("\n");
		printf("-->Introduzca el nombre del nuevo trabajador\n");
		
		scanf("%s",vector[i].empleado);		
			fflush(stdin);
		printf("Empleado registrado correctamente pulse cualquier tecla para volver al menu empleados\n");
		fflush(stdin);
		system("pause");
		i++;
		system("cls");
		
	
	
	fichero = fopen("empleados.txt", "w");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
		}
		
	
	for(j=0;j<i;j++){
		fprintf(fichero,"%s\n", vector[j].empleado);
		}
	
	fclose(fichero); 
			
	break;
		
		
		
		
		
		
	case 4:
			system("cls");
			printf("Esta usted seguro que desea salir de la aplicacion?\n");
			
			printf("1.SI \n");
					printf("2.NO \n");
						do{
							scanf("%i",&salir);	
							if(salir<1 || salir>2){
								printf("Opcion no valida\n");
							}
						}while(salir<1 || salir>2);
							if(salir==1){
								printf("Sesion cerrada con exito, hasta pronto");
								return 0;
							}else{
								system("cls");
							}
							break;
		
		default: printf("Opcion no valida\n");
		system("pause");
		system("cls");
		
	}		
	}while(submenu!='4');
		case 2:
		fichero=fopen("reservas.txt", "r");
			contadorReserva=0;
			if(fichero==NULL){
				printf("No se ha podido encontrar el fichero\n");
				return -1;
			}
			
			printf("Fechas ya reservadas:\n");
			while(fscanf(fichero, "%d %d %d", &vectorReservas[contadorReserva].dia, &vectorReservas[contadorReserva].mes, &vectorReservas[contadorReserva].annyo) != EOF){
				printf("%d/%d/%d\n", vectorReservas[contadorReserva].dia, vectorReservas[contadorReserva].mes, vectorReservas[contadorReserva].annyo);
				contadorReserva++;
			}	
			
			fclose(fichero);
			
					
					
					printf("Introduzca la fecha deseada:\n");
					printf("\t--> Dia:");
					scanf("%d", &vectorReservas[contadorReserva].dia);
					printf("\t--> Mes:");
					scanf("%d", &vectorReservas[contadorReserva].mes);
					printf("\t--> Annyo:");
					scanf("%d", &vectorReservas[contadorReserva].annyo);
					printf("Reserva realizada con exito\n");
					system("pause");
					contadorReserva++;
				
					system("cls");
				 	
			fichero = fopen("reservas.txt", "w");
	
				if (fichero == NULL) {
					printf("No se ha podido crear el fichero\n");
					return -1;
				}
	
				for (i=0; i < contadorReserva; i++) {
					fprintf(fichero, "%d %d %d\n", vectorReservas[i].dia, vectorReservas[i].mes, vectorReservas[i].annyo);
				}
	
				fclose(fichero);
				break;
		case 3:
				fichero=fopen("carta.txt", "r");
				
				if(fichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
				}
				
				printf("Desea mirar la carta mientras pide? [S/N]");
				fflush(stdin);
				scanf("%c", &seleccionPedido);
				
				if(seleccionPedido=='s'||seleccionPedido=='S'){
					while (!feof(fichero)) {
	        		printf("%c",getc(fichero));
	    			}
				fclose(fichero);
				
				printf("\nElija un entrante:\t");
				fflush(stdin);
				gets(entrante);
				fflush(stdin);
				printf("Elija un menu:\t");
				fflush(stdin);
				gets(menuPedido);
				printf("Por ultimo, escoja un postre (invita la casa):\t");
				fflush(stdin);
				gets(postre);
				
				printf("Operacion terminada\n");
				printf("Su pedido se compone de:\n\n");
				printf("\tUn entrante --> %s\n", entrante);
				printf("\tUn menu --> %s\n", menuPedido);
				printf("\tY un postre --> %s\n\n", postre);
				
				printf("Si desea volver al menu principal pulse 1\n");
				printf("Para salir, pulse cualquier otra tecla\n");
				fflush(stdin);
				scanf("%d", &opcionPedido);
				
					if(opcionPedido==1){
						system("cls");
						menuPrincipal();
					}
					else{
						printf("Hasta pronto\n");
						return 0;
					}
				}else{
					printf("De acuerdo. Sigamos\n");
					printf("Elija un entrante:\t");
					fflush(stdin);
					gets(entrante);
					printf("Elija un menu:\t");
					fflush(stdin);
					gets(menuPedido);
					printf("Por ultimo, escoja un postre (invita la casa):\t");
					fflush(stdin);
					gets(postre);
			
				
					printf("Operacion terminada\n");
					printf("Su pedido se compone de:\n\n");
					printf("\tUn entrante --> %s\n", entrante);
					printf("\tUn menu --> %s\n", menuPedido);
					printf("\tY un postre --> %s\n\n", postre);
				
					printf("Si desea volver al menu principal pulse 1\n");
					printf("Para salir, pulse cualquier otra tecla\n");
					fflush(stdin);
					scanf("%d", &opcionPedido);
				
					if(opcionPedido==1){
						system("cls");
						menuPrincipal();
					}
					else{
						printf("Hasta pronto\n");
						return 0;
					}
				}
					break;
		case 4:
			fichero=fopen("carta.txt", "r");
			
			if(fichero==NULL){
				printf("No se ha podido encontrar el fichero\n");
				return -1;
			}
			system("cls");
			printf("\t\t\t\t\tNuestra carta incluye:\n");
			
			while (fscanf(fichero, "%s %f", vectorProducto[contador].nombre, &vectorProducto[contador].precio) != EOF) {
					printf("\t\t\t\t%s........................ %.2f$\n", vectorProducto[contador].nombre, vectorProducto[contador].precio);
					contador++;
				}
	    	
	    	fclose(fichero); 
	    	
	    	printf("\nPara volver al menu principal pulse 1\n");
	    	printf("Para salir, pulse cualquier otra tecla\n");
	    	scanf("%d", &opcionCarta);
	    	
	    	if(opcionCarta==1){
	    		system("cls");
	    		menuPrincipal();
			}
			else{
				system("cls");
				printf("Hasta pronto!\n");
				return 0;
			}
			break;
		case 5:
			system("cls");
			printf("Esta usted seguro que desea salir de la aplicacion?\n");
			
			printf("1.SI \n");
					printf("2.NO \n");
						do{
							scanf("%i",&salir);	
							if(salir<1 || salir>2){
								printf("Opcion no valida\n");
							}
						}while(salir<1 || salir>2);
							if(salir==1){
								printf("Hasta la proxima.");
								return 0;
							}else{
								system("cls");
							}
							break;
		
		default: printf("Opcion no valida\n");
		system("pause");
		system("cls");

break;
}
}while(menu!='5');
}

//       FUNCIONES	:


void menuPrincipal(){
		 	printf("\n\t\t\t\t\t\tMENU PRINCIPAL\n\n\n");
		printf("\t\t\t\t\t1- Portal de empleados\n");
		printf("\t\t\t\t\t2- Hacer una reserva\n");
		printf("\t\t\t\t\t3- Hacer un pedido\n");
		printf("\t\t\t\t\t4- Carta\n");
		printf("\t\t\t\t\t5- Salir\n");
		printf("\n\t\t\t\t\tIngrese su opcion: [ ]\b\b");
}
void menuUsuario(){


	printf("\t\t\t\t\t1-Registro de empleados\n");
	printf("\t\t\t\t\t2-Agregar producto a la carta\n");
	printf("\t\t\t\t\t3-Agregar trabajador\n");
	printf("\t\t\t\t\t4-Salir");
	printf("\t\t\t\t\t\nIngrese su opcion: [ ]\b\b");
	
}
