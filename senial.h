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

/*nodoSenial* borrarnodoSenialBuscado(nodoSenial* lista, int nota);
nodoSenial* agregarEnOrden(nodoSenial * lista, nodoSenial* nuevonodoSenial);
nodoSenial* borrarTodaLaLista(nodoSenial* lista);
nodoSenial* borrarPrimernodoSenial(nodoSenial* lista);
nodoSenial* borrarUltimonodoSenial(nodoSenial* lista);
int sumarNotasLista(nodoSenial* lista);
int sumarNotasListaRecursivo(nodoSenial* lista);
int sumarNotasListaRecursivoTernario(nodoSenial* lista);
void mostrarUnnodoSenial(nodoSenial* aux);
void mostrarUnaNota(stNotaAlumno n);
void recorrerYmostrar(nodoSenial* lista);
int cuentaAlumnos(nodoSenial* lista);

*/
#endif // SENIAL_H_INCLUDED
