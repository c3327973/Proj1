#include <stdio.h>
#include <string.h>

int encryption(char str);

int main(void)
{
    char letters[1000];
    char e; // temp storage
    char c;                 // will store the vaules of each letter of the array to get changed
    scanf("%[^\n]s\n", letters); // take a user input 
    printf("%s\n", letters); // check what scanf stored in letters
    int length;
    length = strlen(letters);
    for(int i=0 ; i< length; i++){
        if ( letters[i] != 32 ){
            e = letters[i] - 97;
            c = ((e + 25)%26);
            c = c + 97;
    }
        else {
            c = letters[i];
        }
        printf("%c", c);
    }
    printf("\n");
    printf("%s\n", letters); // compart the code to the original input
    return 0;
}

int encryption(char str){
    
}
