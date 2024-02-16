#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book *prev;
    struct Book *next;
};

// Global variable to keep track of the head of the linked list
struct Book *head = NULL;

// Function to create a new book node
struct Book* createBook(int id, char title[], char author[]) {
    struct Book newBook = (struct Book)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->prev = NULL;
    newBook->next = NULL;
    return newBook;
}

// Function to add a new book to the library
void registerBook(int id, char title[], char author[]) {
    struct Book *newBook = createBook(id, title, author);
    if (head == NULL) {
        head = newBook;
    } else {
        struct Book *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
        newBook->prev = temp;
    }
}

// Function to search for a book by ID
struct Book* searchById(int id) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search for a book by title
struct Book* searchByTitle(char title[]) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search for a book by author
struct Book* searchByAuthor(char author[]) {
    struct Book *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->author, author) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to display all books in the library
void displayBooks() {
    struct Book *temp = head;
    printf("Books Available in Library:\n");
    while (temp != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

// Function to issue a book
void issueBook(int id) {
    struct Book *book = searchById(id);
    if (book != NULL) {
        printf("Book '%s' issued successfully!\n", book->title);
        // Code to handle issuing the book goes here
    } else {
        printf("Book with ID %d not found!\n", id);
    }
}

// Function to return a book
void returnBook(int id) {
    struct Book *book = searchById(id);
    if (book != NULL) {
        printf("Book '%s' returned successfully!\n", book->title);
        // Code to handle returning the book goes here
    } else {
        printf("Book with ID %d not found!\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Register a new book\n");
        printf("2. Search for a book\n");
        printf("3. Display all books\n");
        printf("4. Issue a book\n");
        printf("5. Return a book\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                {
                    int id;
                    char title[100], author[100];
                    printf("Enter book ID: ");
                    scanf("%d", &id);
                    printf("Enter book title: ");
                    scanf("%s", title);
                    printf("Enter author name: ");
                    scanf("%s", author);
                    registerBook(id, title, author);
                    printf("Book registered successfully!\n");
                    break;
                }
            case 2:
                {
                    int searchChoice;
                    printf("Search by:\n");
                    printf("1. ID\n");
                    printf("2. Title\n");
                    printf("3. Author\n");
                    printf("Choose an option: ");
                    scanf("%d", &searchChoice);
                    switch (searchChoice) {
                        case 1:
                            {
                                int id;
                                printf("Enter book ID: ");
                                scanf("%d", &id);
                                struct Book *book = searchById(id);
                                if (book != NULL) {
                                    printf("Book found: ID: %d, Title: %s, Author: %s\n", book->id, book->title, book->author);
                                } else {
                                    printf("Book not found!\n");
                                }
                                break;
                            }
                        case 2:
                            {
                                char title[100];
                                printf("Enter book title: ");
                                scanf("%s", title);
                                struct Book *book = searchByTitle(title);
                                if (book != NULL) {
                                    printf("Book found: ID: %d, Title: %s, Author: %s\n", book->id, book->title, book->author);
                                } else {
                                    printf("Book not found!\n");
                                }
                                break;
                            }
                        case 3:
                            {
                                char author[100];
                                printf("Enter author name: ");
                                scanf("%s", author);
                                struct Book *book = searchByAuthor(author);
                                if (book != NULL) {
                                    printf("Book found: ID: %d, Title: %s, Author: %s\n", book->id, book->title, book->author);
                                } else {
                                    printf("Book not found!\n");
                                }
                                break;
                            }
                        default:
                            printf("Invalid option!\n");
                    }
                    break;
                }
            case 3:
                displayBooks();
                break;
            case 4:
                {
                    int id;
                    printf("Enter book ID to issue: ");
                    scanf("%d", &id);
                    issueBook(id);
                    break;
                }
            case 5:
                {
                    int id;
                    printf("Enter book ID to return: ");
                    scanf("%d", &id);
                    returnBook(id);
                    break;
                }
            case 6:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}