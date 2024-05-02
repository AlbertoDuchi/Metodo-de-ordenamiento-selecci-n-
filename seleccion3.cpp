#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
int main(){
	vector<int> listado;
	int numElementos;//1-100
	do{
		cout<<"Numero de elementos: ";
		cin>>numElementos;
		if(numElementos<2 || numElementos>100){
			cout<<"\tError...!!!\n";
		}
	}while(numElementos<2 || numElementos>100);
	//generar numeros
	srand(time(NULL));
	for(int i=0;i<numElementos;i++){
		listado.push_back((1+rand()%(100-1)));
	};
	//mostrar
	cout<<"\nLista de Datos\n";
	int cuentaDatos=0;
	for(auto i: listado){
		if(cuentaDatos==10){
			cout<<endl;
			cuentaDatos=0;
		}
		cout<<i<<"\t";
		cuentaDatos++;
	}
	//ordenar
	int minimo;
	for(int i=0;i<listado.size();i++){
		minimo=i;
		for(int j=i+1;j<listado.size();j++){
			if(listado[j]<listado[minimo]){
				minimo=j;
			}
		}
		swap(listado[i],listado[minimo]);
	}
	cout<<endl;
	//mostrar
	cout<<"\nLista de Datos\n";
	cuentaDatos=0;
	for(auto i: listado){
		if(cuentaDatos==10){
			cout<<endl;
			cuentaDatos=0;
		}
		cout<<i<<"\t";
		cuentaDatos++;
	}	
	return 0;
}