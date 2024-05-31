#include "Arboles.h"

Arboles::Arboles(){
	arbol = NULL;
}

Nodo *Arboles::crearNodo(char *palabra) 
{
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo -> palabra = palabra;
	nuevo_nodo -> izquierda = NULL;
	nuevo_nodo -> derecha = NULL;
	
	return nuevo_nodo;
}

void Arboles::insertarNodo(Nodo *&arbol, char *palabra){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(palabra); 
		arbol = nuevo_nodo;
	} else {
		char *raiz = arbol -> palabra;
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

void Arboles::mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		cout << "El arbol está vacío";
	} else {
		mostrarArbol(arbol -> derecha, contador+1);
		for(int i = 0; i < contador; i++){
			cout << "   ";
		}
		cout << arbol -> palabra << endl;
		mostrarArbol(arbol -> izquierda, contador+1);
		
	}
}



