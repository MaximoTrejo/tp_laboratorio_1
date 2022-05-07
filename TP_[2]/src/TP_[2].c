/*
 ============================================================================
 Name        : Tp-Dos.c
 Author      : Maximo Trejo
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	passenger pasajeros[CANTPAS];

	initPassengers(pasajeros, CANTPAS);

	harcodeo(pasajeros,CANTPAS);

	menuPasajeros(pasajeros, CANTPAS);

	return EXIT_SUCCESS;
}
