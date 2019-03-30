#include <sstream>
#include "interface.h"
//#include "llist.cpp"
#define SAVE_LOG
//#define SAVE_DATA
//#define SAVE_TOKENS
//#define SAVE_CMD_TOKENS
//#define SAVE_CMD_LOG

Interface::INTERFACE::INTERFACE(){
	active = true;
	save = true;
	cmdMode = true;
	/*
	tokenStream.Add("mat");
	tokenStream.Add("=");
	tokenStream.Add("row");
	tokenStream.Add("how?");
	
	//std::cout << tokenStream;// << std::endl;// << tokenStream.size << std::endl;
	//tokenStream.Remove("now");
	tokenStream.Remove("how?");
	tokenStream.Remove("row");
	//std::cout << tokenStream[0] << std::endl;
	//*/
#ifdef SAVE_LOG
	tokenStream.Save("exec_log.txt", "#<BEGIN");
#endif
}

Interface::INTERFACE::~INTERFACE(){
	save = false;
	active = false;
#ifdef SAVE_LOG
	tokenStream.Save("exec_log.txt", "#END>");
#endif
	//std::cin.get();
}

void Interface::INTERFACE::Tokenizer(const std::string &line){
	CleanStream();
	//lineStream.Add("\n");
	using namespace std;
	string intermediate;
	/*
	getline(strstream, intermediate, ':');
	tokenStream.Add(intermediate);
	cout << intermediate<< endl;
	//*/
	/*
	getline(strstream, intermediate, '=');
	tokenStream.Add(intermediate);
	cout << intermediate << endl;
	//*/
	int start = line.find(':');
	if (start != string::npos) {
		lineType = decl;

		intermediate = line.substr(0, start);
		tokenStream.Add(intermediate);
		//cout << intermediate << endl;
		if (start == line.length() - 1)
			return;
		stringstream strstream(line.substr(start + 1));
		//int i = 1;
		//*
		while (getline(strstream, intermediate, ' ')) {
			tokenStream.Add(intermediate);
			//cout << intermediate << endl;
			//i++;
		}
		//cout << i << endl;
		//tokenStream.Save("token_streams.txt", "");

		return;
	}
	start = line.find('=');
	if (start != string::npos) {
		lineType = assi;

		intermediate = line.substr(0, start);
		tokenStream.Add(intermediate);
		//cout << intermediate << endl;
		if (start == line.length() - 1)
			return;
		stringstream strstream(line.substr(start + 1));
		//int i = 1;
		//*
		while (getline(strstream, intermediate, ' ')) {
			tokenStream.Add(intermediate);
			//cout << intermediate << endl;
			//i++;
		}
		//cout << i << endl;
		//tokenStream.Save("token_streams.txt", "");

		return;
	}
	//start = line.find(' ');
	else {
		lineType = valu;

		stringstream strstream(line);
		while (getline(strstream, intermediate, ' ')) {
			tokenStream.Add(intermediate);
			//cout << intermediate << endl;
			//i++;
		}
		//tokenStream.Save("temp_data.txt", "");
		return;
	}
	//std::string temp;
	//strstream >> temp;
	//*/
	/* Printing the token vector
	for (int i = 0; tokens.ListEnd(i); i++)
		cout << tokens[i] << '\n';
	//*/
	//return tokens;
}

inline void Interface::INTERFACE::MarkCharacters(int &pos_i, int &pos_f, std::string &stream) {
	char clean_char = stream[pos_i];
	pos_f = pos_i;
	while (stream[pos_f] == clean_char)
		pos_f++;
}

void Interface::INTERFACE::CleanStream() {
	//std::cin.get();
	//*
	std::string temp;
	int pos_i, pos_f, pos_x, pos_sub_i;
	pos_x = inputStream.find_first_of(":=");
	if (pos_x != std::string::npos) {
		temp = inputStream.substr(0, pos_x);

		pos_i = temp.find(' ');
		if (pos_i != std::string::npos) {
			MarkCharacters(pos_i, pos_f, temp);
			if (pos_i == 0) {
				inputStream.erase(pos_i, pos_f);
				//std::cout << "input" << inputStream << std::endl;
				temp.erase(pos_i, pos_f);
				pos_x -= pos_f;
				//std::cout << "temp" << temp << std::endl;
			}
			//pos_i = 0;
			//*
			while (1) {
				pos_sub_i = temp.substr(pos_i).find(' ');
				pos_i += pos_sub_i;
				if (pos_sub_i != std::string::npos) {
					MarkCharacters(pos_i, pos_f, temp);
					pos_f -= pos_i;
					pos_x -= pos_f - 1;
					inputStream.erase(pos_i, pos_f - 1);
					//std::cout << "input" << inputStream << std::endl;
					temp.erase(pos_i, pos_f - 1);
					//std::cout << "temp" << temp << std::endl;
					pos_i++;
				}
				else
					break;
			}
			//*
			if (inputStream[pos_x - 1] == ' ')
				inputStream.erase(--pos_x, 1);
			//*/
		}
		//std::cout << inputStream << std::endl;

		int pos_y = ++pos_x;
		pos_x = inputStream.length();
		temp = inputStream.substr(pos_y);
		pos_i = 0;

		//std::cout << temp << std::endl;
		pos_i = temp.find(' ');
		if (pos_i != std::string::npos) {
			MarkCharacters(pos_i, pos_f, temp);
			if (pos_i == 0) {
				inputStream.erase(pos_i + pos_y, pos_f);
				//std::cout << "input" << inputStream << std::endl;
				temp.erase(pos_i, pos_f);
				pos_x -= pos_f;
				//std::cout << "temp" << temp << std::endl;
			}
			//pos_i = 0;
			//*
			while (1) {
				pos_sub_i = temp.substr(pos_i).find(' ');
				pos_i += pos_sub_i;
				if (pos_sub_i != std::string::npos) {
					MarkCharacters(pos_i, pos_f, temp);
					pos_f -= pos_i;
					pos_x -= pos_f - 1;
					inputStream.erase(pos_i + pos_y, pos_f - 1);
					//std::cout << "input" << inputStream << std::endl;
					temp.erase(pos_i, pos_f - 1);
					//std::cout << "temp" << temp << std::endl;
					pos_i++;
				}
				else
					break;
			}
			//*
			if (inputStream[pos_x - 1] == ' ')
				inputStream.erase(--pos_x, 1);
			//*/
		}
	}
	else {
		//temp = inputStream;
		pos_i = inputStream.find(' ');
		pos_x = inputStream.length();
		if (pos_i != std::string::npos) {
			MarkCharacters(pos_i, pos_f, inputStream);
			if (pos_i == 0) {
				inputStream.erase(pos_i, pos_f);
				//std::cout << "input" << inputStream << std::endl;
				//inputStream.erase(pos_i, pos_f);
				if (!inputStream.length())
					return;
				pos_x -= pos_f;
				//std::cout << "temp" << temp << std::endl;
			}
			//pos_i = 0;
			//*
			while (1) {
				pos_sub_i = inputStream.substr(pos_i).find(' ');
				pos_i += pos_sub_i;
				if (pos_sub_i != std::string::npos) {
					MarkCharacters(pos_i, pos_f, inputStream);
					pos_f -= pos_i;
					pos_x -= pos_f - 1;
					inputStream.erase(pos_i, pos_f - 1);
					//std::cout << "input" << inputStream << std::endl;
					//inputStream.erase(pos_i, pos_f - 1);
					//std::cout << "temp" << temp << std::endl;
					pos_i++;
				}
				else
					break;
			}
			//*
			if (inputStream[pos_x - 1] == ' ')
				inputStream.erase(--pos_x, 1);
			//*/
		}
		//tokenStream.Add(inputStream);
		//tokenStream.Save("dum.txt", ">>");
	}
	//*/
}

void Interface::INTERFACE::FetchLine(){

}

void Interface::INTERFACE::SplitLine(std::string inputStream) {
	/*	Fetches a line a puts in the input stream
	static unsigned int i = 0;
	//	std::cout << i << std::endl;
	tokenStream.Delete();
	switch (i)
	{
	case -1:
		break;
	case 0:
		tokenStream.Add("matrix");
		tokenStream.Add(":");
		tokenStream.Add("mat1");
		tokenStream.Add("mat2");
		break;
	//*
	case 1:
		tokenStream.Add("mat1");
		tokenStream.Add("=");
		break;
	//*
	//*
	case 2:
		tokenStream.Add("mat2");
		tokenStream.Add("=");
		break;
	//*
	case 3:
		tokenStream.Add("matrix");
		tokenStream.Add(":");
		tokenStream.Add("mat1");
		tokenStream.Add("mat2");
		break;
		//*
	case 4:
		tokenStream.Add("mat1");
		tokenStream.Add("=");
		break;
		//*
		//*
	case 5:
		tokenStream.Add("mat2");
		tokenStream.Add("=");
		break;
		//*
	default:
		active = false;							//	It is where the user program ends
		return;
	}
	i++;
	tokenStream.Save("data.txt", "#TOKEN LIST\n");
	return;
	//*/
	Tokenizer(inputStream);
	//Processing
	tokenStream.Delete();
}

//*	
void Interface::INTERFACE::FetchLineCmd(bool &cActive) {
	//	Fetchline has to set inactive to make process end
	std::getline(std::cin, inputStream);
	//CleanStream();
	Tokenizer(inputStream);
#ifdef SAVE_CMD_TOKENS
	tokenStream.Save("cmd_token_streams.txt", "");
#endif
#ifdef SAVE_LOG
	tokenStream.Save("exec_log.txt", "#TOKEN LIST>>");
#endif
	if (lineType == decl && tokenStream[0] == "quit") {
		if (tokenStream.ListEnd(1)) {
			//lineStream.Remove("");
			lineStream.Save("last_session.txt", "", false);
			cActive = false;
			tokenStream.Delete();
			return;
		}
		else {
			//	for one or more arguments
		}
	}
	else if (lineType == decl && tokenStream.ListEnd(1) && tokenStream[0] == "man") {
		Manual();
		tokenStream.Delete();
		return;
	}
	else if (lineType == decl  && tokenStream[0] == "run") {
		INTERFACE interface;
		interface.save = false;
		if (tokenStream.ListEnd(3)) {
			interface.ExecFile(tokenStream[1], tokenStream[2]);
			tokenStream.Delete();
			//return;
		}
		// for one argument
		else if(tokenStream.ListEnd(2)){
			//INTERFACE interface;
			interface.ExecFile(tokenStream[1], "");
			tokenStream.Delete();	
			//return;
		}
		//save = true;
		return;
	}
	else if (lineType == decl && tokenStream[0] == "load") {
		// for one argument
		if (tokenStream.ListEnd(2)) {
			//INTERFACE interface;
			std::string openFile = tokenStream[1];
			tokenStream.Delete();
			//cmdMode = false;
			if (openFile == ".") {
				ExecFile("last_session.txt", "");
			}
			else
				ExecFile(openFile, "");
			//cmdMode = true;
			//tokenStream.Delete();
			return;
		}
	}
	else if (
#ifdef SAVE_CMD_LOG
		Main("cmd_data_out")
#endif
#ifndef SAVE_CMD_LOG
		Main("")
#endif
		) {
		//Error
		std::cout << "no main execution!" << std::endl;
		cActive = false;
		//tokenStream.Delete();
		//return;
	}
	//if(cmdMode)
	//	lineStream.Add(inputStream + '\n');
	tokenStream.Delete();
	return;
	//active = false;
	//return;
	/*
	if (inputStream == "quit:") {
		active = false;
		return;
	}
	else if (inputStream == "\n") {
		return;
	}
	else if (inputStream == "man:") {
		Manual();
		return;
	}
	//	ffile command has to be inside else condition, after parsing
	else if (inputStream == "run:") {
		/*
		Interface::INTERFACE interface;
		interface.FetchLine();
		int end;
		while (interface.active) {
			end = interface.Main();
			if (end)
				break;
		}
		return;
		//*
		Interface::INTERFACE interface;
		interface.ExecFile("de.txt");

	}
	else {

		return;
	}//*/
}
//*/

//*	Main executes a line
int Interface::INTERFACE::Main(std::string oFileName){
	//if (!active)
	//	return 1;
	if (lineType == assi) {
		if (save)
			lineStream.Add(inputStream + '\n');
		//	Assignment line type:
		if (tokenStream.ListEnd(1)) {
			//	Initialization:
			Assi_init_base();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			if (oFileName.length())
				dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
		else if(tokenStream.ListEnd(3)){
			//	Initialization:
			Assi_init_base_dimension();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			if (oFileName.length())
				dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
		else {
			//	Expressional assignment:

			return 0;
		}
	}
	else if (lineType == decl) {
		if (save)
			lineStream.Add(inputStream + '\n');
		//	Declaration line type:
		if (tokenStream[0] == "matrix") {
			Decl_matrix_base();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			//dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
		else if (tokenStream[0] == "vector") {
			Decl_vector_base();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			//dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
		else if (tokenStream[0] == "auto") {
			Decl_auto_base();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			//dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
		//	Special line type:
		else if (tokenStream[0] == "display") {
			Spec_display_base();
#ifdef SAVE_LOG
			dataList.Save("exec_log.txt", "#DATA LIST>>\n");
#endif
#ifdef SAVE_DATA
			dataList.Save("data_lists.txt", "");
#endif // SAVE_DATA
			//if (oFileName.length())
			//	dataList.Save(oFileName, "");
			//FetchLine();
			return 0;
		}
	}
	else if(tokenStream.ListEnd(0)){
		return 0;
	}
	return 1;
}

int Interface::INTERFACE::ExecFile(std::string fileName, std::string oFileName){
	//INTERFACE interface;
	//std::ifstream file;
	file.open(fileName, std::ios::in | std::ios::beg);
	if (!file.is_open()) {
		// File cannot be opened
		std::cout << "File not opened" << std::endl;
	}
	else {
		while (!file.eof()) {
			std::getline(file, inputStream);
			//CleanStream();
			Tokenizer(inputStream);
#ifdef SAVE_LOG
			tokenStream.Save("exec_log.txt", "#TOKEN LIST>>");
#endif
#ifdef SAVE_TOKENS
			tokenStream.Save("exec_token_streams.txt", "");
#endif
			cmdMode = false;
			if (Main(oFileName)) {
				//Error
				std::cout << "invalid input" << std::endl;
				tokenStream.Delete();
				file.close();
				return 1;
			}
			cmdMode = true;
			tokenStream.Delete();
		}
		//interface.active = false;
	}
	file.close();
	return 0;
}

void Interface::INTERFACE::CmdInterface(bool cActive){
	//  Intro
	std::cout << "Welcome to Project ML" << std::endl
		<< "Type man: and press enter to open manual." << std::endl
		<< "Type quit: and press enter to quit." << std::endl
		<< ">>";
	while (cActive) {
		FetchLineCmd(cActive);
		std::cout << ">>";
	}
}
//*/
void Interface::INTERFACE::Manual() {
	using std::cout;
	using std::endl;
	//  cout<< ">>Manual is WIP<<"<< endl<< endl;
	//  
	cout << "Declaration of variables:" << endl;
	cout << "    Use declaration keywords matrix, vector, auto with syntax:" << endl << endl;
	cout << "        declare:[variable1] [variable2] [...]" << endl << endl;
	cout << "Initialization of variable:" << endl;
	cout << "    Initialize while declaration using the assignment operator '=' for each variables" << endl << endl;
	cout << "Assignment of values for variables:" << endl;
	cout << "    Assign values for variables using the assignment operator '=' using the syntax:" << endl << endl;
	//  Assignment syntax for matrix class
	cout << "    Syntax for matrices:" << endl << endl;
	cout << "        variable=[rows] [columns]" << endl;
	cout << "        [value] [value] [...  ]" << endl;
	cout << "        [value] [value] [...  ]" << endl;
	cout << "        [...  ] [...  ] [...  ]" << endl;
	cout << endl;
	//  Operations
	cout << "Performing operations:" << endl;
	cout << "    Unary operators:" << endl << endl;
	cout << "        [variable]' -----------------------------------> Puts the transpose into the same variable" << endl;
	cout << "        [variable1] = [variable2]'" << endl;
	cout << "    Binary operators:" << endl << endl;
	cout << "        [variable1] + [variable2] ---------------------> Puts the sum into [variable1]" << endl;
	cout << "        [variable1] = [variable2] + [variable3]" << endl;
	cout << "    -Other binary operators(-, *) share the same syntax." << endl << endl;
	//  Display
	cout << "Display a variable:" << endl;
	cout << "    Use display keyword with the syntax:" << endl << endl;
	cout << "        display: [variable1] [variable2] [...]" << endl << endl;
}

#include "namelist.cpp"
/*	Test function
int WIDTH = 12;
#include "namelist.cpp"
int main() {
	/*
	LLIST<double> list;
	list.Append(5.3);
	list.Append(5332.23);
	std::cout << list[0] << list[1];
	//*
	/*	Namelist test**
	int m = 4, n = 6;
	Matrix::MATRIX a(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a.element(i, j) = double(i) + -double(j) + 4;
	NAME_LIST<Matrix::MATRIX> names;
	names.Add("matter", &a);
	names.Save("dete.txt", "HELLO\n");
	//*
	/*
	Interface::INTERFACE interface;
	int end;
	while (interface.active){
		end = interface.Main();
		if (end)
			break;
	}
	//*
	/*
	int m = 1, n = 6;
	Matrix::MATRIX a(m, n);
	Matrix::MATRIX b(m, n);
	Matrix::MATRIX c(m, n);
	Matrix::MATRIX d(n, m);
	Matrix::MATRIX e(m, m);
	Matrix::MATRIX f(m, m);
	//  Fill matrices
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a.element(i, j) = double(i) + -double(j) + 4;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			b.element(i, j) = double(i)*double(i) - double(j);
	c = a + b;
	d = ~b;
	e = -c * d;
	f = (a + b) * ~b;
	///*
	std::cout << a;
	//	e.OutStream(std::cout);
	NAME_LIST<Matrix::MATRIX> nameList;
	nameList.Add("first_matrix", &a);
	nameList.Add("second_matrix", &b);
	nameList.Add("third_matrix", &c);
	nameList.Add("fourth_matrix", &d);
	nameList.Add("fifth_matrix", &e);
	nameList.Add("sixth_matrix", &f);
	nameList.Search("fifth_matrix").element(0, 0) = 74;
	nameList.Remove("fourth_matrix");
	nameList.Save("dex.txt", "#MATRIX");
	//*
	/*
	bool q = true;
	Interface::INTERFACE interface;
	while (q) {
		interface.FetchLineCmd(q);
	}
	//*
	Interface::INTERFACE interface;
	interface.CmdInterface();
	/*
	Interface::INTERFACE interface;
	interface.ExecFile("de.txt");
	//*
	return 0;
}
//*/