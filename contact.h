#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int loadcontacts(AddressBook *);
void save_progress_animation();
int isname(const char* name);
int ismobile(const char* num,AddressBook *addressbook,int unique);
int mailid(const char *mail,AddressBook *addressbook,int unique);
int searchbyname(AddressBook *addressbook);
int searchbymobile_number(AddressBook *addressbook);
int searchbymail_id(AddressBook *addressbook);
#endif // CONTACT_H
       // CONTACT_H