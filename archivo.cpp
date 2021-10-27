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
/*
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
*/
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

void buscarId(int id){
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
            cout<<"\nNombre: "<<p.nombre<<" Cedula: "<<p.cedula<<" Edad: "<<p.edad<<" annos "<<"\nProvincia: "<<p.provincia<<" Canton: "<<p.canton<<" Distrito: "
            <<p.distrito<<" Sexo: "<<p.sexo<<" Estado Civil: "<<p.estCivil<<"\nSueldo: "<<p.sueldo<<" Annos Trabajando: "
            <<p.annosTrabajando<<" Cantidad de Hijos: "<<p.cantHijos<<"\nTipo de Alimentacion: "<<p.tipoAlimentacion<<" Tipo de Comida: "
            <<p.tipoComida<<" Hobby: "<<p.hobby<<" Tipo de Musica: "<<p.tipoMusica<<endl;
            cout<<"Posicion: "<<contador<<endl;
        }
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
	archivo.close();
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
            cout<<contador<<endl;
            return contador;
        }
        contador = contador + 1;
		archivo.read(reinterpret_cast<char*>(&p), sizeof(p));
	}
    archivo.close();
    return contador;
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

void modificarNombre(int reg, string nNombre){
	cout<<"Modificar nombre";
    fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;
	if(archivo.fail()){
		cout<<"\nNo se pudo abrir el archivo";
		exit(1);
	}
    Persona nueva = {nNombre, p.edad, p.provincia, p.canton, p.distrito, p.sexo, p.estCivil, p.sueldo, p.annosTrabajando, p.cantHijos, p.tipoAlimentacion, p.tipoComida, p.hobby, p.tipoMusica, p.cedula};
    cout<<"Persona nueva";
    archivo.seekp(reg*sizeof(nueva), ios::beg);
	archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
	
	archivo.close();
}

void modificarPersona(int cedula, string nombre){
    cout<<"Modificar"<<endl;
    int pos = buscarPos(cedula);
    cout<<"Posicion: "<<pos<<" Cedula: "<<cedula<<" Nombre: "<<nombre<<endl;
    modificarNombre(pos, nombre);
}

//archivo.write(reinterpret_cast<char*>(&nueva), sizeof(nueva));
void imprimirPersona(int reg){
	fstream archivo ("archivobinario.txt", ios::in|ios::out|ios::binary);
	Persona p;

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
	Persona p1 = {"Earl", 52, 5, "LA UNION", "Juan Viñas", 1, 1, 104359, 2, 0, 1, 4, "Cantar", 4, 165195055};
    escribir(p1);

    Persona p2 = {"Brenda", 29, 7, "TURRIALBA", "Pavones", 2, 2, 722324, 8, 4, 4, 1, "Guitarra", 2, 274023277};
    escribir(p2);

    Persona p3 = {"Vianna", 32, 3, "ALVARADO", "Cervantes", 2, 2, 107361, 7, 3, 4, 1, "Programar", 7, 450564599};
    escribir(p3);

    Persona p4 = {"Heimy", 40, 4, "OREAMUNO", "San Rafael", 2, 1, 429157, 2, 2, 1, 3, "Correr", 2, 520496956};
    escribir(p4);

    Persona p5 = {"Alia", 42, 7, "EL GUARCO", "Patio de Agua", 2, 3, 416446, 0, 3, 1, 1, "Ajedrez", 5, 269060435};
    escribir(p5);

    Persona p6 = {"Jackeline", 41, 6, "HEREDIA", "Mercedes", 2, 1, 333500, 4, 3, 3, 1, "Ajedrez", 3, 610700085};
    escribir(p6);

    Persona p7 = {"Adrian", 37, 6, "OREAMUNO", "Santa Rosa", 1, 2, 521349, 2, 2, 1, 4, "Musica", 6, 144106118};
    escribir(p7);

    Persona p8 = {"Amanda", 31, 5, "BARVA", "San Roque", 2, 2, 185996, 7, 3, 1, 2, "Gimnasio", 2, 411779978};
    escribir(p8);

    Persona p9 = {"Victoria", 40, 5, "OREAMUNO", "San Rafael", 2, 3, 459711, 6, 0, 1, 1, "Gimnasio", 3, 348124677};
    escribir(p9);

    Persona p10 = {"Alysa", 41, 4, "HEREDIA", "Ulloa", 2, 1, 97609, 2, 4, 1, 3, "Dibujar", 6, 565280258};
    escribir(p10);

    Persona p11 = {"Enrique", 18, 5, "ALVARADO", "Capellades", 1, 2, 128210, 3, 2, 3, 2, "Musica", 1, 726697183};
    escribir(p11);

    Persona p12 = {"Frida", 51, 3, "SANTO DOMINGO", "Santa Rosa", 2, 1, 86681, 6, 4, 4, 2, "Musica", 2, 671736524};
    escribir(p12);

    Persona p13 = {"Rossana", 43, 2, "SANTA BARBARA", "Purabá", 2, 3, 142461, 8, 0, 1, 1, "Dibujar", 4, 135075072};
    escribir(p13);

    Persona p14 = {"Antonia", 42, 7, "SANTA BARBARA", "Jesús", 2, 3, 571058, 7, 4, 4, 3, "Dibujar", 1, 615094092};
    escribir(p14);

    Persona p15 = {"Tania", 44, 6, "SAN RAFAEL", "San Josecito", 2, 4, 86699, 6, 3, 3, 1, "Cocinar", 7, 618645381};
    escribir(p15);

    Persona p16 = {"William", 46, 6, "BELEN", "San Antonio", 1, 1, 348825, 5, 3, 4, 3, "Guitarra", 5, 514526027};
    escribir(p16);

    Persona p17 = {"Jesus", 25, 5, "FLORES", "Barrantes", 1, 3, 310118, 8, 2, 2, 1, "Guitarra", 7, 678143097};
    escribir(p17);

    Persona p18 = {"Jazmin", 38, 1, "SARAPIQUI", "Puerto Viejo", 2, 2, 429470, 1, 3, 1, 1, "Programar", 5, 378694828};
    escribir(p18);

    Persona p19 = {"Carmen", 31, 2, "LIBERIA", "Liberia", 2, 4, 621668, 1, 3, 3, 3, "Cantar", 8, 171087147};
    escribir(p19);

    Persona p20 = {"Alejandro", 28, 2, "FLORES", "Llorente", 1, 3, 549532, 2, 1, 4, 4, "Ajedrez", 1, 220369512};
    escribir(p20);

    Persona p21 = {"Carlos", 20, 5, "NICOYA", "Nicoya", 1, 4, 576816, 5, 1, 2, 4, "Gimnasio", 4, 253560202};
    escribir(p21);

    Persona p22 = {"David", 26, 3, "NICOYA", "Nicoya", 1, 1, 735170, 5, 2, 1, 2, "Correr", 7, 124851917};
    escribir(p22);

    Persona p23 = {"Max", 23, 2, "SAN RAFAEL", "San Josecito", 1, 1, 660443, 8, 1, 2, 1, "Cocinar", 4, 331075702};
    escribir(p23);

    Persona p24 = {"Ingrid", 45, 6, "FLORES", "Barrantes", 2, 3, 736953, 3, 4, 3, 1, "Gimnasio", 2, 499164993};
    escribir(p24);

    Persona p25 = {"Alberto", 23, 7, "NICOYA", "Nicoya", 1, 3, 671779, 5, 4, 1, 4, "Ajedrez", 8, 509337935};
    escribir(p25);

    Persona p26 = {"Rachell", 51, 1, "SANTA CRUZ", "27 de Abril", 2, 4, 410822, 1, 4, 3, 4, "Guitarra", 6, 565815663};
    escribir(p26);

    Persona p27 = {"Ashley", 42, 3, "BAGACES", "Río Naranjo", 2, 4, 682545, 6, 0, 1, 3, "Correr", 7, 562244536};
    escribir(p27);

    Persona p28 = {"Joan", 37, 3, "CARRILLO", "Belén", 1, 2, 211349, 3, 0, 3, 2, "Programar", 5, 653911929};
    escribir(p28);

    Persona p29 = {"Walter", 31, 4, "TILARAN", "Tilarán", 1, 4, 339760, 4, 4, 2, 2, "Musica", 1, 426107980};
    escribir(p29);

    Persona p30 = {"Maria", 30, 5, "CARRILLO", "Belén", 2, 4, 342056, 8, 4, 2, 4, "Dibujar", 6, 386140477};
    escribir(p30);

    Persona p31 = {"Albert", 40, 4, "ABANGARES", "Juntas", 1, 3, 136473, 5, 3, 3, 1, "Cantar", 8, 399727089};
    escribir(p31);

    Persona p32 = {"Luis", 30, 7, "LA CRUZ", "La Cruz", 1, 4, 398808, 7, 2, 2, 2, "Dibujar", 8, 306132513};
    escribir(p32);

    Persona p33 = {"Daniel", 52, 5, "NANDAYURE", "Santa Rita", 1, 4, 209406, 1, 2, 3, 1, "Cantar", 2, 346825927};
    escribir(p33);

    Persona p34 = {"Steven", 19, 6, "NANDAYURE", "Bejuco", 1, 1, 312324, 6, 2, 1, 2, "Cocinar", 7, 664105033};
    escribir(p34);

    Persona p35 = {"Sofia", 22, 7, "TILARAN", "Tilarán", 2, 2, 334979, 3, 4, 4, 1, "Gimnasio", 3, 330400118};
    escribir(p35);

    Persona p36 = {"Erick", 52, 6, "BAGACES", "Río Naranjo", 1, 4, 130416, 7, 2, 4, 2, "Cocinar", 4, 403171121};
    escribir(p36);

    Persona p37 = {"Melina", 20, 5, "BAGACES", "Fortuna", 2, 4, 595679, 1, 0, 1, 1, "Gimnasio", 8, 160345539};
    escribir(p37);

    Persona p38 = {"Ismael", 20, 4, "HOJANCHA", "Monte Romo", 1, 2, 318160, 5, 4, 2, 2, "Musica", 3, 591878812};
    escribir(p38);

    Persona p39 = {"Ignacio", 44, 1, "PUNTARENAS", "Chomes", 1, 4, 563482, 7, 1, 2, 4, "Gimnasio", 2, 433918107};
    escribir(p39);

    Persona p40 = {"Ashanti", 49, 3, "PUNTARENAS", "Cóbano", 2, 3, 155325, 4, 4, 2, 2, "Musica", 4, 416190133};
    escribir(p40);

    Persona p41 = {"Diana", 50, 5, "LA CRUZ", "Santa Elena", 2, 1, 112614, 8, 4, 1, 1, "Guitarra", 3, 524961385};
    escribir(p41);

    Persona p42 = {"Isabel", 49, 7, "PUNTARENAS", "Guacimal", 2, 1, 346954, 7, 4, 2, 1, "Correr", 2, 436066097};
    escribir(p42);

    Persona p43 = {"Jorge", 26, 4, "BUENOS AIRES", "Volcán", 1, 1, 218657, 4, 4, 3, 4, "Cocinar", 8, 251134631};
    escribir(p43);

    Persona p44 = {"Sandra", 30, 5, "MONTES DE ORO", "San Isidro", 2, 1, 666403, 6, 4, 3, 4, "Correr", 7, 477585290};
    escribir(p44);

    Persona p45 = {"Gabriela", 19, 4, "PUNTARENAS", "Guacimal", 2, 3, 676822, 8, 0, 2, 4, "Dibujar", 7, 698194886};
    escribir(p45);

    Persona p46 = {"Isaac", 52, 2, "BUENOS AIRES", "Volcán", 1, 1, 596146, 2, 2, 4, 2, "Cantar", 2, 474735454};
    escribir(p46);

    Persona p47 = {"Alan", 44, 3, "AGUIRRE", "Quepos", 1, 1, 708964, 3, 4, 3, 4, "Ajedrez", 1, 597053677};
    escribir(p47);

    Persona p48 = {"Bruno", 39, 6, "HOJANCHA", "Huacas", 1, 2, 75101, 6, 3, 2, 3, "Cantar", 3, 291709845};
    escribir(p48);

    Persona p49 = {"Soledad", 32, 5, "COTO BRUS", "San Vito", 2, 4, 471099, 5, 2, 4, 4, "Correr", 7, 454691434};
    escribir(p49);

    Persona p50 = {"Zul", 31, 1, "ESPARZA", "San Juan Grande", 1, 3, 282601, 2, 2, 2, 3, "Guitarra", 2, 521424187};
    escribir(p50);
	
	//leer();

	//Persona nueva = {"Mauricio", 20, 3, "El  Guarco", "Tejar", 1, 2, 300000, 5, 0, 1, 2, "Guitarra", 8, 119540199};
	//modificar(nueva,1);

	//leer();

}

int main(){
    ofstream archivo("archivobinario.txt");
	cargarDatos();
	//cout<<"\nImprimir"<<endl;
	//imprimirPersona(0);
    
    //buscarId(615094092);
    modificarPersona(521424187, "Juana");
    buscarId(521424187);
    //buscarId(521424187);
	int status = remove("archivobinario.txt");

	return 0;
}
