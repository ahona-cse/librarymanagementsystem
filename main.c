#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

struct Book
{
    int id,issued;
    char title[50],author[50];
};

struct Book library[MAX];
int TotalBooks = 0;


void AddNewBook();
void SearchBook();
void ViewAllBooks();
void IssueBook();
void DeleteBook();
void ReturnBook();
void CheckAvailability();
void TotalSummary();
void Exitprogram();
void WelcomeScreen();
void Login();


int main()
{
    Login();
    WelcomeScreen();
    library[0].id=101;
    strcpy(library[0].title, "C Programming");
    strcpy(library[0].author, "Dennis Ritchie");
    library[0].issued = 0;

    library[1].id = 102;
    strcpy(library[1].title, "Data Structures");
    strcpy(library[1].author, "Mark Allen");
    library[1].issued = 1;

    library[2].id = 103;
    strcpy(library[2].title, "Algorithms");
    strcpy(library[2].author, "Thomas Cormen");
    library[2].issued = 0;

    TotalBooks = 3;

    int choice;
    do{
    printf("\n=======MAIN MENU=======\n");
    printf("1.Add New Book\n");
    printf("2.search Book\n");
    printf("3.View All Books\n");
    printf("4.Issue Book\n");
    printf("5.Delete Book\n");
    printf("6.Return Book\n");
    printf("7.Check Availability\n");
    printf("8.Total Summary\n");
    printf("9.Exit Program\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:AddNewBook();
        break;
    case 2:SearchBook();
        break;
    case 3:ViewAllBooks();
        break;
    case 4:IssueBook();
        break;
    case 5:DeleteBook();
        break;
    case 6:ReturnBook();
        break;
    case 7:CheckAvailability();
        break;
    case 8:TotalSummary();
        break;
    case 9:Exitprogram();
        break;
    default:
        printf("Invalid Choice!\n");
    }
    }
    while(choice!=9);
    return 0;
}
void Login()
{
    char username[20], password[20];

    printf("=====================================\n");
    printf("         LIBRARY LOGIN SYSTEM         \n");
    printf("=====================================\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

        printf("\nLogin Successful!\n");
        printf("Press ENTER to continue...");
        getchar();
        getchar();
}
void WelcomeScreen()
{
    printf("\n");
    printf("==============================================\n");
    printf("         WELCOME TO LIBRARY SYSTEM              \n");
    printf("==============================================\n");
    printf("  Project  : Library Management System\n");
    printf("  Language : C Programming\n");
    printf("  User     : Student\n");
    printf("----------------------------------------------\n");
    printf("  Press ENTER to continue to Main Menu...\n");
    printf("==============================================\n");
    getchar();
}

void AddNewBook()
{
    char title[50], author[50];

    if (TotalBooks >= MAX)
    {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("\n======= ADD NEW BOOK =======\n");

    printf("Enter Book ID: ");
    scanf("%d", &library[TotalBooks].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", author);

    strcpy(library[TotalBooks].title, title);
    strcpy(library[TotalBooks].author, author);

    library[TotalBooks].issued = 0;

    TotalBooks++;

    printf("\nBook added successfully!\n");
}
void SearchBook()
{
    int searchId, found = 0;

    printf("\n======= SEARCH BOOK =======\n");
    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < TotalBooks; i++)
    {
        if (library[i].id == searchId)
        {
            found = 1;
            printf("\nBook Found!\n");
            printf("ID     : %d\n", library[i].id);
            printf("Title  : %s\n", library[i].title);
            printf("Author : %s\n", library[i].author);
            printf("Status : %s\n",
                   library[i].issued ? "Issued" : "Available");
            break;
        }
    }

    if (!found)
    {
        printf("\nBook not found.\n");
    }
}
void ViewAllBooks()
 {
    if (TotalBooks == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    printf("\n=========All Books=========\n");
    printf("ID     Title                      Author          Status\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < TotalBooks; i++)
    {
        printf("%d   %s  %s      %s\n",library[i].id,library[i].title,library[i].author,library[i].issued ? "Issued" : "Available");

    }
 }
 void IssueBook()
{
    int id;
    int found = 0;

    printf("\n======= ISSUE BOOK =======\n");
    printf("Enter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < TotalBooks; i++)
    {
        if (library[i].id == id)
        {
            found = 1;

            if (library[i].issued == 0)
            {
                library[i].issued = 1;
