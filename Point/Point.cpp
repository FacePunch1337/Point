#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <string.h>


struct Point {
    char* title;
    double x, y;
    Point(): title{NULL}, x{5}, y{5} {};
    void SetTitle(const char* title) {
		if (this->title) delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
    }
    Point(Point&& other) noexcept : x{ other.x }, y{ other.y }, title{ other.title } {
        other.title = NULL;
        printf("Move constructor\n");
    }
    Point(const Point& other):  x{ other.x }, y{ other.y }, title{ NULL } {
        this->SetTitle(other.title);
    };
    Point(double x, double y, char* title = NULL) : x{ x }, y{ y }, title{ title } {
        if (title) SetTitle(title);
    }
 
    ~Point() {
        if(title) delete[] title;
        printf("Destructor\n");
    }

	Point& operator = (const Point& other) {
		this->x = other.x;
		this->y = other.y;

		this->SetTitle(other.title);
		printf("Copy =\n");
		return *this;
	}


	Point& operator =  (Point&& other) noexcept {
		this->x = other.x;
		this->y = other.y;
		this->title = other.title;

		other.title = NULL;
		printf("Move =\n");
		return *this;
	}

	Point operator-() {
		this->x = -this->x;
		this->y = -this->y;
		return *this;
	}

	Point operator-(const Point& other) {
		Point tmp;
		tmp.x = this->x - other.x;
		tmp.y = this->y - other.y;
		return tmp;
	}

	Point operator+() {

		return *this;
	}

	Point operator+(const Point& other) {
		Point tmp;
		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;
		return tmp;
	}

	

        
   
};

    
   

int main()
{
	Point a;
	Point b;
	Point c;

	a.x = 10;
	a.y = 5;
	b.x = 1;
	b.y = 2;

	std::cout << a.x << " " << a.y << "\n";
	c = a + b;
	std::cout << c.x << " " << c.y << "\n";
   
}


