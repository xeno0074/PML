#pragma once
#include "matrix.h"

template<typename type>
class NAME_LIST{
    struct BLOCK{
        std::string name;
        type *pData;
        BLOCK *nextBlock;
    };
    BLOCK *list, *bottomList, *temp;
    public:
		bool found;
        NAME_LIST();
        ~NAME_LIST();
        void Add(std::string, type * = NULL);	//	Very Sensitive Line //	Add //	type *data = NULL
        void Remove(std::string);	//	WIP
        void Save(std::string, std::string);
        void Load();    //WIP
        type *&Search(std::string);
		//	std::ostream &
		void OutStream(std::ostream &, bool = true);
        //  inline void Assign(std::string, type *);
        
};
