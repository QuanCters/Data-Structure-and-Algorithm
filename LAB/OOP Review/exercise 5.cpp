/*
In the toy store, all toy has a price.Car toy has a price and color, Puzzle toy has a price and size.We have to implement class CarToy and class PuzzleToy which inherit from class Toy.class ToyBox has a pointer array to store a list of toys(up to 5 items including car and puzzle) and number of items in the box.Your task is to implement two function addItem(…) in class ToyBox.If successfully added, the function returns the current number of toys in the box.If the box is full, return -1.

For example :
________________________________________________________
Test                              |  Result
__________________________________|_____________________
CarToy car(20000, red);           | This is a car toy
PuzzleToy puzzle(30000, small);   | This is a puzzle toy
car.printType();                  |
puzzle.printType();               |
__________________________________|_____________________
CarToy car(20000, red);           | This is a car toy
PuzzleToy puzzle(30000, small);   | This is a puzzle toy
                                  |
ToyBox box;                       |
box.addItem(car);                 |
box.addItem(puzzle);              |
box.printBox();                   |
__________________________________|_____________________
Toy *toy = new CarToy(30000, red);| This is a car toy
toy->printType();                 |
__________________________________|_____________________
*/
enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        /*
         * STUDENT ANSWER
         */
        this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        /*
         * STUDENT ANSWER
         */
        this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy *toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero numberOfItems and nullptr toyBox
         */
        this->numberOfItems = 0;
        for (int i = 0; i < 5; i++)
        {
            toyBox[i] = nullptr;
        }
    }

    int addItem(const CarToy &carToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Car toy to the box.
                 If successfully added, the function returns the current number of toys in the box.
                 If the box is full, return -1.
         */
        if (numberOfItems >= 5)
        {
            return -1;
        }
        else
        {
            toyBox[numberOfItems] = new CarToy(carToy);
            numberOfItems++;
            return numberOfItems;
        }
    }

    int addItem(const PuzzleToy &puzzleToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Puzzle toy to the box.
                 If successfully added, the function returns the current number of toys in the box.
                 If the box is full, return -1.
         */
        if (numberOfItems >= 5)
        {
            return -1;
        }
        else
        {
            toyBox[numberOfItems] = new PuzzleToy(puzzleToy);
            numberOfItems++;
            return numberOfItems;
        }
    }

    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};