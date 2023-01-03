#include <stdio.h>

int length(char*);

int main(){
    printf("%d", length("foo bar "));
}

int length(char*x){
    int i;
	for (i = 0; x[i] != '\0'; i++){
	}
	return i;
}


"abc"+"de"  -> "abcde"

for(int i =0; i< length(s); i++)
