#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val)
    {
        next = nullptr;
    };
};

class LinkedList
{
private:
    /* data */
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        size = 1;
    };

    void printList()
    {
        Node *node = head;
        cout << "The link list is: " << endl;
        while (node != nullptr)
        {
            /* code */
            cout << node->value << endl;
            node = node->next;
        }
    }
    void appendNode(int value)
    {
        Node *newNode = new Node(value);
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    };

    Node *get(int index)
    {
        if (index < 0 || index >= size)
            return nullptr;
        Node *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value)
    {
        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > size)
            return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == size)
        {
            appendNode(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
            return deleteFirst();
        if (index == size - 1)
            return deleteLast();

        Node *prev = get(index - 1);
        Node *temp = prev->next;
        prev->next = temp->next;
        cout
            << "deleted: " << temp->value << endl;
        delete temp;
        size--;
    }

    void
    deleteFirst()
    {
        if (size == 0)
            return;
        Node *temp = head;
        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        size--;
    };
    void deleteLast()
    {
        Node *temp = head;
        Node *pre = head;
        if (size == 0)
            cout << "You cannot delete of an empty list." << endl;
        if (size == 1)
        {
            temp = head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }

        size--;
        cout << "The last item in the list is: " << temp->value << endl;
        delete temp;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void reverse()
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *after = temp->next;
        Node *before = nullptr;
        for (int i = 0; i < size; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
    void getHead()
    {
        cout << "head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "tail: " << tail->value << endl;
    }
    void getSize()
    {
        cout << "size: " << size << endl;
    }
    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main()
{
    LinkedList *myLinkList = new LinkedList{20};
    myLinkList->appendNode(24);
    myLinkList->appendNode(53);
    myLinkList->appendNode(8);
    myLinkList->appendNode(10);
    myLinkList->insert(3, 60);
    myLinkList->deleteNode(2);
    cout << myLinkList->get(3)->value << endl;
    // myLinkList->getHead();
    // myLinkList->getTail();
    // myLinkList->prepend(34);
    // myLinkList->getSize();

    myLinkList->printList();
    // myLinkList->deleteLast();
    return 0;
}
