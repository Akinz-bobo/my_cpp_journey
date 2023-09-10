#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    };
};

class DoublyLinkedlist
{
private:
    /* data */
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedlist(int value);
    ~DoublyLinkedlist();
    // print out all the values in the linked list.
    void printList()
    {
        Node *temp = head;
        cout << "The link list is: " << endl;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    };
    // add a value to the end of the list.
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    };
    // add a value to the beginning of the list.
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    // takes index and change the value if index exits.
    bool setValue(int index, int value)
    {
        Node *temp = getIndex(index);
        if (temp)
        {
            temp->value = value;
            return true;
        };
        return false;
    };
    // retrun the node at the given index.
    Node *getIndex(int index)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        };
        Node *temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int j = length - 1; j > index; j--)
            {
                tail = temp->prev;
            }
        };
        return temp;
    }
    // insert value at the given index.
    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            cout << "Cannot insert at index: " << index << " if length is: " << length << endl;
            return false;
        }
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *before = getIndex(index - 1);
        Node *after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    };
    //  delete the last item in the list.
    void deleteLast()
    {
        if (length == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        };
        Node *temp = tail;
        cout << "deleting the node: " << temp->value << endl;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }
    // delete the first item in the list.
    void deleteFirst()
    {
        if (length == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        };
        Node *temp = head;
        cout << "deleting the node: " << temp->value << endl;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    //
    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (length == 0)
            deleteFirst();
        if (length == length)
            deleteLast();
        Node *temp = getIndex(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
    }

    // return the last item in the list
    void getHead()
    {
        cout << "Head: " << head->value << endl;
    };
    // return the fist item in the list.
    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    };
    // return the length of the list.
    void getLength()
    {
        cout << "Length: " << length << endl;
    }
};
// Contructor of the linked list.
DoublyLinkedlist::DoublyLinkedlist(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
};
// Destructor of the linked list.
DoublyLinkedlist::~DoublyLinkedlist(){};

int main()
{
    DoublyLinkedlist *myDLL = new DoublyLinkedlist(7);
    myDLL->append(20);
    myDLL->prepend(12);
    myDLL->setValue(2, 10);
    myDLL->insert(3, 6);
    // myDLL->getTail();
    // myDLL->getLength();
    // myDLL->deleteLast();
    myDLL->printList();
    return 0;
}