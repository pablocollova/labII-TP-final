#ifndef ADQUISIDOR_H_INCLUDED
#define ADQUISIDOR_H_INCLUDED

#include <iostream>
#include <string>


#include "SerialClass.h"
#include"senial.h"

class Adquisidor
{
private:
    int dniPaciente;
    nodoSenial* senial;
    Serial * emisor;
    float izquierda;
    float derecha;
    float ventana;
    int dimBuffer;

public:
    Adquisidor(int dni, int dimensionBuffer);
    ~Adquisidor();

    void entrenar();
    float adquirirEntrenamiento(float &prom);
    void start();
    void parar();
    void conectar(int puerto);
};

#endif // ADQUISIDOR_H_INCLUDED
