#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846

class Shape{
	protected:
		pair<double,double> position; //x and y coord paired together under position
		string color;
		bool borderThickness;
	public:
	    Shape(double x, double y, string color,bool bT) : position({x,y}), color(color), borderThickness(bT){}	
	    
		virtual void draw(){
	        cout << "Drawing " <<color<< " Shape At Position (" << position.first<< "," << position.second <<"), ";
	        if(borderThickness) cout << "With thick Borders" << endl << endl;
			else cout << "Without Thick Borders" << endl << endl;
		}
		
		virtual void calculateArea(){ return; }
		virtual void calculatePerimeter(){ return;}
};

class Circle : public Shape{
	double radius;
	
	public:
		Circle(double x, double y, string color,bool bT, double radius): Shape(x,y,color,bT), radius(radius){}
		void draw() override{
			cout << "Drawing " <<color<< "  Circle Of Radius = "<<radius << "cm, At Centre Position (" << position.first<< "," << position.second <<"), ";
	        if(borderThickness) cout << "With thick Borders" << endl << endl;
			else cout << "Without Thick Borders" << endl << endl;
		}
		void calculateArea() override{ cout<< "Area of Circle Is: " << radius *radius * PI<< endl << endl; }
		void calculatePerimeter() override{cout<< "Perimeter of Circle Is: " << radius *radius *PI<< endl << endl; }
};
class Rectangle : public Shape{
	double width, height;
	
	public:
		Rectangle(double x, double y, string color,bool bT, double width, double height): Shape(x,y,color,bT), width(width), height(height){}
		void draw() override{
			cout << "Drawing " <<color<< " Rectangle of width = "<<width << "cm, height = "<< height << "cm, from top-left corner Position (" << position.first<< "," << position.second <<"), ";
	        if(borderThickness) cout << "With thick Borders" << endl << endl;
			else cout << "Without Thick Borders" << endl << endl;
		}
		void calculateArea() override{ cout<< "Area of Rectangle Is: " << width * height<< endl << endl; }
		void calculatePerimeter() override{cout<< "Perimeter of Rectangle Is: " << (width + height ) * 2 << endl << endl; }
};
class Triangle : public Shape{
	double base, height;
	
	public:
		Triangle(double x, double y, string color,bool bT, double base, double height): Shape(x,y,color,bT), base(base), height(height){}
		void draw() override{
			cout << "Drawing " <<color<< " Triangle of base = "<<base << "cm, height = "<< height << "cm, from top Positionioned at = " << position.first<< "," << position.second;
	        if(borderThickness) cout << ", With thick Borders" << endl << endl;
			else cout << ", Without Thick Borders" << endl << endl;
		}
		void calculateArea() override{ cout<< "Area of Triangle Is: " << 0.5 * base * height<< endl << endl; }
		void calculatePerimeter() override{
		    double side1 = sqrt(pow(base/2,2) + pow(height,2)); //assuming isosceles or equilateral triangle
			cout<< "Perimeter of Triangle Is: " << side1 + side1 + base << endl << endl; }
};

class Polygon : public Shape{
	int sides;
	double length;
	
	public:
		Polygon(double x, double y, string color,bool bT, int sides, double len): Shape(x,y,color,bT), sides(sides), length(len){}
		void draw() override{
			cout << "Drawing " <<color<< " Polygon with "<<sides << " sides, Each of Equal Length = "<< length << "cm, centre Position (" << position.first<< "," << position.second <<"), ";
	        if(borderThickness) cout << "With thick Borders" << endl << endl;
			else cout << "Without Thick Borders" << endl << endl;
		}
		void calculateArea() override{ cout<< "Area of Polygon is: " << (sides*length*length)/(4*tan(PI/sides))<< endl<< endl;}
		void calculatePerimeter() override{ cout << "Perimeter Of Polygon is: " << sides*length<< endl << endl;} 
};

int main(){
	Circle c(0, 0, "Red", true, 3);
    c.draw();

    Rectangle r(8, 4, "Yellow", false, 8, 4);
    r.calculateArea();
    
	Triangle t(3, 3, "Green", true, 6, 4);
    t.calculatePerimeter();

    Polygon p(0, 0, "Blue", false, 5, 5);
    p.calculateArea();
}
