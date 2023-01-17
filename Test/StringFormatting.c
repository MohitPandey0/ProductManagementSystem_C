#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(short x, short y)
{
    COORD pos = {x,y};//sets co-ordinates in(x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
    // printf("|%10s","Aman\n");
    // printf("..........\n");
    // printf("|%10s","Aman Tiw\n");
    // // printf("%#x",15);
    // printf("%05d\n",67);
    // printf("%09s\n","Aman");
    // printf("|%-5d|%-5d|\n",1,2);

    // Note: A screen has 25 lines and 80 columns.

    // gotoxy(26,100);
    // printf("hii");

    char text[4000]="\
         0000   000000  000000  0000  000000  00   00  000000   000000\n\r\
        00  00    00      00     00     00    00   00  00   00  00\n\r\
        000000    00      00     00     00    00   00  00   00  0000\n\r\
        00  00    00      00     00     00    00   00  00   00  00\n\r\
        00  00    00      00    0000    00     00000   000000   000000\n\r\
        \n\r\
         00  00000 00000 00000 0   0 0000  00000 0   0  00000 00000\n\r\
        0  0   0     0   0     00  0 0   0 0     00  0 0      0\n\r\
        0000   0     0   000   0 0 0 0   0 000   0 0 0 0      000\n\r\
        0  0   0     0   0     0  00 0   0 0     0  00 0      0\n\r\
        0  0   0     0   00000 0   0 0000  00000 0   0  00000 00000\n\r\
        \n\r\
        0   0   00   0   0   00    00000  00000  0   0  00000  0   0  00000\n\r\
        00 00  0  0  00  0  0  0  0       0      00 00  0      00  0    0\n\r\
        0 0 0  0000  0 0 0  0000  0  000  000    0 0 0  000    0 0 0    0\n\r\
        0   0  0  0  0  00  0  0  0    0  0      0   0  0      0  00    0\n\r\
        0   0  0  0  0   0  0  0   00000  00000  0   0  00000  0   0    0\n\r\
        \r ";  

        printf("%s",text);
    getch();
    return 0;
}
