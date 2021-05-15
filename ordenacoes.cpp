#include<bits/stdc++.h>
using namespace std;
int array1[100000];
int array2[100000];
int array3[100000];
int array4[100000];
int array5[100000];

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

long long tempoDeOrdenacao(int array[], int tamanho){
    auto inicio = std::chrono::high_resolution_clock::now();
    ordenaCrescente(array, tamanho);
    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long milissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    return milissegundos;

}
int main (){
    int tamanho_max = 100000, min = 1;

    // aleatório -> crescente
    for(int i = 0; i < tamanho_max; i++){
        int aleatorio = rand()%(tamanho_max-min+1) + min;
        array1[i] = aleatorio;
    }
    cout << "Aleatório -> Crescente: " << tempoDeOrdenacao(array1, tamanho_max) << "ms\n";
    
    // crescente -> crescente
    for(int i = 0; i < tamanho_max; i++){
        array2[i] = array1[i];
    }
    cout << "Crescente -> Crescente: " << tempoDeOrdenacao(array2, tamanho_max) << "ms\n";

    // decrescente -> crescente
    for(int i = 0, j = tamanho_max; i < tamanho_max; i++, j--){
        array3[i] = j;
    }
    cout << "Decrescente -> Crescente: " << tempoDeOrdenacao(array3, tamanho_max) << "ms\n";

    // decrescente/crescente -> crescente
    for(int i = tamanho_max/2, j = 0; i >= 0; i--, j++){
        array4[j] = array3[i];
    }
    for(int i = tamanho_max/2+1; i <= tamanho_max; i++){
        array4[i] = array3[i];
    } 
    cout << "Decrescente/Crescente -> Crescente: " << tempoDeOrdenacao(array4, tamanho_max) << "ms\n";

    // crescente/decrescente -> crescente
    for(int i = 0; i <= tamanho_max/2; i++){
        array5[i] = array4[i];
    }
    for(int i = tamanho_max/2, j = tamanho_max; i < tamanho_max; i++, j--){
        array5[j] = array4[i];
    }
    cout << "Crescente/Decrescente -> Crescente: " << tempoDeOrdenacao(array5, tamanho_max) << "ms\n";

    // auto inicio = std::chrono::high_resolution_clock::now();
    // ordenaCrescente(array1, 100000);
    // auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    // long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();
    // cout << "array 1 Ordena Crescente: " << milliseconds << " milisegundos\n";

    
    return 0;
}