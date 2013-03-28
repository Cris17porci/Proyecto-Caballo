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
             // aqui imprime el tablero de ajedrez
            cuenta++;
            
        }
    }
    
}

int verificador( char tablero[7][7])
{
    char x =(char)48;
    for(int i=0;i<8;i++)
    {
            for(int j=0; j<8;j++)
            {
                    if(tablero[i][j]== x)
                    {
                               return 0;
                                               }
                    
                    }
            }
            return 1;
    }

void mover(char tablero[7][7], int x , int y)
{
     srand((unsigned)time(0));
     int e=0;
     ofstream fs("mov.txt");
     while(e!=1)
     {
  int op= (1 + rand() % 8);
       
     if(op==1)
     {  
     if(x+2<8 && y+1<8 && tablero[x+2][y+1]!=(char)260 && x+2>=0 && y+1>=0)
     {
            x=x+2;
            y++;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            
            ver(tablero);
            e=verificador(tablero);
           
            }
     }
     if(op==2)
     {       
             
             
           if(x+2<8 && y-1<8 && tablero[x+2][y-1]!=(char)260 && x+2>=0 && y-1>=0 )
           {
                    
                  x=x+2;
                  y--;
                  tablero[x][y]=(char)1;
                  cout<<"Se a producido un movimiento";
                  fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
                  ver(tablero);
                  e=verificador(tablero);
                  
            
            }
            }
     if(op==3)
     {
              
          
     if(x-2<8 && y+1<8 && tablero[x-2][1+y]!=(char)260 && x-2>=0 && y+1>=0 )
     {
              
            x=x-2;
            y++;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            ver(tablero);
            e=verificador(tablero);
           
            
            }
            }
     if(op==4)
     {
              
          
     if(x-2<8 && y-1<8 && tablero[x-2][y-1]!=(char)260 && x-2>=0 && y-1>=0 )
     {
              
            x=x-2;
            y--;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            ver(tablero);
            e=verificador(tablero);
            
            
            }
            }
     if(op==5)
     {
              
        
     if(x+1<8 && y+2<8 && tablero[x+1][y+2]!=(char)260 && x+1>=0 && y+2>=0 )
     {
              
            y=y+2;
        x++;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            
            ver(tablero);
            e=verificador(tablero);
            
            }
            }
     if(op==6)
     {       
             
             
           if(x-1<8 && y+2<8 && tablero[x-1][y+2]!=(char)260 && x-1>=0 && y+2>=0 )
           {
                    
                  y=y+2;
           x--;
                  tablero[x][y]=(char)1;
                  cout<<"Se a producido un movimiento";
                  fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
                  ver(tablero);
                  e=verificador(tablero);
                  
            
            }
            }
     if(op==7)
     {
              
          
     if(x+1<8 && y-2<8 && tablero[x+1][y-2]!=(char)260 && x+1>=0 && y-2>=0)
     {
              
            y=y-2;
     x++;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            ver(tablero);
            e=verificador(tablero);
            
            
            }
            }
     if(op==8)
     {
              
          
     if(x-1<8 && y-2<8 && tablero[x-1][y-2]!=(char)260 && x-1>=0 && y-2>=0)
     {
              
            y=y-2;
            x--;
            tablero[x][y]=(char)1;
            cout<<"Se a producido un movimiento";
            fs<<"Posicion: ["<<x<<","<<y<<"]"<<endl;
            ver(tablero);
            e=verificador(tablero);
            
            
            }
          }
          
          }
          
          
          fs.close();
          ver(tablero);
          system("pause");
}

     



int main()
{
    
    char tablero[7][7];
    int x,y,cuenta=0,inicial=0,z=0,b=0,fin=1;
    
    

 while(inicial==0)
{
    cout<<"Bienvenido a la tarea 01 de software"<<endl; 
    cout<<"A continuacion se le pedira la posicion inicial"<<endl;
    cout<<"en la que desea colocar al caballo"<<endl<<endl<<endl;
    cout<<"Ingrese posicion x del caballo en donde desea posicionarlo: ";
    cin>>x;
    cout<<"Ingrese posicion y del caballo en donde desea posicionarlo: ";
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
       cout<< "Recuerde que los peones estan en la posicion: "<<endl;
       cout<< "[2][3], [2][5], [5][2], [5][5]"<<endl;
        
       system("pause");
       system("cls");
       }     
       
}
ver(tablero);
system("pause");

mover(tablero,x,y);
ver (tablero);

 

   system("pause");
}
