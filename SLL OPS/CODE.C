#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    int data;
    struct nodes *link;
};
struct nodes *deletebg(struct nodes *head)
{
    struct nodes *ptr;
    if (head == NULL)
    {
        printf("create a list");
    }
    else
    {
        ptr = head;
        head = head->link;
        free(ptr);
    }
    return head;
}
struct nodes *deleteeg(struct nodes *head)
{
    struct nodes *ptr, *prev;
    prev = malloc(sizeof(struct nodes));
    ptr = malloc(sizeof(struct nodes));
    if (head == NULL)
    {
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
    return head;
}
struct nodes *deletetgiven(struct nodes *head, int data)
{
    struct nodes *ptr, *ptr1, *ptr2, *ptr3;
    ptr = malloc(sizeof(struct nodes));
    ptr1 = malloc(sizeof(struct nodes));
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr1 = ptr;
        ptr = ptr->link;
        if (ptr->data == data)
        {
            ptr2 = ptr->link;
            ptr3 = ptr;
            ptr = ptr1;
            ptr->link = ptr2;
        }
    }
     free(ptr3);
    return head;
}
int main()
{
    struct nodes *head;
    struct nodes *ptr;
    struct nodes *current;
    head = malloc(sizeof(struct nodes));
    head->data = 10;
    head->link = NULL;
    current = malloc(sizeof(struct nodes));
    current->data = 11;
    current->link = NULL;
    head->link = current;
    current = malloc(sizeof(struct nodes));
    current->data = 12;
    current->link = NULL;
    head->link->link = current;
    current = malloc(sizeof(struct nodes));
    current->data = 13;
    current->link = NULL;
    head->link->link->link = current;
    //head=deletebg(head);
    //head=deleteeg(head);
   // head=deletetgiven(head,11);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
}
