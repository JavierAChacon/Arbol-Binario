#include "Archivo.h"

void Archivo::leerArchivo() 
{
    ifstream archivo("arbol.txt");
    if (!archivo) {
    	system("cls");
		perror("Error al abrir el archivo");
        system("pause");
        return;
    }
    string linea;
    while (getline(archivo, linea)) 
	{
        char* lineaChar = new char[linea.length() + 1];
        strcpy(lineaChar, linea.c_str());
        Arbol arbol;
        char* palabra = strtok(lineaChar, " ");
        while (palabra != NULL) 
		{
            arbol.insertarNodo(arbol.arbol, palabra);
            palabra = strtok(NULL, " ");
        }
        arboles.push_back(arbol);
    }
}

void Archivo::imprimirArboles()
{
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) 
	{
		int contador = 0;
		vector<char*> palabras;
		arboles[i].mostrarArbol(arboles[i].arbol,contador);
		arboles[i].imprimirPostorden(arboles[i].arbol, palabras);
		cout << "\nORDEN POSTORDEN: ";
		for(int a = 0; a < palabras.size(); a++)
		{
			cout << palabras[a] << " ";
		}
		cout << "\n\n";
    }
    system("pause");
}

void Archivo::imprimirAlturaArboles()
{
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) 
	{
		int altura = arboles[i].calcularAlturaArbol(arboles[i].arbol);
		cout << "Arbol " << i+1 <<": "<< altura << "\n\n";
    }
    system("pause");
}

void Archivo::imprimirHojasArboles()
{
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) 
	{
		vector<char*> hojas;
		cout << "Arbol " << i+1 <<": ";
		arboles[i].imprimirHojasArbol(arboles[i].arbol, hojas);
		for (size_t a = 0; a < hojas.size(); ++a)
		{
			if(a == hojas.size()-1)
			{
				cout << hojas[a]; 
			} 
			else 
			{
				cout << hojas[a] << ", "; 
			}
		}
		cout << "\n\n";
    }
    system("pause");
}

void Archivo::imprimirEquilibrioArboles()
{
	system("cls");
	for (size_t i = 0; i < arboles.size(); ++i) {
		if (arboles[i].calcularEquilibrioArbol(arboles[i].arbol) >= -1 && arboles[i].calcularEquilibrioArbol(arboles[i].arbol) <= 1)
		{
			cout << "Arbol " << i+1 <<": Esta en equilibrio\n\n";
		} 
		else 
		{
			cout << "Arbol " << i+1 <<": No esta en equilibrio\n\n";
		}
    }
    system("pause");
}
