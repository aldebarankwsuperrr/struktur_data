#include <iostream>

using namespace std;

template <typename type>
class stack
{
private:
    int size;
    type* data;
    int head = 0;
    int tail = 0;

public:
    stack<type>(int n) : size(n)
    {   
        data = new type [n];
    }

    stack<type>& pop ()
    {
        this->head++;
    }

    stack<type>& push (type data)
    {
        if (tail < size)
        {
            this->data[tail++] = data;
            return (*this);
        }
        return (*this);
    }

    void print()
    {
        for (int i = head; i < size;i++)
        {
            cout << this->data[i] << endl;
        }
    }
};

int main ()
{
    try
    {
        stack<int> stack1(3);

        stack1.push(1).push(2).push(5).push(3);
        
        stack1.print();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    




    return 0;
}
