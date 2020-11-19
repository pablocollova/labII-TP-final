#ifndef paciente_H_INCLUDED
#define paciente_H_INCLUDED

#include <iostream>
#include <string.h>

#include "pacientes.h"

/// estructura de datos
typedef struct nodoPaciente
{
    char nombre[30];
    char apellido[30];
    int dni;
    struct nodoPaciente * izq;
    struct nodoPaciente * der;
} nodoPaciente;

/// funciones basicas
nodoPaciente * inicPaciente();
nodoPaciente * crearnodoPaciente(char nombre[], char apellido[],int dni);
nodoPaciente * insertarPaciente (nodoPaciente * arbolPacientes, nodoPaciente* nodoNuevo);
void inorder(nodoPaciente * paciente);
void preorder(nodoPaciente * paciente);
void postorder(nodoPaciente * paciente);
void mostrarPaciente(nodoPaciente * paciente);
nodoPaciente * buscar(nodoPaciente * paciente, int dato);
nodoPaciente buscarXdni(nodoPaciente * raiz, int dni);

/// funciones extras
int sumarValorespaciente(nodoPaciente * paciente);

/// funciones que dibujan el paciente (de enteros nada mas..)
int dibujarpacienteLinea(nodoPaciente * paciente, int esIzq, int inicia, int nivel, char s[20][255]);
int dibujarArbolPaciente(nodoPaciente * paciente);

#endif // paciente_H_INCLUDED
