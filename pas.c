#include<stdio.h>
#include<stdlib.h>
//#include"conio.h"
#include<string.h>
//#include"fram.c"
void passwrd() 
{   
        char c;
        char orp[20]="pass",pas[20];
        int n=0,i=0,m;
        fflush(stdout);
        sleep(1);
        system("clear");
        frame();
        gotoxy(60,18);
        printf("Enter Password");
        gotoxy(65,19);
        while((pas[i++]=getch())!=EOF)
        {
                if(pas[i-1]=='\n')
                {
                        pas[--i]='\0';
                        break;
                }
                printf("*");
        }
        while(n<2)
        {
                if(strcmp(pas,orp)!=0)
                {
                        i=0;
                        n=n+1;
                        fflush(stdout);
                        sleep(1);
                        system("clear");
                        frame();
                        gotoxy(60,18);
                        printf("Invalid Password");
                        gotoxy(60,20);
                        printf("Re-enter Password");
                        while((pas[i++]=getch())!=EOF)
                        {
                                if(pas[i-1]=='\n')
                                {
                                        pas[--i]='\0';
                                       break;
                                }
                                printf("*");
                        }

                }
                else
                {
                        break;
                }
        }
        if(n>=2)
        {

                fflush(stdout);
                sleep(1);
                system("clear");
                frame();
                gotoxy(60,18);
                printf("No more chances");
                fflush(stdout);
                while(1);

        }
}



