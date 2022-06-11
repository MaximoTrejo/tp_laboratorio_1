/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include"Passenger.h"
#include "utn.h"
#include "menu.h"
#include "parser.h"


Passenger* Passenger_new(){
	Passenger *pasajero;
	/*
	 * La función malloc() devuelve un puntero al tipo de datos void (sin tipo). Dicho puntero
	 * puede ser asignado a una variable puntero de cualquier tipo mediante una conversión forzada
	 * de tipo de datos (casting).
	 */

	//crea un solo pasajero en MEMORIA
	pasajero=(Passenger*)malloc(sizeof(Passenger));

	return pasajero;
}

//devuelve un pasajero en memoria dinamica
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* tipoPasajeroStr,char* precioStr,char* codigoVueloStr,char* isEmptyStr ){

	Passenger *pasajeros=Passenger_new();
	//valido que no haya basura
	if(pasajeros != NULL){
		//llamo funcion para que me guarde el dato en la estructura
		Passenger_setId(pasajeros, atoi(idStr));//cambio id(char) a ententero
		Passenger_setNombre(pasajeros, nombreStr);
		Passenger_setApellido(pasajeros, apellidoStr);
		Passenger_setPrecio(pasajeros, atof(precioStr));
		Passenger_setTipoPasajero(pasajeros, atoi(tipoPasajeroStr));
		Passenger_setCodigoVuelo(pasajeros, codigoVueloStr);
	}
	return pasajeros;
}

void Passenger_delete(Passenger*this){
	free(this);
}
//----------------------------------------------------------ID-------------------------------------------
int Passenger_setId(Passenger* this,int id){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL){
		//guarda el valor id en la variable id de la estructura
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int *id){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL && id != NULL){
		//guarda el valor que ya esta en la estructura en el puntero , el cual caudno termine la funcion puede ser usado
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

//----------------------------------------------------------NOMBRE----------------------------------------
int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		//estoy copiando en la estructura el dato del puntero que viene de parametro
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		//en este caso estoy copiendo en el puntero el dato de la estructura
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

//----------------------------------------------------------APELLIDO--------------------------------------
int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this!=NULL && apellido != NULL){
		//estoy copiando en la estructura el dato del puntero que viene de parametro
		strcpy(this->apellido,apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno=-1;
	if(this!=NULL && apellido != NULL){
		//en este caso estoy copiendo en el puntero el dato de la estructura
		strcpy(apellido,this->apellido);
		retorno=0;
	}
	return retorno;
}

//----------------------------------------------------------CODIGO VUELO----------------------------------------
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
		if(this!=NULL && codigoVuelo != NULL){
			//estoy copiando en la estructura el dato del puntero que viene de parametro
			strcpy(this->codigoVuelo,codigoVuelo);
			retorno=0;
		}
		return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
	if(this!=NULL && codigoVuelo != NULL){
		//en este caso estoy copiendo en el puntero el dato de la estructura
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno=0;
	}
	return retorno;
}

//----------------------------------------------------------TIPO PASAJERO----------------------------------------
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL){
		//guarda el valor id en la variable id de la estructura
		this->tipoPasajero=tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL && tipoPasajero != NULL){
		//guarda el valor que ya esta en la estructura en el puntero , el cual caudno termine la funcion puede ser usado
		*tipoPasajero=this->tipoPasajero;
		retorno=0;
	}
	return retorno;
}

//----------------------------------------------------------PRECIO----------------------------------------

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL){
		//guarda el valor id en la variable id de la estructura
		this->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL && precio != NULL){
		//guarda el valor que ya esta en la estructura en el puntero , el cual caudno termine la funcion puede ser usado
		*precio=this->precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_setIsEmpty(Passenger* this,int isEmpty){
	int retorno=-1;
	//valido que no haya basura
	if(this != NULL){
		//guarda el valor id en la variable id de la estructura
		this->isEmpty=isEmpty;
		retorno=0;
	}
	return retorno;
}


int Passenger_getIsEmpty(Passenger* this,int* isEmpty){
	int retorno=-1;
		//valido que no haya basura
	if(this != NULL && isEmpty != NULL){
		//guarda el valor que ya esta en la estructura en el puntero , el cual caudno termine la funcion puede ser usado
		*isEmpty=this->isEmpty;
		retorno=0;
	}
	return retorno;
}


//-------------------------------------------------------------------------------------------------
/*
 * //funcion que compara //
 * tiene como parametros 2 punteros genericos que para que se transformen
 * hay que castiarlos a pasajeros y de ahi poder llamar a los datos
 */
int Passenger_compareById(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;
	int compara;
	compara=0;//cuando son iguales

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	if(unPasajero->id > otroPasajero->id){
		compara = 1;//cuando p1 es mayor a p2
	}else{
		if(unPasajero->id < otroPasajero->id){
			compara=-1;//cuando p1 es menor a p2
		}
	}
	return compara;
}

int Passenger_compareByName(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	return strcmp(unPasajero->nombre,otroPasajero->nombre);
}

int Passenger_compareByApellido(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	return strcmp(unPasajero->apellido,otroPasajero->apellido);
}


int Passenger_compareByPrecio(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;
	int compara;
	compara=0;//cuando son iguales

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	if(unPasajero->precio > otroPasajero->precio){
		compara = 1;//cuando p1 es mayor a p2
	}else{
		if(unPasajero->precio < otroPasajero->precio){
			compara=-1;//cuando p1 es menor a p2
		}
	}
	return compara;
}

int Passenger_compareByTipoPsajero(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;
	int compara;
	compara=0;//cuando son iguales

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	if(unPasajero->tipoPasajero > otroPasajero->tipoPasajero){
		compara = 1;//cuando p1 es mayor a p2
	}else{
		if(unPasajero->tipoPasajero < otroPasajero->tipoPasajero){
			compara=-1;//cuando p1 es menor a p2
		}
	}
	return compara;
}

int Passenger_compareByCodigoVuelo(void* p1 ,void*p2){
	Passenger* unPasajero;
	Passenger*otroPasajero;

	unPasajero=(Passenger*)p1;
	otroPasajero=(Passenger*)p2;

	return strcmp(unPasajero->codigoVuelo,otroPasajero->codigoVuelo);
}

//-------------------------------------------------------------------------------------------------------------
