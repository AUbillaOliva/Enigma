#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
typedef bool;
#define true 1
#define false 0
#define SIZE 1000

void toUpperCase(char text[SIZE]);
void spaceToX(char text[SIZE]);
void grouping(char text[SIZE], int length);
void getAsciiNum(char text[SIZE], int length, int a, int b, int c);
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
    printf("CONFIG: %d,%d,%d\n\n", 1,21,19);
    grouping(text, length);
    hr();
    getAsciiNum(text,length, 1,21,19);
    loop(1,21,19,length);
    return 0;
}
void hr(){
    printf("\n----------------------------\n");
}

getAsciiNum(char text[SIZE], int length, int a, int b, int c){
    char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, num, j=1, sum, rest, c2;
    for(i = 0; i < length; i++){
        num = text[i] - 64;
        /*8 = 72 - 64 */
        SetColor(10);
        printf("TEXT: %c\nTEXT NUM: %d\n", text[i], text[i]);
        SetColor(15);
        sum = c-2+num;
        SetColor(14);
        printf("SUM: %d\n", sum);
        if(sum > 26){
            sum = sum - 26;
            //c = 1;
            printf("SUM > 26\nREST = %d\n", sum );
            //sum = rest;
        }
        SetColor(12);
        printf("NUM: %d\n", num);
        SetColor(15);
        printf("RT1 IN ASCII: %d\nRT1 ASCII LETTER: %c\n\n", rt1[sum], rt1[sum]);
        sum = 0;
        /*if(rt1[c + i] == num){
            printf("THE VAL OF NUM VAR: %d \n", num);
            printf("THE WORD IS: %s\n", rt1[c + i]);
        } else {
            printf("NO MATCH!\n");
        }*/
    }
}

void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

grouping(char text[SIZE], int length){
    char * space = 32;
    int j=0;
    for(int i = 0; i <= length; i++){
        printf("%c", text[i]);
        if((i+1) % 4 == 0){
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


// TODO: establecer config.

int loop(int a, int b, int c, int length){
    /* I */ char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    /* II */ char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    /* III */ char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    int i = c, j = b, k = a, x = 0;
    while(x <= length){
        if(i > 25){
            j++;
            i=0;
        }
        if(j > 26){
            k++;
            j=1;
        }
        if(k > 26){
            i=0;
            k=1;
        }
        printf("RT1: %c\n", rt1[i-1]);
        printf("RT2: %c\n", rt2[j-1]);
        printf("RT3: %c\n", rt3[k-1]);
        i++;
        printf("i:%d, j:%d, k:%d\n", i,j,k);
        x++;
    }
}

/*
 3 * 2 * 1 = 6
 26 * 26 * 26 = 17.576
 6 * 17.576 = 105.456
 ' ' = X

*/
