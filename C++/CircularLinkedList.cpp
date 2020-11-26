#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value)
    {
        data = value;
        next = NULL;
    }
};

template <class T>
class CircularLinkedList
{
    Node<T> *head = NULL;

public:
    void insert(T value)
    {
        Node<T> *node = new Node<T>(value);
        Node<T> *last = head;
        if (head)
        {
            do
            {
                last = last->next;

            } while (last->next != head);
            last->next = node;
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
            node->next = node;
        }
    }
    void display()
    {
        Node<T> *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
    void recDisplay()
    {
        recD(head);
    }
    void insert(T value, int index)
    {
        if (index == 0)
        {
            insert(value);
        }
        else
        {
            Node<T> *node = new Node<T>(value);
            Node<T> *p = head;
            Node<T> *q = NULL;
            while (index > 0)
            {
                q = p;
                p = p->next;
                index--;
            }
            q->next = node;
            node->next = p;
        }
    }
    T del(T x)
    {
        Node<T> *p = head;
        Node<T> *last = head;
        int delValue = -1;
        do
        {
            last = last->next;
        } while (last->next != head);

        if (p->data == x)
        {
            head = p->next;
            last->next = head;
            delete p;
        }
        else
        {
            while (p != last && p->next->data != x)
            {
                p = p->next;
            }
            if (p->next->data == x)
            {
                Node<T> *delNode = p->next;
                p->next = p->next->next;
                delValue = delNode->data;
                delete delNode;
                return delValue;
            }
        }
        return -1;
    }
    T delAtIndex(int index)
    {
        Node<T> *p = head;

        int deleteValue = -1;

        if (index == 0)
        {
            Node<T> *last = head;
            do
            {
                last = last->next;
            } while (last->next != head);

            head = p->next;
            last->next = head;
            deleteValue = p->data;
            delete p;
            return deleteValue;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {  
                p = p->next;
            }
            Node<T> *q = p->next;
            deleteValue = q->data;
            p->next = q->next;
            delete q;
            return deleteValue;
            
        }
    }

private:
    void recD(Node<T> *p)
    {
        static int flag = 0;
        if (p != head || !flag)
        {
            flag = 1;
            cout << p->data << " ";
            recD(p->next);
        }
    }
};

int main()
{
    CircularLinkedList<int> list;
    list.insert(1);
    list.insert(34);
    list.insert(43);
    //list.display();
    list.insert(314, 3);
    list.delAtIndex(3);
    list.recDisplay();
}