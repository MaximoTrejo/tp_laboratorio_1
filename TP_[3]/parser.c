#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	char id[TAM],nombre[TAM],apellido[TAM],precio[TAM],tipoPasajero[TAM],codigoVuelo[TAM],isEmpty[TAM];
	int cantidad;
	Passenger* pAuxPasajeros;

	if(pFile != NULL && pArrayListPassenger != NULL){
		//scanf se utiliza para leer los datos//leo la primer linea , el encabezado
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,isEmpty);

		while(!feof(pFile)){//feof devuelve 0 si llega al final del bloque de datos y 1 si no llega

			cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,isEmpty);
			//entra y si cada ves que pasa lee la cantidad de datos correctos entra y crea un nuevo pasajero
			if(cantidad < 7){
				//libera memoria
				Passenger_delete(pAuxPasajeros);
				retorno=-1;
				break;
			}else{
				/*
				 * 1-crear nuevo pasajero en la estructura psajeros
				 * 2-ver que no este con basura
				 * 3-cargarlo en lickedlist
				 * 4-retornar
				 */
				pAuxPasajeros=Passenger_newParametros(id, nombre, apellido, tipoPasajero, precio, codigoVuelo, isEmpty);

				if(pAuxPasajeros != NULL){

					ll_add(pArrayListPassenger, pAuxPasajeros);

					retorno=0;
				}
			}

		}//una funcion si le llego al final de un archivo 0 mal 1 bien
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		do
			{
				Passenger* pPassenger = Passenger_new();
				if(pPassenger != NULL && fread(pPassenger, sizeof(Passenger), 1, pFile) == 1)
				{
					ll_add(pArrayListPassenger, pPassenger);
					retorno = 0;
				}
				else
				{
					break;
				}
			}while(!feof(pFile));
	}
    return retorno;
}
