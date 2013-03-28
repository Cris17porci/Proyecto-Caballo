#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream> 

using namespace std;

void inicializar(char tablero[7][7],int x,int y)
{
    int i,j;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            tablero[i][j]=(char)48;
        }
    }
    tablero [x][y]= (char)1; // Casillero en donde se encuentra el caballo representado con una carita
    tablero [2][2]= (char)260; // Casillas donde se encuentran los peones representados por rombos
    tablero [2][5]= (char)260;
    tablero [5][2]= (char)260;
    tablero [5][5]=(char)260;
}


int pos_real(int x, int y)
{
   if(x==2 && y==2 || x==2 && y==5 || x==5 && y==2 || x==5 && y==5 || x<0 || y<0 || x>7 || y>7) // verificamos en que casillas no puede encontrarse el caballo
        return 0;
    else
        return 1;
}

void ver(char tablero[7][7])
{
   int i,j,cuenta=0;
   cout<<endl<<endl;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
                        if (j<7)
            cout<<" | "<<tablero[i][j];
            else
            cout<<" | "<<tablero[i][j]<<" | "<<endl;
             // aqui imprime el tablero de ajedres
            cuenta++;
        }
    }
    cout<<endl<<endl<<"Total de casillas: "<<cuenta <<endl;
}

int main()
{

    char tablero[7][7];
    int x,y,cuenta=0,inicial=0,z=0,b=0;
    

 while(inicial==0)
{
    cout<<"Bienvenido a la tarea 01 de software"<<endl; 
    cout<<"A continuacion se le pedira la posicion inicial"<<endl;
    cout<<"en la que desea colocar al caballo"<<endl<<endl<<endl;
    cout<<"Ingrese posicion x del caballo en donde desea posicionarlo: ";
    cin>>x;
    cout<<"Ingrese posicion ydel caballo en donde desea posicionarlo: ";
    cin>>y;
    cout<<endl;
    z=pos_real(x,y);
    if(z==1)
      {
       inicializar(tablero,x,y);
       inicial=1;
       
      }
    else
       {
       cout<<endl;
       cout<<"La posicion iniciada no existe dentro de un tablero de ajedres"<<endl;
       cout<<"Recordar que debe ingresar pos entre [0][0] a [7][7]"<<endl; 
       system("pause");
       system("cls");
       }     
       
}
ver(tablero);
 

   system("pause");
}
