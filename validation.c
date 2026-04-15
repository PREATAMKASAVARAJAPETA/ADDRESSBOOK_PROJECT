#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include <unistd.h>
/*
This isname funtion will be included many kind of validations that need to make 
like only alphabets should contain on contact username this is validation 
this funtion will be called in several places in this project if we want to edit,
delete or add new contact this validation is must and should....... 
*/
int isname(const char* name)
{
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        //if the below condition gets true below statement prints
        if(!(name[i]>='A'&& name[i]<='Z'|| name[i]>='a'&& name[i]<='z'|| name[i]==' '))
        {
            printf("The contact Name should Consist only Alphabets!.....\n");
            return 0;
        }
    }
    return 1;
}
/*
This ismobile funtion will be included many kind of validations that need to make 
like only 10 numbers should contain on contact mobile_no this is validation 
this funtion will be called in several places in this project if we want to edit,
delete or add new contact this validation is must and should....... 
*/
int ismobile(const char* num,AddressBook *addressbook,int unique)
{
    int i;
    //if the below condition gets true below statement prints
    if(strlen(num)!=10)
    {
        printf("\033[31mMobile number should consists only 10 numbers!\033[0m\n");//only numbers that too only 10 numbers are must and should
        return 0;
    }
    for(i=0;num[i];i++)
    {
        //if the below condition gets true below statement prints
        if(!isdigit((unsigned char)num[i]))
        {
            printf("\033[31mMobile number should consist only numeral digits!\033[0m\n");//if we provide rather than numbers print this message
            return 0;
        }
    }
    //if the below condition gets true below statement prints
    if(!(num[0]>='6'&& num[0]<='9'))
    {
        printf("\033[31mPlease Enter the Starting Number Between 6 and 9!\033[0m\n");//the starting number should be between 6 to 9
        return 0;
    }
    //if we enter the existing mobile number then the below statements get printed and loop ends there 
    if(unique==1)
    {
        for(i=0;i<addressbook->contact_count;i++)
        {
            //t first compares the current variable and mailid which already stored if that matches then it prints below two statements
            if(strcmp(addressbook->contact_details[i].Mobile_number,num)==0)
            {
                printf("\033[31mContact Already Exist!.....\033[0m\n");
                printf("\033[31mEnter Different Mobile Number!\033[0m\n");
                return 0;
            }
        }
    }
    return 1;
}
/*
This mailid funtion will be included many kind of validations that need to make 
like only lower case alphabets should contain on contact mailid and it may consist numbers also
this is validation this funtion will be called in several places in this project if we want to edit,
delete or add new contact this validation is must and should....... 
*/
int mailid(const char *mail, AddressBook *addressbook, int unique)
{
    int i;
    int at_count = 0;

    /* Count @ Symbols present in string and increment at_count value */
    for (i = 0; mail[i] != '\0'; i++)
    {
        if (mail[i] == '@')
            at_count++;
    }
    //if no @ found in mailid then print below staement
    if (at_count == 0)
    {
        printf("\033[31mError: No '@' symbol found in mail ID!\033[0m\n");
        return 0;
    }
    //if more than 1 @ found in mailid then print below staement
    if (at_count > 1)
    {
        printf("\033[31mError: %d '@' characters found! Only one '@' is allowed.\033[0m\n", at_count);
        return 0;
    }

    //while string comparision if @ and .com found then goto that @'s index value and .com value store it into p1 and p2 locally 
    char *p1 = strchr(mail, '@');
    char *p2 = strstr(mail, ".com");

    if (!(p1) || !(p2))
        printf("\033[31m '@' & '.com' domains must contain inside mailid\033[0m\n");
        return 0;

    int found = 0;

    /* username should consists only lowercase alphabets may be numbers also can be considered to avoid unique mailid */
    for (i = 0; i < p1 - mail; i++)   
    {
        if (!isalnum((unsigned char)mail[i]))
        {
            printf("\033[31mOnly alphanumerics are allowed...!\033[0m\n");
            return 0;
        }    
        //if we try to give capital alphabets for gmail username this condition gets true and below statement will get printed
        if (isupper((unsigned char)mail[i]))
        {
            printf("\033[31mCapital alphabets are not allowed for username...!\033[0m\n");
            return 0;
        }

    } 
    for (char *p3 = p1 + 1; p3 < p2; p3++)
    {
        if (islower((unsigned char)*p3))
            found = 1;
    }

    if (!found)
        return 0;

    /* This condition checks weather the mail id provided by user is UNIQUE one or not*/
    if (unique == 1)
    {
        for (i = 0; i < addressbook->contact_count; i++)
        {
            //it first compares the current variable and mailid which already stored if that matches then it prints below two statements
            if (strcmp(addressbook->contact_details[i].Mail_ID, mail) == 0)
            {
                printf("\033[31mEntered Mail_ID Exist Already!......\033[0m\n");
                printf("\033[31mPlease Enter Another MailID!\033[0m\n");
                return 0;
            }
        }
    }
    return 1;
}
/*
This save_progress_animation function will be used only while saving the contacts
*/
void save_progress_animation()
{
    int width = 50;

    printf("\n\033[32mSaving contacts \033[0m");

    for (int percent = 0; percent <= 100; percent++)
    {
        int filled = (percent * width) / 100;

        printf("\r\033[36mSaving contacts \033[0m[");
        for (int i = 0; i < width; i++)
            printf(i < filled ? "\033[32m-\033[0m" : "\033[7m \033[0m");

        printf("] %d%%", percent);

        fflush(stdout);
        usleep(50000);
    }
}