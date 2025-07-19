#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
	virtual void calculateArea() const {
    	cout << "Area of the shape: ";
	}
	virtual ~Shape() {}
};
class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r) : radius(r) {}
	void calculateArea() const override {
    	cout << "Area of the circle: " << 3.14 * radius * radius << endl;
	}
};
class Rectangle : public Shape {
private:
	double length;
	double width;
 
public:
	Rectangle(double l, double w) : length(l), width(w) {}
	void calculateArea() const override {
    	cout << "Area of the rectangle: " << length * width << endl;
	}
};

int main(){
    double r;
    double l,w;
    cin >> r;
    cin >> l >> w;
    Shape *s = new Shape;
    Shape *shape1 = new Circle(r);
    Shape *shape2 = new Rectangle(l,w);
    shape1->calculateArea();
    shape2->calculateArea();
	delete shape1;
	delete shape2;
}
