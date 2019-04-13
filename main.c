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
const char * grouping(char text[SIZE], int length);
void getAsciiNum(char text[SIZE], int length, int a, int b, int c);
void SetColor(int ForgC);
void encript(int a, int b, int c, int length, char text[SIZE]);
void decrypt(int a, int b, int c, int length, char text[SIZE]);
void hr();
void saveText(char text[SIZE], char encripted[SIZE]);
void appendString(char * str1, char * str2);
int main(){
    int a,b,c;
    char text[SIZE];
    int length,op;
    printf("Porfavor ingrese una opcion: \n1) Encriptar\n2) Desencriptar\nOpcion: ");scanf("%d", &op);
    while(op < 1 || op > 2){
        system("cls");
        printf("Por favor ingrese una opcion valida!\n1) Encriptar\n2) Desencriptar\nOpcion: ");scanf("%d", &op);
    }
    fflush(stdin);
    printf("Ingrese Palabra: ");
    gets(text);
    printf("Ingrese configuracion RT1 (C): ");scanf("%d", &c);
    while(c > 26 || c < 1){
        printf("Ingrese configuracion RT1 (C): ");scanf("%d", &c);
    }
    printf("Ingrese configuracion RT2 (B): ");scanf("%d", &b);
    while(b > 26 || b < 1){
        printf("Ingrese configuracion RT2 (B): ");scanf("%d", &b);
    }
    printf("Ingrese configuracion RT3 (A): ");scanf("%d", &a);
    while(a > 26 || a < 1){
        printf("Ingrese configuracion RT3 (A): ");scanf("%d", &a);
    }
    toUpperCase(text);
    length = strlen(text);
    system("cls");
    printf("%s, String length: %d",text, length);
    fflush(stdin);
    hr();
    printf("CONFIG: %d,%d,%d", a,b,c);
    hr();
    if(op == 1){
        encript(a,b,c,length,text);
    } else {
        if(op == 2){
            printf("Desenctiptrar");
        }
    }
    printf("\nDesea volver a usar el programa?\n1) Si\n2) No\nOpcion: ");scanf("%d", &op);
    while(op < 1 || op > 2){
        system("cls");
        printf("Por favor ingrese una opcion valida\n1) Si\n2) No\nOpcion: ");scanf("%d", &op);
    }
    switch(op){
        case 1:
            system("cls");
            return main();
            break;
        case 2:
            printf("Hasta luego!");
            return 0;
    }
}
hr(){
    printf("\n----------------------------\n");
}
SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
const char * grouping(char text[SIZE], int length){
    char * space = 32;
    char new_str[SIZE];
    int j=0,c=0, a=0;
    for(int i = 0; i < length; i++){
        new_str[c] = text[a];
        if((i+1) % 5 == 0){
            new_str[c] = 32;
            length++;
            j++;
            a--;
            if(j % 4 == 0){
                new_str[c] = 10;
                c++;
            }
        }
        printf("C: %d - %c | I: %d - %c\n", c,new_str[c],a, text[a]);
        a++;
        c++;
    }
    hr();
    printf("%s", new_str);
    hr();
    return new_str;
}
appendString(char * str1, char * str2){
    char new_str;
    while(1){
        new_str = *str1;
        if(new_str==0){
            break;
        }
        str1 += 1;
    }
    while(1){
        *str1=*str2;

        if((*str1) == 0){
            break;
        }
        str1 += 1;
        str2 += 1;
    }
    return;
}
spaceToX(char text[SIZE]){
    for(int i = 0;i <= strlen(text); i++){
        if(text[i] == 32){
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
saveText(char text[SIZE], char encripted[SIZE]){
    char name[SIZE];
    char * new_str;
    int check;
    char* dirName = "files";
    char * uri = "files\\";
    FILE * fPointer;
    fflush(stdin);
    check = mkdir(dirName);

    if (!check){
        printf("Directorio creado\n");
    } else {
        if(check){
            printf("Directorio ya creado!\n");
        } else {
            printf("No se pudo crear el directorio.\n");
        }
    }

    printf("Ingrese un nombre al texto: ");gets(name);
    fflush(stdin);

    if((new_str = malloc(strlen(name)+strlen(".txt")+1)) != NULL){
        new_str[0] = '\0';
        strcat(new_str, name);
        strcat(new_str, ".txt");
        printf("%s", new_str);
    }
    if((uri = malloc(strlen("files\\")+strlen(new_str) + 1)) != NULL){
        uri[0] = '\0';
        strcat(uri, "files\\");
        strcat(uri, new_str);
        printf("%s", uri);
    }

    fPointer = fopen(uri, "w");
    fprintf(fPointer, text);
    fprintf(fPointer, encripted);
    fclose(fPointer);
}
encript(int a, int b, int c, int length, char text[SIZE]){
    char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newstr[SIZE];
    char origin[SIZE];
    char * new_str;
    static char * encripted;
    strcpy(origin, text);
    printf("%s", origin);
    int i = c, j = b, k = a, i2;
    int x = 0, num, abcn, f, op;
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
        i++;
        x++;
    }
    hr();
    printf("Original Text: \n%s\n\n", origin);
    printf("FINAL OUTPUT: \n");
    encripted = grouping(newstr, length);
    printf("FINAL STRING: %s", encripted);
    if((new_str = malloc(strlen(origin)+strlen("\n")+1)) != NULL){
        new_str[0] = '\0';   // ensures the memory is an empty string
        strcat(new_str,origin);
        strcat(new_str,"\n");
    }
    printf("new_str: %s\nnewstr: %s\n", new_str, newstr);
    hr();
    printf("Desea guardar el texto?\n1) Si\n2) No\nOpcion: ");scanf("%d", &op);
    while(op < 1 || op > 2){
        system("cls");
        printf("Por favor ingrese una opcion valida\n1) Si\n2) No\nOpcion: ");scanf("%d", &op);
    }
    switch(op){
        case 1:
            system("cls");
            saveText(new_str, newstr);
            break;
        case 2:
            printf("No Guardar");
            return 0;
    }
}
decrypt(int a, int b, int c, int length, char text[SIZE]){
    char rt1[] = "KFZAMQWCXOESIBTHRJUVNLPGDY";
    char rt2[] = "DXJTPVRGFZAWBISOLUYQCEHKNM";
    char rt3[] = "NYPEUBSAMHXCLWFQVZIGJOKTRD";
    char abc[SIZE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newstr[SIZE];
    int i = c, j = b, k = a, i2;
    int x = 0, num, abcn, f;
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
