/*
 * Clientes.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Ignacio
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "GetsUtn_2.h"

#define Alta 1
#define Baja 0


struct
{
	int idCliente;
	char cuit[12];
	char direccion[51];
	char localidad[51];
	int isEmpty;
}typedef eClientes;


int iniciaClientes(eClientes* lista,int longitud);

void MostrarUnEmp (eClientes lista);

int printClientes (eClientes* lista, int longitud);

//int AutoIncrementIDCliente (eClientes* list, int lenght, int* idAutomatico);

int CargaCliente (eClientes* lista, int longitud, int* IdAutomatico);

int findeClienteById (eClientes* list, int lenght, int id);

int ModificarCliente (eClientes* list, int lenght);

int removeCliente (eClientes* list, int lenght, int id);

int BajaCliente(eClientes* list, int lenght);





#endif /* CLIENTES_H_ */
