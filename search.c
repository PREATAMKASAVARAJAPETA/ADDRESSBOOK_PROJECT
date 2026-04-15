#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include <unistd.h>
/*
Here Searchbyname function will be used for purpose of searching deleting and editing options 
this function uses for only contacts name editing,adding or deleting searching is original but
editing and deleting function will redirecting to this function only to make correct operation
*/
int searchbyname(AddressBook *addressbook)
{
    char name[32];
    int arr[20], count = 0, serial_no;
    //this loop enters until the condition gets true
    do {
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
    } while (!isname(name));

    for (int i = 0; i < addressbook->contact_count; i++)
    {
        //if the below condition gets true below statement prints
        if(strcasestr(addressbook->contact_details[i].Name, name) != NULL)
        {
            if (count < 20)                 
                arr[count++] = i;
        }
    }

    if (count == 0)
    {
        printf("\033[31mcontact not found!\033[0m\n");
        return -1;
    }
    //this entire printf displays for users to choose choice and info what are included in this function
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  |                        \033[30mCONTACT DETAILS\033[0m                                   |\n");
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  | \033[33msi_no\033[0m      |       \033[34mname\033[0m        |       \033[35mmobile_no\033[0m       |     \033[32mmail_id\033[0m     |\n");
    printf("  |--------------------------------------------------------------------------|\n");
    //if we want to display single contact this printf will be helping for displaying contact info
    if (count == 1)        
    {
        int index=arr[0];
        printf("  | %-10d | %-17s | %-21s | %-15s |\n",
               1,
               addressbook->contact_details[index].Name,
               addressbook->contact_details[index].Mobile_number,
               addressbook->contact_details[index].Mail_ID);
        printf("  |--------------------------------------------------------------------------|\n");
        return index;
    }
    //if multiple contacts found then this loop runs and display the required info
    for (int i = 0; i < count; i++)
    {
        int index = arr[i];
        printf("  | %-10d | %-17s | %-21s | %-15s |\n",
               i + 1,
               addressbook->contact_details[index].Name,
               addressbook->contact_details[index].Mobile_number,
               addressbook->contact_details[index].Mail_ID);
        printf("  |--------------------------------------------------------------------------|\n");
    }

    printf("select contact(1-%d): ", count);
    scanf("%d", &serial_no);
    //check if the user enter correct index value or not if not entered
    if (serial_no < 1 || serial_no > count)
    {
        printf("\033[31mInvalid serial no\033[0m\n");//this statement prints and returns to the loop again
        return -1;
    }

    return arr[serial_no - 1];
}
/*
Here Searchbymobile_number function will be used for purpose of searching deleting and editing options 
this function uses for only contacts mobile_number editing,adding or deleting searching is original but
editing and deleting function will redirecting to this function only to make correct operation
*/
int searchbymobile_number(AddressBook *addressbook)
{
    char mobile[11];
    int index = -1;
    //this loop continues until we enter the correct requirement
    do {
        printf("Enter the mobile number: ");
        scanf("%s", mobile);
    } while (!ismobile(mobile, addressbook, 0));

    for (int i = 0; i < addressbook->contact_count; i++)
    {
        //this compares two strings of original one in addressbook and temp variable mobile
        if (strcmp(addressbook->contact_details[i].Mobile_number, mobile) == 0)
        {
            index = i;
            break;
        }
    }
    //if index value doesnt change then we have to consider that no contacts found on searching
    if (index == -1)
    {
        printf("\033[31mContact not found!\033[0m\n");
        return -1;
    }
    //this entire printf displays for users to choose choice and info what are included in this function
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  |\033[30m                        CONTACT DETAILS                    \033[0m|\n");
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  | si_no      |       name        |       mobile_no       |     mail_id     |\n");
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  | %-10d | %-17s | %-21s | %-15s |\n", index + 1,addressbook->contact_details[index].Name,addressbook->contact_details[index].Mobile_number,addressbook->contact_details[index].Mail_ID);
    printf("  |--------------------------------------------------------------------------|\n");

    return index;
}
/*
Here Searchbymailid function will be used for purpose of searching deleting and editing options 
this function uses for only contacts mailid editing,adding or deleting searching is original but
editing and deleting function will redirecting to this function only to make correct operation
*/
int searchbymail_id(AddressBook *addressbook)
{
    char mail[35];
    int index = -1;
    //this loop continues until we enter the correct requirement
    do {
        printf("Enter the mail id: ");
        scanf("%s", mail);
    } while (!mailid(mail, addressbook, 0));

    for (int i = 0; i < addressbook->contact_count; i++)
    {
        //this compares two strings of original one in addressbook and temp variable mail
        if (strcmp(addressbook->contact_details[i].Mail_ID, mail) == 0)
        {
            index = i;//if found it will help to display the required contact info
            break;
        }
    }
    //if index value doesnt change then we have to consider that no contacts found on searching
    if (index == -1)
    {
        printf("\033[31mContact not found!\033[0m\n");
        return -1;
    }
    //this entire printf displays for users to choose choice and info what are included in this function
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  |\033[30m                        CONTACT DETAILS                    \033[0m|\n");
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  | si_no      |       name        |       mobile_no       |     mail_id     |\n");
    printf("  |--------------------------------------------------------------------------|\n");
    printf("  | %-10d | %-17s | %-21s | %-15s |\n",index + 1,addressbook->contact_details[index].Name,addressbook->contact_details[index].Mobile_number,addressbook->contact_details[index].Mail_ID);
    printf("  |--------------------------------------------------------------------------|\n");

    return index;
}
