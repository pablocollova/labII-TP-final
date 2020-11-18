#include "gestionPacientes.h"

using namespace std;


pacientes::pacientes()
{
      p=inicPaciente();
}
int pacientes::agregarPaciente()
{
    char nombre[30];
    char apellido[30];
    int dni;
    char rta='s';

        cout<<endl<<"--------------Nuevo Paciente------------------"<<endl;

        cout<<"Nombre: ";cin>>nombre;
        cout<<"Apellido: ";cin>>apellido;
        cout<<"dni: "; cin>>dni;

        cout<<endl<<"----------------------------------------------"<<endl;


        nodoPaciente* aux=crearnodoPaciente(nombre,apellido, dni);

        p= insertarPaciente(p,aux);

        cout<<endl<<"ingresar otro paciente? (s/n)"<<endl;
        cin>>rta;

return dni;

}

void pacientes::mostrarPacientes()
{
    inorder(p);
    cout<<endl;
    //dibujarArbolPaciente(p);
}

int pacientes::fileToMemo()
{
    FILE *f;
    nodoPaciente* pAux;

    f = fopen ("pacientes.dat", "rb");
    if (f==NULL)
    {
   perror("No se puede abrir fichero.dat");
   return -1;
    }
    else
    {
        while (!feof(f))
        {
            fread (&pAux, 1, sizeof(nodoPaciente), f);
            p = insertarPaciente(p, pAux) ;
        }
    }
}

int pacientes::memoToFile()
{
    FILE*f;
    f = fopen ("pacientes.dat", "wb");
    if (f==NULL)
    {
        perror("No se puede abrir pacientes.dat");
        return -1;
    }
}

