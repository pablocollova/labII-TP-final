#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include<iostream>
#include<string>



typedef struct nodoBuffer
{
    float medicion;
    struct nodoBuffer * siguiente;
}nodoBuffer;


nodoBuffer* inicBuffer();
nodoBuffer* crearNodoBuffer(float valor);
nodoBuffer* buscarUltimo(nodoBuffer* buffer);
nodoBuffer* agregarAlBuffer(nodoBuffer* buffer, nodoBuffer* nuevoNodo);
float sumarMedicionesBuffer(nodoBuffer* buffer);
float promedioBuffer(nodoBuffer* buffer, int tamanioBuffer);

#endif // BUFFER_H_INCLUDED
