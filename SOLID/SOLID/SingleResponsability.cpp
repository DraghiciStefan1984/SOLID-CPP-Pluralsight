#include "pch.h"
#include <string>
#include <vector>

struct Journal
{
	std::string title;
	std::vector<std::string> entries;

	explicit Journal(const std::string& title) :title{ title }
	{

	}

	void add(const std::string& entry)
	{
		entries.push_back(entry);
	}
};

struct PersistenceManager
{
	static void save(const Journal& journal, const std::string& filename)
	{
		std::ofstream ofs(filename);
		for (auto& s : journal.entries)
		{
			ofs << s << std::endl;
		}
	}
};