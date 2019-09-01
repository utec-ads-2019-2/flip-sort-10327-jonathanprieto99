#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n;
int input[1000];
int * operaciones= new int;

void generar(int input[], int n){
    for (int i = 0; i < n; ++i) {
        int z=rand()%100;
        input[i]=z;
    }
}

void printarray(int input[], int n){
    for (int i = 0; i!=n; i++) {
        int flag=0;
        if (i==0 and flag==0){
            cout <<"["<< input[i]<<";";
            flag=1;
        }
        if (i==n-1 and flag==0){
            cout << input[i] << "]" <<endl;
            flag=1;
        }
        else{
            if (flag==0){
                cout << input[i]<<";";
                flag=1;
            }
        }
    }
}

void ordenar(int input[], int n, int &operaciones){
    int  j;
    int i;
    operaciones=0;
    for (i=0; i<n-1 ; i++) {
        for (j=0; j<n-i-1 ; j++){
            int valor1=input[j];
            int valor2=input[j+1];
            if(valor1>valor2){
                input[j]=valor2;
                input[j+1]=valor1;
                operaciones++;
            }
        }
    }
}


int main() {
    srand(time(NULL));

    //cout << "Ingresar la longitud del array a crear: ";
    //generar(input,n);
    while (cin >>n && n<=1000){
        for (int i = 0; i !=n ; ++i) {
         cin>>input[i];
        }

        //printarray(input,n);

        ordenar(input,n,*operaciones);

        //printarray(input,n);

        cout<<"\n"<<"Minimum exchange operations : "<<*operaciones<<"\n";
    }
}