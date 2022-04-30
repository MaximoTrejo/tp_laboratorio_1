/*
 * funciones.c
 *
 *  Created on: 3 abr. 2022
 *      Author: maxim
 */


#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//para el strlen
#include <ctype.h>

static int getInt(int * pResultado);
static int esNumerica(char* cadena,int limite);

static int getFloat (float* pResultado);
static int esNumericaF (char* cadena);
static int myGetsF (char* cadena, int longitud);

static int esTexto (char* cadena);
static int myGetsCaracter (char* cadena, int longitud);
/*
//brief obtiene un numero entero
//paran pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
//return Retorna 0 (EXITO) si se obtiene un nunero entero y -1 (ERROR) si no
*/
static int getInt(int * pResultado){
  int retorno=-1;
  char bufferString[50];

  if(pResultado != NULL){

	  if(myGetsInt(bufferString,sizeof(bufferString))== 0){
		  /////
		if(esNumerica(bufferString,sizeof(bufferString))==1){
			retorno=0;
			*pResultado=atoi(bufferString);//covierte un array de caracteres un string en un numero integer(entero)
		}
	  }
  }
  return retorno;
}

/*
//brief Verifica si la cadena ingresada es numerica
//param cadena Cadena de caracteres a ser analizada
//return Retorna 1 (EXITO) si la cadena es numerica y 0 (MALO) si no lo es y -1 en caso de error de parametros
*/

static int esNumerica(char* cadena , int limite){//LIMITE POR SI YO PONGO MAL
 int retorno = -1;//MAL

 if(cadena!=NULL && limite >0){

	 retorno=1;//exito

	 for(int i=0; i<limite && cadena[i] != '\0'; i++){ // va vacio porque la inicializacion del for depende de la condicion del if de arriba

	 	 if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
	 		 continue;//hace q se saltee el resto y vuelve al bucle
	 	 }
	 	 if(cadena[i] > '9' || cadena[i] < '0'){//si esta mal estra
	 		 retorno=0;//MUY MALO
	 		 break;
	 	 }
	  }
 }
 return retorno;
}



//brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
//      un máximo de 'longitud - 1' caracteres.
//paran pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
//paran Longitud Define el tamaño de cadena
//return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no

int myGetsInt(char *cadena,int longitud){
	int retorno=-1;
	char bufferString[4096];//**********DUDOSA CALIDAD*********
	//char*bufferString =malloc(sizeof(char)*longitud) //MAS ADELANTE
	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] =='\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] ='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/*
• \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
* \paran pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
• \paran mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param minimo Es el numero maximo a ser aceptado
* \param maximo Es el minino minimo a ser aceptado
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

	int retorno=-1;
	int bufferInt;//espacio auxiliar
	if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		do{
		   printf("%s", mensaje);
		   if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo){
		       *pResultado = bufferInt;
		       retorno = 0;
		       break;
		   }
		   reintentos--;
		   printf("%s" ,mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;

}


//-------------------------------------------------FUNCIONES VIEJAS --------------------------------------------------------------------


int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float bufferFloat=-1;
	int retorno;
	int i;

	if (minimo<maximo)
	{
		for (i = 0; i <= reintentos; i++)
		{
			if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos != 0)
			{
				printf ("%s", mensaje);
				if (getFloat (&bufferFloat) == 0 && bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					retorno = 1;
					printf ("%s\n",mensajeError);
				}
			}
		}
	}
	return retorno;
}

static int getFloat (float* pResultado)
{
	int retorno;
	char buffer [7500];
	if (myGetsF(buffer, sizeof (buffer))== 0 && esNumericaF(buffer))
	{
		retorno = 0;
		*pResultado = atof(buffer); //se transforma el dato string a un tipo de dato float
	}
	return retorno;
}

static int esNumericaF (char* cadena)
{
	int retorno = 1;
	int i=0;
	int contSigno = 0;
	int contPuntos = 0;
	while (cadena [i] != '\0' && (retorno == 1))
	{
		if (cadena [i] == '-')
		{
			contSigno++;
		}
		if (cadena [i] == '.')
		{
			contPuntos++;
		}
		if (isdigit (cadena [i]) || (cadena [0] == '-') || (cadena [i] == '.')){
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
		i++;
	}
	if (contSigno > 1 || contPuntos > 1){
		retorno = 0;
	}
	return retorno;
}

static int myGetsF (char* cadena, int longitud)
{

	fflush(stdin);
		//stdin lee el archivo temporal de lo que ingresa el usuario por consola
					//longitud de hasta donde leer
	fgets (cadena, longitud, stdin); //esto sirve para reemplazar el scanf
	cadena [strlen (cadena) - 1] = '\0';

	return 0;

}

//-------------------------------------------------FUNCIONES VIEJAS --------------------------------------------------------------------


int utn_getCaracter(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
    int retorno = -1;
    int i;
    for(i=0; i<=reintentos; i++)
    {
        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            printf("%s", mensaje);
            if ((myGetsCaracter(pResultado, len)==0) && esTexto(pResultado) ==0)
            {
            	if(strnlen(pResultado,len)>0)
            	{
            		retorno=0;
            		break;
            	}
            	 else
				{
					printf("%s", mensajeError);
				}
            }
            else
            {
			   printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

static int myGetsCaracter (char* cadena, int longitud)
{
	int indexFInal;
	fflush(stdin);
		//stdin lee el archivo temporal de lo que ingresa el usuario por consola
					//longitud de hasta donde leer
	fgets (cadena, longitud, stdin); //esto sirve para reemplazar el scanf
	indexFInal = strlen (cadena) - 1;

	if (cadena [indexFInal] == '\n')
		{
			cadena [indexFInal] = '\0';
 		}
	return 0;
}

static int esTexto (char* cadena)
{
	int retorno = 0;
	int i=0;
	int strelenCadena;

	strelenCadena = strlen (cadena);

	while (i<strelenCadena && retorno == 0)
	{
		if (isalpha(cadena [i]) != 0)
		{
			i++;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}
