//
//  indiceVector.cpp
//  Relación 2: Divide y Vencerás
//
//  Created by Jesús Jiménez Sánchez on 29/4/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <algorithm>

using namespace std;

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

int Indice(vector<int> enteros){
	int mitad;
	
	if(enteros.size() <= 1){
		if(enteros[0] == 0){
			return 0;
		}
		else{
			return -1;
		}
	}
	else{
		mitad = (int)(enteros.size() / 2);
		
		if(enteros[mitad] == mitad){
			return mitad;
		}
		else{
			if(enteros[mitad] > mitad){
				vector<int> recursivo = enteros;
				auto it = recursivo.begin();
				
				recursivo.erase(it, it + mitad);	//Borramos la primera mitad del vector

				return Indice(recursivo);
			}
			else{
				vector<int> recursivo = enteros;
				auto it = recursivo.begin();
				
				recursivo.erase(it + mitad, recursivo.end());	//Borramos la segunda mitad del vector
				
				return Indice(recursivo);
			}
		}
	}
	
	return 0;
}

int IndiceAlReves(vector<int> enteros){
	int mitad;
	
	if(enteros.size() <= 1){
		if(enteros[0] == 0){
			return 0;
		}
		else{
			return -1;
		}
	}
	else{
		mitad = (int)(enteros.size() / 2);
		
		if(enteros[mitad] == mitad){
			return mitad;
		}
		else{
			if(enteros[mitad] < mitad){
				vector<int> recursivo = enteros;
				auto it = recursivo.begin();
				
				recursivo.erase(it, it + mitad);	//Borramos la primera mitad del vector
				
				return Indice(recursivo);
			}
			else{
				vector<int> recursivo = enteros;
				auto it = recursivo.begin();
				
				recursivo.erase(it + mitad, recursivo.end());	//Borramos la segunda mitad del vector
				
				return Indice(recursivo);
			}
		}
	}
	
	return 0;
}

int main(int argc, const char * argv[]) {
	vector<int> prueba;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i = 0; i < 100; i++){  // Recorrer vector
		prueba.push_back(rand() % 100);    // Generar aleatorio [0,vmax[
	}
	
	QuickSort(prueba, 0, (int)prueba.size());
	
	cout << "El elemento que coincide con su índice es -> " << Indice(prueba) << endl;
}
