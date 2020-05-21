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
	char platoPedido[50];
	int opcionPedido;
	float coste=0;
	
	//carta
	int opcionCarta;
	
	//agregar producto
	struct inventario vectorProducto[100];
	int contadorCarta=0;
	
	do{
	system("cls");
	system("color F1");
	menuPrincipal();
	scanf("%i",&menu);
	fflush(stdin);
	switch(menu){
		
		case 1:
			system("cls");
			fichero = fopen("empleados.txt", "r");
		
			if (fichero == NULL) {
				printf("\n\n\t\t\t\t\tNo se ha podido abrir el fichero\n");
				return -1; 
			}
			
			i=0;
			while (fscanf(fichero, "%s", vector[i].empleado)!=EOF) {
				i++;
			}
		
			fclose(fichero);
		
			existe=1;
			
			do{
				printf("\n\t\t\t\t\tIntroduzca su usuario:\t");
				gets(empleadoRegistrado);
				
				for(j=0;j<i;j++){
					if(strcmp(empleadoRegistrado,vector[j].empleado)==0){
						existe=0;	
					}		
				}
				
				if(existe!=0){
					printf("\n\t\t\t\t\tSu usuario no ha sido registrado aun\n");
				}
				
			}while(existe!=0);
				
			fflush(stdin);
				
			existe=1;
			
			printf("\t\t\t\t\tIntroduzca la clave de usuario:\t");
					
			do{
				scanf("%d", &clave);

				if(clave==password){
					existe=0;
		
				}
				else{
					printf("\n\t\t\t\t\tPassword incorrecta, vuelva a introducirla por favor:\t");
				}		
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
						printf("\n\n\t\t\t\t\tNo se ha podido abrir el fichero\n");
						return -1; 
					}
					
					i=0;
					printf("\n\n\t\t\t\t\tEmpleados registrados:\n");
					
					while (fscanf(fichero, "%s", vector[i].empleado)!=EOF) {
						printf("\t\t\t\t\t-> %s\n", vector[i].empleado);
						i++;
					}
					fclose(fichero);
					
					printf("\t\t\t\t\tPresione una tecla para regresar al menu\n\n");
					system("pause");
					system("cls");
					break;
	
				case 2:
					fichero=fopen("carta.txt", "r");
			
					if(fichero==NULL){
						printf("\n\n\t\t\t\t\tNo se ha encontrado el fichero\n");
						return -1;
					}
			
					printf("\n\n\t\t\t\tEstos son los articulos disponibles en este momento\n");
					
					while (fscanf(fichero, "%s %f", vectorProducto[contadorCarta].nombre, &vectorProducto[contadorCarta].precio) != EOF) {
						printf("\t\t\t\t-> %s ---> %.2f$\n", vectorProducto[contadorCarta].nombre, vectorProducto[contadorCarta].precio);
						contadorCarta++;
					}
					
	    				fclose(fichero);
					
					printf("\nIntroduzca el producto que desee y el precio para dicho producto\n");
					fflush(stdin);
					printf("\t-> Producto:\t");
					scanf("%s", vectorProducto[contadorCarta].nombre);
					printf("\t-> Precio:\t");
					scanf("%f", &vectorProducto[contadorCarta].precio);
					
					printf("\nDe acuerdo, el producto ha sido agregado a la carta.\n");
					contadorCarta++;
					system("pause");
					
					fichero=fopen("carta.txt", "w");
					
					if(fichero==NULL){
						printf("\t\t\t\t\tNo se ha encontrado el fichero\n");
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
						printf("\n\n\t\t\t\t\tNo se ha podido abrir el fichero\n");
						return -1; 
						}
					
					i=0;
					while (fscanf(fichero, "%s",vector[i].empleado)!=EOF) {
						i++;
					}
					fclose(fichero);

					printf("\n");
					printf("\n\n\t\t\t\tIntroduzca el nombre del nuevo trabajador: ");
					scanf("%s",vector[i].empleado);		
					fflush(stdin);
					printf("\t\tEmpleado registrado correctamente pulse cualquier tecla para volver al menu empleados\n\n\n");
					fflush(stdin);
					system("pause");
					i++;
					system("cls");
		
					fichero = fopen("empleados.txt", "w");
	
					if (fichero == NULL) {
						printf("\n\n\t\t\t\t\tNo se ha podido abrir el fichero\n");
						return -1;
					}
		
					for(j=0;j<i;j++){
						fprintf(fichero,"%s\n", vector[j].empleado);
					}
	
					fclose(fichero);	
					break;
	
				case 4:
					system("cls");
					printf("\n");
					printf("\t\t\t\t\tEsta usted seguro que desea salir de la aplicacion?\n");
					printf("\n\t\t\t\t\t1.SI\n");
					printf("\t\t\t\t\t2.NO\n");
					printf("\n\t\t\t\t\tIntroduzca su opcion:\t");
						
					do{
						scanf("%i",&salir);	
						if(salir<1 || salir>2){
							printf("\t\t\t\t\tOpcion no valida\n");
						}
					}while(salir<1 || salir>2);
					
					if(salir==1){
						printf("\n\t\t\t\tSesion cerrada con exito, hasta pronto\n\n");
						return 0;
					}
					else{
						system("cls");
					}
					break;
		
				default: printf("\t\t\t\t\tOpcion no valida\n");
				system("pause");
				system("cls");
		
				}		
			}while(submenu!='4');
			
		case 2:
			system("cls");
			fichero=fopen("reservas.txt", "r");
			contadorReserva=0;
			
			if(fichero==NULL){
				printf("\n\n\t\t\t\t\tNo se ha podido encontrar el fichero\n");
				return -1;
			}
			
			printf("\n\t\t\t\t\tFechas ya reservadas:\n\n");
			
			while(fscanf(fichero, "%d %d %d", &vectorReservas[contadorReserva].dia, &vectorReservas[contadorReserva].mes, &vectorReservas[contadorReserva].annyo) != EOF){
				printf("\t\t\t\t\t-> %d/%d/%d\n", vectorReservas[contadorReserva].dia, vectorReservas[contadorReserva].mes, vectorReservas[contadorReserva].annyo);
				contadorReserva++;
			}	
			
			fclose(fichero);
		
			printf("\n\t\t\t\t\tIntroduzca la fecha deseada:\n\n");
			printf("\t\t\t\t\t--> Dia: ");
			scanf("%d", &vectorReservas[contadorReserva].dia);
			printf("\t\t\t\t\t--> Mes: ");
			scanf("%d", &vectorReservas[contadorReserva].mes);
			printf("\t\t\t\t\t--> Annyo: ");
			scanf("%d", &vectorReservas[contadorReserva].annyo);
			printf("\n\n\t\t\t\t\tSu reserva ha sido realizada con exito\n\n");
			
			system("pause");
			contadorReserva++;
				
			system("cls");
				 	
			fichero = fopen("reservas.txt", "w");
	
			if (fichero == NULL) {
				printf("\n\n\t\t\t\t\tNo se ha podido crear el fichero\n");
				return -1;
			}
	
			for (i=0; i < contadorReserva; i++) {
				fprintf(fichero, "%d %d %d\n", vectorReservas[i].dia, vectorReservas[i].mes, vectorReservas[i].annyo);
			}
	
			fclose(fichero);
			break;
			
		case 3:
			system("cls");
			fichero=fopen("carta.txt", "r");
				
			if(fichero==NULL){
				printf("\n\n\t\t\t\t\tNo se ha podido encontrar el fichero\n");
				return 0;
			}
			
			fichero=fopen("carta.txt", "r");
		
			printf("\n\n\t\t\tEstos son los platos disponibles en este momento:\n\n");
			
			while (fscanf(fichero, "%s %f", vectorProducto[contadorCarta].nombre, &vectorProducto[contadorCarta].precio) != EOF) {
				printf("\t\t\t\t-> %s ---> %.2f$\n", vectorProducto[contadorCarta].nombre, vectorProducto[contadorCarta].precio);
				contadorCarta++;
			}
	    	
			fclose(fichero);
	   
	   		do{	
	   			fflush(stdin);
	    		printf("\nIntroduzca el nombre del plato que desea:\t");
	    		gets(platoPedido);
	
	    		for(i=0;i<contadorCarta;i++){
	    			if(strcmp(vectorProducto[i].nombre, platoPedido)==0){
	    				printf("\nDe acuerdo, se adicionan %.2f al precio final\n\n", vectorProducto[i].precio);
	    				coste+=vectorProducto[i].precio;	
					}
				}
		
				printf("Desea continuar pidiendo?\n\n");
				printf("\t1-Continuar\n");
				printf("\t2-Salir\n");
				printf("\tIntroduzca su opcion:\t");
				scanf("%d", &opcionPedido);
			}while(opcionPedido!=2);
			
			printf("Pedido realizado con exito, el precio final seran : %.2f$\n\n\n", coste);
			printf("Muchas gracias :)\n\n");
			system("pause");
			break;
			
		case 4:
			fichero=fopen("carta.txt", "r");
			
			if(fichero==NULL){
				printf("\n\n\t\t\t\t\tNo se ha podido encontrar el fichero\n");
				return -1;
			}
			
			system("cls");
			printf("\n\n\t\t\t\t\tNuestra carta incluye:\n\n");
			
			while (fscanf(fichero, "%s %f", vectorProducto[contador].nombre, &vectorProducto[contador].precio) != EOF) {
				printf("\t\t\t-> %s........................ %.2f$\n", vectorProducto[contador].nombre, vectorProducto[contador].precio);
				contador++;
			}
	    	
	    		fclose(fichero); 
	    	
	    		printf("\n\n\t\t\t\tPara volver al menu principal pulse 1\n");
	    		printf("\t\t\t\tPara salir, pulse cualquier otra tecla: ");
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
			printf("\n");
			printf("\t\t\t\t\tEsta usted seguro que desea salir de la aplicacion?\n");
			printf("\t\t\t\t\t1.SI\n");
			printf("\t\t\t\t\t2.NO\n");
			printf("\t\t\t\t\tIntroduzca su opcion:\t");
			
			do{
				scanf("%i",&salir);	
				if(salir<1 || salir>2){
					printf("\t\t\t\t\tOpcion no valida\n");
				}
			}while(salir<1 || salir>2);
							
			if(salir==1){
				printf("\n\n\t\t\t\t\tHasta la proxima.");
				return 0;
			}
			else{
			system("cls");
			}
			break;
		
		default: printf("\t\t\t\t\tOpcion no valida\n");
			system("pause");
			system("cls");
			break;
		}
	}while(menu!='5');
}

//FUNCIONES:

void menuPrincipal(){ 
	printf("\n\t\t\t      BIENVENIDO AL MENU PRINCIPAL DEL CRUJIENTE CANGREJO!\n\n");
	printf("\n\t\t\t\t\t\tMENU PRINCIPAL\n");
	printf("\t\t\t\t\t\t--------------  \n");
	printf("\t\t\t\t\t1- Portal de empleados\n");
	printf("\t\t\t\t\t2- Hacer una reserva\n");
	printf("\t\t\t\t\t3- Hacer un pedido\n");
	printf("\t\t\t\t\t4- Carta\n");
	printf("\t\t\t\t\t5- Salir\n");
	printf("\n\t\t\t\t\tIngrese su opcion: [ ]\b\b");
}

void menuUsuario(){
	printf("\n\n\t\t\t\t\t\tMENU EMPLEADOS\n\n");
	printf("\t\t\t\t\t1-Registro de empleados\n");
	printf("\t\t\t\t\t2-Agregar producto a la carta\n");
	printf("\t\t\t\t\t3-Agregar trabajador\n");
	printf("\t\t\t\t\t4-Salir\n");
	printf("\t\t\t\t\tIngrese su opcion: [ ]\b\b");
}
