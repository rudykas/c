#include <stdio.h>

//mentioning function in advance in order to avoid an error 
int length(char*);

//%d defining a type with %d

// int main(){
//     printf("%d", length("foo bar "));
// }

int length(char*x){
    int i;
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	for (i = 0; x[i] != '\0'; i++){
	}
	return i;
}


// "abc"+"de"  -> "abcde"

// for(int i =0; i< length(s); i++)

int is_substring(char*, char*);

// int main(){
// 	printf("%d", is_substring("tem", "tetimt"));
// }

int is_substring(char* x, char* y){
	int i; 
	//here:
	for (i = 0; i < length(y)-length(x)+1; i++){
		if (x[0] == y[i]){
			int j;
			for (j=0; j <= length(x); j++){
				if (x[j] != y[i+j]){goto here;
				} 
			}
		return 1;	
		} 
	here:;
	}
	return 0;	
	// for i in range(len(b)-len(a)+1):
    //     if a[0] == b[i]:
    //         for j in range(len(a)):
    //             if a[j] == b[i+j]: continue
    //             else: break
    //         return 1 
    // return 0
}

int is_beginning(char*, char*);

// int main(){
// 	printf("%d", is_beginning("abc","acbcdef"));
// }

int is_beginning(char* x, char* y){
	int i;
	for (i = 0; i < length(x); i++){
		if (x[i] != y[i]){return 0;} 
	}
		return 1;	
} 

int is_palindrome(char*);

int main(){
printf("%d", is_palindrome("abcddcba"));
}

	
int is_palindrome(char* x){
	int i;
	for (i = 0; i < length(x)/2; i++){
		if (x[i] != x[length(x)-1-i]){return 0;} 
	}
		return 1;	
} 

