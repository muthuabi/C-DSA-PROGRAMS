#include <stdio.h>

int main() {
    int n,i,evencount=0, oddcount=0;
    printf("Enter the number: ");
    scanf("%d", &n);
    for ( i = 1; i <= n; i++) {
    	if(i%2==0){
            evencount++; 
        } else {
            oddcount++;  
        }
    }
    printf("\n Evencount: %d\n", evencount);
    printf(" Oddcount: %d\n", oddcount);

    return 0;
}
 
