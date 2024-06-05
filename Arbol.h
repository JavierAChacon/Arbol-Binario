#ifndef ARBOL_H
#define ARBOL_H

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

struct Nodo 
{
 char *palabra;
 Nodo *izquierda;
 Nodo *derecha;	
};


class Arbol
{
	public:
	Nodo *arbol;
	Arbol();
	public:
	void insertarNodo(Nodo*& arbol, char* palabra);
	void mostrarArbol(Nodo* arbol, int contador);
	void imprimirHojasArbol(Nodo* arbol, vector<char*>& hojas);
	void imprimirPostorden(Nodo* arbol, vector<char*>& palabras);
	int calcularAlturaArbol(Nodo* arbol);
	int calcularEquilibrioArbol(Nodo* arbol);
	private:
	Nodo *crearNodo(char* palabra);
};

#endif //ARBOL_H
