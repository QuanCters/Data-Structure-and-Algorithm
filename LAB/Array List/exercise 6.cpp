/*
Implement methods removeAt, removeItem, clear in template class ArrayList
representing the singly linked list with type T with the initialized frame.
The description of each method is given in the code.

template <class T>
class ArrayList {
protected:
T* data; // dynamic array to store the list's items
int capacity; // size of the dynamic array
int count; // number of items stored in the array

public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
};

For example:
___________________________________________________________________
Test	                                Result
___________________________________________________________________
ArrayList<int> arr;                     [1, 2, 3, 4, 5, 6, 7, 8, 9]
                                        9
for (int i = 0; i < 10; ++i) {
    arr.add(i);
}

arr.removeAt(0);

cout << arr.toString() << '\n';
cout << arr.size();
___________________________________________________________________
ArrayList<int> arr;                     [0, 1, 2, 3, 4, 5, 6, 7, 8]
                                        9
for (int i = 0; i < 10; ++i) {
    arr.add(i);
}

arr.removeAt(9);

cout << arr.toString() << '\n';
cout << arr.size();
___________________________________________________________________
ArrayList<int> arr;                     [0, 1, 2, 3, 4, 6, 7, 8, 9]
                                        9
for (int i = 0; i < 10; ++i) {
    arr.add(i);
}

arr.removeAt(5);

cout << arr.toString() << '\n';
cout << arr.size();
*/
template <class T>
T ArrayList<T>::removeAt(int index)
{
    /*
    Remove element at index and return removed value
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index < 0 || index >= this->count)
    {
        throw std::out_of_range("Index is out of range");
    }
    T del = data[index];
    for (int i = index; i < count - 1; i++)
    {
        data[i] = data[i + 1];
    }
    count--;
    return del;
}

template <class T>
bool ArrayList<T>::removeItem(T item)
{
    /* Remove the first apperance of item in array and return true, otherwise return false */
    int pos = -1;
    for (int i = 0; i < count; i++)
    {
        if (data[i] == item)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        return false;
    }
    else
        return (removeAt(pos) != -1);
}

template <class T>
void ArrayList<T>::clear()
{
    /*
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (count == 0)
    {
        return;
    }
    else
    {
        delete[] data;
        capacity = 5;
        this->count = 0;
        data = new T[capacity];
    }
}
