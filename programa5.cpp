#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

class Jugador{
	private:
		string cadena_movimientos;
		int posicion;
		int pos_ganadora;
	public:
		Jugador(int posicion);
		void move();
		int getPosicion();
		void setCadenaMovimientos(string);
		string getCadenaMovimientos();
		void show_cadena();
		void juega(Jugador);
};

Jugador::Jugador(int pos, int gana){
	posicion=pos;
	pos_ganadora=gana;
}
int Jugador::getPosicion(){
	return posicion;
}
void Jugador::setCadenaMovimientos(string cad){
	cadena_movimientos=cad;
}
string Jugador::getCadenaMovimientos(){
	return cadena_movimientos;
}
void Jugador::show_cadena(){
	cout<<cadena_movimientos<<endl;
}
void Jugador::juega(Jugador p2){

/*aqui ya nos e que hacer xD*/
	for(int i=0;i<this->cadena_movimientos.lengh();i++){
		switch (this->posicion){
			case 1:
			if(movimientos[i]=='r'){

			}else{

			}
				/* code */
				break;
			case 2:
				/* code */
				break;
			case 3:
				/* code */
				break;
			case 4:
				/* code */
				break;
			case 5:
				/* code */
				break;
			case 6:
				/* code */
				break;
			case 7:
				/* code */
				break;
			case 8:
				/* code */
				break;
			case 9:
				/* code */
				break;
			case 10:
				/* code */
				break;
			case 11:
				/* code */
				break;
			case 12:
				/* code */
				break;
			case 13:
				/* code */
				break;
			case 14:
				/* code */
				break;
			case 15:
				/* code */
				break;
			case 16:
				/* code */
				break;
			default:
				break;
			}
		
	}
}
int opcion(){
	int op;
	do{
		cout<<"1. Ingresar la cadena de movimientos"<<endl<<"2. Generar automaticamente"<<endl;
		cout<<"Ingrese la opcion deseada:\t"<<endl;
		cin>>op;
	}while(op!=1 && op!=2);
	return op;
}
void limite_cadena(int *limite){
	*limite = rand()%6;
}
void createArray(char **A,int elem){
    *A=(char *)malloc((elem)*sizeof(char));
    if(*A==NULL){
        printf("No hay memoria disponible...\n");
        exit(0);
    }
}
void llena_array(char *movimientos,int limite){
	char r_or_b[]={'r','b'};
	for (int i=0;i<limite;i++)
		movimientos[i]=r_or_b[rand()%2];
}

bool valida_cadena(string movimientos){
	int i;
	for(i=0;i<movimientos.length();i++)
		if(movimientos[i]!='r' && movimientos[i]!='b')
			return false;
	return true;
}

int main(){
	srand(time(NULL));
	int limite,op;
	char *movimientos,*m2;
	string str_movimientos;
	Jugador p1=Jugador(1,16),p2=Jugador(4,13);
	bool cad_correcta;
	op=opcion();
	if(op==1){
		do{
			fflush(stdin);
			cout<<"Ingresa la cadena de movimientos (solo debe contener r's y b's)"<<endl;
			getline(cin,str_movimientos);
			cad_correcta=valida_cadena(str_movimientos);
		}while(!cad_correcta);
		limite=str_movimientos.length();
		p1.setCadenaMovimientos(str_movimientos);
	}
	else{
		limite_cadena(&limite);
		createArray(&movimientos,limite);
		llena_array(movimientos,limite);
		str_movimientos=movimientos;
		p1.setCadenaMovimientos(str_movimientos);
		free(movimientos);
	} 
	//el usuario solo tiene control del jugador 1, por lo tanto las tiradas del segundo, de ahuevo deben ser
	//generadas automaticamente
	createArray(&m2,limite);
	llena_array(m2,limite);
	str_movimientos=m2;
	p2.setCadenaMovimientos(str_movimientos);
	free(m2);
	p1.show_cadena();
	p2.show_cadena();
	return 0;
}
