#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
	int opcion=0;

	LinkedList* listaPasajeros = ll_newLinkedList();

	do{
		opcionesMenu();
		if(utn_getInt(&opcion,"Opcion:", "La opcion no es correcta", 1, 10, REINTENTOS)==0){
			switch(opcion){

			case 1:
				//saco el largo de la lista , retorna 0 bien | -1 mal
				if(controller_loadFromText("data.csv",listaPasajeros)==0){
					printf("*Archivo cargado correctamente\n");
				}else{
					printf("No se pudo cargar el archivo\n");
				}
				break;
			case 2:

				if(controller_loadFromBinary("data.bin",listaPasajeros)==0){
					printf("*Archivo cargado correctamente\n");
				}else{
					printf("*No se pudo cargar el archivo\n");
				}
				break;
			case 3:
				if(controller_addPassenger(listaPasajeros)==0){
					printf("*Se cargo correctamente el pasajero\n");
				}else{
					printf("*No se pudo cargar el pasajero\n");
				}
				break;
			case 4:
				if(controller_editPassenger(listaPasajeros)==0){
					printf("Se modifico correctamente\n");

				}else{
					printf("No se pudo modificar\n");
				}
				break;
			case 5:
				if(controller_removePassenger(listaPasajeros)==0){
					printf("Se elimino con exito\n");
				}else{
					printf("No se pudo eliminar");
				}
				break;
			case 6:
				if(controller_ListPassenger(listaPasajeros)==0){
					printf("Se listo correctamente\n");

				}else{
					printf("No se pudo listar \n");
				}
				break;
			case 7:
				if(controller_sortPassenger(listaPasajeros)==0){
					printf("se ordeno correctamente\n");
				}else{
					printf("no se ordeno correctamente\n");
				}
				break;
			case 8:
				//saco el largo de la lista , retorna 0 bien | -1 mal
				if(controller_saveAsText("data.csv",listaPasajeros)==0){
					printf("*Archivo guardo correctamente\n");
				}else{
					printf("No se pudo guardar el archivo\n");
				}
				break;
			case 9:
				if(controller_saveAsBinary("data.bin", listaPasajeros)==0){
					printf("*Archivo guardo correctamente\n");
				}else{
					printf("No se pudo guardar el archivo\n");
				}
				break;
			case 10:
				break;
			default:
				printf("esa opcion no existe");
			}
		}
	}while(opcion != 10);


    return EXIT_SUCCESS;
}
