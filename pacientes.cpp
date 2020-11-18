#include "pacientes.h"

using namespace std;

nodoPaciente * inicPaciente()
{
    return NULL;
}

nodoPaciente * crearnodoPaciente(char nombre[], char apellido[], int dni)
{
    nodoPaciente * aux = (nodoPaciente *) malloc(sizeof(nodoPaciente));

    strcpy(aux->nombre, nombre);
    strcpy(aux->apellido, apellido);
    aux->dni=dni;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}


nodoPaciente * insertarPaciente (nodoPaciente * arbolPacientes,nodoPaciente *nodoNuevo)
{
    if(arbolPacientes==NULL)
    {
        arbolPacientes = nodoNuevo;
    }
    else
    {
        if(nodoNuevo->dni>arbolPacientes->dni)
        {
            arbolPacientes->der=insertarPaciente(arbolPacientes->der, nodoNuevo);
        }
        else
        {
            arbolPacientes->izq=insertarPaciente(arbolPacientes->izq, nodoNuevo);
        }
    }
    return arbolPacientes;
}


void inorder(nodoPaciente * Paciente)
{
    if(Paciente!=NULL)
    {
        inorder(Paciente->izq);
        mostrarPaciente(Paciente);
        inorder(Paciente->der);
    }
}
void mostrarPaciente(nodoPaciente * p)
{
        cout<<p->nombre<<endl;
        cout<<p->apellido<<endl;
        cout<<p->dni<<endl;

}

int dibujarPacienteLinea(struct nodoPaciente * p, int esIzq, int inicia, int nivel, char s[20][255])
{
    char b[10];
    int ancho = 4;
    int i;

    if (!p)
        return 0;

    sprintf(b, "%c  %c", p->nombre, p->apellido);

    int izq  = dibujarPacienteLinea(p->izq,  1, inicia, nivel + 1, s);
    int der = dibujarPacienteLinea(p->der, 0, inicia + izq + ancho, nivel + 1, s);

    //dibujo nodoSenialBuffer
    for (i = 0; i < ancho; i++)
        s[2 * nivel][inicia + izq + i] = b[i];

    //dibujo lineas .----+----.
    if (nivel && esIzq)
    {

        for (i = 0; i < ancho + der; i++)
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';

    }
    else if (nivel && !esIzq)
    {

          for (i = 0; i < ancho + der; i++)
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';
    }

    //Cerebros quemados everywere!!
    return izq + ancho + der;
}

int dibujarArbolPaciente(struct nodoPaciente * p)
{
    char s[20][255];

    //creo una matriz de char para hacer mi "dibujo"
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    //Hago magia
    dibujarPacienteLinea(p, 0, 0, 0, s);

    //Imprimo matris
    for (int i = 0; i < 10; i++)
        printf("%s\n", s[i]);
}

