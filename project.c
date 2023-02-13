#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void password();
void hedding();
void MainMenu();
void addMember();
void viewMember();
void search();
void editMember();
void  successfully ();
void delete1();

int d=1;

struct add_member {
    int U_ID;
    char name[15];
    int RN;
    char DS[30];
    char PS[100];
    char pr[40];

};
struct add_member s1;
   FILE *file;

void delete1()
{
    system("cls");
    printf("\n\n\t\t\t ------------------------Delete Member information------------------\n");
    printf("\n\n\t\t\t press any go to the mainMenu...");
    fflush(stdin);
    getchar();
    MainMenu();

}

void  successfully (){
    system("cls");
 printf(" \n\n\t\t\t successfully ! ");
 printf("\n\n\t\t\t press any key go to the mainMenu...");
 fflush(stdin);
 getchar();
 MainMenu();
}

void editMember()
{
    system("cls");
    int n,count=0;
    printf("\n\t\t\t-----------------Edit Member information--------------------\n");
    printf("\n\t\t\t Enter ID: ");
    scanf("%d",&n);
    file = fopen("information.dat","rb+");
    while(fread(&s1,sizeof(s1),1,file)==1){
        if(n == s1.U_ID){
            printf(" \n\t\t\tEdit your correct information: \n");
            printf("\n\t\t\t Enter name name: ");
            scanf("%s",s1.name);
            printf("\n\t\t\t Enter new room number: ");
            scanf("%d",&s1.RN);
            printf("\n\t\t\t Enter Profession: ");
            scanf("%s",s1.pr);
            printf("\n\t\t\t Enter district: ");
            scanf("%s",s1.DS);
            fseek(file,ftell(file)-sizeof(s1),0);

            fwrite(&s1,sizeof(s1),1,file);
            fclose(file);
            count=1;
            successfully ();
        }
    }
    if(count == 0){
            system("cls");
        printf("\n\n\t\t\t Member not found: ");
        printf("\n\t\t\t Press any key go to the mainMenu....");
    fflush(stdin);
    getchar();
      MainMenu();
    }

}

void  search()
{

    system ("cls");
    int n,count=0;
    printf("\n\t\t\t ---------------------search member information--------------------\n");
    file=fopen("information.dat","rb");
    printf("\n \t\t\t Enter ID: ");
    scanf("%d",&n);
    while(fread(&s1,sizeof(s1),1,file)==1){

    if(n==s1.U_ID)
    {
        printf("\n\t\t Successfully !");
        printf("\n\n\t\t ID= %d",s1.U_ID);
        printf("\n\t\t Name= %s",s1.name);
        printf("\n\t\t Room Number= %d",s1.RN);
        printf("\n\t\t profession = %s",s1.pr);
        printf("\n\t\t District = %s",s1.DS);
         printf("\n\n\t\t press nay key go to the mainMenu...");
       fflush(stdin);
        getchar();
       MainMenu();


    }
    else
    {
        system("cls");
        printf("\t\t\tYour chose is Wring!");
        printf("\n\n\t\t\t press any key go to the mainMemu.... ");
        fflush(stdin);
        getchar();
         MainMenu();

    }
}
}

void  addMember()
{

    system("cls");
     int n,count =0;
    printf("\n\t\t\t--------------------------Add Member------------------------\n");
   file = fopen("information.dat","a+");
   printf("\n\t\t\t Enter Unique ID: ");
   scanf("%d",&n);
   rewind(file);
   while (fread(&s1,sizeof(s1),1,file)==1)
   {
        if (n== s1.U_ID){
        printf("\n\t\t\tThis member is already in our mess! \n");
        printf("\nt\t\t place enter new id. press any key.....");

        fflush(stdin);
       getchar();
       addMember();
       }
   }
  s1.U_ID=n;
    printf("\n\t\t\t Enter Name: ");
    scanf("%s",s1.name);
    printf("\n\t\t\t Enter Room number: ");
     scanf("%d",&s1.RN);
    printf("\n\t\t\t Enter Profession ");
    scanf("%s",s1.pr);
    printf("\n\t\t\t Enter district: ");
    scanf("%s",s1.DS);
    fseek(file,0,SEEK_END);
    fwrite(&s1,sizeof(s1),1,file);
    fclose(file);
    printf("\n\t\t\t add member successfully! ");
    printf("press any key go to the mainMenu..");
    fflush(stdin);
    getchar();
    MainMenu();
}

void viewMember()
{
    system("cls");
    printf("\n\t\t View Member list\n");
    printf("\n\n\t\t Unique ID \t Name \t Room number \t profession \t District \n");

    file = fopen("information.dat", "rb+");
    while(fread(&s1,sizeof(s1),1,file)==1);
    {
        printf("\t\t%2d",s1.U_ID);
        printf("\t %12s",s1.name);
        printf("\t%8d",s1.RN);
        printf("\t%10s",s1.pr);
        printf("\t %10s",s1.DS);


    }
    fclose(file);
     printf("\n\n\t  #press any key go to the mainMenu....");

    fflush(stdin);
    getchar();

    MainMenu();

}

void MainMenu()
{
       int n;
       system("cls");
       printf("\n\t\t\t---------------------Main Menu-------------------------\n");
       printf("\n\t\t\t 1. add member");
       printf("\n\t\t\t 2. view member list");
       printf("\n\t\t\t 3. search member information");
       printf("\n\t\t\t 4. edit member information");
       printf("\n\t\t\t 5. delete member informaton");
       printf("\n\n\t\t\t---------------------------------------------------------\n");
       printf("\n\t\t\t Enter your choice: ");
       scanf("%d",&n);
       if(n==1)
       {
           addMember();
       }
       else if (n==2)
       {
           viewMember();
       }
        else if (n==3)
       {
           search();
       }
        else if (n==4)
       {
           editMember();
       }
        else if (n==5)
       {
           delete1();
       }
       else {
            system("cls");
        printf("\n\t\t\t Your chose is wrong! \n");
        printf("\t\t\t press any key go to the MainMenu....");
       fflush(stdin);
       getchar();
        MainMenu();
       }

}

void hedding()
{
    printf("\n\t\t\t------------------- Bachelor Family-------------------------\n");

}
void password()
{
    system("cls");
  hedding();


    char pass[30]="golam";
    char pass1[30];
    printf("\n\t\t\tEnter password: ");
    scanf("%s",pass1);
    if(strcmp (pass,pass1) == 0)
    {
        char s[2]="y";
        char s1[2];
         system("cls");
        printf("\n\t\t\t * Match Password...\n");
        printf("\n\t\t\t *If you want to skip press y: ");
        scanf("%s",s1);

        if(strcmp (s,s1) == 0 )
        {
           MainMenu();
          //totalmembur();
        }
        else
        {
            system("cls");
            printf("\n\n\n\t\t\t             opps ");
             printf("\n\n\t\t\t # Press any key go to the BachelorFamily.....");
             fflush(stdin);
             getchar();
             password();
        }
    }
    else
    {

        if(d == 3)
        {
            exit(0);
        }

        printf("\n\t\t\t # please enter correct password %d to 3 times \n",d);
         printf("\t\t\t # press any key to continue...");
        d++;
         fflush(stdin);
         getchar();
        password();


    }
    fflush(stdin);
    getchar();

}

int main()
{

    password();
    return 0;
}
