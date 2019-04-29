#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *subsitution_cypher_encryption(char str[], char key[]);
char *rotation_cypher_encryption(char str[], int rotation);
char *subsitution_cypher_decryption(char letters[], char key[]);
char *Attack_rotation_encryption(char letters[]);
char *Attack_subsitution_encryption(char letters[]);
double Fitness(char charater_list[], int length);
char letters[100000]; // stores the message from the console
char encrypt[100000]; // encryption is for storing the encoded message befor returning it to letters
char charater_list[100000];
char best_letters[100000];
char Rkey[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabet_refferance[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Skey[30];
char Tkey[30];
char Fkey[30];
char compare[10];
char lookup[100];
char quadgraph[20];
char key[100];

int main(void)
{
    int hat=1, call_function=0, hat_counter=0;
    int rotation;
    printf("give me a message\n");
    scanf("%[^\n]s", letters); // take a user input 
    printf("whitch function would you like to call?\n"); 
    printf("1)Keyed rotation cypher encryption\n");
    printf("2)Keyed rotation cypher decryption\n"); 
    printf("3)Keyed subsitution cypher encryption\n"); 
    printf("4)Keyed subsitution cypher decryption\n");
    printf("5)Attack rotation cypher\n");
    printf("6)Attack subsitution cypher\n");
    /*  - depending on which user input the switch case will direct the program to which function to run
        - hat is set to zero so the program will exit after function is called*/    
    while((hat==1) && (hat_counter < 30)){
        scanf("%d", &call_function);
        switch(call_function){
            case(1):printf("give me a rotation key\n");
                    scanf("%d", &rotation);
                    printf("%s\n", rotation_cypher_encryption(letters, rotation)); // send letters to function and then print return  string
                    hat = 0;
                    break;
            case(2):printf("give me the original rotation key\n");
                    scanf("%d", &rotation);
                    rotation = -rotation;
                    printf("%s\n", rotation_cypher_encryption(letters, rotation)); // send letters to function and then print return  string
                    hat = 0;
                    break;
            case(3):printf("give me a key\n");
                    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
                    scanf("%s", key);
                    printf("%s\n", subsitution_cypher_encryption(letters, key)); // send letters to function and then print return  string
                    hat = 0;
                    break;
            case(4):printf("give me a key\n");
                    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
                    scanf("%s", key);
                    printf("%s\n", subsitution_cypher_decryption(letters, key)); // send letters to function and then print return  string
                    hat = 0;
                    break;
            case(5):printf("%s\n",Attack_rotation_encryption(letters)); // send letters to function and then print return  string           
                    hat = 0;
                    break;
            case(6):printf("This will run until killed by the user.\n");
                    printf("%s\n",Attack_subsitution_encryption(letters)); // send letters to function and then print return  string
                    hat = 0;
                    break;
            default:printf("invalid input please try again entering a vaule between 1-6 thankyou.\n");
                    hat = 1;
                    hat_counter ++;
        }
    }
    if(hat_counter == 30){
        printf("you have broken the code by entering a non digit entry\n");
        printf("this is a knowen bug and we are sorry for any inconvenince\n");
        printf("next time please enter a number between 1-6 thankyou\n");
    }
    // printf("%s\n", letters); // check what scanf stored in letters
    //printf("\n");
    return 0;
}

char *rotation_cypher_encryption(char str[], int rotation){
    int length;
    char uppercase;
    length = strlen(str); // calculates the length of the message given
    for(int i=0 ; i<= length; i++){
        /* converts all lowercase letters to uppercase letters befor encryption*/
        if ((96 < str[i]) && (str[i] < 123)){
            str[i] = str[i] - 32;
        }
        /*Take the uppercase letters and convert them to intergers between 0-25
          the letters then get a rotation applyed.*/
        if ((64 < str[i]) && (str[i] < 91)){
            uppercase = str[i] - 65;
            encrypt[i] = ((uppercase + rotation)%26);
            /* if the remainder from the rotaion is negative. it is convered to loop backaround to the back of the loop again
                eg A - 65 = 0 - 2 = -2 + 26 = 14 + 65 = X */
            if (encrypt[i] < 0)
                encrypt[i] = encrypt[i] + 26;
            // converts interger back to ascii letter vaule
            encrypt[i] = encrypt[i] + 65; 
        }
        // if not a letter do not encrypt
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
    length = strlen(str); // calculates the length of the message
    //printf("%d\n", length);
    int uppercase;
    for(int i=0 ; i < length; i++){
       // converts Uppercase letters to lowwercase
       if ((96 < str[i]) && (str[i] < 123)){
            str[i] = str[i] - 32;
        }
        /*since the key is stored in an array from 0-25, converting the letters to number from 0-25
          and storing it in uppercase. each letter can be converted by looking up its correspongding
          vaule in the key*/
        if ((64 < str[i]) && (str[i] < 91)){
            uppercase = str[i] - 65;
            encrypt[i] = key[uppercase] ;
        }
        // if not a letter do not encrypt
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
    //calculates the length of the message
    length = strlen(letters);
    //printf("%d\n", length);
    /*for each letter of the key 1,2,3,4 ... pass through the entire message and change all 
      occurances of that letter to the corrosponding letter in the alphabet.
      E.g key[1] = P for letters[i] = P letters[i] = ist letter of alphabet A.*/
    for(int j = 0; j< 26; j++){
        for(int i = 0; i<=length; i++ ){ 
            if ((96 < letters[i]) && (letters[i] < 123)){
                letters[i] = letters[i] - 32; // converts lowercase letters to uppercase
            }
            if ((64 < letters[i]) && (letters[i] < 91)){
                if( letters[i] == key[j]){
                    encrypt[i] = alphabet_refferance[j];
                } 
            }
            // if not a letter leave it alone
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
        /* English quadgrams is a file containing a list of the frequency of four letter combinations in english
        and is used to test the fitness of the rotation*/
        FILE *fd = fopen("english_quadgrams.txt","r");
        // longer the message corser the grading
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
                // converts uppercase to lowercase
                if ((96 < letters[i]) && (letters[i] < 123)){
                        letters[i] = letters[i] - 32;
                }
                // applys key to charater_list  
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
            // fgets read information from quadgraph and stores it in lookup
            fgets(lookup, 100, fd);
            //puts(lookup);
            // lookup is broken up into two parts quadgraph and score
            sscanf(lookup, "%s %f", quadgraph, &score);
            for(int i=0; i<length; i++){
                // stores 4 charaters form charater_list[i] into compare
                memcpy( compare, &charater_list[i], 4);
                // see if compare and quadgraph are equal
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
        // if current key is better than last key update the solution key Skey
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
            // applys the Solution key to message
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

char *Attack_subsitution_encryption(char letters[]){
    int length=0;
    int tempstorage;
    double Total=0, PTotal, maxTotal = -99999999999999;
    int k=0, i=0, j=0, m=0, y=1;
    int count = 0;
    length = strlen(letters);
    int good_score = -100;
    int a=0, b=0;
    //printf("%d\n", length);
    for(i=0 ; i<= length; i++){
        if ((96 < letters[i]) && (letters[i] < 123)){
            letters[i] = letters[i] - 32;
        }
    }
    //printf("%s\n", letters);
    //printf("hi\n");
    for(i = 0; i<26 ; i++){
        Skey[i] = Rkey[i];
    }
    while(1){
        //printf("Yoyo\n");
        //printf("%s\n", Skey);
        // scarmbels the alphabet and stores it in Skey
        for(j =0; j<26; j++){
            m = rand()%26;
            //printf("m= %d\n",m);
            tempstorage = Skey[m];
            Skey[m] = Skey[j];
            Skey[j] = tempstorage;
            //printf("%s\n", Skey);
        }
        printf("%s\n", Skey);
        // printf("G'day\n");
        count = 0;
        k = 0;
        // takes all the letters in the array letters [] and move them into charater_list with the scrammbeled key 
        for( i=0 ; i < length; i++){ 
            if ((64 < letters[i]) && (letters[i] < 91)){
                tempstorage = letters[i] - 65;
                charater_list[i+k] = Skey[tempstorage];
            }
            else {
                k--;
            }
        } 
        //printf("%s\n", charater_list);
        // //printf("hello\n");
        //calculates how good the Skey is based on the fitness test
        PTotal = Fitness(charater_list, strlen(charater_list));
        //printf("%d\n", PTotal);
        //printf("hey\n");
        //printf("wazzaup\n");
        while(count<=80){
            //printf("Skey = %s\n", Skey);
            for( i=0; i<26; i++){
                Tkey[i] = Skey[i];
            }  
            //printf("Tkey = %s\n", Tkey);
            Total = 1;
            // takes two random letters in Tkey and swap them
            a = rand()%26;
            b = rand()%26;
            tempstorage = Tkey[a];
            Tkey[a] = Tkey[b];
            Tkey[b] = tempstorage;
            //printf("Tkey = %s\n\n", Tkey);
            k = 0;
            // apply Tkey to letters and store in charater_list
            for( i=0 ; i < length; i++){
                if ((64 < letters[i]) && (letters[i] < 91)){
                    tempstorage = letters[i] - 65;
                    charater_list[i+k] = Tkey[tempstorage];
                }

                else {
                    k--;
                }
            } 
            //printf("%s\n", charater_list);
            // calculate the fitness of the Tkey to see if it made it better
            Total = Fitness(charater_list, strlen(charater_list));
            //printf("%s\n\n", charater_list);
            //printf("%s a%d b%d\t %d\n", Tkey, a, b, Total);
            //printf("%d\n", count);
            //printf("total = %f\t ptotal = %f\n", Total, PTotal);
            // if Tkey was better than Skey
            if ( (Total > PTotal) && (Total!=1) ){
                PTotal = Total;
                printf("new best %f\n\n", PTotal);
                // Skey = Tkey = new best
                for( i=0; i<26; i++){
                    Skey[i] = Tkey[i];
                } 
                count=0;
            }
            //printf("%d\n", count);
            count++;
            // if no improvement in last 80 switches kill this and restaert with new random parent seed
        }
        // stroes the absolute best key for refferance
        if( PTotal > maxTotal){
            // calculate the new best message
            maxTotal = PTotal;
            for( i=0; i<26; i++){
                Fkey[i] = Skey[i];
            }  
            for(i=0 ; i < length; i++){
                if ((64 < letters[i]) && (letters[i] < 91)){
                    tempstorage = letters[i] - 65;
                    best_letters[i] = Fkey[tempstorage] ;
                }
                else{
                    best_letters[i] = letters[i];
                }
                //printf("\t%d\t%c\t%d\t%c\t%d\n",letters[i], letters[i], best_letters[i], best_letters[i], i);
            } 
            count = 0;
            printf("Fkey = %s\n", Fkey);
            printf("best = %s\n", best_letters);
            //printf("%d\n%s\n%f\n\n",y,best_letters, PTotal);
            // figger out what good score is :}
        }
        else{
            printf("%f is not better than %f\n", PTotal, maxTotal);
            printf("%s is not better than %s\n", Skey, Fkey);
            for(i=0; i<26; i++){
                Skey[i] = Fkey[i];
            }  
        }
        y++;
        printf("y = %d\n", y);
    }
    letters = best_letters;
    return letters;
}

double Fitness( char charater_list[], int length){
    //printf("%d\n", length);
    // scroe toatl  =  to the total amount of quadgram occourances
    int accuracy;
    if(length <= 100){
        accuracy = 1000;
        if(length <= 10){
        accuracy = 10000;
        }
    }
    else{
        accuracy = 800;
    }
    double scoretotal = /*254121853;*/4190947328.000000;
    double Total=1, Cscore, otherscore=1;
    int score=0, flag, loop, i;
    FILE *fe;
    for(i=0; i<(length-4); i++){
        flag = 0;
        // reads 4 charaters and stores them in compare
        memcpy(compare, &charater_list[i], 4);
        fe = fopen("english_quadgrams.txt","r");
        for(loop = 0; loop<accuracy/*389373*/; loop++){ 
            // fgets read information from quadgraph and stores it in lookup   
            fgets(lookup, 100, fe);
            //printf("%s\n", lookup);
            // lookup is broken up into two parts quadgraph and score
            sscanf(lookup, "%s %d", quadgraph, &score);
            //printf("quadgraph = %s  score = %d\n", quadgraph, score);
            // see if compare and quadgraph are equal
            if(strncmp(compare, quadgraph, 4)==0){
                //printf("match\n");
                Total += log10(score/scoretotal);
                flag = 1;
                // breaks out of the loop
                loop = 800;
            }
        }
        fclose(fe);
        // penalty for not matching any of the quadgraphs 
        if(flag == 0){
            Total += log10(0.01/scoretotal);
        }
    }
    //otherscore = logf(otherscore);
    //printf("Total = %f ", Total);
    //printf("otherscore = %f\n",otherscore);
    return Total;
}
//kill me now !!!