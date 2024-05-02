#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona();
		void setNombre(string nombre);
		void setEdad(int edad);
		string getNombre();
		int getEdad();
		string mostrarDatos();		
};
Persona::Persona(){
	nombre="S/N";
	edad=0;
};
void Persona::setNombre(string nombre){
	this->nombre=nombre;
};
void Persona::setEdad(int edad){
	this->edad=edad;	
};
string Persona::getNombre(){
	return nombre;	
};
int Persona::getEdad(){
	return edad;	
};
string Persona::mostrarDatos(){
	return (nombre+"\t"+to_string(edad));
};
void ingresoDatos(vector<Persona> &listado, int numElementos);
void mostrarDatos(vector<Persona> listado, string titulo);
void ordenaSeleccion(vector<Persona> &listado);
int main(){
	vector<Persona> listado;
	
	int numElementos;//1-100
	do{
		cout<<"Numero de elementos: ";
		cin>>numElementos;
		if(numElementos<2 || numElementos>100){
			cout<<"\tError...!!!\n";
		}
	}while(numElementos<2 || numElementos>100);	
	//ingreso de datos	
	ingresoDatos(listado,numElementos);
	mostrarDatos(listado, "datos");
	ordenaSeleccion(listado);
	mostrarDatos(listado, "datos ordenados");
	return 0;
};void ingresoDatos(vector<Persona> &listado, int numElementos){
	Persona persona;
	string nombre;
	int edad;
	for(int i=0;i<numElementos;i++){
		cout<<"Ingrese el nombre: ";
		getline(cin>>ws,nombre);
		cout<<"Ingrese la edad: ";
		cin>>edad;
		//guadar
		persona.setNombre(nombre);
		persona.setEdad(edad);
		listado.push_back(persona);

	}
};
void mostrarDatos(vector<Persona> listado, string titulo){
	cout<<"\n******* "<<titulo<<" *******\n";
	Persona persona;
	for(auto i: listado){
		persona=i;
		cout<<persona.mostrarDatos()<<endl;
	}
};
void ordenaSeleccion(vector<Persona> &listado){
	int minimo;
	for(int i=0;i<listado.size();i++){
		minimo=i;
		for(int j=i+1;j<listado.size();j++){
			if(listado[j].getNombre()<listado[minimo].getNombre()){
				minimo=j;
			}
		}
		swap(listado[i],listado[minimo]);
	}	
};