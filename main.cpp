#include <iostream>
#include <cctype>
#include <fstream>
#include "Archivo.h"

using namespace std;

void imprimirEncabezado(char* dirArchivo);

int main () 
{
	int opcionMenu;
	Archivo arbolesBinariosDeBusqueda;
	arbolesBinariosDeBusqueda.leerArchivo();
	do 
	{
		do 
		{
			imprimirEncabezado("ascii-header.txt");
			cout << "1. Imprimir arboles.\n";
			cout << "2. Altura de cada arbol.\n";
			cout << "3. Nodos hojas de cada arbol.\n";
			cout << "4. Verificar si cada arbol esta equilibrado.\n";
			cout << "5. Salir.\n\n";
			cout << "Selecciona una opcion: ";
			fflush(stdin);
			cin >> opcionMenu;
		
			if(opcionMenu <= 0 || opcionMenu > 5)
			{
				system("cls");
				cout << "Por favor introduce una opcion valida.\n\n";
				system("pause");
			}
		} 
		while (opcionMenu <= 0 || opcionMenu > 5);	
		
		if (opcionMenu == 1 )
		{
			arbolesBinariosDeBusqueda.imprimirArboles();
		} 
		else if (opcionMenu == 2) 
		{
			arbolesBinariosDeBusqueda.imprimirAlturaArboles();
		} 
		else if (opcionMenu == 3) 
		{
			arbolesBinariosDeBusqueda.imprimirHojasArboles();
		} 
		else if (opcionMenu == 4) 
		{
			arbolesBinariosDeBusqueda.imprimirEquilibrioArboles();
		}
		
	} 
	while (opcionMenu != 5);
	system("cls");
	imprimirEncabezado("ascii-farewell.txt");
}

void imprimirEncabezado(char* dirArchivo)
{
	system("cls");
	ifstream archivo(dirArchivo);
	string linea;
	while(getline(archivo, linea))
	{
		cout << linea << endl;
	}
	archivo.close();
	cout << "\n\n";	                                                                                            
}
