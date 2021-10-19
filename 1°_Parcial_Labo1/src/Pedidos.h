/*
 * Pedidos.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Ignacio
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "GetsUtn_2.h"

#define Alta 1
#define Baja 0

struct
{
	int idPedidos;
	int idClientes;
	float kilos;
	char estado[11];
	int isEmpty;
	float HDPEkg;
	float LDPEg;
	float PPkg;
}typedef ePedidos;

#endif /* PEDIDOS_H_ */

void MostrarUnPeido (ePedidos lista);

int printPedidos (ePedidos* lista, int longitud);

int iniciaPedidos(ePedidos* lista,int longitud);

int CrearPedido (ePedidos* lista, int longitud, int* IdAutomatico);

int findePeidoById (ePedidos* list, int lenght, int id);

int PedidoProcesado (ePedidos* lista, int longitud);
