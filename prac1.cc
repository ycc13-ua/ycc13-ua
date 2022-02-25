//DNI X8866729E YANAN CHEN

#include <iostream>
#include <cstdlib> // Para rand(), srand() y atoi()
#include<cstring>

using namespace std;

//rgrbgergj


const int KNAME=32;
const int KENEMIES=5;
const int KPOINTS=200;
const int KDICE=20; // Número de caras del dado

struct Core{
  int attack;
  int defense;
  int hp; // Puntos de vida
  int pt;
  int vida;
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
  
    srand(time(NULL));
    return rand()%KDICE+1;
   
  
}

int rollDice2(){
    
    return rand()%KDICE+1;
}





Hero createHero(){
    

  //inicializar la STRUCT
  Hero myhero;
  
      //Variable para decirnos si el nombre que se ha introducido es correcto
      bool nombrecorrecto = true;
  
      //Bucle do que como minimo se ejecuta una vez lo que hay dentro hasta 
      //que NO se cumpla la condicion del while
      cout << "[Hero]" << endl;
      do{
        nombrecorrecto = true;
        cout << "Enter hero name: ";
        cin.getline(myhero.name,KNAME-1);
  
        //Comprobamos solamente el primer caracter del nombre si es letra o no
        if(!isalpha(myhero.name[0])){
          nombrecorrecto = false;
        }
        
        //Bugle FOR para comprobar cada uno de los caracteres del nombre si coincide con 
        //las condiciones que se nos pide
        int i ;
        for( i=0 ; i < (int) strlen(myhero.name) ; i++){
          if(!isalpha(myhero.name[i]) and !isdigit(myhero.name[i])){
            nombrecorrecto=false;
            break; //Una vez que encontremos el error,ya CONFIRMAMOS EL ERROR y no 
                  //hace falta seguir recorriendo el bucle
          }
        }
  
        //Si el nombre no es correcto entonces mostramos el mensaje SOLO UNA VEZ
        if(nombrecorrecto == false){
          cout<<"ERROR: wrong name"<<endl;        
        }
  
      }while(nombrecorrecto == false);
      

    //inicial la struct CORE
    Core puntos;
    char barra;
    int suma;
    
    

    
    do{

      do{

        cout << "Enter attack and defense:" ;
        cin >> puntos.attack ; cin >> barra ; cin >> puntos.defense;
      
        myhero.features.attack = ((float)puntos.attack / (float)100) * KPOINTS;
        myhero.features.defense = ((float)puntos.defense / (float)100) * KPOINTS;

        suma = puntos.attack + puntos.defense;
        
        if (puntos.attack <0 || puntos.defense <0 || suma != 100 || barra != '/' ) {
          cout << "Error: wrong distribution" << endl;
        }
        
      }while(barra != '/' || puntos.attack<0 || puntos.defense  <0 || suma != 100 );

      
      if (suma > 100 || suma == 100){
        
        
        myhero.features.hp = myhero.features.defense * 2;
        cout << "Puntos de vida:" << myhero.features.hp << endl;


      };

    }while(suma != 100 || suma < 100 );

    return myhero;

}






Enemy createEnemy(){

  Enemy myenemy;
  Breed b;
  cout << "[Enemy]" << endl;
  cout << "El número de dado es:" << rollDice () << endl;

  if ( rollDice() >0 && rollDice() <= 6 ){
    b = AXOLOTL;
    myenemy.features.attack = 40 ;
    myenemy.features.defense = 40 ;
    myenemy.features.hp = ( (float)myenemy.features.defense / (float)100 ) * KPOINTS * 2;
    myenemy.features.pt = 100;
  };
  if ( rollDice() >=7 && rollDice() <= 11 ){
    b=TROLL;
    myenemy.features.attack = 60 ;
    myenemy.features.defense = 80 ;
    myenemy.features.hp = ( (float)myenemy.features.defense / (float)100 ) * KPOINTS * 2;
    myenemy.features.pt = 150 ;
  };
  if ( rollDice() >=12 && rollDice() <= 15 ){
    b=ORC;
    myenemy.features.attack = 80 ;
    myenemy.features.defense = 120 ;
    myenemy.features.hp = ( (float)myenemy.features.defense / (float)100 ) * KPOINTS * 2;
    myenemy.features.pt = 200 ;
  };
  if ( rollDice() >=16 && rollDice() <= 18 ){
    b=HELLHOUND;
    myenemy.features.attack = 120 ;
    myenemy.features.defense = 100 ;
    myenemy.features.hp = ( (float)myenemy.features.defense / (float)100 ) * KPOINTS * 2;
    myenemy.features.pt = 300 ;
  };
  if ( rollDice() >=19 && rollDice() <= 20 ){
    b=DRAGON;
    myenemy.features.attack = 160 ;
    myenemy.features.defense = 140 ;
    myenemy.features.hp = ( (float)myenemy.features.defense / (float)100 ) * KPOINTS * 2;
    myenemy.features.pt = 400 ;
  };
  
  

  switch(b){

    case 0:

      cout << "Breed: Axolotl" << endl;
      cout << "Attack:" << myenemy.features.attack << endl ;
      cout << "Defense: " << myenemy.features.defense << endl;
      cout << "Health points: " << myenemy.features.hp << endl;
      break;

    case 1:

      cout<<"Breed: Troll"<< endl;
      cout<<"Attack: " << myenemy.features.attack << endl;
      cout<<"Defense: " << myenemy.features.defense << endl;
      cout << "Health points: " << myenemy.features.hp << endl;
      break;

    case 2:

      cout<<"Breed: Orc"<<endl;
      cout<<"Attack: " << myenemy.features.attack << endl;
      cout<<"Defense: "<< myenemy.features.defense << endl;
      cout << "Health points: " << myenemy.features.hp << endl;
      break;

    case 3:

      cout<<"Breed: Hellhound"<<endl;
      cout<<"Attack: " << myenemy.features.attack << endl;
      cout<<"Defense: "<<  myenemy.features.defense << endl;
      cout << "Health points: " << myenemy.features.hp << endl;
      break;

    case 4:

        cout<<"Breed: Dragon"<<endl;
        cout<<"Attack: " << myenemy.features.attack <<endl;
        cout<<"Defense: " << myenemy.features.defense << endl;
        cout << "Health points: " << myenemy.features.hp << endl;
        break;

  }



  return myenemy;

}




void fight(Hero &myhero,Enemy &myenemy){
  
  int dado1,dado2;
  int Hataque, Edefensa , Pdanyos ;

  dado1 = rollDice () * 5;
  dado2 = rollDice2 () * 5;

  Hataque = myhero.features.attack + dado1 ;
  Edefensa = myenemy.features.defense + dado2 ;
  Pdanyos = Hataque - Edefensa ;
  myenemy.features.vida = myenemy.features.hp - Pdanyos ;
  
  cout << "[Hero -> Enemy]" << endl;
  cout << "Attack: " << myhero.features.attack << "+" << dado1 << "=" << Hataque << endl;
  cout << "Defense: " << myenemy.features.defense << "+" << dado2 << "=" << Edefensa << endl;

  if(Pdanyos <= 0){
    cout << "Hit points: 0" << endl;
    cout << "Enemy health points: " << myenemy.features.hp << endl;
  }
  else{
    cout << "Hit points: " << Pdanyos << endl; 
    cout << "Enemy health points: " << myenemy.features.vida << endl;
  }
  

  
  if (myenemy.features.vida != 0){
    int Eataque , Hdefensa ;

    Eataque = myenemy.features.attack + dado1 ;
    Hdefensa = myhero.features.defense + dado2 ;
    Pdanyos = Eataque - Hdefensa ;
    myhero.features.vida = myhero.features.hp - Pdanyos;

    cout << "[Enemy -> Hero]" << endl ;
    cout << "Attack: " << myenemy.features.attack << "+" << dado1 << "=" << Eataque << endl;
    cout << "Defense: " << myhero.features.defense << "+" << dado2 << "=" << Hdefensa << endl;

    if(Pdanyos <= 0){
      cout << "Hit points: 0" << endl;
      cout << "Hero health points: " << myhero.features.hp << endl;
    }
    else{
      cout << "Hit points: " << Pdanyos << endl; 
      cout << "Hero health points: " << myhero.features.vida << endl;
    }
  }
}


void run_away(Hero &myhero,Enemy &myenemy){
    
    

    cout << "You run away" << endl;
    
     
    
    
  

  


}

void special(Hero &myhero,Enemy &myenemy){

}

void report(const Hero &myhero){

  cout << "Name: " << myhero.name << endl;
  cout << "Attack: " << myhero.features.attack << endl;
  cout << "Defense: " << myhero.features.defense << endl;
  cout << "Health points:" << myhero.features.vida << endl;
  cout << "Special: " << endl;
  cout << "Runaways: " << endl;
  
  cout << "Exp: " << myhero.kills << myhero.exp << endl;
  cout << "Enemies killed: " << endl;


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
   
   
    Hero myhero;
    Enemy myenemy;

    myhero=createHero();




    /*cout<<hero.features.attack;*/

    char op;
    
    
    do{
      
      myenemy=createEnemy();

      do{

        do{
   
          showMenu();
          cin>>op;
      
          if(op=='1'){
            fight( myhero , myenemy ) ;
          }
      
          

          
  
          if(op=='2'){

            myhero.runaways=3;
            while(myhero.runaways>0){

              myhero.runaways = myhero.runaways-1;
              cout << "contador" << myhero.runaways << endl;
              
              run_away (myhero , myenemy );
             
            }
            if (myhero.runaways==3){
              cout << "Error: cannot run away" << endl;
            }

          }
      




          if(op=='3'){
            special(myhero , myenemy );
          }
      
          if(op=='4'){
            report(myhero);
          }
      
          if(op!='1' and op!='2' and op!='3' and op!='4' and op!='q'){
            cout<<"ERROR: wrong option"<<endl;
          }
      
        }while(op!='1' and op!='2' and op!='3' and op!='4' and op!='q');

      }while(myhero.features.vida > 0);



      //si el enemigo muere
      if (myenemy.features.vida <= 0 ) {
        cout << "Enemy killed" << endl ;
      };
      
      for (int i=0; i<0 ; i++){
        myhero.exp = myenemy.features.pt + i  ; 
        cout << "Sus puntos de experencia son: " << myhero.exp << endl; 
      };
  
    }while(myenemy.features.vida<=0 || myhero.runaways<3);

    // si muere el heroe
    if(myhero.features.vida <= 0){
      cout << "You are dead" << endl;
      report(myhero);    
    }


  }
  
    
  return 0;
  // Aquí vendrá todo tu código del "main"...
}