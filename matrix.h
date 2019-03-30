#pragma once
//	#include "llist.h"
#include<iostream>
#include<iomanip>
#include<string>
#include <fstream>


extern int WIDTH;

namespace Matrix{
    class MATRIX{
        protected:
//        public:
            int m, n;
            double **go;
        public:
            MATRIX();
            MATRIX(int, int);
            MATRIX(int, int, double **);
            MATRIX(const MATRIX &);
            ~MATRIX();
            double &element(int, int);
//            void display(int);
            void operator= (const MATRIX &);
            MATRIX operator+ (MATRIX);
            MATRIX operator- ();
            MATRIX operator* (MATRIX);
            MATRIX operator~ ();
//			std::ostream &
//			void OutStream(std::ostream &);
			friend std::ostream &operator<< (std::ostream &, const MATRIX &);
            //  operator double();
    };
}
