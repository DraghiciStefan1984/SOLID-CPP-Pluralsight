#include "pch.h"
#include <iostream>
#include <vector>

struct Document;

/*
Bad
struct IMachine
{
	virtual void print(std::vector<Document*> docs) = 0;
	virtual void scan(std::vector<Document*> docs) = 0;
	virtual void fax(std::vector<Document*> docs) = 0;
};

struct MFP :IMachine
{
	void print(std::vector<Document*> docs) override;
	void scan(std::vector<Document*> docs) override;
	void fax(std::vector<Document*> docs) override;
};
*/

struct IPrinter
{
	virtual void print(std::vector<Document*> docs) = 0;
};

struct IScanner
{
	virtual void scan(std::vector<Document*> docs) = 0;
};

struct IFax
{
	virtual void fax(std::vector<Document*> docs) = 0;
};

struct Printer :IPrinter
{
	void print(std::vector<Document*> docs) override {}
};