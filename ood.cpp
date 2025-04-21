#include <iostream>

class Car {
    private:
        int speed;
    public:
        void setSpeed(int s) 
        {
            speed = s;
        }
        int getSpeed()
        {
            return speed;
        }
};

class Shape {
public:
    virtual double area() = 0; 
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14 * radius * radius; }
};

int main()
{
    Car myCar;
    Shape *s = new Circle(5.0);
    myCar.setSpeed(50);
    std::cout << myCar.getSpeed();
    std::cout << s->area();
}