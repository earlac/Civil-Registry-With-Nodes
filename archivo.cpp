#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Persona{
	string nombre;
	int edad;
	int provincia;
	string canton;
	string distrito;
	int sexo;
	int estCivil;
	int sueldo;
	int annosTrabajando;
	int cantHijos;
	int tipoAlimentacion;
	int tipoComida;
	string hobby;
	int tipoMusica;
	int cedula;

	/*
	Persona(string nNombre, int nEdad, int nProvincia, string nCanton, string nDistrito, int nSexo, int nEstCivil, int nSueldo, int nAnnosTrabajando, int nCantHijos, int nTipoAlimentacion, int nTipoComida, string nHobby, int nTipoMusica, int nCedula){
		nombre = nNombre;
		edad = nEdad;
		provincia = nProvincia;
		canton = nCanton;
		distrito = nDistrito;
		sexo = nSexo;
		estCivil = nEstCivil;
		sueldo = nSueldo;
		annosTrabajando = nAnnosTrabajando;
		cantHijos = nCantHijos;
		tipoAlimentacion = nTipoAlimentacion;
		tipoComida = nTipoComida;
		hobby = nHobby;
		tipoMusica = nTipoMusica;
		cedula = nCedula;
	}
	*/
};
void setNombre(Persona *p, int nNombre){p->nombre= nNombre;}
void setEdad(Persona *p, int nEdad){p->edad= nEdad;}
void setProvincia(Persona *p, int nProvincia){p->provincia= nProvincia;}
void setCanton(Persona *p, int nCanton){p->canton= nCanton;}
void setDistrito(Persona *p, int nDistrito){p->distrito= nDistrito;}
void setSexo(Persona *p, int nSexo){p->sexo= nSexo;}
void setEstcivil(Persona *p, int nEstcivil){p->estCivil= nEstcivil;}
void setSueldo(Persona *p, int nSueldo){p->sueldo= nSueldo;}
void setAnnostrabajando(Persona *p, int nAnnostrabajando){p->annosTrabajando= nAnnostrabajando;}
void setCanthijos(Persona *p, int nCanthijos){p->cantHijos= nCanthijos;}
void setTipoalimentacion(Persona *p, int nTipoalimentacion){p->tipoAlimentacion= nTipoalimentacion;}
void setTipocomida(Persona *p, int nTipocomida){p->tipoComida= nTipocomida;}
void setHobby(Persona *p, int nHobby){p->hobby= nHobby;}
void setTipomusica(Persona *p, int nTipomusica){p->tipoMusica= nTipomusica;}
void setCedula(Persona *p, int nCedula){p->cedula= nCedula;}

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
	Persona p;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		cout<<"\nNombre: "<<p.nombre<<" Edad: "<<p.edad<<endl;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
}

//-------------------| Methods |---------------------

//-------|Find person using ID or name |---------

void buscarId(){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		cout<<"\nNombre: "<<p.nombre<<" Edad: "<<p.edad<<endl;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
}

void imprimirPersona(int reg){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
	int contador = 0;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.seekp(reg*sizeof(p), ios::beg);
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	cout<<"\nNombre: "<<p.nombre<<" Edad: "<<p.edad<<endl;
	archivo.close();
}

void cargarDatos(){

	cout<<"El tamano en bits de la estructura persona: "<<sizeof(Persona);
//string nNombre, int nEdad, int nProvincia, string nCanton, string nDistrito, int nSexo, int nEstCivil, int nSueldo, 
//int nAnnosTrabajando, int nCantHijos, int nTipoAlimentacion, int nTipoComida, string nHobby, int nTipoMusica, int nCedula
	Persona p = {"Areck", 19, 3, "La Union", "San Rafael",1, 2, 489000, 1, 0, 1, 2, "Ejercicio", 3, 118540199};
	escribir(p);

	Persona p2 = {"Brenda", 20, 3, "La Union", "San Juan", 2, 2, 480000, 15, 0, 1, 3, "Leer", 1, 118330375};
	escribir(p2);

	Persona p3 = {"Ana", 19, 3, "Cartago", "Quircot", 2, 2, 150000, 15, 0, 1, 3, "Guitarra", 1, 119440295};
	escribir(p3);
	
	leer();

	//Persona nueva = {"Mauricio", 20, 3, "El  Guarco", "Tejar", 1, 2, 300000, 5, 0, 1, 2, "Guitarra", 8, 119540199};
	//modificar(nueva,1);

	//leer();

}

int main(){
	cargarDatos();
	cout<<"\nImprimir"<<endl;
	imprimirPersona(0);

	std::ofstream ofs;
	ofs.open("archivobinario.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	return 0;
}
