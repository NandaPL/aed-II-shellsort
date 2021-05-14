#include<bits/stdc++.h>
using namespace std;
int array1[100000];
int array2[100000];
int array3[100000];
int array4[100000];

void ordenaCrescente(int a[],int n){
	int salto, j, menor_valor;
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
			menor_valor = a[i];
			for(j = i; j >= salto; j-= salto){  
                if(menor_valor < a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = menor_valor;
		}
    }
}

void ordenaDecrescente(int a[], int n){
	int salto, j, maior_valor;
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
			maior_valor = a[i];
			for(j = i; j >= salto; j-= salto){  
                if(maior_valor > a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = maior_valor;
		}
    }
}
void ordenaCrescenteDecrescente(int a[], int n){
    int salto, j, menor_valor;
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
			menor_valor = a[i];
			for(j = i; j >= salto; j-= salto){  
                if(menor_valor < a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = menor_valor;
		}
    }
    int maior_valor;
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
			if(i < n/2) continue;
            maior_valor = a[i];

			for(j = i; j >= salto; j-= salto){  
                if(j < n/2) break;
                if(maior_valor > a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = maior_valor;
		}
    }
    
}
void ordenaDecrescenteCrescente(int a[], int n){
    // ordena todo o array de forma crescente
    int salto, j, menor_valor, maior_valor;
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
			menor_valor = a[i];
			for(j = i; j >= salto; j-= salto){  
                if(menor_valor < a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = menor_valor;
		}
    }
	for(salto = n/2; salto >= 1; salto /= 2){
		for(int i = salto; i < n; i++){
            if(i >= n/2) continue;
			maior_valor = a[i];
			for(j = i; j >= salto; j-= salto){ 
                if(j >= n/2) break; 
                if(maior_valor > a[j-salto] == false) break;
                else{
                    a[j] = a[j-salto];
                }
            }
			a[j] = maior_valor;
		}
    }
	
}

int main (){
    int max = 100000;
    int min = 1;
    for(int i = 0; i < 100000; i++){
        int aleatorio = rand()%(max-min+1) + min;
        array1[i] = aleatorio;
        array2[i] = aleatorio;
        array3[i] = aleatorio;
        array4[i] = aleatorio;
    }
    auto inicio = std::chrono::high_resolution_clock::now();
    ordenaCrescente(array1, 100000);
    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    cout << "array 1 Ordena Crescente: " << milliseconds << " milisegundos\n";
    
    inicio = std::chrono::high_resolution_clock::now();
    ordenaDecrescente(array2, 100000);
    resultado = std::chrono::high_resolution_clock::now() - inicio;
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    cout << "array 2 Ordena Decrescente: " << milliseconds << " milisegundos\n";

    inicio = std::chrono::high_resolution_clock::now();
    ordenaCrescenteDecrescente(array3, 100000); 
    resultado = std::chrono::high_resolution_clock::now() - inicio;
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    cout << "array 3 Ordena Crescente e Decrescente: " << milliseconds << " milisegundos\n";

    inicio = std::chrono::high_resolution_clock::now();
    ordenaDecrescenteCrescente(array4, 100000);    
    resultado = std::chrono::high_resolution_clock::now() - inicio;
    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    cout << "array 4 Ordena Decrescente e Crescente: " << milliseconds << " milisegundos\n";

    
    return 0;
}