#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void admin_display();
struct product
{
	char type[100];
	char name[100];
	char brand[100];
	char code[100];
	char price[100];
	char n[100];
	char id[100];
}o;

struct admin_login
{
	char username[100];
	char password[100];
}a;

FILE *fp= NULL;
void admin_insert()
{
	char ch;
	system("cls");
	printf("\n************************* INSERT ITEMS *************************");
	printf("\n\n\n");
	
	printf("-------------------------------------------------------------------------------\n");
	printf("|  PODUCT ID  |  TYPE  |  NAME  |  BRAND  |  CODE  |  PRICE  |  NO. OF ITEMS  |\n");
	printf("-------------------------------------------------------------------------------\n\n\n");
	do
	{
		
		scanf("%s %s %s %s %s %s %s",&o.id,&o.type,&o.name,&o.brand,&o.code,&o.price,&o.n);
		fflush(stdin); 
		char val;
			if(fp==NULL)
			{
				fp=fopen("product.txt","w");
				fprintf(fp,"-----------------------------------------------------------------\n");
				fprintf(fp,"| PODUCT ID | TYPE | NAME | BRAND | CODE | PRICE | NO. OF ITEMS |\n");
				fprintf(fp,"-----------------------------------------------------------------\n");
			//	printf("\nPOSITION = %d",ftell(fp));
				fprintf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\n",o.id,o.type,o.name,o.brand,o.code,o.price,o.n);
				fclose(fp);
			}
			else
			{
				fp=fopen("product.txt","a");
			//	printf("\nPOSITION = %d",ftell(fp));
				fprintf(fp,"\n\n%s\t%s\t%s\t%s\t%s\t%s\t%s\n",o.id,o.type,o.name,o.brand,o.code,o.price,o.n);
				fclose(fp);
			}
		
		//printf("\n\n\n\n*******************ITEMS INSERTED SUCCESSFULLY*******************");
		
		printf("\n\n\tDO YOU WANT TO INSERT MORE ITEMS TO THE DATABSE Y/N ");
		fflush(stdin); 
		scanf("%c",&ch);
		fflush(stdin); 
		}while(ch!='N');
	
}
void admin_delete()
{
	char val[100];
	admin_display();
	printf("\n\nENTER THE PRODUCT ID TO BE DELETED\t");
	scanf("%s",&o.id);
	int i=0;
	fp=fopen("product.txt","r+");
	while(fp!=NULL)
	{
		fscanf(fp,"%s",val);
		printf("\nvalue = %s  position = %d",val,ftell(fp));
		if(!strcmp(val,o.id))
		{
			int pos=ftell(fp);
			pos=pos-1;
			printf("\n\n\nposition = %d\n",pos);		
			printf("\nRECORD FOUND");
			//printf("\nENTER PRODUCT DETAILS\t");
			//scanf("%s %s %s %s %s %s %s",&o.id,&o.type,&o.name,&o.brand,&o.code,&o.price,&o.n);
			fseek(fp,pos,SEEK_SET);	
			//int pos=ftell(fp);
			char ch1;
			int count =0;
			//ch1= fgetc(fp);
			while(ch1!='\n')
			{
				count=count+1;	
				ch1=fgetc(fp);			
			}
		//	pos=pos-count+1;
			fseek(fp,pos,SEEK_SET);
			//ch1 = fgetc(fp);
			printf("\n\n\n\ncharacter = %c",ch1);
			int i=0;
			while(i<count)
			{
				fprintf(fp,"\r ");
				i++;
			}
			printf("\n\ncount = %d",count);
			//fprintf(fp,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			//fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",o.id,o.type,o.name,o.brand,o.code,o.price,o.n);
			fflush(stdin); 
			fclose(fp);
			
			return;
		}
		
		fflush(stdin);
	
}
}

void admin_update()
{
	char val[100];
	admin_display();
	printf("\n\nENTER THE PRODUCT ID TO BE DELETED\t");
	scanf("%s",&o.id);
	int i=0;
	fp=fopen("product.txt","r+");
	while(fp!=NULL)
	{
		
		fscanf(fp,"%s",val);
		printf("\nvalue = %s  position = %d",val,ftell(fp));
		if(!strcmp(val,o.id))
		{
			
			int pos=ftell(fp);
			pos=pos-1;
			printf("\n\n\nposition = %d\n",pos);
			
			printf("\nRECORD FOUND");
			printf("\nENTER PRODUCT DETAILS\t");
			scanf("%s %s %s %s %s %s %s",&o.id,&o.type,&o.name,&o.brand,&o.code,&o.price,&o.n);
			fseek(fp,pos,SEEK_SET);	
			//int pos=ftell(fp);
			
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",o.id,o.type,o.name,o.brand,o.code,o.price,o.n);
			fflush(stdin); 
			fclose(fp);
			
			return;
		}
		
		fflush(stdin);
		//i++;
	}
	printf("\nRECORD NOT FOUND");
}

void admin_display()
{
	system("cls");
	fp=fopen("product.txt","r");
	if(fp==NULL)
	{
		printf("\n\n\nNO SUCH FILE IN THE DIRECTORY\n\n\n");
		return ;
	}
	else
	{
		char buf[100];
		while (fgets(buf, sizeof buf, fp) != NULL)
		{
			//fgets(buf, MAX, stdin); 
    		printf("%s\n", buf);		
		}
	}
}
void admin()
{
	system("cls");
	printf("\n\t\t**********ADMINISTRATION LOGIN**********\n\n\n");
	printf("\n\n\t\tENTER USERNAME ");
	scanf("%s",a.username);
	printf("\n\n\n\t\tENTER PASSWORD ");
	scanf("%s",a.password);
	fflush(stdin); 
	if(!strcmp(a.username,"admin") && !strcmp(a.password,"admin"))
	{
		system("cls");
		int ch;
		do
		{
		printf("\n\t\t*****************WELCOME*****************");
		
		printf("\n\n\n");
		printf("\t\t\tPRESS <1> INSERT");
		printf("\n\n\t\t\tPRESS <2> DELETE");
		printf("\n\n\t\t\tPRESS <3> UPDATE");
		printf("\n\n\t\t\tPRESS <4> DISPLAY");
		int choice;
		printf("\n\n\t\tEnter Your Choice ");
		scanf("%d",&choice);
		fflush(stdin); 
		switch(choice)
		{
			case 1:admin_insert();break;
			case 2:admin_delete();break;
			case 4:admin_display();break;
			case 3:admin_update();break;
			default :printf("\n\n\t\t\tINVALID CHOICE");
		}
		
		printf("\n\n\n\t\tPRESS <1> FOR MAIN MENU\n\n\n\t\tPRESS <2> TO EXIT\n\n\n\t\tPRESS <3> TO CONTINUE\n");
		printf("\n\n\t\tEnter Your Choice ");

		scanf("%d",&ch);
		system("cls");
		if(ch==1)
		{
			return ;
		}
		else if(ch == 2)
		{
			exit(1);
		}
		else
		{
			continue;
		}
		fflush(stdin); 
	}while(1);
	system("cls");
}
}

void user()
{
	fp=fopen("product.txt","r");
	while(fp!=NULL)
	{
		fscanf(fp,"%s",&o.id);
		if(!strcmp(o.id,"1"))
		{
			fscanf(fp,"%s %s %s %s %s %s",&o.type,&o.name,&o.brand,&o.code,&o.price,&o.n);
			printf("%s %s %s %s %s %s %s",o.id,o.type,o.name,o.brand,o.code,o.price,o.n);		
			int total = 2*atoi(o.price);
			printf("\n\nTOTAL COST = %d",total);
			break;
		}
	}
}

void signup()
{
	
}
int main()
{
	char ch;
	printf("\n\t*************** WELCOME TO ONLINE SHOPPING ***************");
	printf("\n\n\n");
	int i=0;
	

	do
	{
	
	
	printf("\n\t\t\t\tSELECT\n\n\t\t\t\t1.ADMIN LOGIN\n\n\t\t\t\t2.USER LOGIN\n\n\t\t\t\t3.NEW USER\n\n\t\t\t\t4.TO EXIT");
	printf("\n\n\n\t\tENTER YOUR CHOICE ");
	int choice;
	scanf("%d",&choice);
	switch(choice)	
	{
		case 1: admin();break;
		case 2: user();break;
		case 3: signup();break;
		case 4:exit(1);
		default : printf("\n\n\n\t\tIVALID CHOICE\n\n\n");
	}
	//printf("\nBACK TO THE MAIN MEMU\n\n");
	}while(1);
		return 0;
}
