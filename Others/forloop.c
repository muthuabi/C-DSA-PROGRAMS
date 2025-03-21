#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void oddeven(int a)
{
    if(a%2==0)
        printf("even\n");
    else 
        printf("odd\n");
}
int main() 
{
    int a,b;
    char words[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    //printf("%s",words[0]);
    // if(a>9)
    //     oddeven(a);
    // else
    if(a<=9)
    printf("%s\n",words[a]);
    if(b<=9)
    printf("%s\n",words[b]);
    else
    printf("%s\n",words[9]);
    oddeven(a);
    oddeven(b);
    
    return 0;
}

