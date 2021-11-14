#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Persona{
    int id;
	string nombre;
	int edad;
	string provincia;
	string canton;
	string distrito;
	string sexo;
	string estCivil;
	int sueldo;
	int annosTrabajando;
	int cantHijos;
	string tipoAlimentacion;
	string tipoComida;
	string hobby;
	string tipoMusica;
    int cedula;
	
};
/*
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
*/

//-------------------| Methods |---------------------

void escribir(Persona p){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}

	archivo.seekp(0, ios::end);
	archivo.write(reinterpret_cast<char*>(&p), sizeof(p));
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
        cout<<"\nNombre: "<<p.nombre<<" Cedula: "<<p.cedula<<" Edad: "<<p.edad<<" annos "<<"\nProvincia: "<<p.provincia<<" Canton: "<<p.canton<<" Distrito: "
        <<p.distrito<<" Sexo: "<<p.sexo<<" Estado Civil: "<<p.estCivil<<"\nSueldo: "<<p.sueldo<<" Annos Trabajando: "
        <<p.annosTrabajando<<" Cantidad de Hijos: "<<p.cantHijos<<"\nTipo de Alimentacion: "<<p.tipoAlimentacion<<" Tipo de Comida: "
        <<p.tipoComida<<" Hobby: "<<p.hobby<<" Tipo de Musica: "<<p.tipoMusica<<endl;
	}
	archivo.close();
}

//-------|Pedir|--------

int pedirInt(string peticion){
/*
Inputs: 
        string that prints the request to the user for which the number is for 
Process:
        asks user for a number, the reason depends on the string entered
Outputs:
        User input
*/
    int num;
    cout<<peticion;
    while(!(cin>>num)){
        cin.clear();
        while(cin.get() != '\n')
            continue;   
        cout<<"Favor digitar solo numeros"<<endl;
        return pedirInt(peticion); 
    }
    return num;   
}

string pedirString(string peticion){
/*
Inputs: 
        peticion: personalizes the request of the string to the user
Process:
        Asks user for a string regarding peticion
Outputs:
        string written by the user
*/
    string nString;
    cout<<peticion;
    cin>>nString;
    return nString;
}

//-------|Find person using ID or name |---------

void buscarId(int id){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
    int contador = 0;
    bool encontrado = false;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		if(p.cedula == id){
            cout<<"\nNombre: "<<p.nombre<<" Cedula: "<<p.cedula<<" Edad: "<<p.edad<<" annos "<<"\nProvincia: "<<p.provincia<<" Canton: "<<p.canton<<" Distrito: "
            <<p.distrito<<" Sexo: "<<p.sexo<<" Estado Civil: "<<p.estCivil<<"\nSueldo: "<<p.sueldo<<" Annos Trabajando: "
            <<p.annosTrabajando<<" Cantidad de Hijos: "<<p.cantHijos<<"\nTipo de Alimentacion: "<<p.tipoAlimentacion<<" Tipo de Comida: "
            <<p.tipoComida<<" Hobby: "<<p.hobby<<" Tipo de Musica: "<<p.tipoMusica<<endl;
            cout<<"Posicion: "<<contador<<endl;
            encontrado = true;
        }
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
    if(encontrado==true)return;
}

void buscarNombre(string pNombre){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
    int contador = 0;
    bool encontrado = false;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		if(p.nombre == pNombre){
            cout<<"\nNombre: "<<p.nombre<<" Cedula: "<<p.cedula<<" Edad: "<<p.edad<<" annos "<<"\nProvincia: "<<p.provincia<<" Canton: "<<p.canton<<" Distrito: "
            <<p.distrito<<" Sexo: "<<p.sexo<<" Estado Civil: "<<p.estCivil<<"\nSueldo: "<<p.sueldo<<" Annos Trabajando: "
            <<p.annosTrabajando<<" Cantidad de Hijos: "<<p.cantHijos<<"\nTipo de Alimentacion: "<<p.tipoAlimentacion<<" Tipo de Comida: "
            <<p.tipoComida<<" Hobby: "<<p.hobby<<" Tipo de Musica: "<<p.tipoMusica<<endl;
            cout<<"Posicion: "<<contador<<endl;
            encontrado = true;
        }
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
    if(encontrado==true)return;
}

int buscarPos(int id){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
    int contador = 0;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
		if(p.cedula == id){
            return contador;
        }
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
    archivo.close();
    return contador;
}

void buscarPorPos(int reg){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    cout<<"\nNombre: "<<p.nombre<<" Cedula: "<<p.cedula<<" Edad: "<<p.edad<<" annos "<<"\nProvincia: "<<p.provincia<<" Canton: "<<p.canton<<" Distrito: "
    <<p.distrito<<" Sexo: "<<p.sexo<<" Estado Civil: "<<p.estCivil<<"\nSueldo: "<<p.sueldo<<" Annos Trabajando: "
    <<p.annosTrabajando<<" Cantidad de Hijos: "<<p.cantHijos<<"\nTipo de Alimentacion: "<<p.tipoAlimentacion<<" Tipo de Comida: "
    <<p.tipoComida<<" Hobby: "<<p.hobby<<" Tipo de Musica: "<<p.tipoMusica<<endl;
	archivo.close();
}

void modificarNombre(int cedula, string nNombre){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, nNombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarEdad(int cedula, int nEdad){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, nEdad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarProvincia(int cedula, string nProvincia){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, nProvincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarCanton(int cedula, string nCanton){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, nCanton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarDistrito(int cedula, string nDistrito){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, nDistrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarSexo(int cedula, string nSexo){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, nSexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarEstcivil(int cedula, string nEstcivil){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, nEstcivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarSueldo(int cedula, int nSueldo){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, nSueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarAnnostrabajando(int cedula, int nAnnostrabajando){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, nAnnostrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarCanthijos(int cedula, int nCanthijos){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, nCanthijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarTipoalimentacion(int cedula, string nTipoalimentacion){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, nTipoalimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarTipocomida(int cedula, string nTipocomida){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, nTipocomida, p.hobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarHobby(int cedula, string nHobby){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, nHobby, p.tipoMusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarTipomusica(int cedula, string nTipomusica){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, nTipomusica, p.cedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

void modificarCedula(int cedula, int nCedula){
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    int reg = buscarPos(cedula);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    
    Persona nueva = {p.id, p.nombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, nCedula};

    archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	archivo.close();
}
        

//void modificarPersona(int cedula, string nombre){
//    int pos = buscarPos(cedula);
//    modificarNombre(pos);
//}

void imprimirPersona(int reg){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.seekp(reg*sizeof(p), ios::beg);
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	archivo.close();
}

void cargarDatos(){

	cout<<"El tamano en bits de la estructura persona: "<<sizeof(Persona);
//string nNombre, int nEdad, int nProvincia, string nCanton, string nDistrito, int nSexo, int nEstCivil, int nSueldo, 
//int nAnnosTrabajando, int nCantHijos, int nTipoAlimentacion, int nTipoComida, string nHobby, int nTipoMusica, int nCedula

Persona p0 = {0, "name",   50, " Alajuela", "canton", "distrito", " Hombre", " Divorciado", 235818, 0, 3, " Vegetariano", " Ninguno", " DibujarBailar", " Merengue", 545012188};
escribir(p0);

        

Persona p1 = {1, "name",   22, " Heredia", "canton", "distrito", " Prefiero no decirlo", " Juntado", 675292, 7, 2, " Vegetariano", " Mediterraneo", " Leer", " Rancheras", 219306035};
escribir(p1);

        

Persona p2 = {2, "name",   22, " Alajuela", "canton", "distrito", " Prefiero no decirlo", " Casado", 579926, 1, 1, " Omnivoro", " Ninguno", " DibujarBailar", " Rap", 618116829};
escribir(p2);

        

Persona p3 = {3, "name",   49, " Alajuela", "canton", "distrito", " Hombre", " Juntado", 617355, 2, 3, " Vegetariano", " Criollo", " Ejercicio", " Plancha", 228110672};
escribir(p3);

        

Persona p4 = {4, "name",   24, " Alajuela", "canton", "distrito", " Prefiero no decirlo", " Soltero", 288376, 5, 2, " Vegetariano", " Coreano", " Correr", " Metal", 483620093};
escribir(p4);

        

Persona p5 = {5, "name",   43, " Guanacaste", "canton", "distrito", " Mujer", " Soltero", 648240, 8, 0, " Carnivoro", " Mexicano", " Cantar", " Indie", 423575889};
escribir(p5);

        

Persona p6 = {6, "name",   34, " Limon", "canton", "distrito", " No binario", " Juntado", 272338, 8, 3, " Vegano", " Ninguno", " Cantar", " Electronica", 341595615};
escribir(p6);

        

Persona p7 = {7, "name",   26, " San Jose", "canton", "distrito", " Mujer", " Soltero", 104893, 7, 0, " Omnivoro", " Salado", " Leer", " Reggaeton", 741722988};
escribir(p7);

        

Persona p8 = {8, "name",   50, " Cartago", "canton", "distrito", " Hombre", " Soltero", 451472, 4, 0, " Vegetariano", " Criollo", " Idiomas", " Reggaeton", 581902812};
escribir(p8);

        

Persona p9 = {9, "name",   37, " Heredia", "canton", "distrito", " Hombre", " Casado", 318752, 6, 3, " Vegano", " Ninguno", " Ejercicio", " Pop", 231584042};
escribir(p9);

        

Persona p10 = {10, "name",   29, " Heredia", "canton", "distrito", " Hombre", " Casado", 314253, 2, 4, " Herbivoro", " Dulce", " Idiomas", " Bachata", 448297849};
escribir(p10);

        

Persona p11 = {11, "name",   38, " San Jose", "canton", "distrito", " Prefiero no decirlo", " Juntado", 130989, 0, 2, " Carnivoro", " Mexicano", " Ejercicio", " Balada", 402095587};
escribir(p11);

        

Persona p12 = {12, "name",   33, " Guanacaste", "canton", "distrito", " Prefiero no decirlo", " Divorciado", 448634, 7, 3, " Vegetariano", " Criollo", " Cantar", " Reggaeton", 539990874};
escribir(p12);

        

Persona p13 = {13, "name",   19, " Limon", "canton", "distrito", " Prefiero no decirlo", " Soltero", 123116, 7, 3, " Omnivoro", " Mediterraneo", " Correr", " Balada", 601478504};
escribir(p13);

        

Persona p14 = {14, "name",   46, " Limon", "canton", "distrito", " Mujer", " Soltero", 221785, 1, 2, " Herbivoro", " Salado", " Cantar", " Rancheras", 299947816};
escribir(p14);

        

Persona p15 = {15, "name",   19, " Cartago", "canton", "distrito", " Hombre", " Juntado", 73888, 6, 3, " Carnivoro", " Ninguno", " Guitarra", " Electronica", 635722895};
escribir(p15);

        

Persona p16 = {16, "name",   42, " Limon", "canton", "distrito", " No binario", " Divorciado", 630144, 0, 0, " Vegano", " Salado", " Ejercicio", " Bachata", 385522440};
escribir(p16);

        

Persona p17 = {17, "name",   30, " Limon", "canton", "distrito", " Mujer", " Divorciado", 362763, 5, 1, " Herbivoro", " Mexicano", " Cantar", " Electronica", 354175593};
escribir(p17);

        

Persona p18 = {18, "name",   51, " San Jose", "canton", "distrito", " Prefiero no decirlo", " Soltero", 466411, 6, 0, " Vegano", " Criollo", " Idiomas", " Reggaeton", 764538659};
escribir(p18);

        

Persona p19 = {19, "name",   31, " Limon", "canton", "distrito", " Prefiero no decirlo", " Juntado", 431982, 7, 2, " Vegetariano", " Mexicano", " Guitarra", " Merengue", 448832513};
escribir(p19);

        

Persona p20 = {20, "name",   40, " Puntarenas", "canton", "distrito", " Mujer", " Soltero", 253105, 5, 4, " Vegano", " Mexicano", " Cantar", " Metal", 557364289};
escribir(p20);

        

Persona p21 = {21, "name",   48, " Alajuela", "canton", "distrito", " Mujer", " Divorciado", 138442, 2, 1, " Carnivoro", " Coreano", " Cantar", " Plancha", 705243648};
escribir(p21);

        

Persona p22 = {22, "name",   39, " Puntarenas", "canton", "distrito", " Hombre", " Casado", 207656, 1, 2, " Omnivoro", " Ninguno", " Idiomas", " Ninguno", 692350022};
escribir(p22);

        

Persona p23 = {23, "name",   20, " San Jose", "canton", "distrito", " Prefiero no decirlo", " Divorciado", 87179, 0, 4, " Herbivoro", " Ninguno", " Leer", " Electronica", 549075936};
escribir(p23);

        

Persona p24 = {24, "name",   29, " San Jose", "canton", "distrito", " Prefiero no decirlo", " Soltero", 77341, 2, 1, " Carnivoro", " Criollo", " Leer", " Salsa", 495231020};
escribir(p24);

        

Persona p25 = {25, "name",   24, " Cartago", "canton", "distrito", " Hombre", " Soltero", 538637, 5, 2, " Omnivoro", " Criollo", " Cantar", " Bachata", 689636910};
escribir(p25);

        

Persona p26 = {26, "name",   42, " Alajuela", "canton", "distrito", " Hombre", " Soltero", 76142, 5, 1, " Herbivoro", " Ninguno", " Correr", " Salsa", 702404935};
escribir(p26);

        

Persona p27 = {27, "name",   31, " Puntarenas", "canton", "distrito", " Prefiero no decirlo", " Soltero", 558374, 6, 0, " Herbivoro", " Coreano", " Ejercicio", " Salsa", 450014061};
escribir(p27);

        

Persona p28 = {28, "name",   39, " San Jose", "canton", "distrito", " No binario", " Divorciado", 360792, 2, 0, " Omnivoro", " Coreano", " Guitarra", " Rap", 372060145};
escribir(p28);

        

Persona p29 = {29, "name",   21, " San Jose", "canton", "distrito", " No binario", " Juntado", 737219, 8, 0, " Carnivoro", " Mediterraneo", " Ejercicio", " Reggaeton", 742679609};
escribir(p29);

        

Persona p30 = {30, "name",   30, " Guanacaste", "canton", "distrito", " Mujer", " Juntado", 386951, 1, 3, " Omnivoro", " Criollo", " Leer", " Rancheras", 472749513};
escribir(p30);

        

Persona p31 = {31, "name",   37, " Heredia", "canton", "distrito", " Mujer", " Divorciado", 384114, 2, 1, " Vegetariano", " Criollo", " Correr", " Balada", 562866850};
escribir(p31);

        

Persona p32 = {32, "name",   30, " Limon", "canton", "distrito", " Mujer", " Juntado", 551478, 2, 3, " Carnivoro", " Dulce", " Cantar", " Salsa", 614068822};
escribir(p32);

        

Persona p33 = {33, "name",   25, " Limon", "canton", "distrito", " Hombre", " Casado", 81108, 5, 0, " Omnivoro", " Ninguno", " Cantar", " Rap", 536709808};
escribir(p33);

        

Persona p34 = {34, "name",   30, " Cartago", "canton", "distrito", " No binario", " Casado", 125865, 3, 0, " Omnivoro", " Dulce", " DibujarBailar", " Salsa", 707779887};
escribir(p34);

        

Persona p35 = {35, "name",   23, " Heredia", "canton", "distrito", " Prefiero no decirlo", " Juntado", 70617, 8, 4, " Omnivoro", " Ninguno", " Idiomas", " Reggaeton", 197703317};
escribir(p35);

        

Persona p36 = {36, "name",   30, " Alajuela", "canton", "distrito", " Hombre", " Casado", 244092, 0, 3, " Herbivoro", " Mediterraneo", " DibujarBailar", " Balada", 616383956};
escribir(p36);

        

Persona p37 = {37, "name",   47, " San Jose", "canton", "distrito", " Prefiero no decirlo", " Casado", 184908, 5, 1, " Vegano", " Criollo", " Leer", " Rap", 239993335};
escribir(p37);

        

Persona p38 = {38, "name",   45, " Heredia", "canton", "distrito", " Mujer", " Divorciado", 585473, 7, 4, " Vegetariano", " Dulce", " Ejercicio", " Indie", 651083742};
escribir(p38);

        

Persona p39 = {39, "name",   29, " Heredia", "canton", "distrito", " No binario", " Soltero", 304264, 5, 1, " Vegano", " Mediterraneo", " Guitarra", " Rancheras", 477803080};
escribir(p39);

        

Persona p40 = {40, "name",   35, " San Jose", "canton", "distrito", " Mujer", " Juntado", 376225, 8, 3, " Vegano", " Dulce", " Correr", " Reggaeton", 347383831};
escribir(p40);

        

Persona p41 = {41, "name",   36, " Cartago", "canton", "distrito", " Hombre", " Juntado", 518929, 3, 3, " Carnivoro", " Criollo", " Leer", " Salsa", 172889982};
escribir(p41);

        

Persona p42 = {42, "name",   26, " San Jose", "canton", "distrito", " No binario", " Juntado", 477369, 4, 0, " Vegano", " Criollo", " Cantar", " Rancheras", 295654304};
escribir(p42);

        

Persona p43 = {43, "name",   39, " Heredia", "canton", "distrito", " Mujer", " Casado", 360039, 6, 1, " Carnivoro", " Ninguno", " Guitarra", " Merengue", 588040450};
escribir(p43);

        

Persona p44 = {44, "name",   24, " Heredia", "canton", "distrito", " No binario", " Casado", 574829, 7, 0, " Omnivoro", " Ninguno", " Leer", " Plancha", 327745362};
escribir(p44);

        

Persona p45 = {45, "name",   28, " Guanacaste", "canton", "distrito", " No binario", " Soltero", 612153, 2, 2, " Vegetariano", " Dulce", " Cantar", " Pop", 620099299};
escribir(p45);

        

Persona p46 = {46, "name",   45, " Limon", "canton", "distrito", " Mujer", " Divorciado", 380469, 6, 2, " Vegetariano", " Criollo", " Idiomas", " Merengue", 543272214};
escribir(p46);

        

Persona p47 = {47, "name",   44, " Alajuela", "canton", "distrito", " Hombre", " Casado", 716810, 0, 1, " Carnivoro", " Criollo", " Cantar", " Metal", 657096129};
escribir(p47);

        

Persona p48 = {48, "name",   29, " Heredia", "canton", "distrito", " Hombre", " Soltero", 595546, 2, 1, " Vegano", " Coreano", " Cantar", " Bachata", 154644921};
escribir(p48);

        

Persona p49 = {49, "name",   43, " Limon", "canton", "distrito", " Mujer", " Divorciado", 208062, 7, 3, " Vegetariano", " Salado", " DibujarBailar", " Plancha", 159095845};
escribir(p49);

        

    cout<<"Las personas han sido ingresadas en el archivo satisfactoriamente."<<endl;
}

void menuPrincipal();

void menuModificar(){
/*
Inputs: 
        string opcionMenuAdmin.
Process:
        Displays a menu, asks for input, leads user to option chosen.
Outputs:
        Menu chosen by the user.
*/
    cout<<"\n-------------------------"<<endl;
    cout<<"--Menu de Modificaciones--"<<endl;
    cout<<"\nEscoja e ingrese el numero de la opcion seleccionada:"<<endl;
    cout<<"1- Nombre\n2- Cedula\n3- Edad\n4- Provincia\n5- Canton\n6- Distrito\n7- Sexo\n8- Estado Civil\n9- Sueldo\n10- Annos Trabajando\n11- Cantidad Hijos\n12- Tipo Alimentacion\n13- Tipo de Comida\n14- Hobby\n15- Tipo de Musica\n\n16- Volver al menu principal\nOpcion: ";
    
    string opcion;
    
    cin>>opcion;
    string pedir = "Ingrese la cedula de la persona: ";
    
    if(opcion =="1"){
        modificarNombre(pedirInt(pedir), pedirString("Ingrese el nuevo nombre: "));
        menuModificar();
    }
    else if(opcion == "2"){
        modificarCedula(pedirInt(pedir), pedirInt("Ingrese la nueva cedula: "));
        menuModificar();
    }
    else if(opcion == "3"){
        modificarEdad(pedirInt(pedir), pedirInt("Ingrese la nueva edad de la persona: "));
        menuModificar();
    }
    else if(opcion == "4"){
        modificarProvincia(pedirInt(pedir), pedirString("Ingrese el numero de la nueva provincia: "));
        menuModificar();
    }
    else if(opcion == "5"){
        modificarCanton(pedirInt(pedir), pedirString("Ingrese el nuevo nombre del canton: "));
        menuModificar();
    }
    else if(opcion == "6"){
        modificarDistrito(pedirInt(pedir), pedirString("Ingrese el nuevo distrito: "));
        menuModificar();
    }
    else if(opcion == "7"){
        modificarSexo(pedirInt(pedir), pedirString("Ingrese el nuevo sexo: "));
        menuModificar();
    }
    else if(opcion == "8"){
        modificarEstcivil(pedirInt(pedir), pedirString("Ingrese el nuevo estado civil: "));
        menuModificar();

    }
    else if(opcion == "9"){
        modificarSueldo(pedirInt(pedir), pedirInt("Ingrese el nuevo sueldo: "));
        menuModificar();

    }
    else if(opcion == "10"){
        modificarAnnostrabajando(pedirInt(pedir), pedirInt("Ingrese la nueva cantidad de annos trabajando: "));
        menuModificar();

    }
    else if(opcion == "11"){
        modificarCanthijos(pedirInt(pedir), pedirInt("Ingrese la nueva cantidad de hijos: "));
        menuModificar();

    }
    else if(opcion == "12"){
        modificarTipoalimentacion(pedirInt(pedir), pedirString("Ingrese el nuevo tipo de alimentacion: "));
        menuModificar();

    }
    else if(opcion == "13"){
        modificarTipocomida(pedirInt(pedir), pedirString("Ingrese el nuevo tipo de Comida: "));
        menuModificar();

    }
    else if(opcion == "14"){
        modificarHobby(pedirInt(pedir), pedirString("Ingrese el nuevo hobby: "));
        menuModificar();

    }else if(opcion == "15"){
        modificarTipomusica(pedirInt(pedir), pedirString("Ingrese el nuevo tipo de musica: "));
        menuModificar();
    }else if(opcion == "16"){
        menuPrincipal();
    }else{
        cout<<"Ingrese una opcion valida."<<endl;
        menuModificar();
    }
}

void menuPrincipal(){
/*
Inputs: 
        Number of choice.
Process:
        Displays the main menu for user to choose between the opcions.
Outputs:
        Respective function in the system.
*/
    cout<<"\n\n"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"--------------Avance del segundo proyecto: Archivos-------------"<<endl;
    cout<<"----------------------------------------------------------------\n"<<endl;
    cout<<"Ingrese el numero de la opcion deseada: \n 1- Buscar persona por ID\n 2- Buscar persona por nombre\n 3- Buscar persona por posicion \n 4- Modificar persona \n 5- Salir\n\nNumero: ";
    string opcion;
    cin>>opcion;
    if(opcion=="1"){
        buscarId(pedirInt("Ingrese la cedula de la persona a buscar: "));
        menuPrincipal();
    }else if(opcion=="2"){
        buscarNombre(pedirString("Ingrese el nombre la persona a buscar: "));
        menuPrincipal();
    }else if(opcion=="3"){
        buscarPorPos(pedirInt("Ingrese la posicion en el archivo de la persona a buscar: "));
        menuPrincipal();
    }else if(opcion=="4"){
        menuModificar();
    }else if(opcion=="5"){
        cout<<"\n\nSaliendo...\n\n";
        cout<<"Gracias por usar nuestro sistema! (Profe porfa ponganos 100)"<<endl;
        system("pause");
        return;
    }else{
        cout<<"Ingrese una opcion valida.";
        menuPrincipal();
    }
}
int main(){
    ofstream archivo("archivobinario.txt");
    cout<<"\n\n\t\tCargando Datos...\n\n";
	cargarDatos();
    //buscarId(521424187);
    //modificarPersona(521424187, "Juana");
    //cout<<"Se termino de modificar"<<endl;
    //buscarId(521424187);
	menuPrincipal();
	return 0;
}
