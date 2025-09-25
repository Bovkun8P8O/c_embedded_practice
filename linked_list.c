/* Practice 4: Linked List
 * Printing a linked list of Harry Potter book series
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BOOK_NAME_LEN 128 // not using consts because of structs
#define MAX_LANG_LEN 32       // const expression is required for array size

void printList(void);
void insertAtBegin(int, const char *, double, int, const char *, double, int);
void insertAtEnd(int, const char *, double, int, const char *, double, int);
void insertAfterNode(int, int, const char *, double, int, const char *, double, int);
void deleteAtBegin(void);
void deleteAtEnd(void);
void deleteNode(int);
int searchList(int);
struct node *getNodePtr(int key);

struct node
{
    int index;
    char book_name[MAX_BOOK_NAME_LEN];
    double book_price;
    int pages;
    char lang[MAX_LANG_LEN];
    double mass;
    int publication_year;
    struct node *next;
};
struct node *head = NULL;

void printList()
{
    struct node *p = head;
    while (p != NULL)
    {
        printf(" Index: %d.\n Book: %s.\n Price: %.2f pounds.\n Pages: %d.\n Language: %s.\n Mass: %.2f kg.\n Publication year: %d.\n->\n",
               p->index, p->book_name, p->book_price, p->pages, p->lang, p->mass, p->publication_year);
        p = p->next;
    }
    printf("\n");
}

void insertAtBegin(int index,
                   const char *book_name,
                   double book_price,
                   int pages,
                   const char *lang,
                   double mass,
                   int publication_year)
{
    struct node *new_link = (struct node *)malloc(sizeof(struct node));
    if (!new_link)
    {
        printf("Memory allocation failed in insertAtBegin.\n");
        return;
    }

    new_link->index = index;
    strncpy(new_link->book_name, book_name, MAX_BOOK_NAME_LEN - 1);
    new_link->book_name[sizeof(new_link->book_name) - 1] = '\0';
    // }
    new_link->book_price = book_price;
    new_link->pages = pages;
    strncpy(new_link->lang, lang, MAX_LANG_LEN - 1);
    new_link->lang[sizeof(new_link->lang) - 1] = '\0';
    new_link->mass = mass;
    new_link->publication_year = publication_year;
    new_link->next = NULL;

    // point new to old first node
    new_link->next = head;
    // point first to new first node
    head = new_link;
}
void insertAtEnd(int index,
                 const char *book_name,
                 double book_price,
                 int pages,
                 const char *lang,
                 double mass,
                 int publication_year)
{
    struct node *new_link = (struct node *)malloc(sizeof(struct node));
    if (!new_link)
    {
        printf("Memory allocation failed in insertAtEnd.\n");
        return;
    }

    new_link->index = index;
    strncpy(new_link->book_name, book_name, MAX_BOOK_NAME_LEN - 1);
    new_link->book_name[sizeof(new_link->book_name) - 1] = '\0';
    new_link->book_price = book_price;
    new_link->pages = pages;
    strncpy(new_link->lang, lang, MAX_LANG_LEN - 1);
    new_link->lang[sizeof(new_link->lang) - 1] = '\0';
    new_link->mass = mass;
    new_link->publication_year = publication_year;
    new_link->next = NULL;

    struct node *linkedlist = head;

    if (linkedlist == NULL)
    {
        head = new_link;
        return;
    }

    // traverse to the end of the list
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;

    // point the last node to the new node
    linkedlist->next = new_link;
}
void insertAfterNode(int target_index,
                     int index,
                     const char *book_name,
                     double book_price,
                     int pages,
                     const char *lang,
                     double mass,
                     int publication_year)
{
    struct node *list = getNodePtr(target_index);
    if (list == NULL)
    {
        printf("The node with given index (%d) is not found.\n", target_index);
        return;
    }

    struct node *new_link = (struct node *)malloc(sizeof(struct node));
    if (!new_link)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_link->index = index;
    strncpy(new_link->book_name, book_name, MAX_BOOK_NAME_LEN - 1);
    new_link->book_name[sizeof(new_link->book_name) - 1] = '\0';
    // }
    new_link->book_price = book_price;
    new_link->pages = pages;
    strncpy(new_link->lang, lang, MAX_LANG_LEN - 1);
    new_link->lang[sizeof(new_link->lang) - 1] = '\0';
    new_link->mass = mass;
    new_link->publication_year = publication_year;
    new_link->next = NULL;

    // point new node to the next node
    new_link->next = list->next;
    // point previous node to the new node
    list->next = new_link;
}
void deleteAtBegin()
{
    if (head == NULL)
    {
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL) // if empty
    {
        return;
    }
    if (head->next == NULL) // if only one node
    {
        free(head);
        head = NULL;
        return;
    }
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
    {
        linkedlist = linkedlist->next;
    }
    free(linkedlist->next);
    linkedlist->next = NULL;
}
void deleteNode(int key)
{
    struct node *temp = head, *prev;
    if (temp != NULL && temp->index == key) // if the head has the key
    {
        head = temp->next;
        free(temp);
        return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp->index != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
    {
        return;
    }
    // Remove the node
    prev->next = temp->next;
    free(temp);
}

// returns 1 if found, 0 if not found
int searchList(int key)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->index == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
struct node *getNodePtr(int key)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->index == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    printList();
    insertAtBegin(1, "Harry Potter and the Philosopher's Stone", 19.99, 223, "English", 0.5, 1997);
    insertAtEnd(2, "Harry Potter and the Chamber of Secrets", 20.99, 251, "English", 0.55, 1998);
    insertAtEnd(4, "Harry Potter and the Goblet of Fire", 22.99, 636, "English", 0.75, 2000);
    insertAfterNode(2, 3, "Harry Potter and the Prisoner of Azkaban", 21.99, 317, "English", 0.6, 1999);
    insertAtEnd(5, "Harry Potter and the Order of the Phoenix", 23.99, 766, "English", 0.8, 2003);
    insertAtEnd(6, "Harry Potter and the Half-Blood Prince", 24.99, 607, "English", 0.7, 2005);
    insertAtEnd(7, "Harry Potter and the Deathly Hallows", 25.99, 607, "English", 0.85, 2007);

    insertAtBegin(0, "The Hobbit", 15.99, 310, "English", 0.4, 1937);
    deleteAtBegin();
    insertAtEnd(8, "The Lord of the Rings", 29.99, 1178, "English", 1.2, 1954);
    deleteAtEnd();
    insertAfterNode(5, 8, "The Lord of the Rings", 29.99, 1178, "English", 1.2, 1954);
    deleteNode(8);

    printList();

    int target_index = 5;
    if (searchList(target_index))
    {
        printf("The node %d is found.\n", target_index);
    }
    else
    {
        printf("The node %d is not found.\n", target_index);
    }

    return 0;
}