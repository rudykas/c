#include <stdio.h>
#include <stdlib.h>



// 1. upcase("abcD12") -> "ABCD12", преобразует буквы в нижнем регистре в верхний регистр, цифры и буквы в верхнем регистре не трогает (см. таблицу ASCII)
// 2. swap_case("abcD12") -> "ABCd12", то же самое, но буквы в верхем регистре пребразует в нижний регистр (см. таблицу ASCII)
// 3. reverse("abc") -> "cba", переворачивает строку
// 4. dup_string("abc",3) -> "abcabcabc", которая повторяет строку n-е кол-во раз, указанное во втором аргументе
// 5. appendl_char("abc",'d') -> "dabc", которая добавляет к строке один символ слева
// 6. appendr_char("abc",'d') -> "abcd", которая добавляет к строке один символ справа

//mentioning function in advance in order to avoid an error 

char* upcase(char*);
int length(char*);
char* swap_case(char*);
char* reverse(char* );
char* dup_string(char*, int);
char* appendr_char(char*, char);
char* appendl_char(char*, char);
char* int_to_string(int);


//%d defining a type with %d

int main(){
/*	printf("%s\n", dup_string("abc",3));
	printf("%s\n", appendr_char("abc",'d'));
	printf("%s\n", appendl_char("abc",'d'));*/ 
	printf("%s", int_to_string(197));
	//printf("%s",reverse("abc"));
}

char* int_to_string(int x){
    char* out = "";
    while (x > 0){
    	int a = x%10;
    	x = x/10;
    	out = appendl_char(out,a+'0');
    }
    return out;
}

// in-place


char* appendl_char(char* x, char y){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	int lenx = length(x);
	char* mem = malloc((lenx+1)*sizeof(char)+1);
	mem[0] = y;
	for (int j = 1; j < lenx+2; j++){
		mem[j] = x[j-1];
	}
	mem[lenx+1] = '\0'; 
	return mem;
}

char* appendr_char(char* x, char y){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	int lenx = length(x);
	char* mem = malloc((lenx+1)*sizeof(char)+1);
	for (int j = 0; j < lenx+1; j++){
		mem[j] = x[j];
	}
	mem[lenx] = y;
	mem[lenx+1] = '\0'; 
	return mem;
}

char* dup_string(char* x, int y){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	int len = length(x);
	char* mem = malloc((len+1)*sizeof(char)*y);
	for (int i = 0; i < y+1; i++){
		for (int j = 0; j < len+1; j++){
		    mem[len*i + j] = x[j];
		}
	}
	mem[len*y] = '\0'; 
	return mem;
}


char* reverse(char* x){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	int len = length(x);
	char* mem = malloc((len+1)*sizeof(char));
	for (int i = 0; i < len; i++){
		mem[i] = x[len - i-1];
	    }
		mem[len+1] = '\0'; 
	return mem;
}

char* swap_case(char*x){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	// int len = length(x);
	char* mem; //= malloc((len+1)*sizeof(char));
	for (int i = 0; i != '\0'; i++){
		if (x[i]> 96 && x[i]< 123) {mem[i] = x[i]-32;
	    }
	    else if (x[i]> 64 && x[i]< 91) {mem[i] = x[i]+32;
	    }
	    
		else {mem[i] = x[i];
	    }
	}
	mem[-1] = '\0'; 	
	return mem;
}

char* upcase(char*x){
    
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	int len = length(x);
	char* mem = malloc((len+1)*sizeof(char));
	for (int i = 0; i < len; i++){
		if (x[i]> 96 && x[i]< 123) {mem[i] = x[i]-32;
	    }
		else {mem[i] = x[i];
	    }
	}
	mem[len] = '\0'; 
//Q what is \0?
	return mem;;
}






int length(char*x){
    int i;
    // used /0 in order to check if it is symbol of the end of the string and not just 0 symbol
	for (i = 0; x[i] != '\0'; i++){
	}
	return i;
}



// "abc"+"de"  -> "abcde"

/*
abc
012

de
01

abcde
01234

valgrind

*/

char* concat(char* x, char* y){
	int lenx = length(x);
	int leny = length(y);
	int out_length = lenx + leny;
	char* mem = malloc((out_length+1)*sizeof(char));
	for (int i = 0; i < lenx; i++){
		mem[i] = x[i];
	}
	for (int i = 0; i < leny; i++){
		mem[lenx+i] = y[i];
	}
	mem[out_length] = '\0';
	return mem;
}


//32


// for(int i =0; i< length(s); i++)

int is_substring(char*, char*);


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


	
int is_palindrome(char* x){
	int i;
	for (i = 0; i < length(x)/2; i++){
		if (x[i] != x[length(x)-1-i]){return 0;} 
	}
		return 1;	
} 

