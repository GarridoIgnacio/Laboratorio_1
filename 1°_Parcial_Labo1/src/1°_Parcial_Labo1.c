/*
 ============================================================================
 Name        : 1°_Parcial_Labo1.c
 Author      : Garrido Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Nexo.h"
#define TamListClientes 100 // cambiar a 100
#define TamListPedidos 1000 // cambiar a 1000


int main(void) {

	int opcion;
	eClientes listaClientes[TamListClientes]= {{180,"20385389346","Av. Argetina 1543","Neuquen",Alta},
											   {177,"21376492443","Leopoldo constans 238","Jose C Paz",Alta},
											   {199,"30469391046","Diagonal sur 367","La Plata",Alta}};
	ePedidos listaPedidos[TamListPedidos]={{1180,180,51.34,"PENDIENTE",Alta},
										   {1256,177,60,"PENDIENTE",Alta},
										   {1367,199,35.6,"PENDIENTE",Alta}};
	int idClienteAuto=100;
	int idPedidosAuto=1000;


	iniciaClientes(listaClientes, TamListClientes);
    iniciaPedidos(listaPedidos, TamListPedidos);

	do
		{

			//system("cls");
			printf("\n\t\t\t\t-----------------------------------------------");
			printf("\n \t\t\t\t|\t       Lista de Empleados             |"
				   "\n \t\t\t\t|\t                                      |");
			printf("\n \t\t\t\t|\t1. Altas Cliente.                     |");
			printf("\n \t\t\t\t|\t2. Modificar datos de Cliente.        |");
			printf("\n \t\t\t\t|\t3. Baja Cliente.                      |");
			printf("\n \t\t\t\t|\t4. Crear Peido de recoleccion.        |");
			printf("\n \t\t\t\t|\t5. Procesar Residuos.                 |");
			printf("\n \t\t\t\t|\t6. Imprimir Clientes.                 |");
			printf("\n \t\t\t\t|\t7. Imprimir Pedidos pendientes.       |");
			printf("\n \t\t\t\t|\t8. Imprimir Pedidos procesados.       |");
			printf("\n \t\t\t\t|\t9. Informes.                          |");
			printf("\n \t\t\t\t|\t0. Salir                              |");
			printf("\n\t\t\t\t-----------------------------------------------\n");

			ObtenerIntConLimite(&opcion, "\n\nIngrese un numero del 1-5: ", "\n\t\tError Opcion no valida!", 0, 9, 3);

			//verif=VerificarEstado(listaEmpleados, TamLista);

			switch(opcion)
			{
				case 1:
					if(!CargaCliente(listaClientes, TamListClientes,&idClienteAuto))
					{
						printf("\n\n\t\t Se cargo correctamente un Cliente.\n");
					}
					else
					{
						printf("\n\n\t\t --Error-- NO se cargo correctamente un Cliente.\n");
					}

				break;
				case 2:
					if(!ModificarCliente(listaClientes, TamListClientes))
					{
						printf("\n\n\t\t Se modifico correctamente un Cliente.\n");
					}else
					{
						printf("\n\n\t\t --Error-- NO se modifico correctamente un Cliente.\n");
					}
				break;
				case 3:
					if(!BajaCliente(listaClientes, TamListClientes))
					{
						printf("\n\n\t\t Se Elimino correctamente al Cliente.\n");
					}else
					{
						printf("\n\n\t\t NO se elimino al Cliente.\n");
					}
				break;
				case 4:
					printClientes(listaClientes, TamListClientes);
					if(!CrearPedido(listaPedidos, TamListPedidos,&idPedidosAuto))
					{
						printf("\n\n\t\t Se Creo el Pedido correctamente al Cliente.\n");
					}
					else{
						printf("\n\n\t\t --Error-- NO se Creo el Pedido correctamente.\n");
					}
				break;
				case 5:
					if(!PedidoProcesado(listaPedidos, TamListPedidos))
					{
						printf("\n\n\t\t Se Cerro el Pedido correctamente al Cliente.\n");
					}
					else{
						printf("\n\n\t\t --Error-- NO se Cerro el Pedido correctamente.\n");
					}
				break;
				case 6:
					CompararListas(listaClientes, listaPedidos, TamListClientes, TamListPedidos);
				break;
				case 0:
					printf("\n\n\n\t\t\tGood Bey");
				break;
			}

		}while(opcion!=0);




	return EXIT_SUCCESS;
}
