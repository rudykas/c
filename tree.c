#include <stdio.h>

// int main(){
// 	for (int i = 0; i <5; i++){
// 		for (int j = 0; j <i; j++){                 
//                     printf("*");}
// 		printf("\n");
		
// 	}
// 	return 0;
// }


// int main(){
// 	for (int i = 0; i < 5; i++){
// 		for (int k=5; k>i+1; k--){
// 			printf(" ");
// 		}
// 		for (int j = 0; j <i; j++){                 
//                     printf("*");
//                 }
// 		printf("\n");
		
// 	}
// 	return 0;
// }

int main(){
	for (int i = 0; i < 6; i++){
		for (int k=6; k>i+1; k--){
			printf(" ");
		}
		
		for (int j = 0; j <i; j++){                 
                    printf("*");                  
                    printf(" ");
         }
		printf("\n");
		
	}
	return 0;
}