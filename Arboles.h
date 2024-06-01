#ifndef ARBOLES_H
#define ARBOLES_H
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
 char *palabra;
 Nodo *izquierda;
 Nodo *derecha;	
};


class Arboles
{
	public:
		
	Nodo *arbol;
	Arboles();
		
	Nodo *crearNodo(char *palabra);
	void insertarNodo(Nodo *&arbol, char *palabra);
	void mostrarArbol(Nodo *arbol, int contador);
	int calcularAlturaArbol(Nodo *arbol);
	void imprimirHojasArbol(Nodo *arbol, vector<char*> &hojas);
};

#endif
