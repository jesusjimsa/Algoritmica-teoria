////
////  subsecuencia.cpp
////  Relación 2: Divide y Vencerás
////
////  Created by Jesús Jiménez Sánchez on 1/5/17.
////  Copyright © 2017 Jesús Jiménez Sánchez. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>  // Para generación de números pseudoaleatorios
//
//using namespace std;
//
//vector<int> subsecuencia(vector<int> grande){
//	vector<int> subsec;
//	
//	if(grande.size() < 3){
//		if(grande.size() == 1){
//			return grande;
//		}
//		else{
//			if(grande[0] < grande[1]){
//				return grande;
//			}
//			else{
//				subsec.push_back(grande[0]);
//				
//				return grande;
//			}
//		}
//	}
//	else{
//		vector<int> primero, segundo;
//		vector<int> recurfirst, recursec;
//		
//		primero = segundo = grande;
//		
//		auto it_prim = primero.begin();
//		auto it_seg = segundo.begin();
//		
//		it_prim += (primero.size() / 2);
//		it_seg += (segundo.size() / 2) + 1;
//		
//		primero.erase(it_prim, primero.end());	//Borramos la primera mitad
//		segundo.erase(segundo.begin(), it_seg);	//Borramos la segunda mitad
//		
//		recurfirst = subsecuencia(primero);	//Hacemos recursividad con la primera mitad
//		recursec = subsecuencia(segundo);	//También con la segunda
//		
//		primero.clear();
//		segundo.clear();
//		subsec.clear();
//		
//		for(int i = 0; i < recurfirst.size() - 1; i++){
//			if(recurfirst[i] < recurfirst[i + 1]){
//				primero.push_back(recurfirst[i]);
//				recurfirst.erase(recurfirst.begin());
//			}
//			else{
//				if(subsec.size() < primero.size()){
//					subsec = primero;
//				}
//				else{
//					primero.clear();
//				}
//			}
//		}
//		
//		subsec.clear();
//		
//		for(int i = 0; i < recursec.size() - 1; i++){
//			if(recursec[i] < recursec[i + 1]){
//				segundo.push_back(recursec[i]);
//				recursec.erase(recursec.begin());
//			}
//			else{
//				if(subsec.size() < segundo.size()){
//					subsec = segundo;
//				}
//				else{
//					primero.clear();
//				}
//			}
//		}
//		
//		/*
//			Si el último elemento de la primera mitad es menor o igual
//			que el primero de la segunda, los juntamos y lo devolvemos.
//		 */
//		if(recurfirst[recurfirst.size() - 1] <= recursec[0]){
//			subsec = recurfirst;
//			
//			subsec.insert(subsec.end(), recursec.begin(), recursec.end());
//			
//			return subsec;
//		}
//		else{	//Si no, devolvemos el de mayor tamaño
//			if(recurfirst.size() > recursec.size()){
//				return recurfirst;
//			}
//			else{
//				return recursec;
//			}
//		}
//	}
//	
//	return subsec;
//}
//
//vector<int> sub(vector<int> grande){
//	vector<int> dev, aux;
//	
//	if(grande.size() < 3){
//		if(grande.size() == 1){
//			return grande;
//		}
//		else{
//			if(grande[0] < grande[1]){
//				return grande;
//			}
//			else{
//				dev.push_back(grande[0]);
//				
//				return grande;
//			}
//		}
//	}
//	
//	for(int i = 0; i < grande.size() - 1; i++){
//		if(grande[i] < grande[i + 1]){
//			aux.push_back(grande[i]);
//			grande.erase(grande.begin());
//			i--;
//		}
//		else{
//			if(dev.size() < aux.size()){
//				dev = aux;
//			}
//			else{
//				aux.clear();
//			}
//		}
//	}
//	
//	return dev;
//}
//
//
//
//int main(){
//	vector<int> prueba;
//	
//	srand((unsigned int)time(0));            // Inicialización del generador de números pseudoaleatorios
//	
//	for (int i = 0; i < 20; i++){  // Recorrer vector
//		prueba.push_back(rand() % 100);    // Generar aleatorio [0,vmax[
//	}
//	
//	cout << "Vector original:" << endl;
//	
//	for(int i = 0; i < prueba.size(); i++){
//		cout << prueba[i] << ", ";
//	}
//	
//	cout << endl;
//	
//	prueba = sub(prueba);
//	
//	cout << "\n\nLa subsecuencia mayor es:" << endl;
//	
//	for(int i = 0; i < prueba.size(); i++){
//		cout << prueba[i] << ", ";
//	}
//	
//	cout << endl;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
