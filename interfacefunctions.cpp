#include "interface.h"
#include "namelist.cpp"

void Interface::INTERFACE::Assi_init_base() {
	//	Initialization:
	/*
	Matrix::MATRIX mat(4, 4);
	int r, c;
	//std::string::size_type sz;
	//std::string line;
	//	Loop to input the matrix by using a string to double conversion function
	//*	**Test**
	static double xd = 4;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			mat.element(i, j) = double(i) + -double(j) + xd;
	xd = 8;
	//*
	if (cmdMode) {
		std::string temp = tokenStream[0];
		tokenStream.Delete();
		std::getline(std::cin, inputStream);
		Tokenizer(inputStream);
		r = std::stoi(tokenStream[0]);
		c = std::stoi(tokenStream[1]);
		tokenStream.Delete();
		Matrix::MATRIX matrix(r, c);
		for (int i = 0; i < r; i++) {
			std::getline(std::cin, inputStream);
			Tokenizer(inputStream);
			for (int j = 0; j < c; j++) {
				matrix.element(i, j) = std::stod(tokenStream[j]);
			}
			tokenStream.Delete();
		}
		//matrix.display(15);
		tempMatrix = new Matrix::MATRIX;
		*tempMatrix = matrix;
		dataList.Search(temp) = tempMatrix;
		return;
	}
	/*
	bool jump = false;
	int i = 0, j;
	while (!jump) {
		j = 0;
		FetchLine();
		//	Check if value string:
		while (tokenStream.ListEnd(j)){
			try{
				//	Insert values in each entry:
				//* ****** =/ std::stod(tokenStream[j]);
				//throw std::invalid_argument("Broke<>");

			}
			catch (const std::invalid_argument&  ia){
				jump = true;
				//	std::cout << ia.what();
			}
			++j;
		}
		++i;
	}
	//*
	tempMatrix = new Matrix::MATRIX;
	*tempMatrix = mat;
	dataList.Search(tokenStream[0]) = tempMatrix;
	/*	dataList.OutStream(std::cout);
		dataList.Save("data.txt", "#DATA LIST");
		FetchLine();
		tokenStream.Save("data.txt", "#TOKEN LIST");
		//*/
		//	Initialization:
	int r, c;
	std::string temp = tokenStream[0];
	//*
	tokenStream.Delete();
	if(cmdMode)
		std::getline(std::cin, inputStream);
	else
		std::getline(file, inputStream);
	//CleanStream();
	Tokenizer(inputStream);
	//*/
	r = std::stoi(tokenStream[0]);
	c = std::stoi(tokenStream[1]);
	if (save)
		lineStream.Add(inputStream + '\n');
	tokenStream.Delete();
	Matrix::MATRIX matrix(r, c);
		for (int i = 0; i < r; i++) {
			if (cmdMode)
				std::getline(std::cin, inputStream);
			else
				std::getline(file, inputStream);
			Tokenizer(inputStream);
			for (int j = 0; j < c; j++) {
				matrix.element(i, j) = std::stod(tokenStream[j]);
			}
			if (save)
				lineStream.Add(inputStream + '\n');
			tokenStream.Delete();
		}
		tempMatrix = new Matrix::MATRIX;
		*tempMatrix = matrix;
		dataList.Search(temp) = tempMatrix;
		return;
}

void Interface::INTERFACE::Assi_init_base_dimension() {
	//	Initialization:
	int r, c;
	std::string temp = tokenStream[0];
	/*
	tokenStream.Delete();
	std::getline(std::cin, inputStream);
	Tokenizer(inputStream);
	//*/
	r = std::stoi(tokenStream[1]);
	c = std::stoi(tokenStream[2]);
	tokenStream.Delete();
	Matrix::MATRIX matrix(r, c);
	for (int i = 0; i < r; i++) {
		if (cmdMode)
			std::getline(std::cin, inputStream);
		else
			std::getline(file, inputStream);
		Tokenizer(inputStream);
		for (int j = 0; j < c; j++) {
			matrix.element(i, j) = std::stod(tokenStream[j]);
		}
		if (save)
			lineStream.Add(inputStream + '\n');
		tokenStream.Delete();
	}
	tempMatrix = new Matrix::MATRIX;
	*tempMatrix = matrix;
	dataList.Search(temp) = tempMatrix;
	return;
}

/*
void Interface::INTERFACE::Assi_init_base() {
	//	Initialization:
	Matrix::MATRIX mat(6, 6);
	//	Loop to input the matrix by using a string to double conversion function
	//*	**Test**
	static double xd = 4;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			mat.element(i, j) = double(i) + -double(j) + xd;
	xd = 8;
	tempMatrix = new Matrix::MATRIX;
	*tempMatrix = mat;
	dataList.Search(tokenStream[0]) = tempMatrix;
}
//*/

void Interface::INTERFACE::Assi_expr_base() {

}

void Interface::INTERFACE::Decl_matrix_base() {
	int i = 1;	// token list must be of form "matrix x x x" so it must have more than one word
	while (!tokenStream.ListEnd(i)) {
		//*
		if (!CheckIdentifier(tokenStream[i])) {
			//error: invalid name for identifier
			i++;
			continue;
		}
		//*/
		//*
		dataList.Search(tokenStream[i]);
		if (dataList.found) {
			i++;
			continue;
		}
		//*/
		dataList.Add(tokenStream[i], NULL);
		i++;
	}
	
	if (i == 1) {
		//	exception: invalid line
	}
}

void Interface::INTERFACE::Decl_vector_base() {

}

void Interface::INTERFACE::Decl_auto_base() {

}

void Interface::INTERFACE::Spec_display_base() {
	if (tokenStream[1] == "**") {
		dataList.OutStream(std::cout);
		return;
	}
	else if (tokenStream[1] == "*") {
		dataList.OutStream(std::cout, false);
		return;
	}
	int i = 1;
	while (!tokenStream.ListEnd(i)) {
		std::cout << tokenStream[i] << std::endl
		<< *dataList.Search(tokenStream[i]) << std::endl;
		i++;
	}
}
