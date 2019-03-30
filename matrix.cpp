#include"matrix.h"

Matrix::MATRIX::MATRIX(){
    m = 0;
    n = 0;
    go = NULL;
}

Matrix::MATRIX::MATRIX(int x, int y){
    m = x;
    n = y;
    go = new double *[m];
    for(int i = 0; i < m; i++){
        go[i] = new double [n];
    }
}

Matrix::MATRIX::MATRIX(int x, int y, double **z){
    m = x;
    n = y;
    go = z;
}

Matrix::MATRIX::MATRIX(const Matrix::MATRIX &b){
    m = b.m;
    n = b.n;
    go = new double *[m];
    for(int i = 0; i < m; i++){
        go[i] = new double [n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            element(i, j) = b.go[i][j];
        }
    }
}

Matrix::MATRIX::~MATRIX(){
    if(go != NULL){
        for(int i = 0; i < m; i++){
            delete []go[i];
        }
        delete []go;
        go = NULL;
    }
}

double &Matrix::MATRIX::element(int i, int j){
    return go[i][j];
}

/*
void Matrix::MATRIX::display(int width){
    if(go != NULL){
        for(int i = 0; i < m; i++){
            std::cout<< std::endl;
            for(int j = 0; j < n; j++){
                std::cout<< std::setw(width)<< element(i, j);
            }
        }
        std::cout<< std::endl<< std::endl;
    }
    else{
        throw("exception: Empty matrix display");
    }
}
//*/

void Matrix::MATRIX::operator= (const Matrix::MATRIX &b){
    /*
     * Code to delete the original matrix.   
    */
    // Create new matrix and assign to it.
    m = b.m;
    n = b.n;
    go = new double *[m];
    for(int i = 0; i < m; i++){
        go[i] = new double [n];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            element(i, j) = b.go[i][j];
        }
    }
}

Matrix::MATRIX Matrix::MATRIX::operator+ (Matrix::MATRIX b){
    MATRIX temp(m, n);
    if(m == b.m && n == b.n){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
            temp.element(i, j) = element(i, j) + b.element(i, j);
            }
        }
        return temp;
    }
    std::cout<< "Addition is not possible"<< std::endl
        << "Addition of matrices of different sizes"<< std::endl;
    return temp;
}

Matrix::MATRIX Matrix::MATRIX::operator- (){
    MATRIX temp(m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp.element(i, j) = -element(i, j);
        }
    }
    return MATRIX(temp);
}

Matrix::MATRIX Matrix::MATRIX::operator* (Matrix::MATRIX b){
    MATRIX temp(m,b.n);
    if(n == b.m){
        for(int i = 0; i < temp.m; i++)
            for(int j = 0; j < temp.n; j++){
                double *sum = new double(0);									//Need double instead of int
                for(int k = 0; k < n; k++)
                    *sum += element(i, k) * b.element(k, j);
                temp.element(i, j) = *sum;
                delete sum;
            }
        return MATRIX(temp);
    }
    std::cout<< "Matrix multiplication is not possible for the given matrices:"<< std::endl
        << m<< " x "<< n<< " & "<< b.m<< " x "<< b.n<< std::endl;
    return temp;
}

Matrix::MATRIX Matrix::MATRIX::operator~ (){
    MATRIX temp(n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            temp.element(i,j) = element(j, i);
        }
    return MATRIX(temp);
}

/*
//std::ostream &
void Matrix::MATRIX::OutStream(std::ostream &out){
    if(go != NULL){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                out<< std::setw(WIDTH)<< go[i][j];
            }
            out<< std::endl;
        }
    }
 //   return out;
    
}
//*/

std::ostream &Matrix::operator<< (std::ostream &out, const Matrix::MATRIX &matrix) {
	if (matrix.go != NULL) {
		for (int i = 0; i < matrix.m; i++) {
			for (int j = 0; j < matrix.n; j++) {
				out << std::setw(WIDTH) << matrix.go[i][j];
			}
			out << std::endl;
		}
	}
	else {
		//throw("exception: Empty matrix display");
	}
	return out;
}

/*
Matrix::MATRIX::operator double(){
	//	Calculate determinant of matrix
    std::cout<< "MATRIX to basic typecast operator is a WIP"<< std::endl;
    
}
//*/
