#ifndef GESTIONPACIENTES_H_INCLUDED
#define GESTIONPACIENTES_H_INCLUDED

#include<iostream>
#include<string>

#include "pacientes.h"


class pacientes{

private:
    nodoPaciente* p;

public:
    pacientes();
    int agregarPaciente();
    void mostrarPacientes();
    void buscarPaciente();
    int fileToMemo();
    int memoToFile();

};

#endif // GESTIONPACIENTES_H_INCLUDED
