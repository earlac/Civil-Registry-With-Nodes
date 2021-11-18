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
struct Indice{
    int posicion;

    Indice *sigInd;

    Indice(int nPosicion){
        posicion= nPosicion;

        sigInd=NULL;
    }
};

struct nodoArbolDecision{
    int cantidad;
    string nivel;
    string valor;

    nodoArbolDecision *sigNodo;
    nodoArbolDecision *sublistaHijos;
    Indice *sigInd;
    
    nodoArbolDecision(int nCantidad, string nNivel, string nValor){
        cantidad= nCantidad;
        nivel= nNivel;
        valor= nValor;

        sigNodo= NULL;
        sigInd= NULL;
        sublistaHijos=NULL;
    }

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
    /*
    F Person is given and has to add this person to the file
    I Person to add
    O file updated with person
    */
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
    /*
    F An id is given and returns the person with this value
    I value to search
    O Person that meets the requirement
    */
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
    /*
    F A name is given and returns the person with this value
    I value to search
    O Person that meets the requirement
    */
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
    /*
    F An id is given and returns the person with this value
    I value to search
    O Person that meets the requirement
    */
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
    /*
    F A position index is given and returns the person in this positiion
    I index
    O Person in this position
    */
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

int tamannoArchivo(){
    /*
    F measures the length of the list in th efile
    I na
    O how many persons are there in the file
    */
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
    int contador = 0;

	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
	archivo.read(reinterpret_cast<char*>(&p), sizeof(p));

	while(!archivo.eof()){
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
    archivo.close();
    return contador;
}

void modificarNombre(int cedula, string nNombre){
    /*
    F Modifies name of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies age of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies state of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies great regione of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies small region of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies gender of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies social status of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies payroll of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies years worked of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies children quantity of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies food category of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies food type of a specific person
    I Old value, new value
    O File updated with new info
    */
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
    /*
    F Modifies hobby of a specific person
    I Old value, new value
    O File updated with new info
    */
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
        /*
    F Modifies music type of a specific person
    I Old value, new value
    O File updated with new info
    */
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
        /*
    F Modifes the personal id of a person
    I new ID and old ID
    O person's info updated
    */
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
        

void imprimirPersona(int reg){
        /*
    F prints a given person information
    I index position
    O return person based in the index
    */
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
    /*
    F loads data into the file
    I na
    O new file with info updated
    */
	cout<<"El tamano en bits de la estructura persona: "<<sizeof(Persona);
//string nNombre, int nEdad, int nProvincia, string nCanton, string nDistrito, int nSexo, int nEstCivil, int nSueldo, 
//int nAnnosTrabajando, int nCantHijos, int nTipoAlimentacion, int nTipoComida, string nHobby, int nTipoMusica, int nCedula

Persona p0 = {0, "Enrique",   50, " Alajuela", "SAN JOSE", "San Fco.de Dos Ríos", "Hombre", "Divorciado", 235818, 0, 3, "Vegetariano", "Ninguno", "Dibujar", "Merengue", 545012188};
escribir(p0);

        

Persona p1 = {1, "Fer",   22, " Heredia", "DESAMPARADOS", "San Rafael Arriba", "Prefiero no decirlo", "Juntado", 675292, 7, 2, "Vegetariano", "Mediterraneo", "Leer", "Rancheras", 219306035};
escribir(p1);

        

Persona p2 = {2, "Ben",   22, " Alajuela", "SAN JOSE", "San Fco.de Dos Ríos", "Prefiero no decirlo", "Casado", 579926, 1, 1, "Omnivoro", "Ninguno", "Bailar", "Rap", 618116829};
escribir(p2);
     

Persona p3 = {3, "Axel",   49, " Alajuela", "PURISCAL", "Barbacoas", "Hombre", "Juntado", 617355, 2, 3, "Vegetariano", "Criollo", "Ejercicio", "Plancha", 228110672};
escribir(p3);

        

Persona p4 = {4, "Lao",   24, " Alajuela", "TARRAZU", "San Marcos", "Prefiero no decirlo", "Soltero", 288376, 5, 2, "Vegetariano", "Coreano", "Correr", "Metal", 483620093};
escribir(p4);

        

Persona p5 = {5, "Pamela",   43, " Guanacaste", "TARRAZU", "San Marcos", "Mujer", "Soltera", 648240, 8, 0, "Carnivoro", "Mexicano", "Cantar", "Indie", 423575889};
escribir(p5);

        

Persona p6 = {6, "Sandra",   34, " Limon", "SANTA ANA", "Salitral", "Mujer", "Juntada", 272338, 8, 3, "Vegano", "Ninguno", "Cantar", "Electronica", 341595615};
escribir(p6);

        

Persona p7 = {7, "Diana",   26, " San Jose", "SAN JOSE", "Uruca", "Mujer", "Soltera", 104893, 7, 0, "Omnivoro", "Salado", "Leer", "Reggaeton", 741722988};
escribir(p7);

        

Persona p8 = {8, "Mauricio",   50, " Cartago", "ALAJUELITA", "San Antonio", "Hombre", "Soltero", 451472, 4, 0, "Vegetariano", "Criollo", "Idiomas", "Reggaeton", 581902812};
escribir(p8);

        

Persona p9 = {9, "Mauricio",   37, " Heredia", "MONTES DE OCA", "Sabanilla", "Hombre", "Casado", 318752, 6, 3, "Vegano", "Ninguno", "Ejercicio", "Pop", 231584042};
escribir(p9);

        

Persona p10 = {10, "William",   29, " Heredia", "TURRUBARES", "San Pablo", "Hombre", "Casado", 314253, 2, 4, "Herbivoro", "Dulce", "Idiomas", "Bachata", 448297849};
escribir(p10);

        
/*
Persona p11 = {11, "Ericka",   38, " San Jose", "ALAJUELITA", "San Antonio", "Prefiero no decirlo", "Juntado", 130989, 0, 2, "Carnivoro", "Mexicano", "Ejercicio", "Balada", 402095587};
escribir(p11);

        

Persona p12 = {12, "Ramses",   33, " Guanacaste", "TURRUBARES", "San Juan de Mata", "Prefiero no decirlo", "Divorciado", 448634, 7, 3, "Vegetariano", "Criollo", "Cantar", "Reggaeton", 539990874};
escribir(p12);

        

Persona p13 = {13, "Mariana",   19, " Limon", "DOTA", "Jardín", "Prefiero no decirlo", "Soltero", 123116, 7, 3, "Omnivoro", "Mediterraneo", "Correr", "Balada", 601478504};
escribir(p13);

        

Persona p14 = {14, "Allison",   46, " Limon", "CURRIDABAT", "Tirrases", "Mujer", "Soltera", 221785, 1, 2, "Herbivoro", "Salado", "Cantar", "Rancheras", 299947816};
escribir(p14);

        

Persona p15 = {15, "Ronald",   19, " Cartago", "CURRIDABAT", "Curridabat", "Hombre", "Juntado", 73888, 6, 3, "Carnivoro", "Ninguno", "Guitarra", "Electronica", 635722895};
escribir(p15);

        

Persona p16 = {16, "Glen",   42, " Limon", "PEREZ ZELEDON", "San Isidro de El General", "Hombre", "Divorciado", 630144, 0, 0, "Vegano", "Salado", "Ejercicio", "Bachata", 385522440};
escribir(p16);

        

Persona p17 = {17, "Mariel",   30, " Limon", "LEON CORTES", "San Pablo", " Mujer", "Divorciada", 362763, 5, 1, "Herbivoro", "Mexicano", "Cantar", "Electronica", 354175593};
escribir(p17);

        

Persona p18 = {18, "Leonardo",   51, " San Jose", "PEREZ ZELEDON", "San Isidro de El General", "Prefiero no decirlo", "Soltero", 466411, 6, 0, "Vegano", "Criollo", "Idiomas", "Reggaeton", 764538659};
escribir(p18);

        

Persona p19 = {19, "Fabricio",   31, " Limon", "LEON CORTES", "San Antonio", "Prefiero no decirlo", "Juntado", 431982, 7, 2, "Vegetariano", "Mexicano", "Guitarra", "Merengue", 448832513};
escribir(p19);

        

Persona p20 = {20, "Alejandra",   40, " Puntarenas", "PEREZ ZELEDON", "Páramo", "Mujer", "Soltera", 253105, 5, 4, "Vegano", "Mexicano", "Cantar", "Metal", 557364289};
escribir(p20);

        

Persona p21 = {21, "Guiselle",   48, " Alajuela", "ALAJUELA", "La Garita", "Mujer", "Divorciada", 138442, 2, 1, "Carnivoro", "Coreano", "Cantar", "Plancha", 705243648};
escribir(p21);

        

Persona p22 = {22, "Joan",   39, " Puntarenas", "ALAJUELA", "Desamparados", "Hombre", "Casado", 207656, 1, 2, "Omnivoro", "Ninguno", "Idiomas", "Ninguno", 692350022};
escribir(p22);

        

Persona p23 = {23, "Max",   20, " San Jose", "SAN RAMON", "Volio", "Prefiero no decirlo", "Divorciado", 87179, 0, 4, "Herbivoro", "Ninguno", "Leer", "Electronica", 549075936};
escribir(p23);

        

Persona p24 = {24, "Laura",   29, " San Jose", "SAN RAMON", "Piedades Norte", "Prefiero no decirlo", "Soltero", 77341, 2, 1, "Carnivoro", "Criollo", "Leer", "Salsa", 495231020};
escribir(p24);

        

Persona p25 = {25, "Albert",   24, " Cartago", "LEON CORTES", "San Andrés", "Hombre", "Soltero", 538637, 5, 2, "Omnivoro", "Criollo", "Cantar", "Bachata", 689636910};
escribir(p25);

        

Persona p26 = {26, "Alejandro",   42, " Alajuela", "GRECIA", "Bolívar", "Hombre", "Soltero", 76142, 5, 1, "Herbivoro", "Ninguno", "Correr", "Salsa", 702404935};
escribir(p26);

        

Persona p27 = {27, "Carlos",   31, " Puntarenas", "SAN RAMON", "San Juan", "Prefiero no decirlo", "Soltero", 558374, 6, 0, "Herbivoro", "Coreano", "Ejercicio", "Salsa", 450014061};
escribir(p27);

        

Persona p28 = {28, "David",   39, " San Jose", "SAN MATEO", "Desmonte", "Hombre", "Divorciado", 360792, 2, 0, "Omnivoro", "Coreano", "Guitarra", "Rap", 372060145};
escribir(p28);

        

Persona p29 = {29, "Jazmin",   21, " San Jose", "GRECIA", "San Roque", "Mujer", "Juntada", 737219, 8, 0, "Carnivoro", "Mediterraneo", "Ejercicio", "Reggaeton", 742679609};
escribir(p29);

        

Persona p30 = {30, "Ursula",   30, " Guanacaste", "ALAJUELA", "San Antonio", "Mujer", "Juntada", 386951, 1, 3, "Omnivoro", "Criollo", "Leer", " ancheras", 472749513};
escribir(p30);

        

Persona p31 = {31, "Ariel",   37, " Heredia", "GRECIA", "San Isidro", "Mujer", "Divorciada", 384114, 2, 1, "Vegetariano", "Criollo", "Correr", "Balada", 562866850};
escribir(p31);

        

Persona p32 = {32, "Tania",   30, " Limon", "ATENAS", "Concepción", "Mujer", "Juntada", 551478, 2, 3, "Carnivoro", "Dulce", "Cantar", "Salsa", 614068822};
escribir(p32);

        

Persona p33 = {33, "Ronald",   25, " Limon", "NARANJO", "San José", "Hombre", "Casado", 81108, 5, 0, "Omnivoro", "Ninguno", "Cantar", "Rap", 536709808};
escribir(p33);

        

Persona p34 = {34, "Erick",   30, " Cartago", "ATENAS", "Concepción", "Hombre", "Casado", 125865, 3, 0, "Omnivoro", "Dulce", "DibujarBailar", "Salsa", 707779887};
escribir(p34);

        

Persona p35 = {35, "Angelica",   23, " Heredia", "PALMARES", "Zaragoza", "Prefiero no decirlo", " Juntado", 70617, 8, 4, " Omnivoro", " Ninguno", " Idiomas", " Reggaeton", 197703317};
escribir(p35);

        

Persona p36 = {36, "Jose",   30, " Alajuela", "PALMARES", "Palmares", "Hombre", "Casado", 244092, 0, 3, "Herbivoro", "Mediterraneo", "DibujarBailar", "Balada", 616383956};
escribir(p36);

        

Persona p37 = {37, "Reyner",   47, " San Jose", "SAN CARLOS", "Fortuna", "Prefiero no decirlo", "Casado", 184908, 5, 1, "Vegano", "Criollo", "Leer", "Rap", 239993335};
escribir(p37);

        

Persona p38 = {38, "Melina",   45, " Heredia", "ATENAS", "Mercedes", "Mujer", "Divorciada", 585473, 7, 4, "Vegetariano", "Dulce", "Ejercicio", "Indie", 651083742};
escribir(p38);

        

Persona p39 = {39, "Frida",   29, " Heredia", "SAN CARLOS", "Fortuna", "Mujer", "Soltera", 304264, 5, 1, "Vegano", "Mediterraneo", "Guitarra", "Rancheras", 477803080};
escribir(p39);

        

Persona p40 = {40, "Antonia",   35, " San Jose", "SAN CARLOS", "Florencia", "Mujer", "Juntada", 376225, 8, 3, "Vegano", "Dulce", "Correr", "Reggaeton", 347383831};
escribir(p40);

        

Persona p41 = {41, "Zul",   36, " Cartago", "ATENAS", "Mercedes", "Hombre", "Juntado", 518929, 3, 3, "Carnivoro", "Criollo", "Leer", "Salsa", 172889982};
escribir(p41);

        

Persona p42 = {42, "Emily",   26, " San Jose", "NARANJO", "San Jerónimo", "Mujer", " Juntada", 477369, 4, 0, " Vegano", " Criollo", " Cantar", " Rancheras", 295654304};
escribir(p42);

        

Persona p43 = {43, "Andrea",   39, " Heredia", "UPALA", "Upala", "Mujer", " Casada", 360039, 6, 1, " Carnivoro", " Ninguno", " Guitarra", " Merengue", 588040450};
escribir(p43);

        

Persona p44 = {44, "Alex",   24, " Heredia", "CARTAGO", "Oriental", "Hombre", " Casado", 574829, 7, 0, " Omnivoro", " Ninguno", " Leer", " Plancha", 327745362};
escribir(p44);

        

Persona p45 = {45, "Julio",   28, " Guanacaste", "LA UNION", "San Rafael", "Hombre", " Soltero", 612153, 2, 2, " Vegetariano", " Dulce", " Cantar", " Pop", 620099299};
escribir(p45);

        

Persona p46 = {46, "Anamarta",   45, " Limon", "CARTAGO", "Oriental", "Mujer", "Divorciada", 380469, 6, 2, "Vegetariano", "Criollo", "Idiomas", "Merengue", 543272214};
escribir(p46);

        

Persona p47 = {47, "Eladio",   44, " Alajuela", "LA UNION", "Tres Ríos", "Hombre", "Casado", 716810, 0, 1, "Carnivoro", "Criollo", "Cantar", "Metal", 657096129};
escribir(p47);

        

Persona p48 = {48, "Steven",   29, " Heredia", "LA UNION", "Tres Ríos", "Hombre", "Soltero", 595546, 2, 1, "Vegano", "Coreano", "Cantar", "Bachata", 154644921};
escribir(p48);

        

Persona p49 = {49, "Marleny",   43, " Limon", "TURRIALBA", "Turrialba", "Mujer", "Divorciada", 208062, 7, 3, "Vegetariano", "Salado", "Dibujar", "Plancha", 159095845};
escribir(p49);
*/
        

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



bool idEnLista(nodoArbolDecision *nodo, int id){
        /*
    F Verifies if id is in linked list
    I first node, id
    O tru or false
    */
    Indice *temp = nodo->sigInd;
    while(temp != NULL){
        if(temp->posicion == id){
            return true;
        }
        temp = temp->sigInd;
    }
    return false;
}

Persona devPers(int reg){
        /*
    F been given a position to return the person in this position in the program
    I index
    O person based on index position
    */
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
    Persona p;
        if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
    archivo.seekp(reg*sizeof(p), ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
    archivo.close();
    return p;
}

string devParametro(string parametro, Persona p){
    /*
    F Receives which kind of parameter is requested and returns it
    I Parameter, person being consulted
    O person's info about this parameter
    */
    string porRevisar;
    if(parametro=="nombre"){            porRevisar= p.nombre;
    }else if(parametro=="edad"){        porRevisar= p.edad;
    }else if(parametro=="provincia"){   porRevisar= p.provincia;
    }else if(parametro=="canton"){      porRevisar= p.canton;
    }else if(parametro=="distrito"){    porRevisar= p.distrito;
    }else if(parametro=="sexo"){        porRevisar= p.sexo;
    }else if(parametro=="estCivil"){    porRevisar= p.estCivil;
    }else if(parametro=="sueldo"){      porRevisar= p.sueldo;
    }else if(parametro=="annosTrabajando"){ porRevisar=p.annosTrabajando;
    }else if(parametro=="cantHijos"){       porRevisar= p.cantHijos;
    }else if(parametro=="tipoAlimentacion"){porRevisar=p.tipoAlimentacion;
    }else if(parametro=="tipoComida"){  porRevisar= p.tipoComida;
    }else if(parametro=="hobby"){       porRevisar= p.hobby;
    }else if(parametro=="tipoMusica"){  porRevisar= p.tipoMusica;
    }else if(parametro=="cedula"){      porRevisar= p.cedula;           
    }
    return porRevisar;    
}

void agregarPersonaAUX(nodoArbolDecision *nodo, Persona persTemp, string codigoUsuario, int profFija, int profDinamica, string paramEnviar){
    /*
    F Auxiliary functions that creates one, else, continues
    I root node, temporally person, codigoUsuario
    O root node links modified to add person
    */
    if( (profDinamica>(profFija-2)) && (profDinamica<profFija) ){   
        if(nodo->sublistaHijos==NULL){          //for the first node
            nodoArbolDecision *nN= new nodoArbolDecision(1, codigoUsuario, paramEnviar); //creates new node
            Indice *nI= new Indice(persTemp.id);       //creates new linked index
            nN->sigInd = nI;
            nodo->sublistaHijos=nN;
            return;
        }
        nodoArbolDecision *temp= nodo->sublistaHijos;

        while(temp->sigNodo!=NULL){
            if (paramEnviar==temp->valor){
                temp->cantidad= temp->cantidad+1;
                Indice *indTemp= temp->sigInd;
                while(indTemp->sigInd!=NULL){
                    indTemp=indTemp->sigInd;
                }
                Indice *nI= new Indice(persTemp.id);
                indTemp->sigInd=nI;
                return;
            }
            temp= temp->sigNodo;
        }
        nodoArbolDecision *nN= new nodoArbolDecision(1, codigoUsuario, paramEnviar);
        Indice *nI= new Indice(persTemp.id);
        nN->sigInd=nI;
        temp->sigNodo= nN;
        return;
    }
    if(idEnLista(nodo, persTemp.id)==true){
        nodoArbolDecision *tempSubLista= nodo->sublistaHijos;
        profDinamica+=1;
        while(tempSubLista!=NULL){
            agregarPersonaAUX(tempSubLista, persTemp, codigoUsuario, profFija, profDinamica, paramEnviar);
            tempSubLista= tempSubLista->sigNodo;
        }
    }else{
        return;
    }
    

}
void agregarPersona(nodoArbolDecision *nodo, Persona persTemp, string codigoUsuario, int profFija, int profDinamica, string paramEnviar){
    /*
    F Auxiliary functions thatvalidates if root has a link or not, if not, creates one, else, continues
    I root node, temporally person, codigoUsuario
    O root node links modified to add person
    */
    if(nodo->sublistaHijos==NULL){          //checks on if root is empty and fills it in, otherwise continues to recursive function
            nodoArbolDecision *nN= new nodoArbolDecision(1, codigoUsuario, paramEnviar);
            Indice *nI= new Indice(persTemp.id);
            nN->sigInd = nI;
            nodo->sublistaHijos=nN;
            return;
        }
    agregarPersonaAUX(nodo, persTemp, codigoUsuario, profFija, profDinamica, paramEnviar);
}
void crearArbol(nodoArbolDecision *raiz){
    /*
    F Recursive functino that asks for info to create a tree
    I How many parameters to use
    O root node and tree created afterwise
    */
    int cantNiveles= pedirInt("Ingrese cuantos elementos desea analizar en el arbol:");
    if(cantNiveles<3){
        cout<<"El minimo de niveles por crear es 3."<<endl;
        crearArbol(raiz);
    }
    
    string nivelesGeneral[15]={"Nombre", "Edad", "Provincia", "Canton", "Distrito", "Sexo", "Estado Civil", "Sueldo", "Anos Trabajando", "Cantidad Hijos", "Tipo Alimentacion", "Tipo Comida", "Hobby", "Tipo de Musica", "Cedula"};
    string parametrosCod[15]={"nombre", "edad", "provincia", "canton", "distrito", "sexo", "estCivil", "sueldo", "annosTrabajando", "cantHijos", "tipoAlimentacion", "tipoComida", "hobby", "tipoMusica", "cedula"};

    cout<<"Ingrese el numero de su nivel deseado uno a la vez."<<endl;
    cout<<"Los niveles disponibles son: \n1-Nombre\t\t2-Edad\t\t3-Provincia\t4-Canton\t\t5-Distrito\n6-Sexo\t\t\t7-Estado Civil\t8-Sueldo\t9-Anos Trabajando\t10-Cantidad Hijos\n11-Tipo Alimentacion\t12-Tipo Comida\t13-Hobby\t14-Tipo de Musica\t15-Cedula"<<endl;
    string nivelesUsuario[15]={};       //showable to user
    string codigosUsuario[15]={};       //inner parameters

    int i=0;
    while (i!=cantNiveles){             //adds to the respective lists the parameters the user asked for
        int opcion;
        cin>>opcion;
        nivelesUsuario[i]= nivelesGeneral[opcion-1];
        codigosUsuario[i]= parametrosCod[opcion-1];
        i+=1;
    }

    cout<<"Los niveles ingresados fueron:";
    int j= 0;                           //confirms the user what was added
    while(j!=cantNiveles){
        cout<<", "<<nivelesUsuario[j];
        j+=1;
    }

    cout<<endl;
    int cant = tamannoArchivo();
    cout<< "En el archivo hay "<< cant << " personas "<<endl;       

    Indice *nInd= new Indice(0);        //se crea un primer indice
    i=1;
    raiz->sigInd= nInd;                 //le asignamos a la raiz la lista de personas
    while (i!=cant){                    //ciclo que crea los valores tipo indice para la raiz
        Indice *tempInd= new Indice(i); //crea uno temporal
        nInd->sigInd=tempInd;           //le asigna que el siguiente del ultimo es 
        nInd= tempInd;                  //los reemplazo
        i+=1;
    }

    int q= 0;
    while(q!= cantNiveles){             //runs over all user's choice
        int i=0;
        while(i!= cant){                    //runs over all the people
            Persona persTemp= devPers(i);
            string paramEnviar= devParametro(codigosUsuario[q], persTemp);
            agregarPersona(raiz, persTemp, codigosUsuario[q], q, 0, paramEnviar);
            i+=1;
        }
        q+=1;
    }

}

int hojas=0;
void contarHojas(nodoArbolDecision *nodo){
    /*
    F Counts how many leaf nodes are there in the tree
    I Node to check temporally
    O changes hojas value to access it later
    */
    if(nodo == NULL)
        return;

        if(nodo->sublistaHijos == NULL){
            hojas++;
            return;
        }
        nodoArbolDecision *tempSubLista = nodo->sublistaHijos;
        while(tempSubLista != NULL){
            contarHojas(tempSubLista);
            tempSubLista = tempSubLista->sigNodo;
        }
}


void menuConsultas(nodoArbolDecision *raiz){
    /*
    F Displays mennu for respective consults
    I option chosen by customer
    O reespective function
    */
    cout<<"Ingrese el numero de la opcion deseada:" << endl;
    cout<< "1- Imprimir la cantidad de hojas en el árbol."<< endl;
    cout<< "NO 2- Imprimir la cantidad de nodos en un nivel X."<< endl;
    cout<< "NO 3- Imprimir cual categoría tiene más valores diferentes, recorriendo todo el árbol."<< endl;
    cout<< "NO 4- Imprimir en el nivel X cuál es el valor de la característica con mayor cantidad de personas y cuál es la que tiene menor cantidad de personas != de cero. "<< endl;
    cout<< "NO 5- Imprimir la suma de todas las cantidades por nivel"<< endl;
    cout<< "6- Imprimir la cantidad de una característica con un valor en específico recorriendo el archivo"<< endl;
    cout<< "Numero: "<< endl;

    string opcion;
    cin>> opcion;

    if(opcion=="1"){
        contarHojas(raiz);
        cout<<"Hay un total de "<< hojas<<" hojas."<<endl;
    }else if(opcion=="2"){
        cout<<"No implementado"<<endl;
    }else if(opcion=="3"){
        cout<<"No implementado"<<endl;
    }else if(opcion=="4"){
        cout<<"No implementado"<<endl;
    }else if(opcion=="5"){
        cout<<"No implementado"<<endl;
    }else if(opcion=="6"){
        cout<<"No implementado"<<endl;
    }else if(opcion =="7"){
        cout<<"No implementado"<<endl;
    }else{
        cout<<"Ingrese una opcion valida"<<endl;
        menuConsultas(raiz);
    }
}
void menuUsuario(){
    /*
    f: Displays a menu to the user
    i: option chosen
    o: na    
    */
    int cant = tamannoArchivo();
    nodoArbolDecision *raiz= new nodoArbolDecision(cant, "Raiz", "--");
    crearArbol(raiz);

    cout<<"Ingrese el numero de la opcion deseada:" << endl;

    cout<< "1- Consultas"<< endl;
    cout<< "2- Reportes"<< endl;
    cout<< "Numero: "<< endl;

    string opcion;
    cin>> opcion;
    if (opcion=="1"){
        menuConsultas(raiz);
    }else if(opcion=="2"){
        cout<<"No implementado"<<endl;
        //menuReportes();
    }else{
        cout<< "Ingrese una opcion valida."<<endl;
        menuUsuario();
        
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
    cout<<"Ingrese el numero de la opcion deseada: \n 1- Buscar persona por ID\n 2- Buscar persona por nombre\n 3- Buscar persona por posicion \n 4- Modificar persona \n C- Continuar con el arbol\n 5- Salir\n\nNumero: ";
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
    }else if (opcion=="C"){
        menuUsuario();
    }else if(opcion=="5"){
        cout<<"\n\nSaliendo...\n\n";
        cout<<"Gracias por usar nuestro sistema!"<<endl;
        system("pause");
        return;
    }else{
        cout<<"Ingrese una opcion valida.";
        menuPrincipal();
    }
}
int main(){
    /*
    F requests a call to the menus
    I na
    O program workflow
    */
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
