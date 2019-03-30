#pragma once
#include "namelist.h"
// List of tokens
class NAMES_LIST {
	struct BLOCK {
		std::string name;
		BLOCK *nextBlock;
	};
	int size;
	BLOCK *list, *bottomList, *temp;
public:
	NAMES_LIST();
	~NAMES_LIST();
	void Add(std::string);
	void Remove(std::string);
	void Delete();
	void Save(std::string, std::string, bool = true);
	void Load();    //WIP
	friend std::ostream &operator<< (std::ostream &, NAMES_LIST &);
	std::string &operator[] (int);
	bool ListEnd(unsigned int);
};
