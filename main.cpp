#include <iostream>
#include <cctype>
#include "Archivos.h"

using namespace std;

void titulo(char *titulo);

int main () {
	int opcion;
	Archivos arbolesBinariosDeBusqueda;
	arbolesBinariosDeBusqueda.leerArchivo();
	do {
		do {
			titulo("MENU");
			cout << "1. Imprimir arboles\n";
			cout << "2. Altura de cada arbol\n";
			cout << "3. Nodos hojas de cada arbol\n";
			cout << "4. Verificar si cada arbol esta equilibrado o no\n";
			cout << "5. Salir\n\n";
		
			cout << "Selecciona una opcion: ";
			fflush(stdin);
			cin >> opcion;
		
			if(opcion < 0 || opcion > 5){
				titulo("ERROR");
				cout << "Por favor introduce una opcion valida.\n\n";
				system("pause");
			}
		} while (opcion < 0 || opcion > 5);	
		
		
	} while (opcion != 5);
}

void titulo (char titulo[30]){
	system("cls");
	cout << "********** " << titulo << "**********\n\n";
}
