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
    int a,b,c;
    char text[SIZE], newc[SIZE];
    int length, ascii;
    printf("Ingrese Palabra: ");
    gets(text);
    system("cls");
    printf("Ingrese configuracion RT1 (C): ");scanf("%d", &c);
    printf("Ingrese configuracion RT2 (B): ");scanf("%d", &b);
    printf("Ingrese configuracion RT3 (A): ");scanf("%d", &a);
    toUpperCase(text);
    length = strlen(text);
    printf("%s, String length: %d\n\n",text, length);
    fflush(stdin);
    hr();
    printf("CONFIG: %d,%d,%d\n", a,b,c);
    hr();
    loop(a,b,c,length,text);
    return main();
}
void hr(){
    printf("\n----------------------------\n");
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

int loop(int a, int b, int c, int length, char text[SIZE]){
    char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newstr[SIZE];
    int i = c, j = b, k = a, i2,j2, k2;
    int x = 0, num, sum, abcn, z, y, f;
    while(x < length){
        num = text[x] - 64;
        printf("LETRA: %c\n", text[x]);

        // RT1
        printf("NUM: %d\n", num);
        abcn = num + i - 1;
        if(abcn > 26){
            abcn -= 26;
        }
        SetColor(14);
        printf("RT1: %c\nRT1 NUM: %d\n", rt1[abcn - 1], rt1[abcn-1] -64);

        // RT2
        for(i2 = 0; i2 < 26; i2++){
            if(abc[i2] == rt1[abcn - 1]){
                num = abc[i2] - 64;
            }
        }
        abcn = num + j - i;
        if(abcn > 26){
            abcn -= 26;
        } else {
            if(abcn < 1){
                abcn += 26;
            }
        }
        SetColor(4);
        printf("RT2: %c\nRT2 NUM: %d\n", rt2[abcn - 1], rt2[abcn - 1] - 64);
        //SEGUNDA PARTE:
        abcn = rt2[abcn-1] - 64;
        abcn = abcn + k - j;
        if(abcn < 1){
            abcn += 26;
        } else {
            if(abcn > 26){
                abcn -= 26;
            }
        }
        SetColor(11);
        printf("RT3: %c\nRT3 NUM: %d\n",rt3[abcn-1], rt3[abcn-1]-64);
        SetColor(15);
        f = rt3[abcn - 1] - 64;
        f -= k;
        if(f<0){
            f += 26;
        } else {
            if(f>26){
                f -= 26;
            }
        }
        printf("FINAL: %c\n",abc[f]);

        //SPACE TO X
        if(text[x] == 32){
            text[x] = 88;
            printf("%c\n\n",text[x]);
            newstr[x] = text[x];
            x++;
            hr();
            continue;
        }

        //CREATE NEW STRING WITH CODIFIED MESSAGE
        newstr[x] = abc[f];

        SetColor(2);
        printf("RT1: %c\n", rt1[i-1]);
        printf("RT2: %c\n", rt2[j-1]);
        printf("RT3: %c\n", rt3[k-1]);

        SetColor(4);
        printf("RT1:%d\nRT2:%d\nRT3:%d\n", i,j,k);
        SetColor(3);
        printf("CODEX: %c\n", newstr[x]);
        printf("\nI: %d\nX: %d", i,x);
        hr();

        SetColor(15);
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
        abcn = 0;
        sum = 0;
        i++;
        x++;
    }
    hr();
    printf("FINAL OUTPUT: \n");
    grouping(newstr, length);
    hr();
}

/* COLOR TABLE:
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
