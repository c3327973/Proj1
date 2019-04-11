#include <stdio.h>
#include <string.h>

char *encryption(char str[], int key);

int main(void)
{
    char letters[1000]; // stores the message from the console 
    char encrypted_message[1000]; // this does nothing but changes things
    int key;
    printf("give me a message\n");
    scanf("%[^\n]s", letters); // take a user input 
    printf("%s\n", letters); // check what scanf stored in letters
    printf("give me a key\n");
    scanf("%d", &key);
    printf("%s\n", encryption(letters, key)); // compair the code to the original input
    return 0;
}

char *encryption(char str[], int key){
    int length;
    char lowercase; // storage of letters
    char uppercase;
    char encrypt[1000];               // will store the vaules of each letter of the array to get changed
    length = strlen(str);
    for(int i=0 ; i< length; i++){
        if ( str[i] != 32 ){

            if ( str[i] < 91 ){
                uppercase = str[i] - 65;
                encrypt[i] = ((uppercase + key)%26);
                if (encrypt[i] < 0)
                    encrypt[i] = encrypt[i] + 26;
                encrypt[i] = encrypt[i] + 65; 
            }
            else if ( 96 < str[i] ){
                lowercase = str[i] - 97;
                encrypt[i] = ((lowercase + key)%26);
                if (encrypt[i] < 0)
                    encrypt[i] = encrypt[i]+26;
                encrypt[i] = encrypt[i] + 97;
            }
           // printf("\t%d\t%d\t%c\n",str[i], encrypt[i], encrypt[i]);
        }

        else {
            encrypt[i] = str[i];
        }
    }
    str = encrypt;
    return str;
}
