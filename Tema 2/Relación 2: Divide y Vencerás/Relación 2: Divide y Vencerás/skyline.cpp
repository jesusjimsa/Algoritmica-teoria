//
//  skyline.cpp
//  Relación 2: Divide y Vencerás
//
//  Created by Jesús Jiménez Sánchez on 1/5/17.
//  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int Pivote(vector< pair< pair<int, int>, int > > &A, int p, int q){
	int x = A[p].first.first;
	int i = p;
	int j;

	for(j = p + 1; j < q; j++){
		if(A[j].first.first <= x){
			i = i + 1;

			swap(A[i], A[j]);
		}
	}

	swap(A[i], A[p]);

	return i;
}


void QuickSort(vector< pair< pair<int, int>, int > > &A, int p, int q){
	int r;

	if(p < q){
		r = Pivote(A, p, q);

		QuickSort(A, p, r);
		QuickSort(A, r + 1, q);
	}
}

vector< pair< pair<int, int>, int > > Skyline(vector< pair< pair<int, int>, int > > edificios, int &num, int &antes){
	//La función debe llamarse siempre con un 0 en num
	if(num == 0){
		QuickSort(edificios, 0, (int)edificios.size());
	}
	
	vector< pair< pair<int, int>, int > > silueta, recursivo;
	pair< pair<int, int>, int > sombra;
	
	if(num < edificios.size()){
		if(edificios[num].second > edificios[num + 1].second){
			if(num == 0){
				sombra.first.first = edificios[num].first.first;
			}
			else{
				sombra.first.first = antes;
			}
			
			sombra.first.second = edificios[num].first.second;
			sombra.second = edificios[num].second;
			silueta.push_back(sombra);
		}
		else{
			if(num == 0){
				sombra.first.first = edificios[num].first.first;
			}
			else{
				sombra.first.first = antes;
			}
			
			sombra.first.second = edificios[num + 1].first.first;
			sombra.second = edificios[num].second;
			silueta.push_back(sombra);
		}
		
		num++;
		antes = sombra.first.second;
		
		recursivo = Skyline(edificios, num, antes);
		
		silueta.insert(silueta.end(), recursivo.begin(), recursivo.end());
	}
	
	return silueta;
}

int main(){
	//(7,10,3), (9,12,7), (1,4,10), (3,8,5) y (11,13,10).
	vector< pair< pair<int, int>, int > > edificios, silueta;
	pair< pair<int, int>, int > bloques;
	int num, antes;
	
	num = antes = 0;
	
	bloques.first.first = 7;
	bloques.first.second = 10;
	bloques.second = 3;
	edificios.push_back(bloques);
	
	bloques.first.first = 9;
	bloques.first.second = 12;
	bloques.second = 7;
	edificios.push_back(bloques);
	
	bloques.first.first = 1;
	bloques.first.second = 4;
	bloques.second = 10;
	edificios.push_back(bloques);
	
	bloques.first.first = 3;
	bloques.first.second = 8;
	bloques.second = 5;
	edificios.push_back(bloques);
	
	bloques.first.first = 11;
	bloques.first.second = 13;
	bloques.second = 10;
	edificios.push_back(bloques);
	
	silueta = Skyline(edificios, num, antes);
	
	for(int i = 0; i < silueta.size(); i++){
		cout << "(" << silueta[i].first.first << ", " << silueta[i].first.second << ", " << silueta[i].second << ")" << endl;
	}
}
