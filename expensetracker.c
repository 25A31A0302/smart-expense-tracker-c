#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "../data/expenses.txt"

struct Expense {
    char date[20];
    char category[50];
    float amount;
};

void addExpense() {
    struct Expense e;
    FILE *file = fopen(FILE_NAME, "a");

    if(file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    printf("Enter Date (DD-MM-YYYY): ");
    scanf("%s", e.date);

    printf("Enter Category: ");
    scanf("%s", e.category);

    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    fprintf(file, "%s %s %.2f\n",
            e.date,
            e.category,
            e.amount);

    fclose(file);

    printf("\nExpense Added Successfully!\n");
}

void viewExpenses() {
    FILE *file = fopen(FILE_NAME, "r");

    if(file == NULL) {
        printf("No expenses found.\n");
        return;
    }

    struct Expense e;

    printf("\n---------------------------------\n");
    printf("Date\t\tCategory\tAmount\n");
    printf("---------------------------------\n");

    while(fscanf(file,
                 "%s %s %f",
                 e.date,
                 e.category,
                 &e.amount) != EOF) {

        printf("%s\t%s\t\t%.2f\n",
               e.date,
               e.category,
               e.amount);
    }

    fclose(file);
}

void searchCategory() {
    char search[50];
    int found = 0;

    printf("Enter category to search: ");
    scanf("%s", search);

    FILE *file = fopen(FILE_NAME, "r");

    if(file == NULL) {
        printf("No data available.\n");
        return;
    }

    struct Expense e;

    while(fscanf(file,
                 "%s %s %f",
                 e.date,
                 e.category,
                 &e.amount) != EOF) {

        if(strcmp(search, e.category) == 0) {
            printf("\n%s | %s | %.2f\n",
                   e.date,
                   e.category,
                   e.amount);
            found = 1;
        }
    }

    if(!found)
        printf("No matching category found.\n");

    fclose(file);
}

void totalExpense() {
    FILE *file = fopen(FILE_NAME, "r");

    if(file == NULL) {
        printf("No data available.\n");
        return;
    }

    struct Expense e;
    float total = 0;

    while(fscanf(file,
                 "%s %s %f",
                 e.date,
                 e.category,
                 &e.amount) != EOF) {

        total += e.amount;
    }

    printf("\nTotal Expenses: %.2f\n", total);

    fclose(file);
}

int main() {
    int choice;

    while(1) {

        printf("\n====== Smart Expense Tracker ======\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Category\n");
        printf("4. Total Expense\n");
        printf("5. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchCategory();
                break;

            case 4:
                totalExpense();
                break;

            case 5:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}