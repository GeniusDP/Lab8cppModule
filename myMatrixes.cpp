#include <iostream>
#include <iomanip>

using namespace std;

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


//#####################################################################
//#####################################################################

void makeMatrix(int rows, int cols, int** matr) {
    int cnt = 0, di, dj, i, j;
    //making "buffer"
    for (i = 0; i < rows + 2; i++)
        for (j = 0; j < cols + 2; j++)
            matr[i][j] = -1;
    for (i = 1; i <= rows; i++)
        for (j = 1; j <= cols; j++)
            matr[i][j] = 0;

    matr[1][1] = 1;
    i = 1;//current pos
    j = 1;//current pos
    cnt = 1;
    di = 1, dj = -1;//direction
    while (cnt < rows * cols) {
        if (matr[i + di][j + dj] == 0) {
            i += di;
            j += dj;
            matr[i][j] = ++cnt;
        }
        else {
            di = -di;
            dj = -dj;
            //********************
            if (j == 1) {
                //left boarder
                if (matr[i + 1][j] == 0) {//down
                    i++;
                    matr[i][j] = ++cnt;
                }
                else {//right
                    j++;
                    matr[i][j] = ++cnt;
                }
            }
            else if (i == rows) {
                //bottom boarder
                j++;
                matr[i][j] = ++cnt;
            }
            //********************
            else if (j == cols) {
                //right boarder
                i++;
                matr[i][j] = ++cnt;
            }
            //********************
            else if (i == 1) {
                //left boarder
                if (matr[i][j + 1] == 0) {//down
                    j++;
                    matr[i][j] = ++cnt;
                }
                else {//right
                    i++;
                    matr[i][j] = ++cnt;
                }
            }
            //********************
        }
    }
}

//#####################################################################
//#####################################################################

void input(int* rows, int* cols, int*** matr, char nameOfMatrix) {
    cout << "Type in rows and cols of matrix " << nameOfMatrix << " :" << endl;
    cin >> *rows >> *cols;
    (*matr) = new int* [2 + *rows];
    for (int i = 0; i < 2 + *rows; i++)
        (*matr)[i] = new int[2 + *cols];
}

//#####################################################################
//#####################################################################

void printMatrix(int rows, int cols, int** matr, char nameOfMatr) {
    cout << "\nThis is matrix " << nameOfMatr << " :" << endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++)
            cout << setw(5) << matr[i][j];
        cout << endl;
    }
}

//#####################################################################
//#####################################################################

void WarningMSG() {
    cout << "\n\nPay attention!" << endl;
    cout << "If A has got size (n x m) B should be (m x p)." << endl;
    cout << "Otherwise program will not work corectly!!!\n\n" << endl;
}

//#####################################################################
//#####################################################################

int** multiplyMatrixes(int n, int m, int p, int** A, int** B) {
    int** result = new int* [2 + n];
    for (int i = 0; i < 2 + n; i++) {
        result[i] = new int[2 + p];
    }

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            cur = 0;
            for (int k = 1; k <= m; k++) {
                cur += A[i][k] * B[k][j];
            }
            result[i][j] = cur;
        }
    }
    return result;
}

//#####################################################################
//#####################################################################

void CLEAN(int rows, int cols, int** matr) {
    for (int i = 0; i < 2 + rows; i++)
        delete[] matr[i];
    delete[] matr;
}

//#####################################################################
//#####################################################################


