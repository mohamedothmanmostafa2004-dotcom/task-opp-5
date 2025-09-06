#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
protected:
    string name;
    string color;
    int id;

public:
    Shape(string n, string c, int i) : name(n), color(c), id(i) {}


    virtual double calculateArea() = 0;

    virtual void display()
    {
        cout << "Shape: " << name << ", Color: " << color << ", ID: " << id << endl;
    }
};


class Circle : public Shape
{
private:
    double radius;

public:
    Circle(string n, string c, int i, double r) : Shape(n, c, i), radius(r) {}

    double calculateArea() override
    {
        return M_PI * radius * radius;
    }

    void display() override
    {
        Shape::display();
        cout << "Circle Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};


class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(string n, string c, int i, double l, double w)
        : Shape(n, c, i), length(l), width(w) {}

    double calculateArea() override
    {
        return length * width;
    }

    void display() override
    {
        Shape::display();
        cout << "Rectangle Length: " << length << ", Width: " << width
             << ", Area: " << calculateArea() << endl;
    }
};


class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(string n, string c, int i, double b, double h)
        : Shape(n, c, i), base(b), height(h) {}

    double calculateArea() override
    {
        return 0.5 * base * height;
    }

    void display() override
    {
        Shape::display();
        cout << "Triangle Base: " << base << ", Height: " << height
             << ", Area: " << calculateArea() << endl;
    }
};

int main()
{

    Shape* shapes[3];

    shapes[0] = new Circle("Circle1", "Red", 1, 5);
    shapes[1] = new Rectangle("Rectangle1", "Blue", 2, 4, 6);
    shapes[2] = new Triangle("Triangle1", "Green", 3, 3, 7);

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->display();
        cout << "-------------------" << endl;
    }


    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }

    return 0;
}
