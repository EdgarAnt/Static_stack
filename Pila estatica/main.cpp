#include<iostream>
#include<stdlib.h>
#include<windows.h>

using namespace std;

 void gotoxy(int x,int y){// Implementacion de gotoxy para una mejor interfaz grafica
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

class pila{//Utilizacion de clases para dirigir los nodos
private: int datos[10],tope;
public:

pila();// contrusctor de clase
void push();
void pop();
int  vacia();
int llena();
void mostrar_pila();
void  gotoxy(int ,int);
};


pila::pila(){
tope=-1;
}


 void pila:: gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void pila::push(){// apilar datos del vector para añadirlos
int x;
if(llena()==0){
    gotoxy(52,21); cout<<"ingresa numero:"<<endl;
    gotoxy(68,21);
    cin>>x;
    tope ++;
    datos[tope]=x;
}

}

void pila::pop(){//Eliminar datos del vector
if(vacia()==0){
datos[tope ]= 0;
tope --;
}

}



void pila::mostrar_pila(){//Mostrar la pila con el gotoxy para una mejor interfaz grafica
int ayuda,i;
if(vacia()==0){
system("cls");
pila::gotoxy(6,4);
printf("\n\n\t Tope-->%c%c%c%c%c \n", 201,205,205,205,187);
    for(i=tope;i>=0;i--){
    printf("\t\t%c ",186,205);
    cout<<datos[i]; printf(" %c\n", 186);
    printf("\t\t%c%c%c%c%c\n", 204,205,205,205,185);
}
//system("pause");
}

  }


int  pila::vacia(){//indicar que la pila esta vacia
if(tope==-1){
system("cls");
cout<<"LA PILA ESTA VACIA"<<endl;
system("pause");

return 1;
} else{
return 0;
}
}
int  pila::llena(){// indicar que la pila esta llena
if(tope==9){
system("cls");
cout<<"LA PILA ESTA LLENA "<<endl;
system("pause");
     return 1;

}
else{
return 0;
}
}


int main(){// elaboracion del menu en el main agregando las demas funciones
pila p;
int opcion,num;
short int i;
do{    system("cls");
       p.mostrar_pila();
        gotoxy(1,3);
//        cout<<"------------------------------------------------------------"<<endl;
//        gotoxy(1,4);
//        cout<<"|                               Menu                       |"<<endl;
//        gotoxy(1,5);
//        cout<<"------------------------------------------------------------"<<endl;
        gotoxy(52,7);
        cout<<"1).Apilar"<<endl;
        gotoxy(52,9);
        cout<<"2).Desapilar"<<endl;
        gotoxy(52,11);
        cout<<"3).salir"<<endl;
        gotoxy(52,15);
        cout<<"Opcion: ";
        cin>>opcion;

switch(opcion){//elaboracion del switch para indicar la opcion a elegir
case 1:   //system("cls");
        p.push();break;
case 2:  p.pop();
         break;


default:
    gotoxy(19,19);// si elige una opcion que no esta en las opciones mostrar opcion incorrecta
    cout<<"Opcion incorrecta "<<endl;
                  system("pause");
}
}while(opcion!=3);
}

