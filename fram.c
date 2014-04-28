#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void gotoxy(int x,int y)
{
        printf("%c[%d;%df",0x1B,y,x);
}

void frame()
{
        system("clear");
        int i,j;
        gotoxy(30,5);
        for(i=0;i<90;i++)
        {
                printf("*");
        }
        for(j=0;j<25;j++)  
        {
                gotoxy(30,j+5);
                printf("*");
                gotoxy(120,j+5);
                printf("*"); 
        }
        gotoxy(30,j+5); 
        for(i=0;i<=90;i++)
        {
                printf("*");
        }
    
}
