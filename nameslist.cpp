#include "nameslist.h"

NAMES_LIST::NAMES_LIST() {
	size = 0;
	list = NULL;
	bottomList = NULL;
}

NAMES_LIST::~NAMES_LIST() {
	//  std::cout<< "NameList Deletion"<< std::endl;
	///*
	while (list) {
		temp = list->nextBlock;
		delete list;
		list = temp;
	}
	//*/
}

void NAMES_LIST::Add(std::string name) {
	if (list == NULL) {
		list = new BLOCK;
		bottomList = list;
		bottomList->name = name;
		bottomList->nextBlock = NULL;
	}
	else {
		bottomList->nextBlock = new BLOCK;
		bottomList = bottomList->nextBlock;
		bottomList->name = name;
		bottomList->nextBlock = NULL;
	}
	size++;
}

void NAMES_LIST::Remove(std::string name) {
	if (list){
		temp = list->nextBlock;
		if (list->name == name) {
			delete list;
			list = temp;
			size--;
			return;
		}
		BLOCK *pretemp = list;
		while (temp != NULL) {
			if (temp->name == name) {
				break;
			}
			pretemp = temp;
			temp = temp->nextBlock;
		}
		pretemp->nextBlock = temp->nextBlock;
		delete temp;
		size--;

	}
	else{
		//	throw exception: null removal

	}
}

void NAMES_LIST::Delete() {
	for (int i = 0; i < size; i++)
		Remove((*this)[i]);
	size = 0;
	list = NULL;
	bottomList = NULL;

}

std::ostream &operator<< (std::ostream &out, NAMES_LIST &namesList) {
	namesList.bottomList = namesList.list;
	while (1) {
		if (namesList.list == NULL) {
			//  Empty name list
			break;
		}
		/*
		nameListFile<< bottomList-> name<< std::endl;
		bottomList->pData->OutStream(nameListFile);//<<std::endl;
		//*/
		out << " " << namesList.bottomList->name;//<<std::endl;
		if (namesList.bottomList->nextBlock == NULL) {
			//  End of list
			break;
		}
		namesList.bottomList = namesList.bottomList->nextBlock;
	}
	//out << std::endl;
	return out;
}

void NAMES_LIST::Save(std::string fileName, std::string sectionName, bool newLine) {
	std::ofstream nameListFile;
	/* File support check
	if (fileName.find('.') == -1) {
		fileName.append(".txt");
	}
	else if (fileName.find(".txt") == -1 &&
		fileName.find(".dat") == -1 &&
		fileName.find(".ods") == -1)
	{
		throw("invalid_file_extension");
		return;
	}
	//*/
	if(newLine)
		nameListFile.open(fileName, std::ios::out | std::ios::app);
	else
		nameListFile.open(fileName, std::ios::out | std::ios::trunc);
	if (!nameListFile.is_open()) {
		//  File cannot be made
	}
	else {
		nameListFile << sectionName;
		nameListFile << *this;
		if (newLine)
			nameListFile << std::endl;
		/*  BLOCK *bottomList;
		bottomList = list;
		while (1) {
			if (list == NULL) {
				//  Empty name list
				break;
			}
			/*
			nameListFile<< bottomList-> name<< std::endl;
			bottomList->pData->OutStream(nameListFile);//<<std::endl;
			//*
			nameListFile << bottomList->name << std::endl;//<<std::endl;
			if (bottomList->nextBlock == NULL) {
				//  End of list
				break;
			}
			bottomList = bottomList->nextBlock;
		}
		//*/
	}
	nameListFile.close();
}

void NAMES_LIST::Load() {
	///*  WIP

	//*/
}

std::string &NAMES_LIST::operator[] (int i){
	if (i < size) {
		temp = list;
		for (int j = 0; j < i; j++) {
			temp = temp->nextBlock;
		}
		return temp->name;
	}
	else {
		//	exception: size overflow
		//*
		std::string nullString = "";
		return nullString;
		//*/
	}
}

bool NAMES_LIST::ListEnd(unsigned int i)
{
	if (i == size)
		return true;
	return false;
}
