#include <bits/stdc++.h>
#include<time.h>
using namespace std;

#define MAX 100
int peso[MAX], valor[MAX]; //Peso de cada obj y el valor es la importanica
int memo[MAX][MAX]; //La memoria
int mochila(int i, int espacio_libre)
{
    if (espacio_libre < 0)
        return -1; //Metimos un objeto demasiado pesado
    else if (i == 0)
        return 0; //Si ya no hay objetos,  no obtenemos ganacia
    else if (memo[i][espacio_libre] != -1){
        cout<<"YA ESTÁ EN MEMORIA >: "<<memo[i][espacio_libre]<<endl;
        return memo[i][espacio_libre]; //Retoan lo que ya se guardo en memoria
    }
    //Si no tomariamos el obj
    int opcion1 = mochila(i - 1, espacio_libre);
    //Si tomariamos el obj
    int opcion2 = valor[i] + mochila(i - 1, espacio_libre - peso[i]);
    //Retornamos el máximo  y procedemos a verficar
    cout<<"OPC 1 "<<opcion1<<endl;
    cout<<"OPC 2 "<<opcion2<<endl;

    return (memo[i][espacio_libre] = max(opcion1, opcion2));
}
int main(int argc, char const *argv[])
{
    int N=50; //Cantidad de objetos
    int CAPACIDAD = 100; //Capacidad de la mochila
    srand(time(NULL));
    for(int i = 0; i < MAX; i++)
    {
        peso[i] = 1+rand()%(101-1); //pesos aleatorios de cada obj
        valor[i] = 1+rand()%(101-1); //valores aletorios de cada obj 
    }
    
    memset(memo, -1, sizeof(memo)); //Marcamos como no calculados
    int solucion = mochila(N, CAPACIDAD);
    cout<<"MEJOR SOLUCIÓN >: "<<solucion<<endl;
    return 0;
}
