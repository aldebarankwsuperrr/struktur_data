#include <iostream>

using namespace std;

const int MAX = 100;

template <class type>
class stack{
    private:
        type st[MAX];
        int top;
    public:
        stack();

        void push(type var);
        type pop();
};

template <class type>
stack<type>::stack(){
    top = -1;
}

template <class type>
void stack<type>::push(type var){
    st[++top] = var;
}

template <class type>
type stack<type>::pop(){
    if (top > -1)
    {
        return st[top--];
    }

    return NULL;
}

int main() {
    try{
        stack<string> s1;
        s1.push("fahrul");
        s1.push("2");
        
        cout << s1.pop() << endl;
        cout << s1.pop() << endl;
        cout << s1.pop() << endl;

    }catch(exception const& ex){
        cerr << "exception: " << ex.what() << endl;
        return -1;

    }
        


};
