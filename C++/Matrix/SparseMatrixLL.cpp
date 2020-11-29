#include <iostream>
using namespace std;

class Node
{
public:
    int c;
    int value;
    Node *next;
    Node(int column, int value)
    {
        this->c = column;
        this->value = value;
        this->next = NULL;
    }
    Node() {
        next = NULL;
    }
};
class Sparse
{
    Node *arr;
    int row;
    int column;
    int num;

public:
    Sparse(int row, int column, int num)
    {
        this->row = row;
        this->column = column;
        this->num = num;
        //arr =(Node *) malloc(sizeof(Node)*row);
        arr = new Node[row];
    }
    void display()
    {
    }
    friend istream &operator>>(istream &is, Sparse &m);
    friend ostream &operator<<(ostream &os, Sparse &m);
};

istream &operator>>(istream &is, Sparse &m)
{
    int index;
    int c;
    int value;
    int preInd = -1;
    Node *p;
    Node *q;
    for (int i = 0; i < m.num; i++)
    {
        cin >> index;
        cin >> c >> value;
        if (preInd != index)
        {   
            q = NULL;
            //if(p->next) p->next = NULL;
            p = &(m.arr[index]);
            preInd = index;
            p->c = c;
            p->value = value;
        }
        else
        {
            p = new Node(c, value);
        }
        if(q) q->next = p;
        q = p;
    }
    return is;
}
ostream &operator<<(ostream &os, Sparse &m)
{
    for (int i = 0; i < m.row; i++)
    {
        Node *p = &(m.arr[i]);
        for (int j = 0; j < m.column; j++)
        {
            if (p && p->c == j)
            {
                cout << p->value << ' ';
                p = p->next;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return os;
}

int main()
{   int n, m, num;
    cout<<"Enter no of rows : ";
    cin>>n;
    cout<<"Enter no of Columns : ";
    cin>>m;
    cout<<"Enter no of non-zero elements : ";
    cin>>num;
    Sparse matrix(n, m , num);
    cin >> matrix;
    cout << matrix;
    return 0;
}