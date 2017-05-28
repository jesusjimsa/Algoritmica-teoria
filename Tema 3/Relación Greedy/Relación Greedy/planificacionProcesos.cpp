//
//  planificacionProcesos.cpp
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

int min(vector< pair<char, int> > usado_TD){
	int min = 10000000;	// Valor muy alto
	int posicion = -1;
	
	for(int i = 0; i < usado_TD.size(); i++){
		if(usado_TD[i].first != 'U' && usado_TD[i].second < min){
			min = usado_TD[i].second;
			posicion = i;
		}
	}
	
	return posicion;
}

int Seleccion(vector< pair<char, int> > &usado_TD){
	int posicion;
	
	posicion = min(usado_TD);
	usado_TD[posicion].first = 'U';	// Usado
	
	return posicion;
}

vector<int> planificacionVoraz(vector< pair<int, int> > duracion_terminacion){
	vector<int> planificacion;
	vector< pair<char, int> > ordenacion;
	pair<char, int> valor_vector;
	
	valor_vector.first = 'N';	// No usado
	
	// Calculamos una especie de "heurística" y a partir de ahí haremos la planficación de procesos
	for(int i = 0; i < duracion_terminacion.size(); i++){
		valor_vector.second = duracion_terminacion[i].second - duracion_terminacion[i].first;
		ordenacion.push_back(valor_vector);
	}
	
	for(int i = 0; i < ordenacion.size(); i++){
		planificacion.push_back(Seleccion(ordenacion));
	}
	
	return planificacion;
}

int main(){
	int tam = 50;     // Tamaño del vector
	
	// Generación del vector aleatorio
	vector< pair<int, int> > v;
	vector<int> plan;
	pair<int, int> insertar;
	int duracion, terminacion;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i = 0; i < tam; i++){  // Recorrer vector
		duracion = (rand() % 99) + 1;
		terminacion = duracion + (rand() % 50) + 1;
		insertar.first = duracion;
		insertar.second = terminacion;
		v.push_back(insertar);
	}
	
	high_resolution_clock::time_point start, end;	// Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    // Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    // Iniciamos el punto de inicio
	
	plan = planificacionVoraz(v);
	
	end = high_resolution_clock::now();    // Anotamos el punto de de fin
	
	// El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);
	
	// Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
