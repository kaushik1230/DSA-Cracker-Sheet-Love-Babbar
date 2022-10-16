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

void move() {
    node *temp1 = head, *temp2;
    while (temp1 -> next) {
        temp2 = temp1;
        temp1 = temp1 -> next;
    }
    cout << endl << temp2 -> data << endl << temp1 -> data << endl;
    temp1 -> next = head;
    temp2 -> next = NULL;
    head = temp1;
}


main () {
    int n, x, val;
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
    printf ("\n\nLast element moved to the front Linked List - ");
    move();
    display();
    return 0;
}