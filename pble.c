#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure
struct Book {
    int id;
    char name[50];
    struct Book* next;
};

struct Book* head = NULL;

// Add Book
void addBook() {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));

    printf("Enter Book ID: ");
    scanf("%d", &newBook->id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", newBook->name);

    newBook->next = head;
    head = newBook;

    printf("Book added successfully!\n");
}

// Display Books
void displayBooks() {
    struct Book* temp = head;

    if (temp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Search Book
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    struct Book* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book Found: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

// Delete Book
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    struct Book *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Book deleted.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Book deleted.\n");
}

// Main
int main() {
    int choice;

    do {
        printf("\n--- LIBRARY MANAGEMENT ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
        }
    } while (choice != 5);

    return 0;
}
