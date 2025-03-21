#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    
   
    while (start < end) {
        
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    char str[100];
   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    reverseString(str);
    
    printf("Reversed string: %s\n", str);

    return 0;
}

