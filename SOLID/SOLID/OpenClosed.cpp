#include "pch.h"
#include <string>
#include <vector>
#include <iostream>

enum class Color{RED, GREEN, BLUE};
enum class Size{SMALL, MEDIUM, LARGE};

struct Product
{
	std::string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	typedef std::vector<Product*> Items;

	static Items getByColor(Items items, Color color)
	{
		Items result;

		for (auto& i : items)
		{
			if (i->color == color)
			{
				result.push_back(i);
			}
		}
		return result;
	}

	static Items getBySize(Items items, Size size)
	{
		Items result;

		for (auto& i : items)
		{
			if (i->size == size)
			{
				result.push_back(i);
			}
		}
		return result;
	}
};

template <typename T> struct ISpecifiaction
{
	virtual bool isSatisfied(T* item) = 0;
};

template <typename T> struct IFilter
{
	virtual std::vector<T*> filter(std::vector<T*> items, ISpecifiaction<T>& spec) = 0;
};

struct BetterFilter :IFilter<Product>
{
	typedef std::vector<Product*> Items;

	virtual std::vector<Product*> filter(std::vector<Product*> items, ISpecifiaction<Product>& spec)
	{
		Items result;

		for (auto& p : items)
		{
			if (spec.isSatisfied(p))
			{
				result.push_back(p);
			}
		}

		return result;
	}
};

struct ColorSpecification :ISpecifiaction<Product>
{
	Color color;

	explicit ColorSpecification(const Color color) :color{ color }
	{

	}

	bool isSatisfied(Product* item) override
	{
		return item->color == color;
	}
};

int main()
{
	Product apple{ "Apple", Color::GREEN, Size::SMALL };
	Product tree{ "Tree", Color::GREEN, Size::LARGE };
	Product house{ "House", Color::BLUE, Size::LARGE };

	std::vector<Product*> allProducts{ &apple, &tree, &house };

	BetterFilter betterFilter;
	ColorSpecification green(Color::GREEN);

	auto green_things = betterFilter.filter(allProducts, green);

	for (auto& item : green_things)
	{
		std::cout << item->name << ", " << std::endl;
	}

	return 0;
}