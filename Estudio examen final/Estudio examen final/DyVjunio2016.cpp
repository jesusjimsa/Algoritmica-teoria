//
//  DyVjunio2016.cpp
//  Estudio examen final
//
//  Created by Jesús Jiménez Sánchez on 3/6/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> Peinado(vector<int> sin_peinar){
	if(sin_peinar.size() <= 10){
		bool abajo = true;	//En la parte baja del peine
		
		for(int i = 0; i < sin_peinar.size() - 1; i++){	//Con el -1 nos ahorramos muchos problemas de memoria más tarde
			if(abajo && sin_peinar[i] > sin_peinar[i + 1]){
				swap(sin_peinar[i], sin_peinar[i + 1]);
				abajo = true;
				i = 0;	//Se vuelve a empezar para comprobar que no se haya desajustado el vector
			}
			else{
				if(!abajo && sin_peinar[i] < sin_peinar[i + 1]){
					swap(sin_peinar[i], sin_peinar[i + 1]);
					abajo = true;
					i = 0;	//Se vuelve a empezar para comprobar que no se haya desajustado el vector
				}
				else{
					if(abajo){
						abajo = false;
					}
					else{
						abajo = true;
					}
				}
			}
		}
		
		return sin_peinar;
	}
	else{
		vector<int> primera_mitad(sin_peinar.begin(), sin_peinar.begin() + sin_peinar.size() / 2);
		vector<int> segunda_mitad(sin_peinar.begin() + (sin_peinar.size() / 2) + 1, sin_peinar.end());
		vector<int> guarda_first, guarda_second, resultado;
		
		guarda_first = Peinado(primera_mitad);
		guarda_second = Peinado(segunda_mitad);
		
		resultado = guarda_first;
		
		for(int i = 0; i < guarda_second.size(); i++){
			resultado.push_back(guarda_second[i]);
		}
		
		return resultado;
	}
}

int main(){
	int tam = 51;     // Tamaño del vector
	
	// Generación del vector aleatorio
	vector<int> v, resultado;
	
	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
	
	for (int i = 0; i < tam; i++)  // Recorrer vector
		v.push_back((rand() % 50) + 1);
	
	high_resolution_clock::time_point start, end;	//Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    //Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    //Iniciamos el punto de inicio
	
	resultado = Peinado(v);
	
	end = high_resolution_clock::now();    //Anotamos el punto de de fin
	
	//El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);
	
	//Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
//	cout << "Resultado de peinar el algoritmo: \n\t";
//	
//	for(int i = 0; i < resultado.size(); i++){
//		cout << resultado[i] << ", ";
//	}
	
	cout << endl;
}
