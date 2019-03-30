#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include <fstream>


template<typename type>
class LLIST{
public:
	LLIST();
	~LLIST();
	void Append(type);
	void Remove();
	type &operator[](int);
	//	friend std::ostream &operator<<(std::ostream &, LLIST &);
private:
	struct BLOCK
	{
		type data;
		BLOCK *nextBlock;
	};
	int size;
	BLOCK *head, *tail, *temp;
};

//#include "llist.cpp"
