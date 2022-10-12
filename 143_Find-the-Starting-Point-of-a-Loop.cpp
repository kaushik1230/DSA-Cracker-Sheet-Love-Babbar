// Program to find the starting of a loop in linked list using Floyd's algorithm and fast and slow pointer

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head;

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

void createLoop (int i) {
    node *start = head, *temp = head;
    while (i--)
        start = start -> next;
    //cout << start -> data << endl;
    while (temp -> next)
        temp = temp -> next;
    //cout << temp -> data << endl;
    temp -> next = start;
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

void loopStart () {
    int count = 0;
    node *slow = head, *fast = head;
    while (slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow)
            break;
        ++count;
    }
    slow = head;
    while (slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    cout << slow -> data;
}

main () {
    int n, x, val, sl;
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
    cout << "\n\nWhere to start the loop?\n";
    cin >> sl;
    createLoop(sl);
    printf ("\n\nStarting of loop in Linked List is at node ");
    loopStart();
    return 0;
}