#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Arboles.h"
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Archivos
{
	public:
	vector<Arboles> arboles;	
	void leerArchivo();
};

#endif
