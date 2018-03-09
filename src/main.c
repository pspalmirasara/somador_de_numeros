/* Somador de numeros */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STRING_MAX 100

double fatorial(int fat){
	int p;
	double res;
	
	p = fat-1;
	while (1){
		if(p==0){
			break;
		}else{
			fat = fat*p;
			p--;
		}		
	}
	res = (double)fat;

	return res;
}
	

int main() {
	char frase[TAM_STRING_MAX]; //contem a string a ser analisada
	char numero_str[TAM_STRING_MAX]; //o numero sera antes uma string, depois convertido e adicionado a soma	
	double numero_db, soma;
	int frase_tam;   //contem o tamanho da string
	int numero_int;
	int i,k;
	int usou_ponto = 0; //1 caso ja tenha usado, 0 caso nao

	int numero_str_ini, numero_str_fim;


	scanf("%[^\n]s", frase);

	
	frase_tam = strlen(frase);
	for (int i=0; i<frase_tam; i++){
	}

	soma = 0.0;

	for (int i=0; i<frase_tam; i++){ //varrendo a string

		//Para caso ache um numero ou ponto
		if ( frase[i] == '0' || frase[i] == '1' || frase[i] == '2' ||
		  frase[i] == '3' || frase[i] == '4' || frase[i] == '5' || frase[i] == '6' ||
		  frase[i] == '7' || frase[i] == '8' ||frase[i] == '9' || frase[i] == '.'){


 			//o numero apenas eh valido caso seja comeco de linha ou tenha espaco antes
			if ( i==0 || frase[i-1] == ' '){
				numero_str_ini = i;
				while (1){
					if (frase[i+1] == '0' || frase[i+1] == '1' || frase[i+1] == '2' ||
				 	 frase[i+1] == '3' || frase[i+1] == '4' || frase[i+1] == '5' || frase[i+1] == '6' ||
				 	 frase[i+1] == '7' || frase[i+1] == '8' ||frase[i+1] == '9' ||frase[i+1] == '.'){
						i++;
					}else{
						break;
					}
				}
				
				//caso de ser valido no final de frase ou com espaco no final
				if ( (i+1 == frase_tam) || (frase[i+1] == ' ')){
					numero_str_fim = i;

					//limpando a string
					for (k=0; k<TAM_STRING_MAX; k++){
						numero_str[k] = '\0';
					}

					//passando o numero para uma string separada
					k=0;
					for (int j = numero_str_ini; j <= numero_str_fim; j++){
						numero_str[k] = frase[j];
						k++;		
					}

					//transformar str em double
					numero_db = atof(numero_str);	
					soma = numero_db + soma;		

				}

				//caso de ser valido com exclamacao no final
				if ( (frase[i+1] == '!') && ((i+2 == frase_tam) || (frase[i+2] == ' '))){
					numero_str_fim = i;

					//limpando a string
					for (k=0; k<TAM_STRING_MAX; k++){
						numero_str[k] = '\0';
					}

					//passando o numero para uma string separada
					k=0;						
					for (int j = numero_str_ini; j <= numero_str_fim; j++){
						numero_str[k] = frase[j];
						k++;		
					}
				
					//transformar str em inteiro
					numero_int = atoi(numero_str);	

					//funcao de fatorial
					numero_db = fatorial(numero_int);
					soma = numero_db + soma;
				}
			}			
		}		
	}

	//printando a saida
	printf ("%.2lf\n", soma);

	return 0;
}
