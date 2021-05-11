#include<bits/stdc++.h>
using namespace std;
// código comentado

void sort(int a[],int n){
	int salto, j, menor_valor;
    // o salto é dividido por 2 a cada iteração
	for(salto = n/2; salto >= 1; salto /= 2){
        // i sempre começa no salto porque garantimos que tem 
        // pelo menos elemento (i-salto) a ser comparado e/ou trocado
		for(int i = salto; i < n; i++){
            // supomos que o menor valor é esse
			menor_valor = a[i];
            // caminhamos pelo array em sentido contrário (<-)
            //  até o primeiro elemento daquele subarray 
			for(j = i; j >= salto; j-= salto){  
                // se essa afirmação for falsa, significa que todos
                // os elementos daquele subarray partindo da posição do
                // menor valor para trás estão ordenados  
                if(menor_valor < a[j-salto] == false) break;
				// se o menor_valor for de fato menor que o j-ésimo anterior a ele,
                // então eles trocam de lugar
                else{
                    a[j] = a[j-salto];
                }
            }
            // a posição mais no início do array recebe aquele menor valor 
			a[j] = menor_valor;
		}
    }
}