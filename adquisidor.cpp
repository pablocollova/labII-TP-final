#include "adquisidor.h"

using namespace std;

Adquisidor::Adquisidor(int dni, int dimensionBuffer)
{
    dniPaciente=dni;
    dimBuffer=dimensionBuffer;
}

Adquisidor:: ~Adquisidor()
{

}
float Adquisidor::adquirirEntrenamiento(float &prom)
{

     nodoSenial* s;
    nodoBuffer* b;

        char palabra[] = "Comenzar";
        char medicion[]="0000";
        float valor;

        nodoBuffer* buffer;
        nodoBuffer*aux;

        nodoSenial* senial;
        nodoSenial* senAux;
        senial=inicSenial();

        cout<<"Enviando :"<<palabra<<endl;
        emisor->WriteData(palabra,sizeof(palabra)-1);

        Sleep(500);
        int i=0;
        int j=0;
        while(j<30)
        {
            buffer=inicBuffer();
            aux=inicBuffer();
            senAux=inicSenial();
            while( (i<dimBuffer)&&(emisor->IsConnected()) )
            {
                i++;
                emisor->ReadData(medicion,sizeof(medicion)-1);
                valor=atof(medicion);
                aux=crearNodoBuffer(valor);
                cout<<endl<<valor<<endl;
                buffer=agregarAlBuffer(buffer,aux);
                Sleep(10);
            }
            j++;
            i=0;
            senAux=crearNodoSenial(buffer, dimBuffer);
            senial=agregarToSenial(senial, senAux);
            Sleep(10);
        }
        prom=promedioSenial(senial);
        float menor=getMenor(senial);
        float mayor=getMayor(senial);
        return(mayor-menor);cout<<3;
}

void Adquisidor::entrenar()
{
    float promIzq=0;
    float promDer=0;
    cout<<"mueva los ojos a la izquierda cuando escuche el sonido hasta que lo vuelva a escuchar"<<endl;
    Sleep(2000);
    cout<<'\a';
    izquierda=adquirirEntrenamiento(promIzq);
    cout<<'\a';
    Sleep(2000);
    cout<<"mueva los ojos a la izquierda cuando escuche el sonido hasta que lo vuelva a escuchar"<<endl;
    Sleep(2000);
    cout<<'\a';
    derecha=adquirirEntrenamiento(promDer);
    ventana=(promDer+promIzq)/2;
    cout<<'\a';

}


void Adquisidor::start()
{
    nodoSenial* s;
    nodoBuffer* b;

    char palabra[] = "Comenzar";
    char medicion[]="0000";
    float valor;

    nodoBuffer* buffer;
    nodoBuffer*aux;

    nodoSenial* senial;
    nodoSenial* senAux;
    senial=inicSenial();

    cout<<"Enviando :"<<palabra<<endl;
    emisor->WriteData(palabra,sizeof(palabra)-1);

    Sleep(500);
    int i=0;
    int j=0;
    float promAux;
    while(j<100)
    {
        buffer=inicBuffer();
        aux=inicBuffer();
        senAux=inicSenial();

        while( (i<dimBuffer)&&(emisor->IsConnected()) )
        {
            i++;
            emisor->ReadData(medicion,sizeof(medicion)-1);
            valor=atof(medicion);
            aux=crearNodoBuffer(valor);
            buffer=agregarAlBuffer(buffer,aux);
            promAux=promedioBuffer(buffer,dimBuffer);
            if(((izquierda-ventana)<promAux)&&((izquierda+ ventana)>promAux))
            {
                cout<<endl<<"---------------------"<<endl<<"izquierda"<<endl<<"--------------------"<<endl;
            }
            else if (((derecha-ventana)<promAux)&&((derecha+ ventana)>promAux))
            {
                cout<<endl<<"---------------------"<<endl<<"derecha"<<endl<<"--------------------"<<endl;
            }
            else
                 {
                cout<<endl<<"---------------------"<<endl<<"centro"<<endl<<"--------------------"<<endl;
            }
            Sleep(400);
        }
        j++;
        i=0;
        senAux=crearNodoSenial(buffer, dimBuffer);
        senial=agregarToSenial(senial, senAux);
        Sleep(10);
        }



}

//printf("%c",'u');
    /*
//Nomenclatura para crear conexión con los puertos COM1 - COM9
Serial* Arduino = new Serial("COM7");
//Nomenclatura para crear conexión con los puertos COM10 en adelante
Serial* Arduino = new Serial("\\\\.\\COM10");

if( Arduino->IsConnected() ) cout<<"Arduino Conectado";

//Crear un buffer de entrada
char lectura[50];
//Hacer la lectura indicando el buffer de entrada y longitud
Arduino->ReadData(lectura,50);

//Crear un buffer de salida
#define longEnvio 20
char envio[longEnvio];
//Hacer el envío indicando el buffer de salida y longitud
Arduino->ReadData(envio,longEnvio);*/



void Adquisidor::conectar(int puerto)
{
    char puerto_to_char[1];
    sprintf(puerto_to_char,"%d",puerto);
    char com[4]="COM";
    com[3]=puerto_to_char[0];
    com[4]=NULL;
    cout<<endl<<"muestro puerto"<<com<<endl;
    //com=strcat(com,puerto_to_char) ;
    emisor = new Serial(com);
    if(emisor->IsConnected())
    {
        cout<<endl<<"---------------------------"<<endl<<" Conexion establecida con el emisor " <<endl<<"-----------------------";
    }
    else
    {
          cout<<endl<<"---------------------------"<<endl<<" Fallo el intento de conexion " <<endl<<"-----------------------";

    }


}

