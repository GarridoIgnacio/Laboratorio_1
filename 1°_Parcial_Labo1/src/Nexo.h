/*
 * Nexo.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Ignacio
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Clientes.h"
#include  "Pedidos.h"

#define Alta 1
#define Baja 0

int printClientesyPedidos (eClientes* listaClientes,ePedidos* listaPeidos ,int longitudClientes,int longitudPeidos);

int CompararListas (eClientes* listaClientes,ePedidos* listaPeidos ,int longitudClientes,int longitudPeidos);


#endif /* NEXO_H_ */
