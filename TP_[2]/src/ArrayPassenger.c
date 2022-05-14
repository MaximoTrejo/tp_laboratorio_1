/*
 * pasajeros.c
 *
 *  Created on: 26 abr. 2022
 *      Author: maxim
 */

#include "ArrayPassenger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

static int dameUnIdNuevo(void);
static void printPassengers(passenger pasajeros);
static int seleccionarModificar(int *seleccionarMod);
static int seleccionarAsDes(void);
//static int estadoVuelo(void);

//---------------------------------------------------------INICIALIZAR---------------------------------
int  initPassengers(passenger list[],int tam){

	int i;
	int retorno= -1;
	if(list != NULL && tam > 0){

		for(i=0;i<tam;i++){
			list[i].isEmpty= LIBRE;
		}
		retorno=0;
	}
	return retorno;
}

//-------------------------------------------------------HARCODEO---------------------------------
void harcodeo(passenger lista[],int tam){
	passenger carga[4]={
			{1,"maximo","apellido",5,"vuelo1",3,1,1},
			{2,"german","apellido",5,"vuelo2",1,1,1},
			{3,"marina","apellido",5,"vuelo3",2,0,1},
			{4,"facu  ","apellido",5,"vuelo4",4,1,1},
					}; //harcodeo (cargo manual)

	for(int i=0; i<4; i++){
		lista[i]=carga[i];
	}

}
//--------------------------------------------------------------ALTA-----------------------------------------
int addPassenger(passenger list[]){
int retorno=-1;
char nombreAux[TAM];
char apellidoAux[TAM];
float priceAux;
int typePassengerAux;
char flycodeAux[CODV];

if(list != NULL){
	if(utn_getCaracter(nombreAux, TAM , "Ingrese el nombre", "Error..", REINTENTOS)==0){
		if(utn_getCaracter(apellidoAux, TAM , "Ingrese el apellido", "Error..", REINTENTOS)==0){
			if(utn_getNumeroFloat(&priceAux, "ingrese el precio", "Error", 1 ,1000 , REINTENTOS)==0){
				if(utn_getInt(&typePassengerAux, "ingresar el tipo de pasajero", "error", 1, 100, REINTENTOS)==0){
					if(utn_getCaracter(flycodeAux, CODV, "ingrese el  codido de vuelo ", "Error..", REINTENTOS)==0){

						strncpy(list ->name,nombreAux,sizeof (list->name));
						strncpy(list ->lastname,apellidoAux,sizeof (list->lastname));
						list->price=priceAux;
						list->typrPassenger=typePassengerAux;
						strncpy(list ->flycode,flycodeAux,sizeof (list->flycode));
						list->id =dameUnIdNuevo();
						list->isEmpty=OCUPADO;
						list->statusFlight= ACTIVO;//estadoVuelo();
						retorno=0;

					}
				}
			}

		}
	}
}

return retorno;
}
//-------------------------------------------------------------------------INFORMES----------------------------------------------------
int totalInforme(passenger list[], int len,float*promedio){
	int retorno=0;
	int contTotal=0;
	int contPasajeros=0;
	if(list != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				contTotal=contTotal+list[i].price;
				contPasajeros++;
				retorno=contTotal;
			}
		}

		*promedio=promedioInforme(contPasajeros,contTotal);
	}

	return retorno;
}

float promedioInforme(int contPasajeros , int totalPasajeros ){
	float retorno=0;
	if(contPasajeros>0 && totalPasajeros>0){
		retorno=(float)totalPasajeros/contPasajeros;
	}

	return retorno;
}

int superPasajeros(passenger list[], int len, float promedio){
	int retorno=0;
	int contSuperPas=0;
	if(list != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==OCUPADO){
				if(list[i].price > promedio){
					contSuperPas++;
					retorno=contSuperPas;
				}
			}
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------------------ID--------------------------
/*
static int estadoVuelo(void){
	int estado;
	int retorno;
	srand(time(NULL));
	estado= 1 +rand()%2;//1+ es para saber que empieza en el 1 y el %3 que son hasta el 10
	if(estado==1){
		retorno=ACTIVO;
	}else{
		retorno=DESACTIVADO;
	}
	return retorno;
}
*/

static int dameUnIdNuevo(void) //privada del archivo
{
	static int contador=4;
	contador++;//es global : mantiene su valor
	return contador;
}
//----------------------------------------------------------------------------BUSCAR ID---------------------------------------


int findPassengerById(passenger list[], int len,int id){

int retorno=-1;
int i;

if(list !=NULL && len > 0 && id >= 0)
{
	for(i=0; i<len ; i++)
	{
		if(list[i].id==id && list[i].isEmpty == OCUPADO)
		{
			retorno = i;
			break;
		}
	}
}

return retorno;//retorna el id (si hay un error retorna -1)
}
//-------------------------------------------------------------------BAJA------------------------------------------------


int removePassenger(passenger list[], int len, int id){
int retorno=-1;
int i;
int confirmar;

	for(i=0; i<len; i++){
		if(list[i].id == id && list[i].isEmpty == OCUPADO ){
			if(utn_getInt(&confirmar, "Dar de baja?[1(S)|2(N)]", "Error\n", 1, 2, REINTENTOS)==0){
				if(confirmar==1){
					list[i].isEmpty=LIBRE;
					printf("Los datos han sido borrado...\n");
					retorno=0;
				}else{
					printf("Los datos no han sido borrado...\n");
				}
				break;
			}
		}
	}

return retorno;
}
//---------------------------------------------------------------------IMPRIMIR-------------------------------------------------


static void printPassengers(passenger pasajeros){
	printf("%d\t|%s\t|%s\t|%f\t\t%d\t|%s\t\t|%d \n" , pasajeros.id , pasajeros.name ,pasajeros.lastname,pasajeros.price,pasajeros.typrPassenger,pasajeros.flycode,pasajeros.statusFlight);
}



int imprimir (passenger list[], int tam) {
int rtn= -1;
int i;

if(list != NULL && tam > 0 ) {
	for(i=0; i<tam; i++) {
		if(list[i].isEmpty==OCUPADO){

			printPassengers(list[i]);
		}
	}
}
return rtn;
}
//----------------------------------------------------------------------MODIFICAR--------------------------------------------------


int modificarPasajeros(passenger list[] ,int len,int idMod){

	int retorno=-1;
	int campoMod;
	char auxlist[TAM];
	float auxF;
	int auxInt;
	if(list !=NULL){

		if(seleccionarModificar(&campoMod)==0){

			switch(campoMod){

			case 1:
				if(utn_getCaracter(auxlist, len, "Ingresa el nombre", "Error", REINTENTOS)==0){
					strcpy(list[idMod].name ,auxlist);
					puts("se modifico correctamente");
					retorno=0;
				}
				break;
			case 2:
				if(utn_getCaracter(auxlist, len, "Ingresa el apellido", "Error", REINTENTOS)==0){
					strcpy(list[idMod].lastname ,auxlist);
					puts("se modifico correctamente");
					retorno=0;
				}

				break;
			case 3:
				if(utn_getNumeroFloat(&auxF, "Ingrese precio", "Error", 1, 2000, REINTENTOS)==0){
					list[idMod].price = auxF;
					puts("se modifico correctamente");
					retorno=0;
				}
				break;
			case 4:
				if(utn_getInt(&auxInt, "ingrese el tipo de pasajero", "Error",1, 2000, REINTENTOS)){
					list[idMod].typrPassenger = auxInt;
					puts("se modifico correctamente");
					retorno=0;
				}


				break;
			case 5:
				if(utn_getCaracter(auxlist, len, "Ingresa el apellido", "Error", REINTENTOS)==0){
					strcpy(list[idMod].flycode ,auxlist);
					puts("se modifico correctamente");
					retorno=0;
				}

				break;
			}
		}
	}
	return retorno;
}


static int seleccionarModificar(int *seleccionarMod){
	int retorno=-1;
	int auxSelecion;

	selecModificar();
	if(utn_getInt(&auxSelecion, "\nElegi la opcion:","error", 1, 5, REINTENTOS)==0){
		retorno=0;
		*seleccionarMod=auxSelecion;
	}
	return retorno;
}


int bucarLibre(passenger pPasajeros[], int len)
{
	int retorno=-1;
	int i;

	if(pPasajeros !=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pPasajeros[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//------------------------------------------------------------------------------------INFORME----------------------------------------------------------------------------------------------------------
static int seleccionarAsDes(void){
	int retorno;
	int auxSelec;
	if(utn_getInt(&auxSelec, "\n0)Ordenar ascendente:\n1)ordenar descendente:\nOpcion:", "Error", 0, 1, REINTENTOS)==0){
		retorno=auxSelec;
	}
	return retorno;
}
//---------------------------------------------------------------------------------------------------------ORDENAR-------------------------------------------------------


//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
int sortPassengers(passenger* list, int len, int order)
{
	int retorno=-1;
	passenger aux;
	int i;
	int j;
	if(order==0){//asendente
		for(i=0;i<len-1; i++){

			for(j=i+1;j<len; j++){
				if((strncmp(list[i].lastname,list[j].lastname,TAM) > 0) || (strncmp(list[i].lastname,list[j].lastname,TAM)== 0 && list[i].typrPassenger > list[j].typrPassenger)){
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
					retorno=0;
				}
			}
		}


	}else{//desendente

		for(i=0;i<len-1; i++){

			for(j=i+1;j<len; j++){
				if((strncmp(list[i].lastname,list[j].lastname,TAM) < 0) || (strncmp(list[i].lastname,list[j].lastname,TAM)== 0 && list[i].typrPassenger < list[j].typrPassenger)){
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
						retorno=0;
					}
				}
			}
	}

	return retorno;
}


//Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
int sortPassengersByCode(passenger* list, int len, int order){

	int retorno=-1;
		passenger aux;
		int i;
		int j;
		if(order==0){//asendente
			for(i=0;i<len-1; i++){

				for(j=i+1;j<len; j++){
					if((strncmp(list[i].flycode,list[j].flycode,CODV) > 0) || (strncmp(list[i].flycode,list[j].flycode,CODV)== 0 && list[i].statusFlight > list[j].statusFlight)){ // **
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
						retorno=0;
					}
				}
			}


		}else{//desendente

			for(i=0;i<len-1; i++){

				for(j=i+1;j<len; j++){
					if((strncmp(list[i].flycode,list[j].flycode,CODV) < 0) || (strncmp(list[i].flycode,list[j].flycode,CODV)== 0 && list[i].statusFlight < list[j].statusFlight)){
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
							retorno=0;
						}
					}
				}
		}


	return retorno;
}

//--------------------------------------------------------------------------------------MENU-----------------------------------------------------------------------
void menuPasajeros(passenger list[], int len){

	int opcion;
	int lugarLibre;
	int flagPrimerVuelo=1;
	int opcionAsDes;
	int opcionInforme;
	int total;
	float promedioInforme;//puntero
	int superPas;
	do{

		menu();
		if(utn_getInt(&opcion,"\nOpcion:", "la opcion ingresada es incorrecta...", 1 , 5, REINTENTOS)==0){}

		switch(opcion){
		case 1:
			//alta
			lugarLibre = bucarLibre(list, len);
			addPassenger(&list[lugarLibre]);
			flagPrimerVuelo=1;
			break;
		case 2:
			//modificar
			if(flagPrimerVuelo==1){
				//muestro todo el array
				printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
				for(int i=0;i<len;i++){
					if(list[i].isEmpty==OCUPADO){
						printPassengers(list[i]);
					}
				}
				//-----------PARTE DE COMIFICACION------------------
				int idIngresado;
				int idModificar;
				if(utn_getInt(&idIngresado, "\ningrese id", "error", 0, 2000, REINTENTOS)==0){
					idModificar= findPassengerById(list,len,idIngresado);
					if(idModificar >= 0){

						modificarPasajeros(list, len, idModificar);
						//pasajeros.id , pasajeros.name ,pasajeros.lastname,pasajeros.price,pasajeros.typrPassenger,pasajeros.flycode,pasajeros.statusFlight);
						printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
						printPassengers(list[idModificar]);
					}else{
						printf("el id no existe");
					}
				}
			}else{
				printf("no hay empleados cargados");
			}

			break;
		case 3:
			//baja
			if(flagPrimerVuelo==1){
				printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
				imprimir(list, len);
				//-------------BAJA---------------------
				int auxCodigo;
				if(utn_getInt(&auxCodigo, "\nIngrese el id", "Error\n", 1, 2000, REINTENTOS)==0){
					removePassenger(list, len, auxCodigo);
				}

			}else{
				printf("no hay empleados cargados");
			}

			break;
		case 4:
			if(flagPrimerVuelo==1){

				opcionesInformes();
				if(utn_getInt(&opcionInforme, "Opcion:", "Error\n", 1, 4, REINTENTOS)==0){
					switch(opcionInforme){
					case 1:
						if(seleccionarAsDes()==0){//asendente
							opcionAsDes=0;
							if(sortPassengers(list,len ,opcionAsDes)==0){
								printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
								imprimir(list, len);
							}
						}else{//descendente
							opcionAsDes=1;
							if(sortPassengers(list,len ,opcionAsDes)==0){
								printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
								imprimir(list, len);
							}
						}
						break;
					case 2:
						total=totalInforme(list,len,&promedioInforme);

						superPas=superPasajeros(list, len, promedioInforme);


						printf("El total de precios es  %d \n",total);
						printf("El promedio de precios es %f",promedioInforme);
						printf("\nLa cantidad de pasajeros que superan al promedio es %d\n\n",superPas);
						break;
					case 3:
						if(seleccionarAsDes()==0){//asendente
							opcionAsDes=0;
								if(sortPassengersByCode(list,len ,opcionAsDes)==0){
									printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
									imprimir(list, len);
								}
						}else{//descendente
							opcionAsDes=1;
								if(sortPassengersByCode(list,len ,opcionAsDes)==0){
									printf("ID\tNOMBRE\tAPELLIDO\tPRECIO\t\tTIPO PASAJERO\tCODIGO VUELO\tESTADO VUELO\n");
									imprimir(list, len);
								}
						}
						break;
					case 4:
						break;
					}
				}
			}else{
				printf("no hay empleados cargados");
			}
			break;
		case 5:
			opcion=5;
			break;
		}
	}while(opcion != 5);
}

//--------------------------------------------------------------ENUNCIADOS------------------------------------------------------------------------------------------------


void opcionesInformes(){
    printf("\nMenu de informes"
            "\n1. Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero."
            "\n2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio."
            "\n3. Listado de pasajeros por Codigo de vuelo y estado de vuelo Activo."
            "\n4. Salir.\n");
}


void menu (){
	printf("Bienvenido");
    printf("\n1) Alta.");
    printf("\n2) Modificacion.");
    printf("\n3) Baja.");
    printf("\n4) Informar.");
    printf("\n5) Salir.");
}


void selecModificar(){
	printf("\n1-nombre");
	printf("\n2-apellido");
	printf("\n3-Precio");
	printf("\n4-TipoPasajero");
	printf("\n5-CodigoVuelo");
}

