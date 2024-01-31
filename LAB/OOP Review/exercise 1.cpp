/*
In the coordinate plane, we have class Point to store a point with it's x-y coordinate.

Your task in this exercise is to implement functions marked with /  * STUDENT ANSWER *  /.

Note: For exercises in Week 1, we have #include <bits/stdc++.h> and using namespace std;

For example:
__________________________________________________
Test	                               |    Result
__________________________________________________
Point A(2, 3);                         |    2 3
cout << A.getX() << " " << A.getY();   | 
__________________________________________________                                   
Point A(2, 3);                         |    5
Point B(1, 1);                         |
cout << pow(A.distanceToPoint(B), 2);  |
__________________________________________________
*/

class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
this->x = 0;
this->y = 0;
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
this->x = x;
this->y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
this->x = x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
this->y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
return this->x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
return sqrt((pointA.getX() - x)*(pointA.getX() - x) + (pointA.getY() - y)*(pointA.getY() - y));
    }
};