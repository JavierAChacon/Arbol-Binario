#include "Archivos.h"

void Archivos::leerArchivo() {
    ifstream archivo("arbol.txt");
    if (!archivo) {
		perror("Error al abrir el archivo");
        system("pause");
        return;
    }
    
    string linea;
    while (getline(archivo, linea)) {
        char* lineaChar = new char[linea.length() + 1];
        strcpy(lineaChar, linea.c_str());
        Arboles arbol;
        char* palabra = strtok(lineaChar, " ");
        while (palabra != NULL) {
            arbol.insertarNodo(arbol.arbol, palabra);
            palabra = strtok(NULL, " ");
        }
        arboles.push_back(arbol);
    }
}


void Archivos::imprimirArboles(){
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) {
		int contador = 0;
		arboles[i].mostrarArbol(arboles[i].arbol,contador);
		cout << "\n\n";
    }
    system("pause");
}

void Archivos::imprimirAlturaArboles(){
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) {
		int altura = arboles[i].calcularAlturaArbol(arboles[i].arbol);
		cout << "Arbol " << i+1 <<": "<< altura << "\n\n";
    }
    system("pause");
}

void Archivos::imprimirHojasArboles(){
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) {
		vector<char*> hojas;
		cout << "Arbol " << i+1 <<": ";
		arboles[i].imprimirHojasArbol(arboles[i].arbol, hojas);
		for (size_t a = 0; a < hojas.size(); ++a){
			if(a == hojas.size()-1){
				cout << hojas[a]; 
			} else {
				cout << hojas[a] << ", "; 
			}
		}
		cout << "\n\n";
    }
    system("pause");
}
