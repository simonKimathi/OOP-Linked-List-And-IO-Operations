#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>

void push(struct Node** head, Student student_data);
void insertAfter(struct Node* prev_node, Student node_data);
void append(struct Node** head, Student node_data);
string displayList(struct Node *node);
void FrontBackSplit(Node* source,Node** frontRef, Node** backRef);
Node* SortedMerge(Node* a, Node* b);
void  MergeSort(Node** headRef);
Node *  loopLinkedListAndFilter(struct Node *node);

using namespace std;


// A linked list node
struct Node
{
    Student student;
    struct Node *next;
};
int main() {
    string text;
    vector<Student> students;
    ifstream MyReadFile("../input1.txt");

    //linked list
    // empty list
    struct Node* head = NULL;

    if(MyReadFile.is_open()) {
        while (getline(MyReadFile, text)) {
            // Read the text from the file

            stringstream ssin(text);
            int i = 0;
            string arr[5];
            while (ssin.good() && i < 5) {
                string value;
                ssin >> value;
                arr[i] = value;
                ++i;
            }
            cout << endl;
            //create new object and set values
            Student student = Student(stoi(arr[0]), &(arr[1])[0], stoi(arr[2]), stoi(arr[3]), stoi(arr[4]));
            //add to list
            push(&head, student);
            //destroy object
            student.Student::~Student();
        }
        // merge sort the list
        MergeSort(&head);

        string output;
        output =displayList(head);

        //write to file
        //write output to file
        // Create and open a text file
        ofstream MyFile("../output-4-1-1.txt");

        // Write to the file
        MyFile << output;

        //close file
        MyFile.close();

        //filter student
        Node * filteredList=loopLinkedListAndFilter(head);
        //clear output
        output="";
        //sort list again before display

        // merge sort the list
        MergeSort(&filteredList);
        //output
        output =displayList(filteredList);
        cout << "after filter \n"<<output;

        // Create and open a new text file
        ofstream MyFileNew("../output-4-1-2.txt");

        // Write to the file
        MyFileNew << output;

        //close file
        MyFileNew.close();

    }

    MyReadFile.close();
    return 0;
}


//insert a new node in front of the list
void push(struct Node** head, Student student_data)
{
    struct Node* newNode = new Node;

    newNode->student = student_data;

    newNode->next = (*head);

    (*head) = newNode;
}

//insert new node after a given node
void insertAfter(struct Node* prev_node, Student node_data)
{
    if (prev_node == NULL)
    {
        cout<<"the given previous node is required,cannot be NULL"; return;
    }

    struct Node* newNode =new Node;

    newNode->student = node_data;

    newNode->next = prev_node->next;

    prev_node->next = newNode;
}

/* insert new node at the end of the linked list */
void append(struct Node** head, Student node_data)
{
    struct Node* newNode = new Node;

    struct Node *last = *head;

    newNode->student = node_data;

    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return;
}

// display linked list contents
string displayList(struct Node *node)
{
    string output="";
    while (node != NULL)
    {
        output= output+  to_string(node->student.getId()) +
                                 " " + string(node->student.getName()) +
                                 " " + to_string(node->student.getMGa()) +
                                 " "+ to_string(node->student.getMGb()) +
                                 " "+ to_string(node->student.getMGc()) +
                                 " "+ to_string(node->student.getMTotal()) +"\n";
        node = node->next;
    }
    return output;
}


void  MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->student.getMTotal() >= b->student.getMTotal()) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}


// loop linked list filtering
Node *  loopLinkedListAndFilter(struct Node *node)
{
    struct Node* newList = NULL;

    string output="";
    while (node != NULL)
    {
        if(node->student.getId() >= 200000 && node->student.getId() <= 700000){
            struct Node* newNode = new Node;

            newNode->student = node->student;

            newNode->next = (newList);

            (newList) = newNode;
        }
        node = node->next;
    }
    return newList;
}
