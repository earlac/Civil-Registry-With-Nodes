#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Persona{
	char nombre[10];
	int edad;
	char correo[20];
};

void escribir(Persona x){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}

	archivo.seekp(0, ios::end);
	archivo.write(reinterpret_cast<char*>(&x), sizeof(x));
	archivo.close();
}

void modificar(Persona nueva, int reg){
	fstream archivo("archivobinario.txt", ios::in|ios::out|ios::binary);

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}

	archivo.seekp(reg*sizeof(nueva), ios::beg);
	archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));

	archivo.close();
}

void leer(){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	struct Persona p;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		cout<<"\nNombre: "<<p.nombre<<" Edad: "<<p.edad<<" Correo: "<<p.correo<<endl;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
}

int main(){

	cout<<"El tamano en bits de la estructura persona: "<<sizeof(Persona);

	Persona p = {"Ana", 20, "ana@gmail.com"};
	escribir(p);

	Persona p2 = {"Carlos", 20, "carlos@gmail.com"};
	escribir(p2);

	Persona p3 = {"Melina", 20, "melina@gmail.com"};
	escribir(p3);

	leer();

	Persona nueva = {"Angel",23,"angel@gmail.com"};
	modificar(nueva,1);

	leer();

	return 0;
}