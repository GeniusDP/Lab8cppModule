//make matrix int form of snake(diagonals)
void makeMatrix(int rows, int cols, int** matr);

//input matrixes
void input(int* rows, int* cols, int*** matr, char nameOfMatrix);

//print the matrix
void printMatrix(int rows, int cols, int** matr, char nameOfMatr);

//warning
void WarningMSG();

//to multiply 2 matrixes A(n x m), B(m x p);
int** multiplyMatrixes(int n, int m, int p, int** A, int** B);

//to delete matrxi from the heap
void CLEAN(int rows, int cols, int** matr);

