#include <bits/stdc++.h>
using namespace std;

struct singly
{
    int data;
    struct singly *next;
} *head = NULL, *tail = NULL;
int nodeCount = 0;

singly *create_a_node(int input)
{
    singly *node, *temp;
    node = new singly[1];
    node->data = input;
    node->next = NULL;
    return node;
}

void reverse_list()
{
    singly *temp1 = head;
    singly *temp2 = head;
    singly *temp3 = head->next;
    temp1->next = nullptr; 
    while (temp3 != nullptr)
    {
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
        temp1 = temp2;
    }
    head = temp2;
    cout << "List reversed " << endl ;
}

void insert_at_begin(int input)
{
    singly *node, *temp;
    node = create_a_node(input);

    if (head == NULL && tail == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    nodeCount++;
    cout << endl
         << input << " inserted at the beginning" << endl;
    cout << "Node count : " << nodeCount << endl;
    return;
}

void insert_at_end(int input)
{
    singly *node, *temp;
    node = create_a_node(input);

    if (head == NULL && tail == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    nodeCount++;
    cout << endl
         << input << " inserted at the end" << endl;
    cout << "Node count : " << nodeCount << endl;
    return;
}

void insert_at_index(int index, int input)
{
    if (index > nodeCount || index < 0)
    {
        cout << endl
             << "Invalid Index" << endl;
        return;
    }
    else if (index == 0)
        insert_at_begin(input);
    else if (index == nodeCount)
        insert_at_end(input);
    else
    {
        singly *node, *temp, *temp2;
        node = create_a_node(input);
        temp = head;
        int count = 0;
        while (count != index - 1)
        {
            temp = temp->next;
            count++;
        }
        temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
        nodeCount++;
        cout << endl
             << input << " inserted at index " << index << endl;
        cout << "Node count : " << nodeCount << endl;
    }
    return;
}

singly *get_node(int value, int signal) // Returns the previous node of the node to be found if
{                                       // signal = -1 and next of if sig == 1 and the node if sig == 1
    singly *temp;
    temp = head;
    int index = 0;
    if (signal == -1)
    {
        while (temp != NULL)
        {
            if (temp->next->data == value)
                return temp;
            temp = temp->next;
        }
    }
    else if (signal == 1)
    {
        while (temp != NULL)
        {
            if (temp->data == value)
                return temp->next;
            temp = temp->next;
        }
    }
    else if (signal == 0)
    {
        while (temp != NULL)
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
    }
    return NULL;
}

void insert_before_a_node(int value, int input)
{
    if (head->data == value)
    {
        insert_at_begin(input);
    }
    else if (tail->data == value)
    {
        insert_at_index(nodeCount - 1, input);
    }
    else
    {
        singly *prevNode = get_node(value, -1), *node, *nextNode;
        if (prevNode == NULL)
        {
            cout << "Value not found" << endl;
        }
        else
        {
            node = create_a_node(input);
            nextNode = prevNode->next;
            prevNode->next = node;
            node->next = nextNode;
            nodeCount++;
            cout << endl
                 << input << " added before " << value << endl;
            cout << "Node count : " << nodeCount << endl;
        }
    }
}

void insert_after_a_node(int value, int input)
{
    if (head->data == value)
    {
        insert_at_index(1, input);
    }
    else if (tail->data == value)
    {
        insert_at_end(input);
    }
    else
    {
        singly *prevNode = get_node(value, 0), *node, *nextNode;
        if (prevNode == NULL)
        {
            cout << "Value not found" << endl;
        }
        else
        {
            node = create_a_node(input);
            nextNode = prevNode->next;
            prevNode->next = node;
            node->next = nextNode;
            nodeCount++;
            cout << endl
                 << input << " added before " << value << endl;
            cout << "Node count : " << nodeCount << endl;
        }
    }
}

void find_in_list(int input)
{
    singly *temp = get_node(input, 0);
    if (temp != NULL)
        cout << input << " found!!" << endl;
    else
        cout << input << " Missing!!" << endl;
    return;
}

void delete_index(int index)
{
    if (index > nodeCount - 1)
    {
        cout << "Index out of bound!!" << endl;
        return;
    }
    else if (index == 0)
    {
        head = head->next;
    }
    else if (index == nodeCount - 1)
    {

        singly *node = get_node(tail->data, -1);
        tail = node;
        node->next = NULL;
    }
    else
    {
        singly *prevNode = head;
        int count = 0;
        while (count != index - 1)
        {
            prevNode = prevNode->next;
            count++;
        }
        prevNode->next = prevNode->next->next;
    }
    nodeCount--;
    cout << endl
         << "Node at index " << index << " deleted. " << endl;
    cout << "No of nodes : " << nodeCount << endl;
    return;
}

void delete_value(int input)
{
    if (head->data == input)
    {
        head = head->next;
    }
    else
    {
        singly *prevNode = get_node(input, -1);
        if (prevNode == NULL)
        {
            cout << endl
                 << "Value not found" << endl;
            return;
        }
        else if (tail->data == input)
        {
            tail = prevNode;
            prevNode->next = NULL;
        }
        else
        {
            prevNode->next = prevNode->next->next;
        }
        nodeCount--;
        cout << endl
             << input << " Deleted!!" << endl;
        cout << "No of nodes : " << nodeCount << endl;
    }
    return;
}

void delete_head()
{
    if (head != NULL)
    {
        cout << endl
             << head->data << " Deleted!!" << endl;
        head = head->next;
        nodeCount--;
    }
    else
    {
        cout << endl
             << "List is Empty!!" << endl;
    }
}

void delete_tail()
{
    if (tail == head)
    {
        tail = NULL;
    }
    else if (tail != NULL)
    {
        singly *prevNode = get_node(tail->data, -1);
        tail = prevNode;
        prevNode->next = NULL;
        cout << endl
             << "Tail Deleted" << endl;
    }
    else
    {
        cout << "List is empty" << endl;
    }
    return;
}

void traverse()
{
    singly *temp;
    temp = head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int input, option, index, value;
    while (1)
    {
        cout << endl
             << "Choose your options : " << endl;
        cout << "1. Insert " << endl;
        cout << "2. Find" << endl;
        cout << "3. Delete " << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Reverse List" << endl;
        cout << "6. End Operation" << endl;
        cin >> option;
        switch (option)
        {

        case 1:
            cout << endl
                 << "1. Insert at beginning" << endl;
            cout << "2. Insert at end" << endl;
            cout << "3. Insert at index" << endl;
            cout << "4. Insert before a node" << endl;
            cout << "5. Insert after a node" << endl;
            cin >> option;
            cout << endl
                 << "Enter the value to be inserted" << endl;
            cin >> input;
            switch (option)
            {
            case 1:
                insert_at_begin(input);
                break;
            case 2:
                insert_at_end(input);
                break;
            case 3:
                cout << "Enter the index at which value is to be inserted : ";
                cin >> index;
                insert_at_index(index, input);
                break;
            case 4:
                cout << "Enter the value before which the value is to be inserted : ";
                cin >> value;
                insert_before_a_node(value, input);
                break;
            case 5:
                cout << "Enter the value after which the value is to be inserted : ";
                cin >> value;
                insert_after_a_node(value, input);
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
            }
            break;

        case 2:
            cout << endl
                 << "Enter the value to be found : " << endl;
            cin >> input;
            find_in_list(input);
            break;

        case 3:
            cout << endl
                 << "1. Delete an index " << endl;
            cout << "2. Delete a value " << endl;
            cout << "3. Delete the head node" << endl;
            cout << "4. Delete the tail node" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                cout << endl
                     << "Enter the index to be deleted :  ";
                cin >> index;
                delete_index(index);
                break;
            case 2:
                cout << endl
                     << "Enter the value to be deleted : ";
                cin >> value;
                delete_value(value);
                break;
            case 3:
                delete_head();
                break;
            case 4:
                delete_tail();
                break;
            default:
                cout << endl
                     << "Invalid Entry" << endl;
                break;
            }
            break;

        case 4:
            traverse();
            break;

        case 5:
            reverse_list(); 
            break; 

        case 6:
            return 0; 

            default:
            cout << endl
                 << "Invalid Entry" << endl;
            break;
        }
    }
}
