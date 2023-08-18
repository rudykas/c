#include <stdio.h>

int is_sorted(int array[], int size){
	for (int i = 0; i < size-1; i++){
		if(array[i+1] < array[i]){
			return 0;
		}
	}
	return 1;
}

int fact(int x){
	if (x == 1){
		return 1;
	}
	return x*fact(x-1);
}

int main(){
	printf("%d", fact(10));
}
