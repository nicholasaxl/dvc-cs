#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct LinkedList
{
    int value;
    LinkedList *next;
};

void print(LinkedList* );
void append_node(LinkedList*&, int);
void insert_node(LinkedList*&, int);
void delete_node(LinkedList*&, int);
void search_node(LinkedList*&, int);
void destroy_list(LinkedList* );

int main()
{
    //variable declaration for the user inputs
    int userInput;
    LinkedList *head = NULL;
    int SIZE;
    int userValue;
    int insertValue;
    int deleteNum;
    int findNum;

    //input validation loop for the size of the linked list
    do{
        cout << "Enter the number of initial nodes (must be at least 1): ";
        cin >> SIZE;
    }while(SIZE < 1); //loops if the user inputs a value less than one



    cout << endl;


    //enter a value that will be sent to the append function
    //will repeat for the specified user size
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Enter a number: ";
        cin >> userValue;
        append_node(head, userValue);
    }

    //first print for the initial linked list
    cout << "Here are the initial values in the linked list: " << endl;
    print(head);


    //user input for the number to be inserted into the linked list
    cout << "Enter a number for a new node to insert to the linked list: ";
    cin >> insertValue;
    insert_node(head, insertValue);

    //second print to display the updated linked list
    cout << "Here is the updated linked list: " << endl;
    print(head);

    //gets the user input for what they want to delete, if the number doesnt exist then it deletes nothing
    cout << "Enter the number that you want to delete from the linked list: ";
    cin >> deleteNum;
    //function call
    delete_node(head, deleteNum);

    //last print for the final update of the linked list
    cout << "Here is the updated linked list: " << endl;
    print(head);

    //gets the user input for the value to be searched
    cout << "Enter the number that you want to search for in the linked list: ";
    cin >> findNum;
    //function call with the value inputted by the user
    search_node(head, findNum);

    system("PAUSE");
	return 0;

}

void append_node(LinkedList*& h, int i)
{
    //general linked list assignments
    LinkedList* n = new LinkedList;
    n->value = i;
    n->next = NULL;
    //if there is no linked list created
    if (h == 0)
    {
        h = n;
    }
    else
    {
        //appends the new list
        LinkedList* p = h;
        while (p->next != NULL)
           {
               p = p->next;
           }
        p->next = n;
    }
}

void insert_node(LinkedList*& head, int user)
{
    LinkedList *newNode;
    LinkedList *nodePtr;
    LinkedList *previousNode = nullptr;

    newNode = new LinkedList;
    newNode->value = user;

    //for when there is no initial node
    if (!head)
    {
        head = newNode; //assigns the head into newNode then puts the next into NULLPTR
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;

        previousNode = nullptr;

        //sorts the new number to put it in a sorted manner
        while (nodePtr != nullptr && nodePtr-> value < user)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //for when there is no previous node
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }

}

void print(LinkedList *p)
{
    //prints the linked list if there are nodes initially
    while (p != NULL)
    {
        cout << p->value << endl;
        p = p->next;
    }
    cout << endl;
}

void delete_node(LinkedList*& head, int number)
{
    LinkedList *nodePtr;
    LinkedList *previousNode;

    //if there is no node to delete
    if (!head)
        return;

    //searches for the specified number then deletes it
    if (head->value == number)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != number)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void search_node(LinkedList*& head, int value)
{
    int index = 1; //declaration to keep the value of the index
    while (head != 0)
    {
        if(head->value == value) //if the same value is found after the looping, print the statement
        {
          cout << "Number found at index " << index << " in the linked list" << endl;
        }
        head = head->next;
        index+=1; //counter variable for the index number
    }
}

void destroy_list(LinkedList* h)
{
    //deletes the entire linked list
    while (h != 0)
    {
        LinkedList *p = h;
        LinkedList *h = h->next;
        delete(p);
    }
}
