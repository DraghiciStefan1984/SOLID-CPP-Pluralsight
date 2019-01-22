#include "pch.h"
#include <iostream>

class Rectangle
{
protected:
	int width, height;

public:
	Rectangle(int height, int width) :width{ width }, height{ height }{}

	virtual int GetWidth() const
	{
		return width;
	}

	virtual void SetWidth(const int width)
	{
		this->width = width;
	}

	virtual int GetHeight() const
	{
		return height;
	}

	virtual void SetHeight(const int height)
	{
		this->height = height;
	}

	int Area() const
	{
		return width * height;
	}
};

class Square:public Rectangle
{
public:
	Square(int size) :Rectangle{ size, size } {}

	void SetWidth(const int width) override
	{
		this->width = height = width;
	}

	void SetHeight(const int height) override
	{
		this->height = width = height;
	}
};

void Process(Rectangle& rectangle)
{
	int w = rectangle.GetWidth();
	rectangle.SetHeight(10);

	std::cout << "expected area is: " << (w * 10) << ", but got " << rectangle.Area() << std::endl;
}

int main()
{
	Rectangle rect{ 5, 5 };
	Process(rect);

	Square square{ 5 };
	Process(square);

	getchar();
	return 0;
}