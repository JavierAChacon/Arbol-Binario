#include "Archivos.h"

void Archivos::leerArchivo(){
	ifstream archivo;
	archivo.open("arbol.txt", ios::in);
	string linea;
	while (getline(archivo, linea)){
		char *lineaChar = new char[linea.length() + 1];
        strcpy(lineaChar, linea.c_str());
		Arboles arbol = Arboles();
		char *palabra = strtok(lineaChar, " "); 
		while(palabra != NULL){
			arbol.insertarNodo(arbol.arbol, palabra);
			palabra = strtok(NULL, " ");
		}
		arboles.push_back(arbol);
	}
}
