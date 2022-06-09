/*
 * menu.c
 *
 *  Created on: 25 may. 2022
 *      Author: maxim
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"

void opcionesMenu(void){
	printf(
	"Menu:\n"
	"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
	"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
	"3. Alta de empleado\n"
	"4. Modificar datos de empleado\n"
	"5. Baja de empleado\n"
	"6. Listar empleados\n"
	"7. Ordenar empleados\n"
	"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
	"9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
	"10. Salir\n");
}

void selecModificar(){
	printf("\n1-nombre");
	printf("\n2-apellido");
	printf("\n3-Precio");
	printf("\n4-TipoPasajero");
	printf("\n5-CodigoVuelo");
}


void opcionesOrdenar(){
	printf("\n1-Id");
	printf("\n2-nombre");
	printf("\n3-apellido");
	printf("\n4-Precio");
	printf("\n5-TipoPasajero");
	printf("\n6-CodigoVuelo");
}

void opcionsort(){
	printf("\n1-Ascendente");
	printf("\n2-Descendente");
}
