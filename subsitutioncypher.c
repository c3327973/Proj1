#include <stdio.h>
#include <string.h>

char *encryption(char str[], char key[]);

int main(void)
{
    char letters[1000]; // stores the message from the console
    char key[100];
    printf("give me a message\n");
    scanf("%[^\n]s", letters); // take a user input 
    printf("%s\n", letters); // check what scanf stored in letters
    printf("give me a key\n");
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    scanf("%s", key);
    printf("%s\n", encryption(letters, key)); // compair the code to the original input
    printf("\n");
    return 0;
}

char *encryption(char str[], char key[]){
    int length;
    length = strlen(str);
    int uppercase;
    int lowercase;
    char encrypt[1000];
    for(int i=0 ; i < length; i++){
       if ( str[i] != 32 ){     
            if ( str[i] < 91 ){
                uppercase = str[i] - 65;
                encrypt[i] = key[uppercase] ;
            }
            else if ( 96 < str[i] ){
                lowercase = str[i] - 97;
                encrypt[i] = key[lowercase];
            }
          printf("\t%d\t%d\t%c\n",str[i], encrypt[i], encrypt[i]);
        }

        else {
            encrypt[i] = str[i];
        }
    }  
    str = encrypt;
    return str;
}
