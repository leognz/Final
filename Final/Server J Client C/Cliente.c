
#include <stdio.h>
#include "Socket.h"
#include "Socket_Cliente.h"

#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include <unistd.h> 
#include <arpa/inet.h>

int  main ()
{

	int Socket_Con_Servidor;
	char Cadena[100];
	int aux;

	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}
	//Se preparan los datos a convertir , en este caso la cadena Hola
	strcpy (Cadena, "Hola");
	aux=htonl (strlen(Cadena)+1);
	//Se procede a enviar los datos (la cadena y el dato)
	Escribe_Socket (Socket_Con_Servidor, (char *)&aux, sizeof(strlen(Cadena)+1));
	printf ("Mensaje a Enviar %s\n",Cadena);
	printf ("Enviando Al servidor.....\n");
	Escribe_Socket (Socket_Con_Servidor, Cadena,strlen(Cadena)+1);
	//Se leen los datos y se prepara para convertirlos y poder mostrarlos eb C
   	Lee_Socket(Socket_Con_Servidor,(char *)&aux,sizeof(int));
   	Lee_Socket(Socket_Con_Servidor, Cadena, ntohl(aux));
   	printf("El servidor envio: %s\n\n", Cadena);

	close (Socket_Con_Servidor);
}
