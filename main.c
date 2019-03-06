#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
typedef bool;
#define true 1
#define false 0
#define SIZE 100

void toUpperCase(char text[SIZE]);
void spaceToX(char text[SIZE]);
void grouping(char text[SIZE], int length);
void hr();
int main(){
    char text[SIZE], newc[SIZE];
    int length, ascii;
    printf("Ingrese Palabra: ");
    gets(text);
    toUpperCase(text);
    length = strlen(text);
    ascii = toascii(text);
    printf("%s, String length: %d\n\n",text, length);
    fflush(stdin);
    spaceToX(text);
    hr();
    grouping(text, length);
    hr();
    //loop(12,23,1,length);
    return 0;
}
void hr(){
    printf("\n----------------------------\n");
}

grouping(char text[SIZE], int length){
    char * space = 32;
    int j=0;
    for(int i = 0; i <= length; i++){
        printf("%c", text[i]);
        if((i+1) % 6 == 0){
            printf(" ");
            j++;
            if(j % 4 == 0){
                printf("\n");
            }
        }
    }
}

spaceToX(char text[SIZE]){
    _Bool space = 0;
    for(int i = 0;i <= strlen(text); i++){
        if(text[i] == 32){
            space = 1;
            text[i] = 88;
        }
    }
}

toUpperCase(char text[SIZE]){
    for(int i=0;i<=strlen(text);i++){
	    if(text[i]>=97 && text[i]<=122){
            text[i]=text[i]-32;
	    }
    }
    return text;
}

int loop(int a, int b, int c, int length){
    int count = 0, x, y, z;
    for(x = a; x < 27; x++){
        for(y = b; y < 27; y++){
            for(z = c; y < 27; z++){
                if(z <= 26){
                    z = 0;
                }
                printf("%d:%d:%d\n",x,y,z);
            }
            if(y <= 26){
                y = 0;
            }
        }
        if(x <= 26){
            x = 0;
        }
    }
}

/*
 3 * 2 * 1 = 6
 26 * 26 * 26 = 17.576
 6 * 17.576 = 105.456
 ' ' = X

*/
