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
int main() {
	double r;
	double l,b;
	cin>>r;
	cin>>l>>b;
	Shape *shape1 = new Circle(r);
	Shape *shape2 = new Rectangle(l,b);
	shape1->calculateArea(); // Output: Area of the circle: 78.5375
	shape2->calculateArea(); // Output: Area of the rectangle: 24
	delete shape1;
	delete shape2;
	return 0;
}
