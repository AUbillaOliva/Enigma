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
void print(char text[SIZE], int length);
void hr();
int main(){
    int a,b,c;
    char text[SIZE], newc[SIZE];
    int length, ascii;
    printf("Ingrese Palabra: ");
    gets(text);
    printf("Ingrese configuracion RT1 (C): ");scanf("%d", &c);
    printf("Ingrese configuracion RT2 (B): ");scanf("%d", &b);
    printf("Ingrese configuracion RT3 (A): ");scanf("%d", &a);
    toUpperCase(text);
    length = strlen(text);
    //ascii = toascii(text);
    printf("%s, String length: %d\n\n",text, length);
    fflush(stdin);
    //spaceToX(text);
    hr();
    printf("CONFIG: %d,%d,%d\n", a,b,c);
    //grouping(text, length);
    hr();
    //getAsciiNum(text,length, a,b,c);
    loop(a,b,c,length,text);
    return 0;
}
void hr(){
    printf("\n----------------------------\n");
}

/*getAsciiNum(char text[SIZE], int length, int a, int b, int c){
    char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char newstr[SIZE];
    int i, num, j=1, sum, rest, c2, w1;

    for(i = 0; i < length; i++){
        if(c > 26){
            b++;
            c = 1;
        }
        if(b > 26){
            b = 1;
            a++;
        }
        if(a > 26){
            a = 1;
            c = 1;
        }
        printf("%d\n", i);
        SetColor(3);
        //w1 = c + text[i] - 1;
        //printf("WIRE 1: %d\n", w1);
        SetColor(15);
        if(text[i] == 32){
            text[i] = 88;
            printf("%c\n\n",text[i]);
            newstr[i] = text[i];
            i++;
        }
        num = text[i] - 64;
        SetColor(10);
        printf("TEXT: %c\nTEXT NUM: %d\n", text[i], text[i]);
        SetColor(15);
        sum = c-2+num;
        SetColor(14);
        printf("SUM: %d\n", sum);
        if(sum > 26){
            sum = sum - 26;
            printf("SUM > 26\nREST = %d\n", sum );
        }
        SetColor(12);
        printf("NUM: %d\n", num);
        SetColor(15);
        printf("RT1 IN ASCII: %d\nRT1 ASCII LETTER: %c\n\n", rt1[sum], rt1[sum]);
        newstr[i] = rt1[sum];
        sum = 0;
        c++;
    }
    hr();
    grouping(newstr, length);
    //printf("\nCODEX: %s", newstr);
    hr();
}*/

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
    for(int i = 0; i < length; i++){
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

/*print(char text[SIZE], int length){
    hr();
    grouping(text, length);
    printf("CODEX: %s", text);
    hr();
}*/
// TODO: establecer config.

int loop(int a, int b, int c, int length, char text[SIZE]){
    /* I */ char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    /* II */ char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    /* III */ char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newstr[SIZE];
    int i = c, j = b, k = a, x = 0, num, sum, abcn, i2;
    while(x < length){
        num = text[x] - 64;
        sum = i - 1 + num;
        SetColor(14);printf("SUM: %d\n", sum);
        if(sum > 26){
            sum = sum - 26;
            printf("SUM > 26\nREST = %d\n", sum);
        }
        printf("RT1 IN ASCII: %d\nRT1 ASCII LETTER: %c\n", rt1[sum-1], rt1[sum-1]);
        SetColor(15);
        printf("TEXT[%d]: %c\n", x, text[x]);
        for(i2=0;i2<26;i2++){
            if(abc[i2]== rt1[sum-1]){abcn = abc[i2] - 64;}
        }
        if(text[x] == 32){
            text[x] = 88;
            printf("%c\n\n",text[x]);
            newstr[x] = text[x];
            x++;
            hr();
            continue;
        }
        newstr[x] = rt1[sum-1];
        sum = 0;
        SetColor(2);printf("RT1: %c\n", rt1[i-1]);printf("RT2: %c\n", rt2[j-1]);printf("RT3: %c\n", rt3[k-1]);SetColor(4);
        printf("RT1:%d\nRT2:%d\nRT3:%d\n", i,j,k);SetColor(15);
        printf("\n%d - %c\n", abcn, abcn + 64);
        printf("WORD: %c\n", text[x]);printf("NUM - WORD: %d\n", num);
        SetColor(3);
        printf("CODEX: %c\n", newstr[x]);
        printf("\nI: %d\nX: %d", i,x);
        hr();
        SetColor(15);

        if(i > 25){
            j++;
            i=1;
        }
        if(j > 26){
            k++;
            j=1;
        }
        if(k > 26){
            i=0;
            k=1;
        }
        i++;
        x++;

    }
    hr();
    printf("FINAL OUTPUT: ");
    grouping(newstr, length);
    //printf("\nCODEX: %s", newstr);
    hr();
}

/*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/

/*
 3 * 2 * 1 = 6
 26 * 26 * 26 = 17.576
 6 * 17.576 = 105.456
 ' ' = X

*/
