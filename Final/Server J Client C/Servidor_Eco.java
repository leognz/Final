

import java.net.*;
import java.io.*;

public class Servidor_Eco
{    
    public static void main (String [] args)
    {
     
        try
        {
     	    //Se inicia el socket
            ServerSocket socket = new ServerSocket (15557);
            System.out.println ("En espera... \n");
            //Aceptamos la conexion
            Socket cliente = socket.accept();
            //Preparamos los datos de salida y entrada
            DatoSocket mensaje = new DatoSocket("Que onda");
            DataOutputStream bufferSalida = new DataOutputStream (cliente.getOutputStream());
            DataInputStream bufferEntrada =new DataInputStream (cliente.getInputStream());
	    mensaje.writeObject (bufferSalida);
            DatoSocket aux = new DatoSocket("");
            aux.readObject (bufferEntrada);
            cliente.close();
            socket.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }


}
