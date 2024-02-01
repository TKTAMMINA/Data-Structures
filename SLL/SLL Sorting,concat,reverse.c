#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    int swapped, temp;
    struct Node* current;
    struct Node* last = NULL;


    if (head == NULL || head->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;
    return list1;
}

int main() {
    struct Node* list = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Sort\n3. Reverse\n4. Concatenate\n5. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                list = insertEnd(list, value);
                break;
            case 2:
                sortList(list);
                printf("List sorted successfully.\n");
                break;
            case 3:
                list = reverseList(list);
                printf("List reversed successfully.\n");
                break;
            case 4:
                {
                    struct Node* list2 = NULL;
                    printf("Enter values for the second list (enter -1 to stop):\n");
                    while (1) {
                        scanf("%d", &value);
                        if (value == -1) {
                            break;
                        }
                        list2 = insertEnd(list2, value);
                    }
                    list = concatenateLists(list, list2);
                    printf("Lists concatenated successfully.\n");
                }
                break;
            case 5:
                displayList(list);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
