#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct record
{
    char phonenumber[20];
    char name[30];
    float amount;
}s;

void addrecords();
void listrecords();
void payment();
void searchrecords();
void deleterecords();

int main()
{
    system("color F1");
    int choice;
    printf("\n\n\n\n\n\t\t*****************************************************");
    printf("\n\t\t* :: :: Welcome to our telecom billing system :: :: *");
    printf("\n\t\t*****************************************************");
    getch();
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\t\t*****************************************************");
        printf("\n\t\t*       > > > > > >     Menu     < < < < < <        *\n");
        printf("\t\t*****************************************************");
        printf("\n\t\t*  1. Adding new records.                           *\n");
        printf("\t\t*  2. List of records.                              *\n");
        printf("\t\t*  3. Payment.                                      *\n");
        printf("\t\t*  4. Searching records.                            *\n");
        printf("\t\t*  5. Deleting records.                             *\n");
        printf("\t\t*  6. Exit.                                         *\n");
        printf("\t\t*****************************************************");

        printf("\n\n\t\tEnter your choice: ");
        scanf("%d",&choice);
        system("cls");

        switch(choice)
        {
            case 1:addrecords();break;
            case 2:listrecords();break;
            case 3:
                        char username[100];
                        char password[100];
                        startpoint:
                            system("cls");
                            printf("\n\n\n\t\t::: Welcome to our Payment service:::\n\n");
                            printf("\n\n\n\t\t username:");
                            scanf("%s",&username);
                            printf("\n\n\t\t password:");
                            scanf("%s",&password);

                            if(strcmp(username,"admin")==0)
                            {
                                if(strcmp(password,"12345")==0)
                                {
                                    printf("\n\n\t\t Logged In Successfully.........\n\n");
                                    getch();
                                    payment();break;
                                }
                                else
                                {
                                    printf("\n\n\n\t\t Wrong Password!!!\n\n");
                                    getch();
                                    goto startpoint;
                                }
                            }
                            else
                            {
                                printf("\n\n\t\t username is wrong!!!\n");
                                getch();
                                goto startpoint;
                            }

            case 4:searchrecords();break;
            case 5:deleterecords();break;
            case 6:
                printf("Thanks You....\n\nFor using our telecom billing system....\n\n");
                exit(0);
            default:
                system("cls");
                printf("You are wrong..... Please try again....");
                getch();
        }
    }
}


void addrecords()
{
	FILE *f;
	char test;
	f=fopen("i_love_you","ab");

	while(1)
	{
		system("cls");
        printf("\n\n\n\n\n\t\t*****************************************************");
        printf("\n\t\t* Enter phone number:");
        fflush(stdin);
		gets(s.phonenumber);
		printf("\n\t\t* Enter name:");
		fflush(stdin);
		gets(s.name);
		printf("\n\t\t* Enter amount:");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
        printf("\n\t\t*****************************************************");

		printf("\n\n\t\t 1 record successfully added");
		printf("\n\t\t   .....Press any key to main menu ::");
        break;
	}
	fclose(f);
	getch();
}

void listrecords()
{
	FILE *f;

	f=fopen("i_love_you","rb");

	system("cls");
	printf("Phone Number\t\tUser Name\t\t\tAmount\n");

    printf("-------------------------------------------------------------------------------");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%s\t\t%s\t\tTK. %.2f /-",s.phonenumber,s.name,s.amount);
	}
	printf("\n");

    printf("-------------------------------------------------------------------------------");

    fclose(f);
    getch();
}


void payment()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	float amt;

	f=fopen("i_love_you","rb");

	system("cls");
    printf("\n\n\n\n\n\t\t*****************************************************");
	printf("\n\t\t* Enter phone number of the subscriber for payment:");
	fflush(stdin);
	scanf("%s",&phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{

			printf("\n\t\t*****************************************************");
			printf("\n\t\t* Phone No.: %s",s.phonenumber);
			printf("\n\t\t* Name: %s",s.name);
			printf("\n\t\t* Current amount: %.2f",s.amount);
			printf("\n\t\t*****************************************************");
			printf("\n\n\t\tEnter amount of payment :");
			fflush(stdin);
			scanf("%f",&amt);
			s.amount=s.amount-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
    printf("\n\n\n\n\n\t\t*****************************************************");
    printf("\n\t\t*    THANK YOU %s FOR YOUR TIMELY PAYMENTS      *",s.name);
    printf("\n\t\t*****************************************************");
	getch();
	fclose(f);
}

void searchrecords()
{
	FILE *f;
	char phonenumber[20];

	f=fopen("i_love_you","rb");

	fflush(stdin);
	system("cls");
    printf("\n\n\n\n\n\t\t*****************************************************");
	printf("\n\t\t* Enter Phone Number to search in our database: ");
	scanf("%s",&phonenumber);
    printf("\n\t\t*****************************************************");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			printf("\n\t\t*     > > > > >     Record Found     < < < < <      *");
            printf("\n\t\t*****************************************************");
			printf("\n\t\t* Phonenumber: %s\n\t\t* Name: %s\n\t\t* Amount: TK.%0.2f",s.phonenumber,s.name,s.amount);

			break;
		}

	}
    printf("\n\t\t*****************************************************");
	getch();
	fclose(f);
}

void deleterecords()
{
	FILE *f,*t;
	char phonenumber[20];
	system("cls");
	f=fopen("i_love_you","rb");
	t=fopen("shahadatt.marjuk","wb");
	do{
	rewind(f);
	printf("Enter the phone number to be deleted from the Database");
	scanf("%s",phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)!=0)
		{
		    fwrite(&s,sizeof(s),1,t);
		}
		else
		printf("Record deleted successfully.");
	}

        fclose(f);
        fclose(t);
        remove("i_love_you");
        rename("i_miss_you","i_love_you");

        f=fopen("i_love_you","rb");
        t=fopen("i_miss_you","wb");
        printf("\nDo you want to delete another record (y/n):");
        fflush(stdin);
	  }
    	while(getche()=='y'||getche()=='Y');
		fclose(f);
	getch();
}
