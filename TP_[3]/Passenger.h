/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define REINTENTOS 5
#define TAM 500

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;//ger puso un char pero es int
	char codigoVuelo[4];
	int isEmpty;

}Passenger;


//constructores
Passenger* Passenger_new();//usar para leer un archivo binario
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* tipoPasajeroStr,char* precioStr,char* codigoVueloStr,char* isEmptyStr );
//----------------------------------------------------------------
//llama a free
void Passenger_delete(Passenger*);

int Passenger_setId(Passenger* this,int id);//guarda
int Passenger_getId(Passenger* this,int* id);//trae

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setIsEmpty(Passenger* this,int isEmpty);
int Passenger_getIsEmpty(Passenger* this,int* isEmpty);

//-----------------------------------------------------------------
int Passenger_compareByName(void*p1,void*p2);
int Passenger_compareById(void* p1 ,void*p2);
int Passenger_compareByApellido(void* p1 ,void*p2);
int Passenger_compareByPrecio(void* p1 ,void*p2);
int Passenger_compareByTipoPsajero(void* p1 ,void*p2);
int Passenger_compareByCodigoVuelo(void* p1 ,void*p2);
//-----------------------------------------------------------------

int controllerPrintInd(Passenger * auxPasajeros,int indice);


#endif /* PASSENGER_H_ */
