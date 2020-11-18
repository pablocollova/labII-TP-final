#include <iostream>
   #include <stdio.h>
#include <dos.h>
#include "conio.h"
#include "stdio.h"



#include "gestionPacientes.h"
#include "adquisidor.h"

using namespace std;

int main (){

    pacientes *p=new pacientes();
    int dni=p->agregarPaciente();

    Adquisidor* a=new Adquisidor(dni,20);

    a->conectar(3);
    a->entrenar();
    a->start();





}
