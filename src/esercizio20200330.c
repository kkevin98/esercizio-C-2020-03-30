#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//funzione che calcola la serie di Fibonacci tornando un long:
unsigned long fibonacci(unsigned int n){

	if(n==0){
		return 0;
	}

	if(n==1){
		return 1;
	}

	return fibonacci(n-1)+fibonacci(n-2);

}

/*Max valore per cui fibonacci funziona
//funzione che calcola la serie di Fibonacci tornando un long long:
unsigned long long fibonacci_longlong(unsigned int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	return fibonacci_longlong(n-1)+fibonacci_longlong(n-2);
}

//funzione che trova il valore massimo di n per cui fibonacci(n) restituisce un valore della serie corretto
unsigned int maxfibonacci_interno(unsigned int n){
	if(fibonacci(n)!=fibonacci_longlong(n)){
		return (n-1);
	}
	else{
		return maxfibonacci_interno(n+1);
	}
}

//funzione che trova il valore massimo di n per cui fibonacci(n) restituisce un valore della serie corretto
int maxfibonacci(){
	return maxfibonacci_interno(0);
}

*/


//restituisce un array dove la cella i-ma contiene il valore di fibonacci(i).
unsigned long * fibonacci_array(unsigned int n){
	unsigned long * array;
	array=malloc((n+1)*sizeof(long));
	if(array==NULL){
		return NULL;
	}
	for(int i=0; i<=n; i++){
		array[i]=fibonacci(i);
	}
	return array;
}

void swap_ulong(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}


unsigned long * reverse_ulong(unsigned long * array, unsigned int i, unsigned int j)
{
	while (i < j)
		swap_ulong(&array[i++], &array[--j]);

	return array;
}


unsigned long * complete_reverse_ulong(unsigned long * array, unsigned int array_len) {
	return reverse_ulong(array, 0, array_len);
}


void bubble_sort(unsigned long * array, unsigned int array_dimension) {
	unsigned int n=array_dimension;
	while(n>=1){
		int newn=0;
		for(int i=1; i<=(n-1); i++){
			if(array[i-1]>array[i]){
				swap_ulong(&array[i-1], &array[i]);
				newn=i;
			}
		}
		n=newn;
	}
}



int main(int argc, char *argv[]) {

	unsigned long * fibonacci_result=fibonacci_array(39);

	unsigned long * fibonacci_result_copy;

	fibonacci_result_copy=malloc(40*sizeof(unsigned long));

	if(fibonacci_result==NULL || fibonacci_result_copy==NULL){
		exit(EXIT_FAILURE);
	}

	memcpy(fibonacci_result_copy, fibonacci_result, 40*sizeof(unsigned long));

	fibonacci_result_copy=complete_reverse_ulong(fibonacci_result_copy, 40);

	bubble_sort(fibonacci_result_copy, 40);

	printf("Confronto degli array:\n");

	for(unsigned int t=0; t<40; t++){
		printf("fibonacci_result[%2u]=%10lu \t fibonacci_result_copy[%2u]=%10lu\n", t, fibonacci_result[t], t, fibonacci_result_copy[t]);
	}

	return 0;
}
















