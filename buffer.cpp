#include "buffer.h"

using namespace std;

nodoBuffer* inicBuffer()
{
    return NULL;
}

nodoBuffer* crearNodoBuffer(float valor)
{
    nodoBuffer* aux=(nodoBuffer*)malloc(sizeof(nodoBuffer));
    aux->medicion=valor;
    aux->siguiente=NULL;
    return aux;
}
nodoBuffer* buscarUltimo(nodoBuffer* buffer)
{
    nodoBuffer* seg = buffer;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}
nodoBuffer* agregarAlBuffer(nodoBuffer* buffer, nodoBuffer* nuevoNodo)
{

    if(buffer == NULL){
        buffer = nuevoNodo;
    }
    else{
        nodoBuffer* ultimo = buscarUltimo(buffer);
        ultimo->siguiente = nuevoNodo;
    }
    return buffer;
}

float sumarMedicionesBuffer(nodoBuffer* buffer)
{
    float suma=0;

    if(buffer!=NULL)
    {
        suma=buffer->medicion + sumarMedicionesBuffer(buffer->siguiente);

    }
    return suma;
}

float promedioBuffer(nodoBuffer* buffer, int tamanioBuffer)
{

    float suma= sumarMedicionesBuffer(buffer);
    cout<<endl<<" tamaño "<<tamanioBuffer<<" suma "<<suma<<endl;
    float prom=suma/tamanioBuffer;
    return prom;
}

