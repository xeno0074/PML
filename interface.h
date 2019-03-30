#pragma once
#include "nameslist.h"

//extern int WITDTH;

namespace Interface{
	class INTERFACE {
		//	static unsigned int count;

		std::string inputStream;
		NAMES_LIST tokenStream;
		NAMES_LIST lineStream;
		NAME_LIST<Matrix::MATRIX> dataList;
		Matrix::MATRIX *tempMatrix;
		enum LINE_TYPE{
			assi, decl, spec, disp, valu
		};
		enum LINE_TYPE lineType;
		bool cmdMode;//	assignment from file or cmd
		std::ifstream file;//file for execution
		bool active;
		bool save;//save session
//	functions:
		//void LoadLineStream();
		void MarkCharacters(int &, int &, std::string &);
		void CleanStream();
		void FetchLine();
		void SplitLine(std::string);
		void FetchLineCmd(bool &);
		void Tokenizer(const std::string &);
		int Main(std::string);						//
		int ExecFile(std::string, std::string);
		void Manual();
//	operations functions:
		void Assi_init_base();
		void Assi_init_base_dimension();
		void Assi_expr_base();
		void Decl_matrix_base();
		void Decl_vector_base();
		void Decl_auto_base();
		void Spec_display_base();
//	op functions' supporting functions:
	public:
		bool CheckIdentifier(std::string);
		bool CheckExpressionSeparator(char);
		INTERFACE();
		~INTERFACE();
		void CmdInterface(bool = true);
	};
}
