#include <iostream>

using namespace std;

template <class type>
class node {
public:
    node* next;
    type value;

    node(){}
    node(type value){
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
    node<type>* head = nullptr;
    node<type>* tail = nullptr;

public:
    
    void insert_tail(type value)
    {
        
        node<type>* newnode = new node<type>;
        newnode->value = value;
        newnode->next = nullptr;
        if (head == nullptr){
            head = newnode;
            tail = newnode;
        }
        else{
            (*tail) > (*newnode);
            tail = newnode;
        }
    }

    void insert_head(type value)
    {
        node<type>* newnode = new node<type>;
        newnode->value = value;
        if (head == nullptr){
            newnode->next = nullptr;
            head = newnode;
            tail = newnode;
        }
        else {
            (*newnode) > (*head);
            head = newnode;
        }
    }

    void remove_head(){
        node<type>* temp = new node<type>;
        temp = head;
        head = temp->next;

        delete temp;
    }
    
    void remove_tail(){
        node<type>* current = new node<type>;
        current = head;
        if (current->next == nullptr){
            delete current;
        }
        else{
            while(current->next != tail){
                current = current->next;
            }
            tail = current;
            delete current->next;
            tail->next = nullptr;
        }
    }

    void print()
    {
        node<type>* newnode = new node<type>;
        newnode = head;
        while(newnode != nullptr){
            cout << newnode->value << endl;
            newnode = newnode->next;
        }
    }

};


int main(){
    try
    {
        linkedlist<char> list;
        list.insert_tail('c');
        list.insert_tail('b');
        // list.insert_head('a');
        // list.insert_head('f');
        // list.insert_head('w');
        list.print();
        cout << "=====" << endl;
        list.remove_head();
        list.print();
        cout << "=====" << endl;
        list.remove_tail();
        list.print();
    }
    catch(exception const& ex){
        cerr << "exception: " << ex.what() << endl;
        return -1;
    }

    return 0;
}