#include <iostream>

using namespace std;


template <class type>
class node
{
public:
    node* next;
    type value;

    node(){};
    node (type value)
    {
        this->value = value;
    }

    node operator > (node& newnode)
    {
        this->next = &newnode;
        return (*this);
    }
};


template <class type>
class linkedlist
{
private:
    node<type>* head = NULL;

public:
    int n = 0;
    void insert(type value)
    {
        n++;
        node<type>* newnode = new node<type>;
        newnode->value = value;
        (*newnode) > (*head);
        head = newnode;
    }

    void print ()
    {
        node<type>* newnode = new node<type>;
        newnode = head;
        while (newnode != NULL)
        {
            cout << newnode->value << endl;
            newnode = newnode->next;
        }
    }
};



int main ()
{
    try
    {
        linkedlist<int> list;
        list.insert(1);
        list.insert(2);
        list.print();
    }
    catch(exception const& ex){
        cerr << "exception: " << ex.what() << endl;
        return -1;

    }


    return 0;
}
