#include<iostream>
using namespace std;
int main(){
	int A[]={9,3,7,1,5,4};
	int tamanio=sizeof A/ sizeof A[0];
	int minimo, aux;
	for(auto i: A){
		cout<<i<<" ";
	};
	//ordenar
	for(int i=0;i<tamanio;i++){//recorrer
		minimo=i;
		for(int j=i+1;j<tamanio;j++){
			if(A[j]<A[minimo]){
				minimo=j;
			}
		}	
		if(i!=minimo){
			aux=A[i];
			A[i]=A[minimo];
			A[minimo]=aux;				
		}

	};
	cout<<"\nDatos ordenados\n";
	for(auto i: A){
		cout<<i<<" ";
	};	
	return 0;
}