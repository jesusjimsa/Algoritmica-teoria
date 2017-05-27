//
//  gasolineras.cpp
//  Relación Greedy
//
//  Created by Jesús Jiménez Sánchez on 27/5/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


int Seleccion(vector<int> &gasolineras, int kmDeposito){
	int lejana = 0;
	bool terminar = false;
	
	for(auto it = gasolineras.begin(); it != gasolineras.end() && !terminar; it++){
		kmDeposito -= (*it);
		lejana += (*it);
		
		if(kmDeposito < 0){
			kmDeposito += (*it);
			lejana -= (*it);
			terminar = true;
		}

		if(!gasolineras.empty()){
			it = gasolineras.erase(it);
		}
	}
	
	return lejana;
}

vector<int> gasolinerasVoraz(vector<int> gasolineras, const int kmDeposito){
	vector<int> planViaje;
	int repostaje = -1;
	
	for (int i = 0; !gasolineras.empty(); i++) {
		repostaje = Seleccion(gasolineras, kmDeposito);
		planViaje.push_back(repostaje);
	}
	
	return planViaje;
}

int main(){
	int tam = 50;     // Tamaño del vector

	// Generación del vector aleatorio
	vector<int> v;
	int kmDeposito = 200;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios

	for (int i = 0; i < tam; i++)  // Recorrer vector
		v.push_back((rand() % 60) + 20);

	high_resolution_clock::time_point start, end;	//Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    //Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    //Iniciamos el punto de inicio

	v = gasolinerasVoraz(v, kmDeposito);

	end = high_resolution_clock::now();    //Anotamos el punto de de fin

	//El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);

	//Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
	
	cout << "Recorridos entre gasolineras:" << endl;
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << ", ";
	}
	
	cout << endl;
}
