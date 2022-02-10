//DNI X8866729E YANAN CHEN

#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include<cstring>

using namespace std;




const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200;
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp; // Puntos de vida
};

enum Breed{
  AXOLOTL,
  TROLL,
  ORC, 
  HELLHOUND,
  DRAGON
};

struct Enemy{
  Breed name;
  Core features;
};

struct Hero{
  char name[KNAME];
  Core features; // Características básicas                                                                      
  bool special; // Ataque especial
  int runaways; // Número de veces que puede huir de la batalla
  int exp; // puntos de experiencia
  int kills[KENEMIES]; // lista de enemigos derrotados
}; 

int rollDice(){
    
  return rand()%KDICE+1;
  
}

Hero createHero(){
    

  //inicializar una STRUCT
  Hero mihero;
  
      //Variable para decirnos si el nombre que se ha introducido es correcto
      bool nombrecorrecto = true;
  
      //Bucle do que como minimo se ejecuta una vez lo que hay dentro hasta
      //que NO se cumpla la condicion del while
      do{
        nombrecorrecto = true;
        cout << "Enter hero name: ";
        cin.getline(mihero.name,KNAME-1);
  
        //Comprobamos solamente el primer caracter del nombre si es letra o no
        if(!isalpha(mihero.name[0])){
          nombrecorrecto = false;
        }
        
        //For para comprobar cada uno de los caracteres del nombre si coincide con 
        //las condiciones que se nos pide
        for(int i=0 ; i<strlen(mihero.name) ; i++){
          if(!isalpha(mihero.name[i]) and !isdigit(mihero.name[i])){
            nombrecorrecto=false;
            break; //Una vez que encontremos el error ya CONFIRMAMOS EL ERROR y no 
            //hace falta seguir recorriendo el bucle
          }
        }
  
        //Si el nombre no es correcto entonces mostramos el mensaje SOLO UNA VEZ
        if(nombrecorrecto == false){
          cout<<"ERROR: wrong name"<<endl;        
        }
  
      }while(nombrecorrecto == false);
      
      return mihero;


  
}

Enemy createEnemy(){
}

void fight(Hero &hero,Enemy &enemy){
}

void report(const Hero &hero){
}

void showMenu(){
  cout << "[Options]" << endl
       << "1- Fight" << endl
       << "2- Run away" << endl
       << "3- Special" << endl 
       << "4- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}









int main(int argc,char *argv[]){
  if(argc!=2){ // Si los parámetros no son correctos, el programa termina inmediatamente
  cout << "Usage: " << argv[0] << " <seed>" << endl;
  }
  else{
    srand(atoi(argv[1])); // Introducimos la semilla para generar números aleatorios
    
    createHero();

    
    
    
    
    
    
    
    // Aquí vendrá todo tu código del "main"...
  }
}









