#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} *head = NULL;

void insert_first(int element)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->link = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }
    else
    {
        struct Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void delete_last()
{
    struct Node *temp = head;
    struct Node *prev;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
    printf("\nDeleted Element at Last!!!\n");
    return;
}

void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty!!!!");
        return;
    }
    // struct Node* temp2 = temp;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->link;
        printf(" -> ");
    }
    printf(" NULL");
}
int main()
{
    insert_first(10);
    insert_first(20);
    insert_first(30);
    insert_first(40);
    insert_first(50);
    display();
    delete_last();
    display();
}