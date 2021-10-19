/*
 * Pedidos.c
 *
 *
 *      Author: Ignacio
 */

#include "Pedidos.h"


int iniciaPedidos(ePedidos* lista,int longitud)
{
	int i;
	int retorno;

	retorno=-1;

	if(lista!=NULL && longitud>0)
	{
		for(i=0; i<longitud; i++)
		{
			if(lista[i].isEmpty!=Alta)
			{
				lista[i].isEmpty=Baja;
				retorno=0;
			}
		}
	}
	return retorno;
}


void MostrarUnPeido (ePedidos lista)
{

		printf("\n %2d %15d %18.3f %18s ",lista.idPedidos,lista.idClientes,lista.kilos,lista.estado);

}

int printPedidos (ePedidos* lista, int longitud)
{
	int i;
	int retorno;

	retorno=-1;
	printf(" ID Pedido     ID Cliente       Peso en Kg         Estado   \n");
	for(i=0;i<longitud;i++)
	{
		if(lista[i].isEmpty==Alta)
		{
			MostrarUnPeido(lista[i]);
			retorno=0;
		}
	}

	return retorno;
}

int CrearPedido (ePedidos* lista, int longitud, int* IdAutomatico)
{
	int retorno;
	int i;
	int auxI;
	int idAux;

	retorno=-1;
	auxI=-5;
	idAux=*IdAutomatico;

	if (lista!=NULL && longitud>0)
	{
		for(i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==Baja)
			{
				auxI=i;
				break;
			}
		}
		if(auxI!=-5)
		{
			lista[i].idPedidos=idAux;
			if(!ObtenerIntConLimite(&lista[auxI].idClientes, "Ingrese el ID del Cliente: ", "--Error-- ID Invalido.", 100, 999, 3))
			{
				if(!ObtenerFloat(&lista[auxI].kilos, "Ingrese la cantidad en Kg a recoletar: ", "--Error-- Cantidad Invalida.", 3))
				{

					strncpy(lista[auxI].estado,"PENDIENTE",sizeof(lista[auxI].estado));

					lista[auxI].isEmpty=Alta;
					retorno=0;
					idAux++;
					*IdAutomatico=idAux;

				}
			}
			else{
				printf("\n\n\n\t Se agotaron los intentos...\n");
			}
		}
	}

	return retorno;
}

int findePeidoById (ePedidos* list, int lenght, int id)
{
	int i;
	int retorno;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].idPedidos==id)
			{
				printf(" ID Pedido     ID Cliente       Peso en Kg         Estado   \n");
				MostrarUnPeido(list[i]);
				retorno=0;
			}
		}
		if(retorno!=0)
		{
			printf("\n--Error. ID invalida.----");
		}
	}

	return retorno;
}

int PedidoProcesado (ePedidos* lista, int longitud)
{
	int retorno;
	int i;
	int idPedido;

	retorno=-1;

	if(lista!=NULL && longitud>0)
	{
		printPedidos(lista, longitud);
		if(!ObtenerIntConLimite(&idPedido, "Ingrese el ID del Pedido: ", "--Error-- ID Invalido ", 1000, 9999, 3)&&
		   !findePeidoById(lista, longitud, idPedido))
		{
			for(i=0;i<longitud;i++)
			{
				if(lista[i].idPedidos==idPedido && lista[i].isEmpty!=Baja)
				{
					ObtenerFloat(&lista[i].HDPEkg, "Ingrese la cantidad en Kg de HDPE procesado: ", "--Error- Peso Invalido", 3);
					ObtenerFloat(&lista[i].LDPEg, "Ingrese la cantidad en Kg de LDPE procesado: ", "--Error- Peso Invalido", 3);
					ObtenerFloat(&lista[i].PPkg, "Ingrese la cantidad en Kg de PP procesado: ", "--Error- Peso Invalido", 3);
					strncpy(lista[i].estado,"Completado",sizeof(lista[i].estado));
					retorno=0;
				}
			}

		}

	}

	return retorno;
}

































