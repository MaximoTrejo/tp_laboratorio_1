/*
 * pasajeros.h
 *
 *  Created on: 26 abr. 2022
 *      Author: maxim
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TAM 51
#define CODV 10
#define CANTPAS 2000

#define LIBRE 0
#define OCUPADO 1

#define ACTIVO 1
#define DESACTIVADO 0

#define REINTENTOS 3



typedef struct
{
	int id;
	char name[TAM];//nombre
	char lastname[TAM];//apellido
	float price;//precio
	char flycode[CODV];//codigoVolador;
	int typrPassenger;//tipoPasajero;
	int statusFlight;//estadoVuelo;
	int isEmpty;//vacio;

}passenger;

int initPassengers(passenger listPasajeros[],int tam);
int addPassenger(passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(passenger list[], int len,int id);
int removePassenger(passenger list[], int len, int id);
int modificarPasajeros(passenger *list ,int len,int idMod);
void menuPasajeros(passenger list[], int len);
int bucarLibre(passenger pPasajeros[], int len);
int eliminarPasajeros(passenger list[],int len ,int idBuscado);
int imprimir (passenger list[], int tam);
void opcionesInformes(void);
void menu (void);
void selecModificar();
int totalInforme(passenger list[], int len,float*promedio);
float promedioInforme(int contPasajeros , int totalPasajeros );
int superPasajeros(passenger list[], int len, float promedio);


void inicializarTickets(passenger lista[],int tam);

#endif /* ARRAYPASSENGER_H_ */
