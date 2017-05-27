//
//  tornillo.cpp
//  Relación 2: Divide y Vencerás
//
//  Created by Jesús Jiménez Sánchez on 29/4/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void Intercambiar(int &i, int &j){
	int aux = i;
	i = j;
	j = aux;
}

int Pivote(int *v, int i, int j, int pos){
	int piv, k, l;
	k = i;
	l = j + 1;
	piv = v[pos];
	
	do{
		k = k + 1;
	} while(v[k] <= piv && k < j);
	
	do{
		l = l - 1;
	} while(v[l] > piv);
	
	while(k < l){
		Intercambiar(v[k], v[l]);
		do{
			k = k + 1;
		} while(v[k] <= piv);
		
		do{
			l = l-1;
		} while(v[l] > piv);
	}
	
	Intercambiar(v[i], v[l]);
	
	return l;
}

void TornillosTuercas(int *tornillos, int *tuercas, int n1, int n2){
	if(n1 < n2){
		int piv = Pivote(tornillos, n1, n2, n1);
		int i = n1;
		
		while (i <= n2 && tuercas[i] != tornillos[piv]){
			i++;
		}
		
		swap(tuercas[n1],tuercas[i]);
		Pivote(tuercas, n1, n2, n1);
		
		TornillosTuercas(tornillos, tuercas, n1, piv - 1);
		TornillosTuercas(tornillos, tuercas, piv + 1, n2);
	}
}

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "Hace falta un argumento que es el número de tornillos y tuercas." << endl;
		exit(-1);
	}
	
	int tam = atoi(argv[1]);
	
	int * tornillos = new int[tam];
	int * tuercas = new int[tam];
	bool * booleanos = new bool[tam];
	set<int> contenedor;
	
	srand((unsigned int)time(0));
	
	for(int i = 0; contenedor.size() != tam; i++){
		contenedor.insert(rand());
	}
	
	auto it = contenedor.begin();
	
	for(int i = 0; i < tam; i++){
		tornillos[i] = (*it);
		++it;
		
		booleanos[i] = false;
	}
	
	int pos;
	
	for(int i = 0; i < tam; i++){
		do{
			pos = rand() % tam;
		}while(booleanos[pos]);
		
		booleanos[pos] = true;
		tuercas[pos] = tornillos[pos];
	}
	
	high_resolution_clock::time_point start, end;	//Punto de inicio y de fin
	duration<double> tiempo_transcurrido;    //Objeto para medir la duracion de end y start
	start = high_resolution_clock::now();    //Iniciamos el punto de inicio
	
	TornillosTuercas(tornillos, tuercas, 0, tam - 1);
	
	end = high_resolution_clock::now();    //Anotamos el punto de de fin
	
	//El tiempo transcurrido es:
	tiempo_transcurrido = duration_cast< duration<double> > (end - start);
	
	//Mostramos resultados
	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
