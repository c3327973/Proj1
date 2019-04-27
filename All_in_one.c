#include <stdio.h>
#include <string.h>
#include <math.h>

char *subsitution_cypher_encryption(char str[], char key[]);
char *rotation_cypher_encryption(char str[], int rotation);
char *subsitution_cypher_decryption(char letters[], char key[]);
char *Attack_rotation_encryption(char letters[]);
char letters[100000]; // stores the message from the console
char encrypt[100000]; // encryption is for storing the encoded message befor returning it to letters
char charater_list[100000];
char alphabet_refferance[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char compare[10];
char lookup[100];
char quadgraph[20];
char key[100];

int main(void)
{
    int hat=1, call_function=0;
    int rotation;
    printf("give me a message\n");
    scanf("%[^\n]s", letters); // take a user input 
    printf("whitch function would you like to call?\n"); 
    printf("1)keyed rotation cypher encryption\n");
    printf("2)keyed rotation cypher decryption\n"); 
    printf("3)keyed subsitution cypher encryption\n"); 
    printf("4)keyed subsitution cypher decryption\n");
    printf("5)Attack rotation cypher\n");
    printf("6)attack subsitution cypher\n");
    while(hat==1){
        scanf("%d", &call_function);
        switch(call_function){
            case(1):printf("give me a rotation key\n");
                    scanf("%d", &rotation);
                    printf("%s\n", rotation_cypher_encryption(letters, rotation)); // compair the code to the original input
                    hat = 0;
                    break;
            case(2):printf("give me the original rotation key\n");
                    scanf("%d", &rotation);
                    rotation = -rotation;
                    printf("%s\n", rotation_cypher_encryption(letters, rotation)); // compair the code to the original input
                    hat = 0;
                    break;
            case(3):printf("give me a key\n");
                    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
                    scanf("%s", key);
                    printf("%s", subsitution_cypher_encryption(letters, key)); // compair the code to the original input
                    hat = 0;
                    break;
            case(4):printf("give me a key\n");
                    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
                    scanf("%s", key);
                    printf("%s", subsitution_cypher_decryption(letters, key)); // compair the code to the original input
                    hat = 0;
                    break;
            case(5):printf("%s",Attack_rotation_encryption(letters)); // compair the code to the original input
                    hat = 0;
                    break;
            case(6):
            default: printf("invalid input please try again entering a vaule between 1-6 thankyou.\n");
        }
    }
    // printf("%s\n", letters); // check what scanf stored in letters
    //printf("\n");
    return 0;
}

char *rotation_cypher_encryption(char str[], int rotation){
    int length;
    char lowercase; // storage of letters
    char uppercase;
    length = strlen(str);
    for(int i=0 ; i<= length; i++){
        if ((96 < str[i]) && (str[i] < 123)){
                    str[i] = str[i] - 32;
        }
        if ((64 < str[i]) && (str[i] < 91)){
            uppercase = str[i] - 65;
            encrypt[i] = ((uppercase + rotation)%26);
            if (encrypt[i] < 0)
                encrypt[i] = encrypt[i] + 26;
            encrypt[i] = encrypt[i] + 65; 
        }
        else {
            encrypt[i] = str[i];
        }
        // printf("\t%d\t%d\t%c\n",str[i], encrypt[i], encrypt[i]);
        
    }
    str = encrypt;
    return str;
}

char *subsitution_cypher_encryption(char str[], char key[]){
    int length;
    length = strlen(str);
    //printf("%d\n", length);
    int uppercase;
    int lowercase;

    for(int i=0 ; i < length; i++){
       
       if ((96 < str[i]) && (str[i] < 123)){
            str[i] = str[i] - 32;
        }
        if ((64 < str[i]) && (str[i] < 91)){
            uppercase = str[i] - 65;
            encrypt[i] = key[uppercase] ;
        }
        else {
            encrypt[i] = str[i];
        }
        //printf("\t%d\t%c\t%d\t%c\t%d\n",str[i], str[i], encrypt[i], encrypt[i], i);
    }  
    str = encrypt;
    return str;
}

char *subsitution_cypher_decryption(char letters[], char key[]){
    int length;
    length = strlen(letters);
    //printf("%d\n", length);
    int uppercase;
    int lowercase;
    for(int j = 0; j< 26; j++){
        for(int i = 0; i<=length; i++ ){ 
            if ((96 < letters[i]) && (letters[i] < 123)){
                letters[i] = letters[i] - 32;
            }
            if ((64 < letters[i]) && (letters[i] < 91)){
                if( letters[i] == key[j]){
                    encrypt[i] = alphabet_refferance[j];
                } 
            }
            else {
                encrypt[i] = letters[i];
            }
               
        } 
    }
    letters = encrypt;
    return letters;
}

char *Attack_rotation_encryption(char letters[]){
    int FTotal = 0, Skey=0;
    int uppercase=0;
    int length=0;
    length = strlen(letters);
    for( int key =0; key<26; key++){
    float score = 0;
    double Pscore = 0;
    double Total = 1;
    int counter=0;
    int accuracy = 10000;
    FILE *fd = fopen("english_quadgrams.txt","r");
    if(length <= 100){
        accuracy = 600;
        if(length <= 10){
        accuracy = 10000;
        }
    }
    else{
        accuracy = 50;
    }
    if (fd == NULL){
        printf("failed to open file\n");
        return -1;
    }
    for(int loop = 0; loop< accuracy; loop++){     
        int j=0;
        for(int i=0 ; i<= length; i++){
            if ((96 < letters[i]) && (letters[i] < 123)){
                    letters[i] = letters[i] - 32;
            }
            if ((64 < letters[i]) && (letters[i] < 91)){
                uppercase = letters[i] - 65;
                charater_list[i+j]=(uppercase - key)%26;
                if (charater_list[i+j] < 0){
                    charater_list[i+j] =charater_list[i+j] + 26;
                }
                charater_list[i+j] += 65;
                //charater_list[i+j] = letters[i];
            }
            else {
                j--;
            }
        }
        //printf("charater_list = %s\n", charater_list);
        fgets(lookup, 100, fd);
        //puts(lookup);
        sscanf(lookup, "%s %f", quadgraph, &score);
        for(int i=0; i<length; i++){
        memcpy( compare, &charater_list[i], 4);
            if(strncmp(compare, quadgraph, 4)==0){
                //printf("match %s\n", compare);
                //printf("score = %f\n", score);
                Pscore = score/4190947328.000000;
                //printf("Pscore = %f\n", Pscore);
                Total = Total + logf(Pscore); 
                //printf("Total = %f\n", Total);
            }
        }
    }
    if(Total<FTotal){
        FTotal = Total;
        Skey = key;
        //printf("we have a new leader,%d\n", Skey);
    }
    // printf("charater_list = %s\n", charater_list);
    // printf("Total = %f\n", Total);
    // printf("key = %d\n", key);
    }
    printf("\n\n THE KEY = %d GIVING A TOTAL SCORE OF %d\n", Skey, FTotal);
    if(FTotal == 0){
        printf(" NOT ENOUGH INFORMATION PLEASE TRY AGAIN :)");
    }
    if(FTotal!=0){
        for(int i=0 ; i<= length; i++){
            if ((96 < letters[i]) && (letters[i] < 123)){
                        letters[i] = letters[i] - 32;
            }
            if ((64 < letters[i]) && (letters[i] < 91)){
                uppercase = letters[i] - 65;
                charater_list[i] = ((uppercase - Skey)%26);
                if (charater_list[i] < 0)
                    charater_list[i] = charater_list[i] + 26;
                charater_list[i] = charater_list[i] + 65; 
            }
            else {
                charater_list[i] = letters[i];
            }
            // printf("\t%d\t%d\t%c\n",letters[i], charater_list[i], charater_list[i]);
            
        }
    }
    letters = charater_list;
    return letters;
}