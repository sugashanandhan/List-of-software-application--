##include <stdio.h>
#include <string.h>

struct Application {
    char bookname[100];
    char author[100];
    char version[20];
    int publishingYear;
    float price;
};

void displayByAuthor(struct Application apps[], int n, char author[]) {
    printf("Applications by author %s:\n", author);
    for (int i = 0; i < n; i++) {
        if (strcmp(apps[i].author, author) == 0) {
            printf("bookName: %s\n", apps[i].bookname);
            printf("Author: %s\n", apps[i].author);
            printf("Version: %s\n", apps[i].version);
            printf("Publishing Year: %d\n", apps[i].publishingYear);
            printf("Price: %.2f\n\n", apps[i].price);
        }
    }
}

void sortByPrice(struct Application apps[], int n) {
    struct Application temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (apps[j].price > apps[j + 1].price) {
                temp = apps[j];
                apps[j] = apps[j + 1];
                apps[j + 1] = temp;
            }
        }
    }
    printf("Applications sorted by price in increasing order:\n");
    for (int i = 0; i < n; i++) {
        printf("bookName: %s\n", apps[i].bookname);
        printf("Author: %s\n", apps[i].author);
        printf("Version: %s\n", apps[i].version);
        printf("Publishing Year: %d\n", apps[i].publishingYear);
        printf("Price: %.2f\n\n", apps[i].price);
    }
}

void displayByPublisherAndYear(struct Application apps[], int n, char publisher[], int year) {
    printf("Applications published by %s in %d:\n", publisher, year);
    for (int i = 0; i < n; i++) {
        if (strcmp(apps[i].author, publisher) == 0 && apps[i].publishingYear == year) {
            printf("bookName: %s\n", apps[i].bookname);
            printf("Author: %s\n", apps[i].author);
            printf("Version: %s\n", apps[i].version);
            printf("Publishing Year: %d\n", apps[i].publishingYear);
            printf("Price: %.2f\n\n", apps[i].price);
        }
    }
}

void sortByNameAndYear(struct Application apps[], int n) {
    struct Application temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(apps[j].author, apps[j + 1].author) > 0 || 
               (strcmp(apps[j].author, apps[j + 1].author) == 0 && apps[j].publishingYear > apps[j + 1].publishingYear)) {
                temp = apps[j];
                apps[j] = apps[j + 1];
                apps[j + 1] = temp;
            }
        }
    }
    printf("Applications sorted by author and publishing year in increasing order:\n");
    for (int i = 0; i < n; i++) {
        printf("bookName: %s\n", apps[i].bookname);
        printf("Author: %s\n", apps[i].author);
        printf("Version: %s\n", apps[i].version);
        printf("Publishing Year: %d\n", apps[i].publishingYear);
        printf("Price: %.2f\n\n", apps[i].price);
    }
}

int main() {
    int n;
    printf("Enter the number of software applications: ");
    scanf("%d", &n);
    
    struct Application apps[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter details for Application %d:\n", i + 1);
        printf("bookName: ");
        scanf("%s", apps[i].bookname);
        printf("Author: ");
        scanf("%s", apps[i].author);
        printf("Version: ");
        scanf("%s", apps[i].version);
        printf("Publishing Year: ");
        scanf("%d", &apps[i].publishingYear);
        printf("Price: ");
        scanf("%f", &apps[i].price);
    }
    
    char author[100];
    printf("Enter the author to search for: ");
    scanf("%s", author);
    displayByAuthor(apps, n, author);
    
    sortByPrice(apps, n);
    
    char publisher[100];
    int year;
    printf("Enter the publisher to search for: ");
    scanf("%s", publisher);
    printf("Enter the year to search for: ");
    scanf("%d", &year);
    displayByPublisherAndYear(apps, n, publisher, year);
    
    sortByNameAndYear(apps, n);
    
    return 0;
}