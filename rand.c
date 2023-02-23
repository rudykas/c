#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main () {
    char i;
    srand(time(NULL));
 
    for (i = 1; i <= 50; i++) {
        printf("%15d", rand());
        if (i % 5 == 0) printf("\n");
    }        
}
