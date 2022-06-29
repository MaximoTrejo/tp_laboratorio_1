#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "LinkedList.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"

int controller_idFantasma(void)
{
	char maxIdAux[10];
	//int maxIdExcel=1000;
	int newMaxId;

	/*
	 * 1-abro el archivo en modo lectura
	 * 2-verifico
	 * 3-leo lo que hay en el archivo
	 * 4-convierto a entero a lo que hay dentro del archivo y le sumo 1
	 * 5-cierro el archivo
	 * -----------------------
	 * 6-hablo el archivo en modo escritura y escribo el nuevo id para guardarlo
	 * 7-cierro el archivo
	 * 8-retorno el nuevo id
	 */

	FILE* pArchivo;

	pArchivo=fopen("idFantasma.txt","r");

	if(pArchivo!=NULL){
		fscanf(pArchivo,"%[^\n]", maxIdAux);
		newMaxId=atoi(maxIdAux);
		newMaxId++;
	}
	fclose(pArchivo);

	pArchivo=fopen("idFantasma.txt","w");
	fprintf(pArchivo,"%d\n",newMaxId);
	fclose(pArchivo);

	return (newMaxId);
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	/*
	 * 1-abro el archivo en modo lectura
	 * 2-llamo al parser y me fijo si lo llamo bien
	 * 3-retorno
	 */

	FILE *pArchivo;//tipo de estructura que me perdite manupular archivo

	pArchivo=fopen(path,"r");

	if(pArchivo != NULL){
		if(parser_PassengerFromText(pArchivo, pArrayListPassenger) ==0){
			//printf("se leyo correctamente\n");
			retorno=0;
		}else{
			//printf("no se leyo correctamente");
			retorno=-1;
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
		/*
		 * 1-abro el archivo en modo lectura
		 * 2-llamo al parser y me fijo si lo llamo bien
		 * 3-retorno
		 */
	if (path != NULL && pArrayListPassenger != NULL) {

		FILE *pArchivo;//tipo de estructura que me perdite manupular archivo

			pArchivo=fopen(path,"rb");

			if(pArchivo != NULL){

				if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger) ==0){
					printf("*Se leyo correctamente\n");
					retorno=0;
					fclose(pArchivo);

				}else{
					printf("*No se leyo correctamente\n");
					retorno=-1;
				}
			}
	}
	return retorno;
}




int controller_newId(LinkedList* pArrayListPassenger){
	int retorno=-1;
	int id;
	int largo;

	largo=ll_len(pArrayListPassenger);
	id=largo+1;
	retorno=id;

	return retorno;
}


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	char nombreAux[TAM];
	char apellidoAux[TAM];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[TAM];
	int idAux;

	/*
	 * 1- pregunto los datos
	 * 2-los cargo con la funcion set (guarda en la estrucuta)
	 * 3-lo guerdo en la linkedlist
	 * 4-retorno
	 */

	Passenger * pasajeros;

	if(pArrayListPassenger != NULL){

		if(utn_getCaracter(nombreAux, TAM , "Ingrese el nombre", "Error..", REINTENTOS)==0){
			if(utn_getCaracter(apellidoAux, TAM , "Ingrese el apellido", "Error..", REINTENTOS)==0){
				if(utn_getNumeroFloat(&precioAux, "ingrese el precio", "Error", 1 ,1000 , REINTENTOS)==0){
					if(utn_getInt(&tipoPasajeroAux, "ingresar el tipo de pasajero", "error", 1, 100, REINTENTOS)==0){
						if(utn_getCaracter(codigoVueloAux, TAM, "ingrese el  codido de vuelo ", "Error..", REINTENTOS)==0){

								pasajeros=Passenger_new();
								idAux=controller_idFantasma();
								//--------------------------------------------
								Passenger_setNombre(pasajeros, nombreAux);
								Passenger_setApellido(pasajeros, apellidoAux);
								Passenger_setPrecio(pasajeros, precioAux);
								Passenger_setTipoPasajero(pasajeros, tipoPasajeroAux);
								Passenger_setCodigoVuelo(pasajeros, codigoVueloAux);
								Passenger_setId(pasajeros, idAux);
								ll_add(pArrayListPassenger, pasajeros);
								retorno=0;

						}
					}
				}
			}
		}

	}


    return retorno;
}



int controller_buscarId(LinkedList* pArrayListPassenger , int len,int id){
	int retorno=-1;
	int i;
	int idAux;
	Passenger* aux;
	/*
	 * 1-validar los parametros
	 * 2-leer todos los datos
	 * 3-traer el id con ll_get (get -Trae)
	 * 4-traer el id de pasajeros
	 * 5-comparar si son iguales el id de pasajeros y el que ingreso el usuario
	 * 6-guardarlo y retornarlo
	 */

	if(pArrayListPassenger!=NULL && len > 0 && id >= 0 ){

		for(i=0;i<len;i++){

			aux = ll_get(pArrayListPassenger, i);

			Passenger_getId(aux,&idAux);
			if(idAux == id){
				retorno=i;
			}
		}
	}

    return retorno;
}


int controllerPrintInd(Passenger * auxPasajeros,int indice){
	int retorno=-1;
	char nombreAux[TAM];
	char apellidoAux[TAM];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[TAM];
	int idAux;
	/*
	 * 1-traigo los datos de todos los pasajeros
	 * 2-verifico todo
	 * 3-lo muestro
	 * 4-retorno
	 */
	Passenger_getId(auxPasajeros, &idAux);
	Passenger_getNombre(auxPasajeros, nombreAux);
	Passenger_getApellido(auxPasajeros, apellidoAux);
	Passenger_getPrecio(auxPasajeros, &precioAux);
	Passenger_getTipoPasajero(auxPasajeros, &tipoPasajeroAux);
	Passenger_getCodigoVuelo(auxPasajeros, codigoVueloAux);

	if(auxPasajeros != NULL && indice >= 0 ){

		printf("%d,%s,%s,%f,%s,%d\n",idAux,nombreAux,apellidoAux,precioAux,codigoVueloAux,tipoPasajeroAux);
		retorno=0;
	}

	return retorno;

}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int largo;
	int i;
	Passenger * pasajeros;

	/*
	 * 1-valido
	 * 2-saco el largo
	 * 3-leo todos los datos
	 * 4-guardo los datos del linkedlist en un puntero a pasajeros
	 * 5-imprimo cada uno
	 * 6-valido
	 */

	if(pArrayListPassenger!=NULL){

		largo = ll_len(pArrayListPassenger);

		for(i=0;i<largo;i++){

			pasajeros =ll_get(pArrayListPassenger, i);

			controllerPrintInd(pasajeros,i);

			retorno=0;
		}

	}

    return retorno;
}


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno=-1;
	char nombreAux[TAM];
	char apellidoAux[TAM];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[TAM];
	int largo;
	int idBuscado;
	int idModificar;
	int opcion;
	Passenger*pasajeros;
	/*
	 *1-valido
	 *2-veo si hay algo cargado
	 *3-muestro la lista
	 *4-pido el id
	 *5-busco el id
	 *6-traigo el dato del linkedlist
	 *7-imprimo el dato indivudial
	 *8-pido que quiere modificar
	 *9-pido el nuevo dato
	 *10-lo cargo con passenger set
	 *11-valido
	 */

	if(pArrayListPassenger!=NULL){
		largo=ll_len(pArrayListPassenger);

		if(largo != 0){
			controller_ListPassenger(pArrayListPassenger);

			if(utn_getInt(&idModificar, "ingrese el ID", "error", 1, 2000, REINTENTOS)==0){

				idBuscado=controller_buscarId(pArrayListPassenger, largo, idModificar);

				if(idBuscado != 0){

					pasajeros=ll_get(pArrayListPassenger, idBuscado);

					controllerPrintInd(pasajeros,idBuscado);

					selecModificar();
					if(utn_getInt(&opcion, "opcion:\n", "Error\n", 1, 5, REINTENTOS)==0){
						switch(opcion){

							case 1:
								if(utn_getCaracter(nombreAux, TAM, "Ingresa el nombre", "Error", REINTENTOS)==0){
									Passenger_setNombre(pasajeros, nombreAux);
									puts("se modifico correctamente");
									retorno=0;
								}
								break;
							case 2:
								if(utn_getCaracter(apellidoAux, TAM, "Ingresa el apellido", "Error", REINTENTOS)==0){
									Passenger_setApellido(pasajeros, apellidoAux);
									puts("se modifico correctamente");
									retorno=0;
								}

								break;
							case 3:
								if(utn_getNumeroFloat(&precioAux, "Ingrese precio", "Error", 1, 2000, REINTENTOS)==0){
									Passenger_setPrecio(pasajeros, precioAux);
									puts("se modifico correctamente");
									retorno=0;
								}
								break;
							case 4:
								if(utn_getInt(&tipoPasajeroAux, "ingrese el tipo de pasajero", "Error",1, 2000, REINTENTOS)){
									Passenger_setTipoPasajero(pasajeros, tipoPasajeroAux);
									puts("se modifico correctamente");
									retorno=0;
								}
								break;
							case 5:
								if(utn_getCaracter(codigoVueloAux, TAM, "Ingresa el codigoVuelo", "Error", REINTENTOS)==0){
									Passenger_setCodigoVuelo(pasajeros, codigoVueloAux);
									puts("se modifico correctamente");
									retorno=0;
								}
								break;
						}
					}
				}else{
					printf("ese id no existe");
				}

			}else{
				printf("no hay nada cargado");
			}
		}
	}
    return retorno;
}



/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int largo;
	int id;
	int idBuscado;
	/*
	 *1-valido
	 *2-saco el largo
	 *3-muestro las opciones
	 *4-pregunto que id
	 *5-busco el id
	 *6-lo borro
	 *7-retorno
	 */

	if(pArrayListPassenger!=NULL){
		largo=ll_len(pArrayListPassenger);


		printf("%d",largo);



		if(largo!=0){
			controller_ListPassenger(pArrayListPassenger);
			if(utn_getInt(&id, "ingrese el id:", "error\n", 1, 2000, REINTENTOS)==0){
				idBuscado=controller_buscarId(pArrayListPassenger, largo, id);
					if(idBuscado!=0){
						ll_remove(pArrayListPassenger, idBuscado);
						retorno=0;
					}
			}
		}else{
			printf("ese id no existe");
		}
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int largo;
	int opcionSort;
/*
 * 1-validar
 * 2-ver si hay algo cargado
 * 2-preguntar que quiere ordenar
 * 3-usar las funcion ll_sort (parametros: linkedlist, funcion ordenar pasajeros, orden (1 o 0))
 */
	if(pArrayListPassenger != NULL){

		largo=ll_len(pArrayListPassenger);
		if(largo!=0){

			opcionesOrdenar();
			if(utn_getInt(&opcion,"Opcion:\n", "Error\n", 1, 6, REINTENTOS)==0){
				switch(opcion){
					case 1:
						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareById, 1)==0){
										printf("Se ordeno correctamente\n");
										retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareById, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}
						}

						break;
					case 2:
						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareByName, 1)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareByName, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}

						}


						break;
					case 3:
						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareByApellido, 1)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareByApellido, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
									}
							}

						}
					break;
					case 4:
						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareByPrecio, 1)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareByPrecio, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}

						}

					break;
					case 5:
						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareByTipoPsajero, 1)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareByTipoPsajero, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}

						}
					break;
					case 6:
						if(ll_sort(pArrayListPassenger,Passenger_compareByCodigoVuelo, 1)==0){
							printf("Se ordeno correctamente\n");
							retorno=0;
						}

						opcionsort();
						if(utn_getInt(&opcionSort, "opcion:\n", "Error\n",  1, 2, REINTENTOS)==0){
							if(opcion==1){
								if(ll_sort(pArrayListPassenger,Passenger_compareByTipoPsajero, 1)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}else{
								if(ll_sort(pArrayListPassenger,Passenger_compareByTipoPsajero, 0)==0){
									printf("Se ordeno correctamente\n");
									retorno=0;
								}
							}

						}
						break;
				}
			}
		}
	}
    return retorno;
}





/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	char nombre[TAM];
	char apellido[TAM];
	float precio;
	int tipoPasajero;
	char codigoVuelo[TAM];
	int isEmpty;
	int largo;
	int i;

	FILE *pArchivo;//tipo de estructura que me perdite manupular archivo
	Passenger * pasajeros;
	/*
	 * 1-abro el archivo en modo escritura
	 * 2-saco el largo
	 * 3-leo el enunciado
	 * 4-traigo los datos de la linkedlist
	 * 5-los leo con la funcion passenger
	 * 6-los escribo
	 * 7-retorno
	*/
	if(path != NULL && pArrayListPassenger != NULL){
		largo =ll_len(pArrayListPassenger);
		pArchivo=fopen(path,"w");

		if(pArchivo!=NULL){

			fprintf(pArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

			for(i=0;i<largo;i++){

				pasajeros=ll_get(pArrayListPassenger, i);

				Passenger_getId(pasajeros, &id);
				Passenger_getNombre(pasajeros, nombre);
				Passenger_getApellido(pasajeros, apellido);
				Passenger_getPrecio(pasajeros, &precio);
				Passenger_getTipoPasajero(pasajeros, &tipoPasajero);
				Passenger_getCodigoVuelo(pasajeros, codigoVuelo);
				Passenger_getIsEmpty(pasajeros, &isEmpty);

				fprintf(pArchivo,"%d,%s,%s,%f,%s,%d,%d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,isEmpty);
			}
			printf("Se leyo bien\n");
			retorno=0;
		}else{
			printf("Error\n");

		}
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int largo;
	int i;

	FILE *pArchivo;//tipo de estructura que me perdite manupular archivo
	Passenger * pasajeros;
	/*
	 * 1-abro el archivo en modo escritura
	 * 2-saco el largo
	 * 3-leo el enunciado
	 * 4-traigo los datos de la linkedlist
	 * 5-los leo con la funcion passenger
	 * 6-los escribo
	 * 7-retorno
	*/
	if(path!=NULL && pArrayListPassenger){

		largo=ll_len(pArrayListPassenger);

		pArchivo=fopen(path,"wb");

		if(pArchivo!=NULL){

			for(i=0;i<largo;i++){

				pasajeros=ll_get(pArrayListPassenger, i);

				if(pasajeros!=NULL){

					fwrite(pasajeros,sizeof(Passenger),1,pArchivo);
				}

			}
			retorno=0;
		}else{
			printf("Error");
		}
		fclose(pArchivo);
	}
    return retorno;
}

