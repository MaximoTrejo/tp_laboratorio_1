/*
 * biblioteca.h
 *
 *  Created on: 6 abr. 2022
 *      Author: maxim
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#define BTC 4606954.55

float tarjetaDebito(float precio ,int kilometros);
float tarjetaCredito(float precio ,int kilometros);
float totalBtc(float precio);
float precioKilometros(float precio ,int km );
float diferenciaLatAero(float precioKmAero , float precioKmLatam);
void menuInicio(void);
void mostrar(int kilometros,float precioVueloAero,float preciosVueloLatam,float tarjetaDAero,float tarjetaCAero,float btcAero, float precioKmAero,float tarjetaDLatam,float tarjetaCLatam,float btcLatam,float precioKmLatam,float diferencia);
#endif /* BIBLIOTECA_H_ */
