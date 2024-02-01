/*
Implement methods ensureCapacity, add, size in template class ArrayList
representing the array list with type T with the initialized frame.
The description of each method is given in the code.

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
};

For example:
________________________________________________________________________________
Test	                                        Result
______________________________________________________________________________________________________________________
ArrayList<int> arr;                             [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
int size = 10;                                  10

for(int index = 0; index < size; index++){
    arr.add(index);
}

cout << arr.toString() << '\n';
cout << arr.size();
______________________________________________________________________________________________________________________
ArrayList<int> arr;                             [19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
int size = 20;                                  20

for(int index = 0; index < size; index++){
    arr.add(0, index);
}

cout << arr.toString() << '\n';
cout << arr.size() << '\n';
arr.ensureCapacity(5);
______________________________________________________________________________________________________________________
*/
template <class T>
void ArrayList<T>::ensureCapacity(int cap)
{
    /*
        if cap == capacity:
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap == this->capacity)
    {
        this->capacity *= 1.5;
        T *newData = new T[this->capacity];
        for (int i = 0; i < count; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    else
    {
        return;
    }
}

template <class T>
void ArrayList<T>::add(T e)
{
    /* Insert an element into the end of the array. */
    ensureCapacity(count);
    data[count] = e;
    count++;
}

template <class T>
void ArrayList<T>::add(int index, T e)
{
    /*
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */
    ensureCapacity(count);
    for (int i = count; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = e;
    count++;
}

template <class T>
int ArrayList<T>::size()
{
    /* Return the length (size) of the array */
    return count;
}
