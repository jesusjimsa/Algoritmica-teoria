//
//  clasificacion.cpp
//  Relación 2: Divide y Vencerás
//
//  Created by Jesús Jiménez Sánchez on 1/5/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector< pair<int, int> > Clasificacion(vector< vector<char> > matriz_resultados, int &fil, int &col){
	vector< pair<int, int> > resultado, recursivo;
	pair<int, int> posicionGanador;
	const int COLUMNAS = (int)matriz_resultados.at(0).size() - 1;
	const int FILAS = (int)matriz_resultados.size() - 1;
	const char GANA = 'G';
	char elemento;
	
	if (fil != col){ // Sino son el mismo elemento
		elemento = matriz_resultados[fil][col];
		
		if (elemento == GANA){
			posicionGanador.first = fil;
			posicionGanador.second = col;
			
			resultado.push_back(posicionGanador);
		}
	}
	
	if(fil < FILAS){
		if(col == COLUMNAS){
			col = 0;
			fil++;
		}
		else{
			col++;
		}
		
		recursivo = Clasificacion(matriz_resultados, fil, col);
		
		resultado.insert(resultado.end(), recursivo.begin(), recursivo.end());
	}
	
	return resultado;
}

int main(){
	vector< pair<int, int> > resultados;
	vector< vector<char> > matriz;
	vector<char> aux;
	int i, j;
	
	i = j = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 20; j++){
			if((j % 5) == 0){
				aux.push_back('G');
			}
		}
		
		matriz.push_back(aux);
	}
	
	resultados = Clasificacion(matriz, i, j);
	
	for(int i = 0; i < resultados.size(); i++){
		cout << "Ganador  " << i << "\t->\t(" << resultados[i].first << ", " << resultados[i].second << ")" << endl;
	}
}
