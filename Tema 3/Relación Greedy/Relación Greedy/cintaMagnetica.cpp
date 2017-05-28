//
//  cintaMagnetica.cpp
//  Relación Greedy
//
//  Created by Jesús Jiménez Sánchez on 26/5/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int Pivote(vector<int> &A, int p, int q){
	int x = A[p];
	int i = p;
	int j;
	
	for(j = p + 1; j < q; j++){
		if(A[j] <= x){
			i = i + 1;
			
			swap(A[i], A[j]);
		}
	}
	
	swap(A[i], A[p]);
	
	return i;
}

void QuickSort(vector<int> &A, int p, int q){
	int r;
	
	if(p < q){
		r = Pivote(A, p, q);
		
		QuickSort(A, p, r);
		QuickSort(A, r + 1, q);
	}
}

bool Factible(const int menor, const int longitud, const int actual){
	return ((actual + menor) <= longitud);
}

int Seleccion(vector<int> &programas, int longitud, int actual){
	int menor = -1;
	auto iter = programas.begin();

	
	if(Factible((*iter), longitud, actual) && !programas.empty()){	//Cuando esté vacío el vector de programas o no sea factible será que ya habremos terminado
		menor = (*iter);											//porque estarán ordenados de menor a mayor
		programas.erase(iter);
	}
	
	return menor;
}

vector<int> cintaVoraz(const int longitud, vector<int> programas){
	vector<int> resultado;
	int actual = 0;
	int programaAniadir;
	bool terminar = false;
	
	QuickSort(programas, 0, (int)programas.size());
	
	for(int i = 0; i < programas.size() && !terminar; i++){
		programaAniadir = Seleccion(programas, longitud, actual);
		
		if(programaAniadir != -1){
			resultado.push_back(programaAniadir);
			actual += programaAniadir;
			
		}
		else{
			terminar = true;
		}
	}
	
	return resultado;
}

int main(){
	int tam = 50;     // Tamaño del vector
	
	// Generación del vector aleatorio
	vector<int> v;
	int obj = rand() % 45;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i = 0; i < tam; i++)  // Recorrer vector
		v.push_back((rand() % 20) + 1);
	
	high_resolution_clock::time_point start, end;	//Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    //Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    //Iniciamos el punto de inicio
	
	cintaVoraz(obj, v);
	
	end = high_resolution_clock::now();    //Anotamos el punto de de fin
	
	//El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);
	
	//Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
