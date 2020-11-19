#ifndef SENIAL_H_INCLUDED
#define SENIAL_H_INCLUDED


#include<iostream>

#include "buffer.h"

typedef struct nodoSenial {
                float promedio;
                nodoBuffer* b;
                struct nodoSenial * siguiente;
}nodoSenial;

nodoSenial* inicSenial();
nodoSenial* crearNodoSenial(nodoBuffer * b, int dimensionBuffer);
nodoSenial* buscarUltimo(nodoSenial* senial);
nodoSenial* agregarToSenial(nodoSenial* senial, nodoSenial* nuevoNodo);
float sumarSenial(nodoSenial* senial);
float promedioSenial(nodoSenial* senial);
float getMenor(nodoSenial* senial);
float getMayor(nodoSenial* senial);

// se pueden agregar distintos modulos de procesamiento
// que devuelvan un nodo a la senial modificada
nodoSenial* procPromedio(nodoSenial*)
#endif // SENIAL_H_INCLUDED
