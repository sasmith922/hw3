#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr) { // base case
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* nextNode = head->next; // save rest of list

    if (head->val <= pivot) // smaller
    {
        smaller = head;
        llpivot(nextNode, smaller->next, larger, pivot);
    }
    else // larger
    {
        larger = head;
        llpivot(nextNode, smaller, larger->next, pivot);
    }

    head = nullptr; // clears list

}

