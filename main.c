#include <stdio.h>
#include "contact.h"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    loadcontacts(&addressbook);

    while (1)
    {
        printf("\033[35mAddress book menu\033[0m\n"); /* Give a prompt message for a user */
        printf("\033[32m1.Add contact\033[0m\n\033[33m2.search contact\033[0m\n\033[33m3.Edit contact\033[0m\n\033[31m4.Delete contact\033[0m\n\033[36m5.Display contact\033[0m\n\033[32m6.Save contact\033[0m\n\033[31m7.Exit\033[0m\n");
        printf("\033[30mEnter the option :\033[0m ");
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            //printf("\033[35mSearch Contact menu : \033[0m\n\033[33m1.Name \033[0m\n\033[33m2.Mobile number\033[0m\n\033[33m3.Mail ID\033[0m\n\033[31m4. Exit\033[0m\n"); /* Providing menu Enter the option : */
            search_contacts(&addressbook);
            break;
        }
        case 3:
            printf("\033[36mEdit Contact menu : \033[0m\n\033[33m1.Name \033[0m\n\033[33m2.Mobile number\033[0m\n\033[33m3.Mail ID\033[0m\n\033[31m4.Exit\033[0m\n"); /* Providing menu */

            edit_contact(&addressbook);
            break;

        case 4:
        {
            printf("\033[31mDelete Contact menu : \033[0m\n\033[33m1.Name \033[0m\n\033[33m2.Mobile number\033[0m\n\033[33m3.Mail ID\033[0m\n\033[31m4.Exit\033[0m\n"); /* Providing menu */

            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("\033[30mList Contacts:\033[0m");
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf("\033[32mSaving contacts\033[0m\n");
            save_contacts(&addressbook);
            break;
        case 7:
            printf("\033[33mINFO\033[0m : \033[32mSave and Exit...\033[0m\n");
            return 0;

        default:
            printf("\033[31mInvalid option \033[0m\n");
            break;
        }
    }
    return 0;
}
