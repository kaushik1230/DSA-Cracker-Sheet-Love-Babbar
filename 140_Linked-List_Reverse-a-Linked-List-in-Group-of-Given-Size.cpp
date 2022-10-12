#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

typedef struct Node node;

void createList (int val) {
    node *newNode = (node *) malloc ( sizeof (node) );
    newNode -> data = val;
    newNode -> next = NULL;

    if (!head) {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp -> next)
        temp = temp -> next;

    temp -> next = newNode;
}

void display () {
    node *temp = head;
    cout << "\n\n[\t";
    while (temp) {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }
    cout << "]";
}

node * reverse(node *head, int g) {
    if (!head) return NULL;
    node *current = head, *next = NULL, *prev = NULL;
    int x = g;
    while (current && g--) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
    }
    if (next) head->next = reverse(next, x);
    return prev;
}


main () {
    int n, x, g, val, ch = -1;
    cout << "\n\nCreate Linked List - \n\nEnter number of nodes: ";
    cin >> n;
    x = n;
    while (n--) {
        cout << "\n\nEnter value for node " << x - n << ": ";
        cin >> val;
        createList (val);
    }
    printf ("\n\nYour Linked List - ");
    display();
    printf ("\n\nEnter size of group: ");
    cin >> g;
    printf ("\n\nReversed Linked List - ");
    head = reverse(head, g);
    display();
    return 0;
}