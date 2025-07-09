#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//H-Expense
// MiniProject - HarshithChegondi
// 30-Mar'2025 to 4-May'2025

typedef struct node { //structure of each node in linked list
    int id;
    char name[50];
    float exp;
    char cat[50];
    struct node* next;
} box;

void strcopy(char s[50], char str[50]) { //to copy any string element inputted by the user
    int i = 0;
    while (str[i] != '\0') {
        s[i] = str[i];
        i++;
    }
    if (str[i] == '\0') s[i] = '\0';
}

box* createBox(int val, char name[50], float exp, char cat[50]) { //to create an entry with following data needed according to the defined structure
    box* newBox = (box*)malloc(sizeof(box));
    if (newBox == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }
    newBox->id = val;
    newBox->exp = exp;
    strcopy(newBox->name, name);
    strcopy(newBox->cat, cat);
    newBox->next = NULL;
    return newBox; // Added return statement
}

box* addBox(box* head, int val, char name[50], float exp, char cat[50]) { //To add a new entry
    box* tempBox = createBox(val, name, exp, cat);
    if (head == NULL) {
        printf("Added %s (ID - %d) who spent %.2f to the expense tracker.\n", name, val, exp);
        return tempBox; // If head is NULL, return the new box as the head
    }
    box* current = head;
    while (current->next != NULL) { //iterates till the last entry and adds the new one there
        current = current->next;
    }
    current->next = tempBox;
    printf("Added %s (ID - %d) who spent %.2f to the expense tracker.\n", name, val, exp);
    return head;
}

void editBox(box* head, int id) { //to edit an entry
    box* current = head;
    while (current != NULL) {  //iterates the linked list till it finds the id of the entry which is to be editted
        if (current->id == id) {
            char choice;

            printf("\nEditing Entry for ID-%d\n", id);
            printf("Current Name: %s\n", current->name);
            printf("Do you want to edit the name? (y/n): "); //asks the user if they want to edit this part or not
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("Enter new name: ");
                scanf("%s", current->name);
            }

            printf("Current Expense: %.2f\n", current->exp);
            printf("Do you want to edit the expense? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("Enter new expense amount: ");
                scanf("%f", &current->exp);
            }

            printf("Current Category: %s\n", current->cat);
            printf("Do you want to edit the category? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("Enter new category: ");
                scanf("%s", current->cat);
            }

            printf("Entry updated successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("No entry found with ID-%d.\n", id); //edge case
}

box* delBox(box* head, int val, char name[50]) { // to delete an entry
    box* current = head;
    box* temp = NULL;

    if (head != NULL && head->id == val && strcmp(head->name, name) == 0) { //strcmp function to compare the strings
        temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %s (ID - %d) from the expense tracker.\n", name, val);
        return head;
    }

    while (current != NULL && current->next != NULL) { //iterates to the entry which is before the "to be deleted entry"
        if (current->next->id == val && strcmp(current->next->name, name) == 0) {
            temp = current->next;
            current->next = current->next->next; //adjusting the next pointer as the entry between it is removed
            free(temp); // freeing the allocated memory (to avoid waste usage of memory)
            printf("Deleted %s (ID - %d) from the expense tracker.\n", name, val);
            return head;
        }
        current = current->next;
    }

    printf("No one with ID-%d found.\n", val); //edge case
    return head;
}

void split(box* head) {
    float count = 0.0, sum = 0.0;
    box* temp = head;

    while (temp != NULL) { //to calculate total number of entries and expenses
        count++;
        sum += temp->exp;
        temp = temp->next;
    }

    if (count == 0) { //edge case
        printf("No data available for settlement.\n");
        return;
    }

    float avgExp = sum / count;
    printf("\nTotal Paid by Everyone: %.2f\n", sum);
    printf("Amount Each Person Should Have Paid: %.2f\n", avgExp);
    printf("\nSettlement Details:\n");

    temp = head;
    while (temp != NULL) { // calculates how much each person should pay / get paid/ not pay
        if (temp->exp > avgExp) {
            printf("%s (ID-%d) should be paid %.2f.\n", temp->name, temp->id, temp->exp - avgExp);
        } 
        else if (temp->exp < avgExp) {
            printf("%s (ID-%d) should pay %.2f.\n", temp->name, temp->id, avgExp - temp->exp);
        } 
        else {
            printf("%s (ID-%d) need not pay anything.\n", temp->name, temp->id);
        }
        temp = temp->next;
    }
}

void abt() { //short description on the project
    printf("\nAbout H-Expense\nH-Expense was created by Harshith Chegondi (se24uari007) to simplify managing group expenses.\n");
    printf("With features like categorizing expenses and viewing detailed reports, it ensures fairness and transparency in group finances.\n");
}

void report(box* head) { //publishes a small report in tabular format
    if (head == NULL) {
        printf("No persons in the list to generate a report.\n");
        return;
    }

    printf("\nH-Expense Report\n");
    printf("-------------------------------------------\n");
    printf("ID\tName\t\tPaid\t\tCategory\n");

    float totalPaid = 0.0;
    while (head != NULL) {
        printf("%d\t%-10s\t%-10.2f\t%-10s\n", head->id, head->name, head->exp, head->cat);
        totalPaid += head->exp;
        head = head->next;
    }
    printf("\nTotal Expenses made by Everyone: %.2f\n", totalPaid);
    printf("-------------------------------------------\n");
}

void printByCat(box* head, char* targetCategory) { //prints the data by category
    box* temp = head;
    int found = 0;
    printf("Entries under category '%s':\n", targetCategory);
    while (temp != NULL) {
        if (strcmp(temp->cat, targetCategory) == 0) {
            printf("ID: %d, Name: %s, Expense: %.2f\n", temp->id, temp->name, temp->exp);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No entries found for the category '%s'.\n", targetCategory);
    }
}

void freeList(box* head) { //it frees all the data in the linked list used for terminating the program
    box* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() { //main function of the program coded here
    box* head = NULL;
    int q, id = 0;

    printf("Welcome to H-Expense: Track and Settle Group Expenses\n");
    printf("1. About H-Expense\n2. Add an entry\n3. Delete an entry\n4. Edit an entry\n5. View all Entries by Categories\n6. Calculate Settlement\n7. Display the report\n8. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &q);

        if (q == 1) {
            abt();
        } 
        else if (q == 2) {
            char name[50], cat[50];
            float paid;

            printf("\nADD AN ENTRY:\nEnter name of the person (no spaces): ");
            scanf("%s", name);
            printf("Enter amount contributed by %s: ", name);
            scanf("%f", &paid);
            printf("Enter the category (no spaces): ");
            scanf("%s", cat);

            head = addBox(head, ++id, name, paid, cat);
        } 
        else if (q == 3) {
            char name[50];
            int deleteId;

            printf("\nDELETE AN ENTRY:\nEnter the name of the person: ");
            scanf("%s", name);
            printf("Enter the unique ID assigned to the person: ");
            scanf("%d", &deleteId);

            head = delBox(head, deleteId, name);
        } 
        else if (q == 6) {
            printf("\nCalculating Settlement...\n");
            split(head);
        } 
        else if (q == 7) {
            report(head);
        } 
        else if (q == 5) {
            char scat[50];
            printf("\nEnter the specific Category: ");
            scanf("%s", scat);
            printByCat(head, scat);
        } 
        else if (q == 8) {
            printf("\nTerminating the Program. Thank you.\n");
            freeList(head); // Free all allocated memory to avoid memory leaks
            return 0;
        } 
        else if(q == 4){
            printf("\nEDIT AN ENTRY: \n Enter the unique id of which you wish to edit: ");
            int uid;
            scanf("%d", &uid);
            editBox(head, uid);
        }
        else { //edge case
            printf("Invalid choice. Please choose a valid option (1-8).\n");
        }
    }
}