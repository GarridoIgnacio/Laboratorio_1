/*
 * Nexo.c
 *
 *
 *      Author: Ignacio
 */


#include "Nexo.h"


/*int MostararUnoClientesyPedidos (eClientes* listaClientes,ePedidos* listaPeidos)
{
	int i;
	int j;
	int retorno;

	retorno=-1;


		retorno=0;


	return retorno;
}
*/

int CompararListas (eClientes* listaClientes,ePedidos* listaPeidos ,int longitudClientes,int longitudPeidos)
{
	int i;
	int j;
	int retorno;

	retorno=-1;
	printf("\n  ID Cliente         CIUT                 Direccion          Localidad         ID Pedido      Estado");
	for(i=0;i<longitudClientes;i++)
	{
		printf("\n %2d %15s %26s %15s",listaClientes[i].idCliente,listaClientes[i].cuit,listaClientes[i].direccion,listaClientes[i].localidad);
		for(j=0;j<longitudPeidos;j++)
		{
			if( (listaClientes[i].isEmpty==Alta&&
				listaPeidos[j].isEmpty==Alta)&&
				listaClientes[i].idCliente!=0 &&
				(listaClientes[i].idCliente==listaPeidos[j].idClientes&&
				strlen(listaPeidos[j].estado)==9))
			{
				printf("\n %18d %15s\n",listaPeidos[j].idPedidos,listaPeidos[j].estado);
				retorno=0;
				break;

			}

		}

	}

	return retorno;
}
