#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct IsOdd 
{
    bool operator()(int value)
    {
        return value % 2 != 0;
    }
};

struct IsEven 
{
    bool operator()(int value)
    {
        return value % 2 == 0;
    }
};

struct GreaterThanFive 
{
    bool operator()(int value)
    {
        return value > 5;
    }
};

struct IsNegative 
{
    bool operator()(int value)
    {
        return value < 0;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    // Test code for IsOdd
    head = llfilter(head, IsOdd());
    cout << "Filtered list (only evens remain): ";
    print(head);
    dealloc(head);

    // Reset
    head = readList(argv[1]);

    // Test for IsEven
    Node* filtered2 = llfilter(head, IsEven());
    cout << "Filtered list (only odds remain): ";
    print(filtered2);
    dealloc(filtered2);

    // Reset
    head = readList(argv[1]);

    // Test for GreaterThanFive
    Node* filtered3 = llfilter(head, GreaterThanFive());
    cout << "Filtered list (only numbers ≤ 5 remain): ";
    print(filtered3);
    dealloc(filtered3);

    // Reset
    head = readList(argv[1]);

    // Test for IsNegative
    Node* filtered4 = llfilter(head, IsNegative());
    cout << "Filtered list (only non-negatives remain): ";
    print(filtered4);
    dealloc(filtered4);

    // Reset
    head = readList(argv[1]);

    // Filter empty list
    Node* emptyList = nullptr;
    Node* filteredEmpty = llfilter(emptyList, IsOdd());
    cout << "Filtered empty list: ";
    print(filteredEmpty);
    dealloc(filteredEmpty);

    // All elements removed
    Node* allRemoved = llfilter(head, [](int){ return true; }); // Removes everything
    cout << "Filtered list (everything removed): ";
    print(allRemoved);
    dealloc(allRemoved);

    // Reset
    head = readList(argv[1]);

    // No elements removed
    Node* noneRemoved = llfilter(head, [](int){ return false; }); // Keeps everything
    cout << "Filtered list (everything kept): ";
    print(noneRemoved);
    dealloc(noneRemoved);

    // Reset
    head = readList(argv[1]);

    // Test llpivot with pivot = 5
    Node* smaller = nullptr;
    Node* larger = nullptr;
    llpivot(head, smaller, larger, 5);
    cout << "List with values <= 5: ";
    print(smaller);
    cout << "List with values > 5: ";
    print(larger);
    cout << "Tests passed!" << endl;
    
    return 0;

}
