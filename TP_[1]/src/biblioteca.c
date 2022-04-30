/*
 * biblioteca.c
 *
 *  Created on: 6 abr. 2022
 *      Author: maxim
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


void menuInicio(){
	//VARIABLES
	int opcion;
	char seguir;
	int km;
	char vuelo;
	//variables cuando cargan precios
	float precioVueloLatam;
	float precioVueloAero;
	//variables para verificar que estan cargados los 2 tipo de precio vuelo
	int flagAerolineas=0;
	int flagLatam=0;
	int flagKm=0;
	int flagSalir=0;
	//todas las de calcular
	float tarjetaCAero;
	float tarjetaDAero;
	float tarjetaCLatam;
	float tarjetaDLatam;
	float btcLatam;
	float btcAero;
	float precioKmLatam;
	float precioKmAero;
	float diferencia;
	//bucle


		do {

				printf("1.Km");
				printf("\n2.Precio vuelo");
				printf("\n3.Calcular todos los costos:");
				printf("\n4.Informar Resultados");
				printf("\n5.Carga forzada de datos");
				printf("\n6.Salir");
				printf("\nElegi una opcion: ");
				scanf("%d",&opcion);

				switch(opcion){
				case 1:
					printf("\nIngresa km");
					scanf("%d" , &km);

					flagKm=1;
					flagAerolineas=0;
					flagLatam=0;
				break;
				case 2:
					printf("Precio vuelo(Aerolineas o latam)");
					fflush(stdin);
					scanf("%c",&vuelo);

					switch(vuelo){
						case 'A':
							printf("Ingresa el precio de Aerolineas");
							scanf("%f", &precioVueloAero);
							flagAerolineas=1;
						break;

						case 'L':
							printf("Ingresa el precio de Latam");
							scanf("%f", &precioVueloLatam);
							flagLatam=1;
						break;
					}
				break;
				case 3:
					if(flagKm==1){
							if(flagAerolineas==1){
								if (flagLatam == 1) {
									//Aero
									tarjetaDAero = tarjetaDebito(precioVueloAero, km);
									tarjetaCAero = tarjetaCredito(precioVueloAero, km);
									btcAero = totalBtc(precioVueloAero);
									precioKmAero = precioKilometros(precioVueloAero, km);
									//LATAM
									tarjetaDLatam = tarjetaDebito(precioVueloLatam, km);
									tarjetaCLatam = tarjetaCredito(precioVueloLatam, km);
									btcLatam = totalBtc(precioVueloLatam);
									precioKmLatam = precioKilometros(precioVueloLatam, km);
									//----------------
									diferencia = diferenciaLatAero(precioKmAero,precioKmLatam);

									printf("\nSe han calculado todos los costos..\n");
								}else{
									printf("\nFalta precios de latam");
								}
							}else{
								printf("\nFalta precios de aerolineas\n");
							}
					}else{
						printf("\nFaltan Km");
					}

				break;
				case 4:
					mostrar(km,precioVueloAero,precioVueloLatam,tarjetaDAero,tarjetaCAero,btcAero,precioKmAero,tarjetaDLatam,tarjetaCLatam,btcLatam,precioKmLatam,diferencia);
				break;

				case 5:
					km=7090;
					precioVueloAero=162965;
					precioVueloLatam=159339;

					//Aero
					tarjetaDAero = tarjetaDebito(precioVueloAero, km);
					tarjetaCAero = tarjetaCredito(precioVueloAero, km);
					btcAero = totalBtc(precioVueloAero);
					precioKmAero = precioKilometros(precioVueloAero, km);
					//LATAM
					tarjetaDLatam = tarjetaDebito(precioVueloLatam, km);
					tarjetaCLatam = tarjetaCredito(precioVueloLatam, km);
					btcLatam = totalBtc(precioVueloLatam);
					precioKmLatam = precioKilometros(precioVueloLatam, km);
					//----------------
					diferencia = diferenciaLatAero(precioKmAero, precioKmLatam);

					mostrar(km,precioVueloAero,precioVueloLatam,tarjetaDAero,tarjetaCAero,btcAero,precioKmAero,tarjetaDLatam,tarjetaCLatam,btcLatam,precioKmLatam,diferencia);

				break;

				case 6:
					flagSalir=1;
					break;
				break;
				}

				if(flagSalir==0){
					printf("\nDesea cargar mas datos : ");
					fflush(stdin);
					scanf("%c" , &seguir);

				}else{
					break;
				}
			}while(seguir =='s'||seguir =='S' );
}



void mostrar(int kilometros,float precioVueloAero,float preciosVueloLatam,float tarjetaDAero,float tarjetaCAero,float btcAero, float precioKmAero,float tarjetaDLatam,float tarjetaCLatam,float btcLatam,float precioKmLatam,float diferencia){
	printf("\nKms Ingresados: %d", kilometros);
	//AERO
	printf("\nPrecio Aerolineas : $%f",precioVueloAero);
	printf("\na)Precio con tarjeta de debito $%f" , tarjetaDAero);
	printf("\nb)Precio con tarjeta de credito $%f" ,tarjetaCAero);
	printf("\nc)Precio pagando con bitcoin $%f", btcAero);
	printf("\nd)Mostrar precio unitario : $%f",precioKmAero);
	//LATAM
	printf("\nPrecio Latam : $%f",preciosVueloLatam);
	printf("\na)Precio con tarjeta de debito $%f", tarjetaDLatam);
	printf("\nb)Precio con tarjeta de credito $%f",tarjetaCLatam);
	printf("\nc)Precio pagando con bitcoin $%f",btcLatam );
	printf("\nd)Mostrar precio unitario : $%f", precioKmLatam);
	//------
	printf("\nLa diferencia de precio es %f\n" , diferencia  );
}


float tarjetaDebito(float precio ,int kilometros){
	float retorno;
	float total;
	total= precio*kilometros;
	retorno = total-(10*total/100);
	return retorno;
}

float tarjetaCredito(float precio ,int kilometros){
	float retorno;
	float total;
	total = precio*kilometros;
	retorno=total+(25*total/100);
	return retorno;
}

float totalBtc(float precio){
	float total;
	total = precio* BTC;
	return total;
}

float precioKilometros(float precio ,int km ){
	float total;
	total= precio*km;
	return total;
}

float diferenciaLatAero(float precioKmAero , float precioKmLatam){
	float diferencia;
	if(precioKmAero < precioKmLatam){
		diferencia=precioKmLatam-precioKmAero;
	}else{
		diferencia=precioKmAero-precioKmLatam;
	}
	return diferencia;
}

