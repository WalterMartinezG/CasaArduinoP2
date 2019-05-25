#include <iostream>
#include <fstream>
#include <windows.h>
#include<string>
#include <stdio.h>
#include "SerialClass.h"

using namespace std;
int salir = 0;
COORD coord={0,0}; // Variable global de coordenadas
char mensaje[50]="\0";
char encendido.1[12]= "encendido1";
char apagado1[12]= "apagado1";
char encendido2[12]= "encendido2";
char apagado2[12]= "apagado2";
char encendido3[12]= "encendido3";
char apagado3[12]= "apagado3";
char encendido4[12]= "encendido4";
char apagado4[12]= "apagado4";
char arriba[8]="arriba";
char abajo[8]="abajo";

char abierto[8]= "abierto";
char cerrado[8]= "cerrado";
//Puerto Serie
    Serial* Puerto = new Serial("COM7");

void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
//Procedimiento para poder abrir o cerrar la puerta
 void ControlPuerta()
 {
     int opc;
     system("cls");
     gotoxy(45,10); cout<< "Casa Arduino IDE - Puerta Principal";
     gotoxy(20,11);cout<<"1.Abrir Puerta";
     gotoxy(20,12);cout<<"2.Cerrar Puerta";
     gotoxy(20,14);cout<<"Elija la opcion deseada: ";
     cin>> opc;

     switch(opc)
     {
     case 1:
        gotoxy(15,18); cout<< "Bienvenido a casa, puerta abierta"<<endl;
        Puerto->WriteData(abierto,sizeof(abierto)-1);
        Sleep(500);
        system("pause");
        break;
     case 2:
        gotoxy(15,18); cout<< "Puerta cerrada"<<endl;
        Puerto->WriteData(cerrado,sizeof(cerrado)-1);
        Sleep(500);
        system("pause");
        break;

     }

 }

 //Procedimieto para poder manejar la plumilla de entrada de carros
 void ControlPlumilla()
 {
     int opc;
     system("cls");
     gotoxy(45,10); cout<< "Casa Arduino IDE - Plumilla";
     gotoxy(20,11);cout<<"1.Subir Plumilla";
     gotoxy(20,12);cout<<"2.Bajar Plumilla";
     gotoxy(20,14);cout<<"Elija la opcion deseada: ";
     cin>> opc;

     switch(opc)
     {
     case 1:
        gotoxy(15,18); cout<< "Bienvenido a casa, abriendo plumilla..."<<endl;
        Puerto->WriteData(arriba,sizeof(arriba)-1);
        Sleep(500);
        system("pause");
        break;
     case 2:
        gotoxy(15,18); cout<< "Plumilla Cerrada"<<endl;
        Puerto->WriteData(abajo,sizeof(abajo)-1);
        Sleep(500);
        system("pause");
        break;

     }


 }

 //Procedimiento para controlar la iluminacion de la casa
   void EncenderLuces()
   {
       int opc;
       system("cls");
       gotoxy(45,10); cout<< "Casa Arduino IDE - Iluminacion";
       gotoxy(20,11);cout<<"1.Encender Luces Dormitorio";
       gotoxy(75,11);cout<<"2.Apagar Luces Dormitorio";
       gotoxy(20,12);cout<<"3.Encender Luces Sanitario";
       gotoxy(75,12);cout<<"4.Apagar Luces Sanitario";
       gotoxy(20,13);cout<<"5.Encender Luces Comedor";
       gotoxy(75,13);cout<<"6.Apagar Luces Comedor";
       gotoxy(20,14);cout<<"7.Encender Luces Sala";
       gotoxy(75,14);cout<<"8.Apagar Luces Sala";
       gotoxy(40,17);cout<<"Elija una opcion entre 1 y 8: ";
       cin>> opc;

       switch(opc)
       {
       case 1:
        gotoxy(0,19);cout<<"Encendiendo luz del Dormitorio"<<endl;
        Puerto->WriteData(encendido1,sizeof(encendido1)-1);
        Sleep(500);
        system("pause");
        break;
       case 2:
        gotoxy(0,19);cout<<"Apagando luz del Dormitorio"<<endl;
        Puerto->WriteData(apagado1,sizeof(apagado1)-1);
        Sleep(500);
        system("pause");
        break;
       case 3:
        gotoxy(0,19);cout<<"Encendiendo luz del Sanitario"<<endl;
        Puerto->WriteData(encendido2,sizeof(encendido2)-1);
        Sleep(500);
        system("pause");
        break;
       case 4:
        gotoxy(0,19);cout<<"Apagando luz del Sanitario"<<endl;
        Puerto->WriteData(apagado2,sizeof(apagado2)-1);
        Sleep(500);
        system("pause");
        break;
       case 5:
        gotoxy(0,19);cout<<"Encendiendo luz del Comedor"<<endl;
        Puerto->WriteData(encendido3,sizeof(encendido3)-1);
        Sleep(500);
        system("pause");
        break;
       case 6:
        gotoxy(0,19);cout<<"Apagando luz del Comedor"<<endl;
        Puerto->WriteData(apagado3,sizeof(apagado3)-1);
        Sleep(500);
        system("pause");
        break;
       case 7:
        gotoxy(0,19);cout<<"Encendiendo luz de la Sala"<<endl;
        Puerto->WriteData(encendido4,sizeof(encendido4)-1);
        Sleep(500);
        system("pause");
        break;
       case 8:
        gotoxy(0,19);cout<<"Apagando luz de la Sala"<<endl;
        Puerto->WriteData(apagado4,sizeof(apagado4)-1);
        Sleep(500);
        system("pause");
        break;


       }


   }

 void Menu()
 {
    int opc = 0;
    system("cls");
    gotoxy(35,8);  cout<<" __^__                                    __^__";
    gotoxy(35,9);  cout<<"( ___ )----------------------------------( ___ )";
    gotoxy(35,10); cout<<" | / |                                    | / |";
    gotoxy(35,11); cout<<" | / |    Control de Casa Arduino - Menu  | / |";
    gotoxy(35,12); cout<<" |___|         Que desea hacer?           |___|";
    gotoxy(35,13); cout<<"(_____)----------------------------------(_____)";
    gotoxy(45,16); cout<<"1. Encender/Apagar Luces";
    gotoxy(45,17); cout<<"2. Abrir/Cerrar Puerta principal";
    gotoxy(45,18); cout<<"3. Subir/Bajar Plumilla";
    gotoxy(45,19); cout<<"4. Salir";
    gotoxy(40,22); cout<<"Ingrese el numero de la opcion deseada [ ]";
    gotoxy(80,22); cin>>opc;

    switch(opc)
    {
    case 1:
        EncenderLuces();
        break;
    case 2:
        ControlPuerta();
        break;
    case 3:
        ControlPlumilla();
        break;
    case 4:
        system("cls");
        cout<<"Buen dia, Casa Arduino IDE cerrado..."<<endl;
        salir=4;
        break;
    default:
        system("cls");
        cout<<"Elija una opcion entre 1 y 4, su opcion no es valida" << endl;
        system("pause");
        break;
    }

 }



int main()
{
    //Titulo de la ventana
    SetConsoleTitle("Casa Arduino Proyecto Final Programacion I");


    while(salir != 4)
    {
        Menu();
    }

    return 0;
}
