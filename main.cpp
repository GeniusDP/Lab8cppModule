#include <iostream>
#include <iomanip>
#include "myMatrixes.h"

using namespace std;

int main() {
    int n, m, p;//size of matrixes
    int** A, ** B, ** C;//our matrixes
    input(&n, &m, &A, 'A');
    makeMatrix(n, m, A);
    printMatrix(n, m, A, 'A');

    WarningMSG();

    input(&m, &p, &B, 'B');
    makeMatrix(m, p, B);
    printMatrix(m, p, B, 'B');

    C = multiplyMatrixes(n, m, p, A, B);
    printMatrix(n, p, C, 'C');

    CLEAN(n, m, A);
    CLEAN(m, p, B);
    CLEAN(n, p, C);
    return 0;
}
