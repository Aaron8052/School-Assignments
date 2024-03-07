/*Yu Jiang
Assignment 10
12/02/2023
*/

#include <iostream>
#include <cmath>

using namespace std;

//int x1, y1, x2, y2, x3, y3 is too long, so I created a struct to store x and y instead
struct Vertex
{
	public:
	  float x = 0;
	  float y = 0;
	  
	/*Vertex()
	{
		x = 0;
	  	y = 0;
	}
  
	Vertex(float _x, float _y)
	{
	  	x = _x;
	  	y = _y;
	}*/
}; 

//Headers

//Get Square of a number
float square(float a);

//Prompt user input for the three vertices
void getVertices(Vertex &vert1, Vertex &vert2, Vertex &vert3);

//Get length of two sides
float sidelength(Vertex a, Vertex b);

//Check if its a valid triangle, base on the lengths
bool validate(float a, float b, float c);

//Get Perimeter of the triangle, base on the lengths
float getPerimeter(float a, float b, float c);

//Get area of the triangle
float getArea(float perimeter,  float a, float b,float c);

//Output all final results
void printResults(float sideA, float sideB, float sideC, float perimeter, float area);



int main()
{
	Vertex vert1, vert2, vert3;

	
	float distAB = -1;
	float distBC = -1;
	float distCA = -1;
	
	//Prompt for user input at least once
	do
	{
		getVertices(vert1, vert2, vert3);
	
		//get distances between vertices 123
		distAB = sidelength(vert1, vert2);
		distBC = sidelength(vert2, vert3);
		distCA = sidelength(vert3, vert1);
	}
	//Check if the vertices are valid or not
	while(!validate(distAB, distBC, distCA));
	
	float perimeter = getPerimeter(distAB, distBC, distCA);
	
	float area = getArea(perimeter, distAB, distBC, distCA);
	
	printResults(distAB, distBC, distCA, perimeter, area);
}

//Implementations
float square(float a)
{
	return a * a;//pow(a, 2);
}


void getVertices(Vertex &vert1, Vertex &vert2, Vertex &vert3)
{
	cout << "Please enter the 3 vertices for the trangle,\nfollow this order: x1, y1, x2, y2, x3, y3: \n";
	
	cin >> vert1.x >> vert1.y 
		>> vert2.x >> vert2.y 
		>> vert3.x >> vert3.y;
		
	cout << endl;
}


float sidelength(Vertex a, Vertex b)
{
	//Square Root of (x2 - x1) square + (y2 - y1) square
	return sqrt(square(b.x - a.x) + square(b.y - a.y));
}


bool validate(float a, float b, float c)
{
	return (a + b > c) && (b + c > a) && (c + a > b);
}

float getPerimeter(float a, float b, float c)
{
	return a + b + c;
}

float getArea(float perimeter, float a, float b, float c)
{
	float s = perimeter/ 2;
	
	//check if some sides are same length,
	//so we can use reduced formula
	if(a == b && b == c && c == a)
		return sqrt(s * pow((s - a), 3));
	
	
	if(a == b)
		return sqrt(s * square(s - a) * (s - c));
		
	
	if(a == c)
		return sqrt(s * square(s - a) * (s - b));
		
		
	if(b == c)
		return sqrt(s * square(s - b) * (s - a));
		
		
	return sqrt(s * (s - a) * (s - b) * (s - c));
}


void printResults(float sideA, float sideB, float sideC, float perimeter, float area)
{
	cout << "Side A Length: " << sideA << " Feet, "
		 << "Side B Length: " << sideB << " Feet, "
		 << "Side C Length: " << sideC << " Feet"
		 << endl;
	
	cout << "Perimeter: " << perimeter << " Feet" << endl;
	
	cout << "Area: " << area << " Square Feet" << endl;
}