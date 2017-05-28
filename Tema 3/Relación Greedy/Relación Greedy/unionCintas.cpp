//
//  unionCintas.cpp
//  Relación Greedy
//
//  Created by Jesús Jiménez Sánchez on 28/5/17.
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

int Seleccion(vector<int> &tamanios){
	int seleccionado = -1;
	auto iter = tamanios.begin();

	seleccionado = (*iter);
	tamanios.erase(iter);
	
	return seleccionado;
}

int unionVoraz(vector<int> tamanioCintas){
	vector<int> sumasParciales;
	int movimientosTotal = 0;
	
	QuickSort(tamanioCintas, 0, (int)tamanioCintas.size());
	
	movimientosTotal += Seleccion(tamanioCintas);
	
	for(int i = 0; !tamanioCintas.empty(); i++){
		movimientosTotal += Seleccion(tamanioCintas);
		sumasParciales.push_back(movimientosTotal);
	}
	
	movimientosTotal = 0;
	
	for(int i = 0; i < sumasParciales.size(); i++){
		movimientosTotal += sumasParciales[i];
	}
	
	return movimientosTotal;
}

int main(){
	int tam = 3;     // Tamaño del vector
	
	// Generación del vector aleatorio
	vector<int> v;
	int resultadoUnion = -1;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i = 0; i < tam; i++){  // Recorrer vector
		int jeje = (rand() % 99) + 1;
		v.push_back(jeje);	// Tamaño máximo de 100 registros (por ejemplo)
		cout << jeje << endl;
	}
	
	high_resolution_clock::time_point start, end;	// Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    // Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    // Iniciamos el punto de inicio
	
	resultadoUnion = unionVoraz(v);
	
	end = high_resolution_clock::now();    // Anotamos el punto de de fin
	
	// El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);
	
	// Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
	cout << "Movimientos necesarios para la unión de las cintas -> " << resultadoUnion << endl;
}
