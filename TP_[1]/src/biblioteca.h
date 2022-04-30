/*
 * biblioteca.h
 *
 *  Created on: 6 abr. 2022
 *      Author: maxim
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#define BTC 4606954.55


////@fn float tarjetaDebito(float)
////@brief funcion para saber el precio de un vuelo al pagar con tarjera de debito
///
////@param precio(es el precio del vuelo) kilometros(kilometros ingresados)
////@return precio del vuelo pagando con debito
float tarjetaDebito(float precio ,int kilometros);

////@fn float tarjetaCredito(float)
////@brief funcion para saber el precio de un vuelo al pagar con tarjera de credito
///
////@param precio(es el precio del vuelo) kilometros(kilometros ingresados)
////@return precio del  vuelo pagando con credito
float tarjetaCredito(float precio ,int kilometros);

////@fn float totalBtc(float)
////@brief funcion para saber el precio de un vuelo al pagar con bitcoin
///
////@param precio(es el precio del vuelo)
////@return precio del vuelo pagando con BTC
float totalBtc(float precio);

////@fn float precioKilometros(float)
////@brief funcion para saber el precio unitario de cada vuelo
///
////@param precio(es el precio del producto) kilometros(kilometros ingresados)
////@return el precio unitario
float precioKilometros(float precio ,int km );

////@fn float diferenciaLatAero(float)
////@brief funcion para saber la diferencia entre las opciones de vuelo
///
////@param precioKmAero(es el precio de Aerolineas)precioKmLatam(es el precio de Latam)
////@return la diferencia entre las opciones de vuelo
float diferenciaLatAero(float precioKmAero , float precioKmLatam);


////@fn void menuInicio(void)
////@brief funcion para pedir datos
///
////@param void
////@return void
void menuInicio(void);

////@fn void mostrar(int ,float,float ,float , float ,float,float,float ,float , float ,float,float,float ,float)
////@brief funcion para mostrar resultados
///
////@param int kilometros,float precioVueloAero,float preciosVueloLatam,float tarjetaDAero,float tarjetaCAero,float btcAero, float precioKmAero,float tarjetaDLatam,float tarjetaCLatam,float btcLatam,float precioKmLatam,float diferencia
////@return void
void mostrar(int kilometros,float precioVueloAero,float preciosVueloLatam,float tarjetaDAero,float tarjetaCAero,float btcAero, float precioKmAero,float tarjetaDLatam,float tarjetaCLatam,float btcLatam,float precioKmLatam,float diferencia);
#endif /* BIBLIOTECA_H_ */
