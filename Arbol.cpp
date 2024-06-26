#include "Arbol.h"

Arbol::Arbol()
{
	arbol = NULL;
}

Nodo* Arbol::crearNodo(char* palabra) 
{
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo -> palabra = palabra;
	nuevo_nodo -> izquierda = NULL;
	nuevo_nodo -> derecha = NULL;
	
	return nuevo_nodo;
}

void Arbol::insertarNodo(Nodo*& arbol, char* palabra)
{
	if(arbol == NULL)
	{
		Nodo *nuevo_nodo = crearNodo(palabra); 
		arbol = nuevo_nodo;
	} 
	else 
	{
		char* raiz = arbol -> palabra;
		int resultado = strcmp(palabra, raiz);
		
		if(resultado < 0)
		{
			insertarNodo(arbol -> izquierda, palabra);
		} 
		else 
		{
			insertarNodo(arbol -> derecha, palabra);
		}
	}
}

void Arbol::mostrarArbol(Nodo* arbol, int contador)
{
	if (arbol == NULL) 
	{
		return;
	} 
	else 
	{
		mostrarArbol(arbol -> derecha, contador+1);
		for(int i = 0; i < contador; i++)
		{
			cout << "   ";
		}
		cout << arbol -> palabra << endl;
		mostrarArbol(arbol -> izquierda, contador+1);
	}
}

void Arbol::imprimirPostorden(Nodo* arbol, vector<char*>& palabras)
{
	if (arbol == NULL) 
	{
		return;
	} 
	else 
	{
		imprimirPostorden(arbol -> izquierda, palabras);
		imprimirPostorden(arbol -> derecha, palabras);
		palabras.push_back(arbol->palabra);
	}
	return;
}

int Arbol::calcularAlturaArbol(Nodo* arbol)
{
	if(arbol->izquierda == NULL && arbol->derecha == NULL)
	{
		return 1;
	} 
	else 
	{
		int alturaIzquierda = -1, alturaDerecha = -1;
		if(arbol->izquierda != NULL)
		{
			alturaIzquierda = calcularAlturaArbol(arbol->izquierda);
		}
		if(arbol->derecha != NULL)
		{
			alturaDerecha = calcularAlturaArbol(arbol->derecha);
		}
		if(alturaIzquierda > alturaDerecha)
		{
			return alturaIzquierda+1;
		}
		else
		{
			return alturaDerecha+1;
		}
	}
}

void Arbol::imprimirHojasArbol(Nodo* arbol, vector<char*>& hojas)
{
	if(arbol->izquierda == NULL && arbol->derecha == NULL)
	{
		hojas.push_back(arbol->palabra);
		return;
	} 
	else 
	{
		if(arbol->derecha != NULL)
		{
			imprimirHojasArbol(arbol->derecha, hojas);		
		}
		if(arbol->izquierda != NULL)
		{
			imprimirHojasArbol(arbol->izquierda, hojas);	
		}
	}
}

int Arbol::calcularEquilibrioArbol(Nodo* arbol)
{
	int alturaIzq = 0, alturaDer = 0;
	if(arbol->izquierda == NULL && arbol->derecha == NULL)
	{
		return 1;
	} 
	else 
	{
		if (arbol->izquierda != NULL)
		{
			alturaIzq = calcularAlturaArbol(arbol->izquierda);
		}
		if (arbol->derecha != NULL)
		{
			alturaDer = calcularAlturaArbol(arbol->derecha);
		}
		return alturaDer-alturaIzq;
	}
}

