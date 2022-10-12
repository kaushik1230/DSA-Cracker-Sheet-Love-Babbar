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


/*          ITERATIVE           */
void reverseit () {
    node *prev = NULL, *cur = head, *next = NULL;
    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}


/*          RECURSIVE           */
node * reversere (node *temp) {
    if (!temp) return NULL;
    if (!(temp -> next)) return head = temp;
    node *t = reversere(temp -> next);
    t -> next = temp;
    temp -> next = NULL;
    return temp;
}

main () {
    int n, x, val, ch = -1;
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
    printf ("\n\nReversed Linked List - ");
    //reverseit();
    reversere(head);
    display();
    return 0;
}