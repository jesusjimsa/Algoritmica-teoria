//
//  seleccion_multiple.cpp
//  Relación 2: Divide y Vencerás
//
//  Created by Jesús Jiménez Sánchez on 1/5/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> SeleccionMultiple(vector<int> desordenado, vector<int> posiciones){
	vector<int> resultado;
	priority_queue<int> ordenacion;
	auto pos_it = posiciones.begin();
	int i = 0;
	
	for(int i = 0; i < desordenado.size(); i++){
		ordenacion.push(desordenado[i]);
	}
	
	for(auto it = desordenado.begin(); it != desordenado.end(); ++it){
		if(i == (*pos_it)){
			resultado.push_back(*it);
			++pos_it;
		}
		
		i++;
	}
	
	return resultado;
}

int main(){
	vector<int> v(8);
	vector<int> pos(3);
	vector<int> jeje;
	
	v[0] = 8;
	v[1] = 14;
	v[2] = 5;
	v[3] = 7;
	v[4] = 3;
	v[5] = 1;
	v[6] = 25;
	v[7] = 2;
	
	pos[0] = 2;
	pos[1] = 5;
	pos[2] = 7;
	
	cout << "Tamaño = " << v.size() << endl;
	jeje = SeleccionMultiple(v, pos);
	
	for(int i = 0; i < jeje.size(); i++){
		cout << jeje[i] << endl;
	}
}











































