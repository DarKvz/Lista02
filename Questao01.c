#include <stdlib.h>
#include<stdio.h>

#define tam 20

int le_valida_num();

int main(){
	int contador=0;
	int i,a;
	int num[tam];
	
	printf("Digite um numero de 1 a 99: ");
	scanf("%d", &num[contador]);
	
	while(contador<tam-1){
		num[contador] = le_valida_num();
		
		if (num[contador] == 0){
			break;
		}
		
        contador++;
		
		if(contador>=10){
			printf("Deseja continuar? digite 0 para parar ");
			scanf("%d", &num[contador]);
			
			if(num[contador]==0){
				break;
			}
		}
	}
	
	for(contador=1;contador<=tam;contador++){
		for(i = 0 ;i < tam-1; i++){
			if(num[i] < num[i + 1]){
				a = num[i];
				num[i] = num[i + 1];
				num[i+1] = a;
			}
		}
	}
	
	printf("numeros em ordem: \n");
	for(i=0;i<contador;i++){
		printf("%d\n\n",num[i]);
	}
	
	return 0;
}

int le_valida_num(){
	int num;
	
	do{
		printf("Digite um numero de 1 a 99: ");
		scanf("%d", &num);
		
		if(num<1||num>99){
			printf("numero invalido!\n");
		}
	}while(num<1||num>99);
	
	return num;
}