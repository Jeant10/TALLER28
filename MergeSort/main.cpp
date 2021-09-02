#include <iostream>
#include <fstream>
using namespace std;


void dividir(int a[], int inicial, int final);

void Fusionar(int a[],int pinicial, int pfinal, int medio);

void ingresar(int a[],int n);

int main()
{
   int A[10];
   ofstream archivo;
   archivo.open("mergesort.txt", ios::out);
   cout<<"INGRESE 10 ELEMENTOS AL ARREGLO :"<<endl;

   ingresar(A,10);

   cout<<endl<<"ELEMENTO DEL ARREGLO: ";
   archivo<<endl<<"ELEMENTO DEL ARREGLO: ";

   for (int i = 0; i < 10; i++)
	{
	    cout<<"|"<<A[i]<<"|";
	    archivo<<"|"<<A[i]<<"|";
	}

   dividir(A,0,10);

   cout<<endl<<"ELEMENTO ORDENADOS DEL ARREGLO: ";
   archivo<<endl<<"ELEMENTO ORDENADOS DEL ARREGLO: ";

   for (int i = 0; i < 10; i++)
	{
	    cout<<"|"<<A[i]<<"|";
	    archivo<<"|"<<A[i]<<"|";
	}

	archivo.close();
	return 0;
}




void dividir(int a[], int inicial, int final)
{

    if(inicial>=final)
    {
		return;
	}
	int m =inicial+ (final-inicial)/2;
	dividir(a,inicial,m);
	dividir(a,m+1,final);
	Fusionar(a,inicial,m,final);
}


void Fusionar(int arr[], int pinicial, int medio, int pfinal)
{
    int n1 = medio - pinicial + 1;
    int n2 = pfinal - medio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[pinicial + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];


    int i = 0;

    int j = 0;

    int k = pinicial;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void ingresar(int a[],int n)
{
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
}
