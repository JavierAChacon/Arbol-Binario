#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "Arbol.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Archivo
{
	protected:
	vector<Arbol> arboles;
	public:	
	void leerArchivo();
	void imprimirArboles();
	void imprimirAlturaArboles();
	void imprimirHojasArboles();
	void imprimirEquilibrioArboles();
};

#endif
