/*
 * Cliente.c
 *
 *
 *      Author: Ignacio
 */


#include "Clientes.h"




int iniciaClientes(eClientes* lista,int longitud)
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

void MostrarUnEmp (eClientes lista)
{

		printf("\n %2d %15s %26s %15s ",lista.idCliente,lista.cuit,lista.direccion,lista.localidad);

}

int printClientes (eClientes* lista, int longitud)
{
	int i;
	int retorno;

	retorno=-1;
	printf("  ID         CIUT                 Direccion          Localidad  \n");
	for(i=0;i<longitud;i++)
	{
		if(lista[i].isEmpty==Alta)
		{
			MostrarUnEmp(lista[i]);
			retorno=0;
		}
	}

	return retorno;
}

int CargaCliente (eClientes* lista, int longitud, int* IdAutomatico)
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
			lista[i].idCliente=idAux;
			if(!ObtenerStringNum(lista[i].cuit, 11, "Ingrese el CUIT del Cliente: ", "--Error. CUIT invalido, Ingresesolo numeros sin signo--", 4))
			{
				printf("\n\nIngrese la dirreccion del Cliente: ");
				PedirCadena(lista[i].direccion, 51);

					if(!ObtenerSoloLetras(lista[auxI].localidad, 51, "Ingrese la localidad del Cliente: ",3))
					{
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

int findeClienteById (eClientes* list, int lenght, int id)
{
	int i;
	int retorno;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].idCliente==id)
			{
				printf("  ID         CIUT                 Direccion          Localidad  \n");
				MostrarUnEmp(list[i]);
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

int ModificarCliente (eClientes* list, int lenght)
{
	int i;
	int retorno;
	char subMenu;
	int idCliente;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		ObtenerIntConLimite(&idCliente, "\n Ingrese el ID del emplado: ", "\n Error! ID invalida ingrese numeros enteros.", 100, 999, 3);
		if(findeClienteById(list,lenght,idCliente)==-1)
		{
			printf("\n El ID ingresado no existe.");
		}
		for(i=0;i<lenght;i++)
		{
			if(list[i].idCliente==idCliente && list[i].isEmpty==Alta)
			{
				do{
					printf("\n\n\t ---------------------------");
					printf("\n\t |  Que desea Modificar?   |"
						   "\n\t |                         |");
					printf("\n\t | 1- Modificar Direccion. |");
					printf("\n\t | 2- Modificar Localidad. |");
					printf("\n\t | 0- Volver.              |");
					printf("\n\t ----------------------------");
					printf("\n\n Ingrese una opcion: ");

					scanf("%c",&subMenu);

					switch(subMenu)
					{
						case '1':
							printf("\n Ingrese nueva Direccion: ");
							PedirCadena(list[i].direccion, sizeof(list[i].direccion));
						break;
						case '2':
							ObtenerSoloLetras(list[i].localidad, sizeof(list[i].localidad), "\n Ingrese nueva Localidad: ",3);
						break;
						case '0':
							printf("\n\n\t bye :)");
						break;
						default:
							printf("\n\n\tOpcion invalida, por favor elija una del 1-4 o 0 para salir");
						break;
					}
					retorno=0;
				}while(subMenu!='0');
			}
		}

	}

	return retorno;
}

int removeCliente (eClientes* list, int lenght, int id)
{
	int retorno;
	int i;

	retorno=-1;

	if(list!=NULL && lenght>0 && id > 0)
	{
		for(i=0;i<lenght;i++)
		{
			if(list[i].idCliente==id && list[i].isEmpty==Alta)
			{
				list[i].isEmpty=Baja;
				retorno=0;
			}
		}

	}
	return retorno;
}

int BajaCliente(eClientes* list, int lenght)
{
	int retorno;
	int idEmpleado;
	char respuesta;

	retorno=-1;

	if(list!=NULL && lenght>0)
	{
		ObtenerInt(&idEmpleado, "\n Ingrese el ID del emplado: ", "\n--Error! ID invalida ingrese numeros enteros.--",3);
		if(!findeClienteById(list, lenght, idEmpleado))
		{
			respuesta=PedirChar("\n Esta seguro que desea dar la baja a este cliente?: ");
			respuesta=tolower(respuesta);
			if(respuesta=='s')
			{
				if(!removeCliente(list, lenght, idEmpleado))
				{
					retorno=0;
				}
			}
		}

	}

	return retorno;
}






























