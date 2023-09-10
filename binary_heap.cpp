#include <iostream>

using namespace std;

void swap(int *x, int *y);

class min_heap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // current number of elements in min heap
public:
    // constructor
    min_heap(int capacity);

    // to heapify a subtree with the root at given index
    void min_heapify(int );

    int parent(int i){
        return (i - 1)/2;
    }

    // to get index of elft child of node at index i
    int left(int i){
        return (2*i) + 1;
    }

    // to get index of right child of node at index i
    int right(int i){
        return (2*i) + 2;
    }

    // to extract the root which is the minimum element
    int extract_min();

    // decreases key value of key at index i to new_val
    void decrease_key(int i, int new_val);

    // returns the minimum key
    int get_min(){
        return harr[0];
    }

    // deletes a key
    void delete_key(int i);

    // insert a new key
    void insert_key(int k);
};

min_heap::min_heap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void min_heap::insert_key(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertkey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void min_heap::decrease_key(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int min_heap::extract_min()
{
    if (heap_size <= 0)
    {
        return INT_MAX;
    }
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    min_heapify(0);

    return root;
}

void min_heap::delete_key(int i)
{
    decrease_key(i, INT_MIN);
    extract_min();
}

void min_heap::min_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smalllest = i;
    if (l < heap_size && harr[l] < harr[i])
    {
        smalllest = l;
    }
    if (r < heap_size && harr[r] < harr[smalllest])
    {
        smalllest = r;
    }
    if (smalllest != i)
    {
        swap(&harr[i], &harr[smalllest]);
        min_heapify(smalllest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    min_heap h(11);
    h.insert_key(3);
    h.insert_key(2);
    h.delete_key(1);
    h.insert_key(15);
    h.insert_key(5);
    h.insert_key(4);
    h.insert_key(45);

    cout << h.extract_min() << " ";
    cout << h.get_min() << " ";

    h.decrease_key(2,1);
    cout << h.get_min();

    return 0;
}