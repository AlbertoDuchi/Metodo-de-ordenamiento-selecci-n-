#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
void generaNumeros(vector<int> &listado, int numElementos);
void mostrarNumeros(vector<int> listado, string titulo);
void ordenarSeleccion(vector<int> &listado);
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
	generaNumeros(listado,  numElementos);
	//mostrar
    mostrarNumeros(listado,"Listado");
	//ordenar
	ordenarSeleccion(listado);
	cout<<endl;
	mostrarNumeros(listado,"Listado Ordenado");	
	return 0;
};
void generaNumeros(	vector<int> &listado,  int numElementos){
	//generar numeros
	srand(time(NULL));
	for(int i=0;i<numElementos;i++){
		listado.push_back((1+rand()%(100-1)));
	};	
};
void mostrarNumeros(vector<int> listado, string titulo){
//mostrar
	cout<<"\n"<<titulo<<"\n";
	int cuentaDatos=0;
	for(auto i: listado){
		if(cuentaDatos==10){
			cout<<endl;
			cuentaDatos=0;
		}
		cout<<i<<"\t";
		cuentaDatos++;
	}	
};
void ordenarSeleccion(vector<int> &listado){
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
};