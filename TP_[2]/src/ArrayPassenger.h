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


////@brief inicializa todo el string en 0
////@fn int initPassengers(passenger listPasajeros[],int tam);
////@param album list[](llamo a todo el string de la estructura album)
////@param int tam(variable de enteros que psa el tamaño del string)
////@return 0[BIEN] | -1[MAL]
int initPassengers(passenger listPasajeros[],int tam);
////@brief cargo 1 lugar del string de la estructura album
////@fn int addPassenger(passenger list[]);
////@param album list[](llamo a todo el string de la estructura album)
////@return 0[BIEN] | -1[MAL]
int addPassenger(passenger list[]);
////@brief busca si el id que ingreso el usuario es igual al id que esta cargado en el string
////@fn int findPassengerById(passenger list[], int len,int id)
////@param passenger list[](llamo a todo el string de la estructura pasajero)
////@param int len(variable de enteros que psa el tamaño del string)
////@param int id(id ingresado por el usuario)
////@return retorna el id | -1[MAL]
int findPassengerById(passenger list[], int len,int id);
////@brief borra de manera logica los datos del string
////@fn int removePassenger(passenger list[], int len, int id)
////@param album list[](llamo a todo el string de la estructura pasajeros)
////@param int len(variable de enteros que psa el tamaño del string)
////@param int id(id que quiere eliminar )
////@return 0[BIEN] | -1[MAL]
int removePassenger(passenger list[], int len, int id);
////@brief modifica uno de los campos que esta cargado en el string
////@fn int modificarPasajeros(passenger *list ,int len,int idMod)
////@param pasajeros list[](llamo a todo el string de la estructura pasajeros)
////@param int len(variable de enteros que psa el tamaño del string)
////@param int idMod(id que el usuario quiere modificar )
////@return 0[BIEN] | -1[MAL]
int modificarPasajeros(passenger *list ,int len,int idMod);
////@brief esqueleto de todo el programa , lugar donde estan todas las opciones y funcionalidades
////@fn void menuPasajeros(passenger list[], int len);
////@param passenger list[](llamo a todo el string de la estructura pasajeros)
////@return no retorno nada es (void)
void menuPasajeros(passenger list[], int len);
////@brief busca un lugar libre em la estructura pasajeros viendo si la cantidad del string no este llena
////@fn int bucarLibre(passenger pPasajeros[], int len);
////@param passenger list[](llamo a todo el string de la estructura pasajeros)
////@param int len(variable de enteros que psa el tamaño del string)
////@return retorna el lugar libre
int bucarLibre(passenger pPasajeros[], int len);
////@brief imprime los datos de la estructura pasajeros
////@fn int imprimir (passenger list[], int tam);
////@param passenger list[](llamo a todo el string de la estructura pasajeros)
////@param int tam(variable de enteros que psa el tamaño del string)
////@return no retorno nada es (void)
int imprimir (passenger list[], int tam);
////@brief todos las opciones de informes
////@fn void opcionesInformes(void);
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void opcionesInformes(void);
////@brief todos las opciones de menu
////@fn void menu (void);
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void menu (void);
////@brief todos las opciones de modificar
////@fn void selecModificar();
////@param no tiene ningun parametro es (void)
////@return no retorno nada es (void)
void selecModificar();
////@brief suma todos los importes
////@fn int totalInforme( album list[],int len,float*promedio);
////@param album list[](llamo a todo el string de la estructura album)
////@param int len(variable de enteros que psa el tamaño del string)
////@param float *promedio(variable donde se va a guardar el promedio)
////@return retorna el total
int totalInforme(passenger list[], int len,float*promedio);
////@brief se calcula el promedio
////@fn float promedioInforme(int contPasajeros , int totalPasajeros );
////@param int contPasajeros(contador de pasajeros )
////@param int totalPasajeros (total de pasajeros , es el total del importe)
////@return retorna el promedio
float promedioInforme(int contPasajeros , int totalPasajeros );
////@brief cantidad de pasajeros que superan al promedio
////@fn int superPasajeros(passenger list[], int len, float promedio);
////@param passenger list[](llamo a todo el string de la estructura pasajeros)
////@param int len(variable de enteros que psa el tamaño del string)
////@param float promedio(promedio antes calculado que sirve para determinar cuales son los que superan el promedio)
////@return retorna la cantidad de pasajeros que superan el promedio
int superPasajeros(passenger list[], int len, float promedio);
////@brief le cargo datos a la estructura pasajeros
////@fn void harcodeo(passenger lista[],int tam);
////@param passenger list[](llamo a todo el string de la estructura pasajeros)
////@param int tam(variable de enteros que psa el tamaño del string)
////@return no retorno nada es (void)
void harcodeo(passenger lista[],int tam);

#endif /* ARRAYPASSENGER_H_ */
