/*
 * GetsUtn_2.h
 *
 *
 *      Author: Ignacio
 */

#ifndef GETSUTN_2_H_
#define GETSUTN_2_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char PedirChar (char mensaje[]);

int PedirCadena (char* cadena, int longitud);

int PedirInt (int* pResultado);

int PedirFloat (float* pNumero);

int ValidarInt (char* cadena, int limite);

int ValidarFloat (char* cadena, int limite);

int ObtenerIntConLimite (int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

int ObtenerInt (int* pNumero, char* mensaje, char* mensajeError, int intentos);

int ObtenerFloatConLimite (float* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

int ObtenerFloat (float* pNumero, char* mensaje, char* mensajeError,int intentos);

int ValidarSoloLetras (char* cadena, int longitud);

int ObtenerSoloLetras (char* cadena, int longitud, char* mensaje,int intentos);

int ValidarStinrgNum (char* cadena, int limite);

int PedirStringNum (char* cadena, int longitud);

int ObtenerStringNum (char* cadena, int longitud,char* mensaje,char* mensajeError,int intentos );



#endif /* GETSUTN_2_H_ */
