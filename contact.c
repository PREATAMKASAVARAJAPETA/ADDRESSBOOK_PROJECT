/*
|---------------------------------------------------------------------------------------------------------------|
|                                           ADDRESSBOOK PROJECT                                                 |
|---------------------------------------------------------------------------------------------------------------|   
|   NAME:KASAVARAJAPETA PREATAM                                                                                 |
|   DATE:25/01/2026                                                                                             |
|   DESCRIPTION:This entire project is about to collect the information like name,mobile_number and mail_ID     |
|   about the persons digitally using c programming language                                                    |
|   Tools and concepts used:Visual Studio Code(Tool for c programming),                                         |
|                   CONCEPTS:                                                                                   |
|                               1.--->Datatypes(printf,scanf.....)                                              |
|                               2.--->if condtitions(if,else if,else),break and continue                        |
|                               3.--->Loops(for,while,do while)                                                 |
|                               4.--->switch case statements                                                    |
|                               5.--->1D arrays                                                                 |
|                               6.--->Functions                                                                 |
|                               7.--->Pointers                                                                  |
|                               8.--->stdio                                                                     |
|                               9.--->Structures                                                                |
|                              10.--->File I/O                                                                  |
|                   these are the 10 concepts included in this project                                          |
|---------------------------------------------------------------------------------------------------------------|
*/
#include <stdio.h>
#include<string.h>
#include"contact.h"
#include<ctype.h>
#include <unistd.h>

// Function Definitions
/*This function is used to create new contact it will work for collecting info like name,mobile,mailid about persons*/
int create_contact(AddressBook *addressbook)
{
    if(addressbook->contact_count>=100)//pointing from addressbook to contact_count checking either existing contact is 100
    {
        printf("\033[32mcontactbook is full\033[0m\n");
        return 0;
    }
    Contacts *c1=&addressbook->contact_details[addressbook->contact_count];//creating temporary variable to avoid the errors happens
    do{
        
        printf("Enter the person name: ");
        scanf(" %[^,\n]",c1->Name);//temporary variable is adding to the name of cotact_details structure 
    }while(!isname(c1->Name));// Loop repeats until a valid name is entered 
    
    do{
        printf("Enter the mobile number: ");
        scanf("%s",c1->Mobile_number);//temporary variable is adding to the mobile no of cotact_details structure 
    }while(!ismobile(c1->Mobile_number,addressbook,1));// Loop repeats until a valid mobile no is entered
    do
    {
        printf("Enter the emai id: ");
        scanf("%s",c1->Mail_ID);//temporary variable is adding to the mailid of cotact_details structure 
    } while (!mailid(c1->Mail_ID,addressbook,1));// Loop repeats until a valid mailid is entered

    addressbook->contact_count++;//after adding the contact the contact count will increase
    printf("\033[32mContact created successfully\033[0m\n");//and display this message
    
}
/*This Function is used for listing the entire contacts which are saved and 
existing one in file it will display the contacts when we give the option*/
void list_contacts(AddressBook *addressbook)
{
    int count=addressbook->contact_count;//this count will check the contact count and it will used to display the entire contact list
    if(count==0)
    {
        printf("\033[31mContact book is empty!\033[0m\n");
        return;
    }
    // printf("\033[32mContact details are\033[0m\n");
    //this entire printf displays for users to choose choice and info what are included in this function
    printf("\n|-------------------------------------------------------------------------|\n");
    printf("|                           \033[34mCONTACT DETAILS\033[0m                               |\n");
    printf("|-------------------------------------------------------------------------|\n");
    for(int i=0;i<count;i++)
    {
        printf("|  \033[33m%d\033[0m  |     \033[36m%s\033[0m        \033[32m%s\033[0m          \033[35m%s\033[0m           \n",i+1,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
        printf("|-------------------------------------------------------------------------|\n");
    }
}
/*This Function is used to search the persons name or mobile number or mailid
this is the main root for this project because all edit contacts,delete contacts
will be diverting to this function only it will display the name or mobile or mailid
of the persons list when we search for the person info*/
int search_contacts(AddressBook *addressbook)
{
    
    int option,index;//this option used to enter the switch case
    while(1)
    {
        //this entire printf displays for users to choose choice and info what are included in this function
        printf("\n\033[35mchoose your contact menu\033[0m\n");
        printf("\033[33m1.Search by name\033[0m\n");
        printf("\033[33m2.Search by mobile number\033[0m\n");
        printf("\033[33m3.Search by mail_id\033[0m\n");
        printf("\033[31m4.Exit\033[0m\n");
        printf("\033[33mEnter your option: \033[0m");
        scanf("%d",&option);
        switch(option)
        {
            case 1:index=searchbyname(addressbook);//redirecting to search by name function which is in search.c file
                    break;
            case 2:index=searchbymobile_number(addressbook);//redirecting to search by mobile function which is in search.c file
                    break;
            case 3:index=searchbymail_id(addressbook);//redirecting to search by mailid function which is in search.c file
                    break;
            case 4:return 0;
        
            default: printf("\033[31mInvalid option\033[0m\n");//else if we choose neither of this option this message will get printed
                    continue;
        }
        if(index==-1)
            printf("\n\033[31mContact not found!\033[0m\n");//if our searching condtion fails this message gets printed
    }
}
/*This Function is used to editing the info of the person as we choose
it can be used either we can edit name or mobile or mailid or we can 
edit all three at a time when we choose either any one option it will
redirected to search by name and again it will ask user to edit name
or mobile or mail id after completion it displays the updated message*/
int edit_contact(AddressBook *addressbook)
{
    while(1)
    {
        int index=-1,option,edit_option;
        //this entire printf displays for users to choose choice and info what are included in this function
        printf("\n\033[35mchoose your option to edit contact\033[0m\n");
        printf("\033[33m1.Search by name\033[0m\n");
        printf("\033[33m2.Search by mobile number\033[0m\n");
        printf("\033[33m3.Search by mail_id\033[0m\n");
        printf("\033[31m4.Exit\033[0m\n");
        printf("\033[32mEnter your option:\033[0m ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:index=searchbyname(addressbook);//redirecting to search by name function which is in search.c file
                    break;
            case 2:index=searchbymobile_number(addressbook);//redirecting to search by mobile function which is in search.c file
                    break;
            case 3:index=searchbymail_id(addressbook);//redirecting to search by mailid function which is in search.c file
                    break;
            case 4:return 0;
        
            default: printf("Invalid option\n");//else if we choose neither of this option this message will get printed
                        return 0;
        }
        if(index==-1)
        {
            printf("\n\033[31mContact not found!\033[0m\n");//if our searching condtion fails this message gets printed
            return 0;
        }
        //this entire printf displays for users to choose choice and info what are included in this function
        printf("\n\033[35mchoose your option to edit\033[0m\n");
        printf("\033[33m1.Edit by name\033[0m\n");
        printf("\033[33m2.Edit by mobile number\033[0m\n");
        printf("\033[33m3.Edit by mail_id\033[0m\n");
        printf("\033[32m4.Edit all\033[0m\n");
        printf("\033[31m5.Exit\033[0m\n");
        printf("\033[32mEnter your option:\033[0m ");
        scanf("%d",&edit_option);
        getchar();
        switch(edit_option)
        {
            case 1:do{
                printf("Enter the name: ");
                scanf(" %[^\n]",addressbook->contact_details[index].Name);//name variable included to update the name of cotact_details structure 
                }while(!isname(addressbook->contact_details[index].Name));// Loop repeats until a valid name is entered
                break;
            case 2:do{
                printf("Enter the mobile number: ");
                scanf("%s",addressbook->contact_details[index].Mobile_number);//mobile_no variable included to update the name of cotact_details structure 
                }while(!ismobile(addressbook->contact_details[index].Mobile_number,addressbook,0));// Loop repeats until a valid mobile no is entered
                break;
            case 3:do{
                printf("Enter the mail id: ");
                scanf("%s",addressbook->contact_details[index].Mail_ID);//mailid variable included to update the name of cotact_details structure 
                }while(!mailid(addressbook->contact_details[index].Mail_ID,addressbook,0));// Loop repeats until a valid mailid is entered
                break;
            case 4:do{
                printf("Enter the name: ");
                scanf(" %[^\n]",addressbook->contact_details[index].Name);//name variable included to update the name of cotact_details structure 
                }while(!isname(addressbook->contact_details[index].Name));// Loop repeats until a valid name is entered
                do{
                printf("Enter the mobile no: ");
                scanf("%s",addressbook->contact_details[index].Mobile_number);//mobile_no variable included to update the name of cotact_details structure 
                }while(!ismobile(addressbook->contact_details[index].Mobile_number,addressbook,0));// Loop repeats until a valid mobile no is entered
                do{
                printf("Enter the mail id: ");
                scanf("%s",addressbook->contact_details[index].Mail_ID);//mailid variable included to update the name of cotact_details structure 
                }while(!mailid(addressbook->contact_details[index].Mail_ID,addressbook,0));// Loop repeats until a valid mailid is entered
                break;
            case 5:return 0;
            default: printf("Invalid option\n");//else if we choose neither of this option this message will get printed
                        return 0;
        }
        printf("Updated contact successfully!\n");//after updating contact successfully this message gets printed
        return 1;
    }
}
/*This Function is used to delete the contact of the user choice
it means user can delete using name or mobile or mailid before deleting
it ask user to delete using which option if the multiple contacts there 
with same name it will ask using si_no we have to delete the contact
after we choose it asks us second opinion is really you want to delete
if yes press'y' else 'n' for cancelling delete operation*/
int delete_contact(AddressBook *addressbook)
{
    int index = -1, option;
    char confirm;
    //this entire printf displays for users to choose choice and info what are included in this function
    printf("\n\033[35mchoose your option to delete\033[0m\n");
    printf("\033[33m1.Search by name\033[0m\n");
    printf("\033[33m2.Search by mobile number\033[0m\n");
    printf("\033[33m3.Search by mail_id\033[0m\n");
    printf("\033[31m4.Exit\033[0m\n");
    printf("\033[32mEnter your option:\033[0m ");
    scanf("%d", &option);

    switch(option)
    {
        case 1: index = searchbyname(addressbook);//redirecting to search by name function which is in search.c file 
                break;
        case 2: index = searchbymobile_number(addressbook); //redirecting to search by mobile function which is in search.c file
                break;
        case 3: index = searchbymail_id(addressbook); //redirecting to search by mailid function which is in search.c file
                break;
        case 4: return 0;
        default:
            printf("\033[31mInvalid option\033[0m\n");//else if we choose neither of this option this message will get printed
            return 0;
    }

    if(index == -1)
    {
        printf("\033[31mContact not found!\033[0m\n");//if our searching condtion fails this message gets printed
        return 0;
    }
    printf("\033[31mConfirmation message....!\033[0m");//confirm message display
    printf("\n\033[33mAre you sure you want to delete this contact? (y/n): \033[0m");//it asks user that if yes press y else n
    scanf(" %c", &confirm);//either two characters only asked for cofirmation 
    switch(confirm)
    {
        case 'Y':
        case 'y'://if we really want to delete this operation will held
            for(int j = index; j < addressbook->contact_count - 1; j++)//
            {
                addressbook->contact_details[j] = addressbook->contact_details[j + 1];
                addressbook->contact_count--;//after deleting the contact the contact count should decrease
            }
            printf("\033[32mContact deleted successfully!\033[0m\n");//this message displays after successfully deleted
            return 1;

        case 'N':
        case 'n':
            printf("\033[32mDeletion cancelled\033[0m\n");//this message displays if we cancell deleted option
            return 0;

        default:
            printf("\033[31mInvalid option!\033[0m\n");//else if we choose neither of this option this message will get printed
            return 0;
    }
}
/*This function is used to save the contacts in CSV file using files i/o concept
after editing or deleting or adding contacts to save changes we need to give option*/
int save_contacts(AddressBook *addressbook)
{
    //file pointer will be used for pass by reference method
    FILE *fp;
    if((fp=fopen("contacts.csv","w"))==NULL)//fopen-->file gets open and it will write inside that file
    {
        fprintf(stderr,"\033[31mFile Not Found!\033[0m\n");
        return 0;
    }
    //#%d-->consists of no of contacts exists totally in file and that count will be updated in file
    fprintf(fp,"#%d\n",addressbook->contact_count);
    for(int i = 0;i<addressbook->contact_count;i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
    fclose(fp);//saving file closes here
    save_progress_animation();//this animation displays after saving the contact
    printf("\n\033[32mContacts saved successfully\033[0m\n");//colour text
    return 1;
}
/*This function is used to load the contacts automatically from the CSV file included 
in this project while displaying contacts it will load from CSV file and display it*/
int loadcontacts(AddressBook *addressbook)
{
    //file pointer will be used for pass by reference method
    FILE *fp;
    if((fp=fopen("contacts.csv","r"))==NULL)//fopen-->file gets open and it will only read inside that file
    {
        fprintf(stderr,"\033[31mFile Not Found!\033[0m\n");
        return 0;
    }
    //#%d-->consists of no of contacts exists totally in file and that count will be updated in file
    fscanf(fp,"#%d\n",&addressbook->contact_count);
    for(int i = 0;i<addressbook->contact_count;i++)
    {
        //here fscanf will help user to enter input correctly if it goes wrong the below printf statement gets printed
        if(fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID)!=3)
        {
            printf("\033[31mError on taking index value\033[0m \033[33m%d\033[0m\n",i+1);//colour text
            fclose(fp);//loading file closes here
            return 0;
        }
    }
    fclose(fp);//loading file closes here entirely
    return 1; 
}