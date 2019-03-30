#include "llist.h"

template<typename type>
LLIST<type>::LLIST() {
	size = 0;
	head = NULL;
	tail = NULL;
}

template<typename type>
LLIST<type>::~LLIST() {
	while (head) {
		temp = head->nextBlock;
		delete head;
		head = temp;
	}
}

template<typename type>
inline void LLIST<type>::Append(type data) {
	if (head == NULL) {
		head = new BLOCK;
		tail = head;
		tail->data = data;
		tail->nextBlock = NULL;
	}
	else {
		tail->nextBlock = new BLOCK;
		tail = tail->nextBlock;
		tail->data = data;
		tail->nextBlock = NULL;
	}
	size++;
}

template<typename type>
inline void LLIST<type>::Remove() {
	/*
	if (head) {
		temp = head->nextBlock;
		if (head->data == data) {
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
	else {
		//	throw exception: null removal

	}
	//*/
}

template<typename type>
inline type & LLIST<type>::operator[](int i) {
	if (i < size) {
		temp = head;
		for (int j = 0; j < i; j++) {
			temp = temp->nextBlock;
		}
		//	return temp->data;
	}
	return temp->data;
	/*
	else {
		//	exception: size overflow
		
		std::string nullString = "";
		return nullString;
	}
		return temp->data;
	//*/
}

/*
template<typename type>
std::ostream & operator<<(std::ostream &out, LLIST<type> &list){
	list.tail = list.list;
	while (1) {
		if (list.list == NULL) {
			//  Empty name list
			break;
		}
		/*
		nameListFile<< bottomList-> name<< std::endl;
		bottomList->pData->OutStream(nameListFile);//<<std::endl;
		//*
		out << " " << list.tail->name;//<<std::endl;
		if (list.tail->nextBlock == NULL) {
			//  End of list
			break;
		}
		list.tail = list.tail->nextBlock;
	}
	out << std::endl;
	return out;
}
//*/