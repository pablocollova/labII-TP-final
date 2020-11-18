#include "senial.h"

using namespace std;

nodoSenial* inicSenial()
{
    return NULL;
}

nodoSenial* crearNodoSenial(nodoBuffer *b,int dimensionBuffer)
{
    nodoSenial * aux = (nodoSenial*)malloc(sizeof(nodoSenial));
    aux->b = b;
    aux->promedio=promedioBuffer(b, dimensionBuffer);
    aux->siguiente = NULL;
    return aux;
}

nodoSenial* buscarUltimo(nodoSenial* senial)
{
    nodoSenial* seg = senial;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}


nodoSenial* agregarToSenial(nodoSenial* senial, nodoSenial* nuevoNodo)
{
    if(senial == NULL){
        senial = nuevoNodo;
    }
    else{
        nodoSenial* ultimo = buscarUltimo(senial);
        ultimo->siguiente = nuevoNodo;
    }
    return senial;
}
float getMenor(nodoSenial* senial)
{
    float menor=0;
    nodoSenial* aux=senial;
    while(aux!=NULL)
    {
        if(aux->promedio<menor)
        {
            menor=senial->promedio;
        }
        aux=aux->siguiente;
    }
    return menor;
}
float getMayor(nodoSenial* senial)
{
    float mayor=0;
    nodoSenial* aux=senial;
    while(aux!=NULL)
    {
        if(aux->promedio>mayor)
        {
            mayor=senial->promedio;
        }
        aux=aux->siguiente;
    }
    return mayor;
}

float sumarSenial(nodoSenial* senial)
{
     int suma=0;
    if(senial){
        suma=senial->promedio + sumarSenial(senial->siguiente);
    }
    return suma;
}
float promedioSenial(nodoSenial* senial)
{
    int cant=0;
    nodoSenial* aux=senial;
    while(aux!=NULL)
    {
        aux=aux->siguiente;
        cant++;
    }

    float suma= sumarSenial(senial);
    float prom=suma/cant;
    return prom;
}
