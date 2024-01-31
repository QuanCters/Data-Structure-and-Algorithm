/*
In a game, we have class Character to store characters' data. The class Character is declared as below : class Character
{
protected:
    int hp;
    int x;
    int y;

public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);

    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character *other);
};
Your task is to define the constructors and the methods of the class.

    Note : In this task,
    iostream library has been included, and namespace std is being used.No other libraries are allowed.

For example :
________________________________________________________________________
Test                                                            |Result
________________________________________________________________________
Character ch1(100, 3, 6);                                       |100 3 6
cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();  |
________________________________________________________________________
*/

Character::Character()
{
    // STUDENT ANSWER
    this->hp = 0;
    this->x = 0;
    this->y = 0;
}

Character::Character(int hp, int x, int y)
{
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;
}

int Character::getHp()
{
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp)
{
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX()
{
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x)
{
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY()
{
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y)
{
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character *other)
{
    // STUDENT ANSWER
    return abs(other->getX() - this->x) + abs(other->getY() - this->y);
}