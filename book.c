//library management system

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fram.c"
#include"conio.h"
#include"pas.c"
struct book
{
	char name[50];
	char auther[50];
	int no,count,stock;
}*bk;
struct issu
{
	int st,bkc;
	char bknam[50];	
}*is;
FaILE *p,*n;

int main()
{
	
	system("clear");
        frame();
        gotoxy(60,18);
        printf("LIBRARY MANAGEMENT SYSTEM");
        gotoxy(90,25);
        printf("SADARUL ANAM");
        sleep(1);
        passwrd();
        printf("\n");
	bk=(struct book *)malloc(sizeof(struct book));
	is=(struct issu *)malloc(sizeof(struct issu));
	int ch,k=60;
	while(1)
	{
		fflush(stdout);
		sleep(1);
		frame();
		gotoxy(k,10);
		printf("1.Add");
		gotoxy(k,12);
		printf("2.Return");
		gotoxy(k,14);
		printf("3.Issue");
		gotoxy(k,16);
		printf("4.Search");
		gotoxy(k,18);
		printf("5.Display");
		gotoxy(k,20);
		printf("6.Issue List");
		gotoxy(k,22);
		printf("7.Exit");
		gotoxy(k,24);
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add();
			break;
			case 2:
				retrn();
			break;
			case 3:
				issue();
			break;
			case 4:
				search();
			break;
			case 5:
				display();
			break;
			case 6:
				isslst();
			break;
			case 7:
				exit(0);
			break;
			default:
				printf("Wrong choice!!");
				printf("Enter your choice:");
		}
	}
	return 0;
}


add()
{
	FILE *q;
	int i,j=0;
	p=fopen("org","a+");
	q=fopen("temp","w");
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(60,18);
	printf("Enter the book number:");
	scanf("%d",&i);
	while(1)
	{
		fread(bk,sizeof(struct book),1,p);
		if(feof(p))
		break;
		if(i==bk->no)
		{
			bk->stock=bk->stock+1;
			bk->count=bk->stock;
			fwrite(bk,sizeof(struct book),1,q);
			j=1;
		}
		else
		{
			fwrite(bk,sizeof(struct book),1,q);
		
		}

	}

	if(j==0)
	{
			bk->no=i;
			gotoxy(60,20);
			printf("Enter the book name:");
		        scanf("%s",bk->name);
			gotoxy(60,22);
     		   	printf("Enter the auther name:");
        		scanf("%s",bk->auther);
			gotoxy(60,24);
        		printf("Enter the count:");
        		scanf("%d",&bk->stock);
			bk->count=bk->stock;
			fwrite(bk,sizeof(struct book),1,q);
	}			
	rename("temp","org");
	fclose(q);
	fclose(p);
}

search()
{
	int j=0;
        char new[50];
        p=fopen("org","a+");
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(60,18);
	
        printf("Enter the book name to search:");
        scanf("%s",new);
        while(1)
        {
                fread(bk,sizeof(struct book),1,p);
                if(feof(p))
                break;
                if(!strcmp(new,bk->name))
                {
			j=1;
                	break; 
                }
	}

	if(j==0)
	{
		fflush(stdout);
        	sleep(1);
        	frame();
		gotoxy(60,18);
		printf("Search Not Found!!!!!!");
		getch();
	}
	else
	{

		fflush(stdout);
     		sleep(1);
        	frame();
		gotoxy(40,9);
		printf("Search Found.......");
		getch();
		fflush(stdout);
     		sleep(1);
        	frame();
		gotoxy(30,18);	
		printf("BookId");
		printf("BookName");
		printf("Auther");
		printf("Stock");
		printf("Curent");
		gotoxy(30,20);
		printf("%d",bk->no);
		printf("\t%s",bk->name);
		printf("\t%s",bk->auther);
                printf("\t%d",bk->stock);
		printf("\t%d",bk->count);
		getch();
	
	}
	getch();
	fclose(p);

}
retrn()
{
	FILE *s,*c;
	int ids,f=0;
	char ne[50];
	p=fopen("org","a+");
	c=fopen("tem","w");
	s=fopen("newd","w");
	n=fopen("iss","a+");
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(60,18);
	printf("Enter the student id:");
	scanf("%d",&ids);
	while(1)
	{
		fread(is,sizeof(struct issu),1,n);
		if(feof(n))
		break;
		if(ids==is->st)
		{
			f=1;
			gotoxy(60,20);
			printf("Enter the book name:");
			scanf("%s",ne);
			if(!(strcmp(ne,is->bknam)))
			{
				while(1)
				{
					fread(bk,sizeof(struct book),1,p);
					if(feof(p))
					break;
					if(!(strcmp(ne,bk->name)))
					{
						(bk->count)=(bk->count)+1;
						fwrite(bk,sizeof(struct book),1,c);
						
						fflush(stdout);
        					sleep(1);
        					frame();
						gotoxy(60,18);
						printf("Returned!");
					}
					else
						fwrite(bk,sizeof(struct book),1,c);
				}
			}
			else
			
				fwrite(is,sizeof(struct issu),1,s);
			
		}
		else
			
			fwrite(is,sizeof(struct issu),1,s);
	}
	if(f==0)
	{
		fflush(stdout);
        	sleep(1);
        	frame();
		gotoxy(60,18);
		printf("Id not match!!");
	}
	rename("newd","iss");
	rename("tem","org");
	fclose(s);
	fclose(n);
	fclose(p);
	fclose(c);
}
isslst()
{
	n=fopen("iss","a+");
	int i,j,y=15;
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(40,10);
	printf("Student");
	printf("\tBook");
	printf("\tBooksTaken");
	while(1)
	{
		y=y+1;
		gotoxy(40,y);
			fread(is, sizeof(struct issu), 1, n);
			if(feof(n))
			break;
			
				printf("%d",is->st);
				printf("\t%s",is->bknam);
				printf("\t%d",is->bkc);
				fflush(stdin);
				getch();
			
	}
	fclose(n);
}

display()
{
	p = fopen("org", "a+");
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(40,18);
	printf("BookId");
	printf("\tBookName");
	printf("\tAuther");
	printf("\tStock");
	printf("\tAvailable");
	int y=19;
        while (1)
        {
        	fread(bk, sizeof(struct book), 1, p);
		if(feof(p))
		{
			break;
		}
		y=y+1;
		gotoxy(40,y);
         	printf("%d", bk->no);
           	printf("\t%s", bk->name);
	  	printf("\t%s",bk->auther);
		printf("\t%d",bk->stock);
		printf("\t%d",bk->count);
		fflush(stdin);
		getch();
            
        }
	getch();
    	fclose(p);
}

issue()
{
	FILE *s;
	char nw[50];
	int stid,fl=0,m=0,c=0;
	p=fopen("org","a+");
	s=fopen("newd","w");
	n=fopen("iss","a+");
	fflush(stdout);
        sleep(1);
        frame();
	gotoxy(60,18);
	printf("Enter the student id:");
	scanf("%d",&stid);
	while(1)
	{
       		fread(is,sizeof(struct issu),1,n);
		if(feof(n))
		break;
		if(is->st==stid)
			c++;
	}
	if(c>2)
	{
		fflush(stdout);
		sleep(1);
		frame();
		gotoxy(60,18);
		printf("No cards left!!");
		getch();
	}
	else
	{
		fflush(stdout);
        	sleep(1);
        	frame();
		gotoxy(60,18);
		printf("Enter the book name to issue:");
		scanf("%s",nw);
		while(1)
		{
			fread(bk,sizeof(struct book),1,p);
			if(feof(p))
			break;
			if(!strcmp(nw,bk->name))
			{
				fl=1;
			 	if((bk->count)>0)
                		{
                        		(bk->count)=(bk->count)-1;
                        		fwrite(bk,sizeof(struct book),1,s);
					gotoxy(60,20);
					strcpy(is->bknam,nw);
					is->st=stid;
					(is->bkc)=(is->bkc)+1;
                                	fwrite(is,sizeof(struct issu),1,n);
					fflush(stdout);
        				sleep(1);
        				frame();
					gotoxy(60,18);
                                	printf("Book is issued.........");
					
				}
				else
				{
                        		fwrite(bk,sizeof(struct book),1,s);
					fflush(stdout);
        				sleep(1);
        				frame();
					gotoxy(60,18);
					printf("All books are issued!!!!!!!1");
					
				}
			}
			else
			fwrite(bk,sizeof(struct book),1,s);
			getch();
		}
	}
	if(c<=2)
	{
		if(fl==0)
		{
		
			fflush(stdout);
     		   	sleep(1);
        		frame();
			gotoxy(60,18);
			printf("Cannot find book name!!!!!!!");
			getch();
		}
	}
	rename("newd","org");

	fclose(s);
	fclose(p);
	fclose(n);
}
