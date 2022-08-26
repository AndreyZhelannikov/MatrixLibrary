#include "s21_matrix_oop.h"

void print_line(int n);

int S21Matrix::GetRows() {
    return rows_;
}
int S21Matrix::GetCols() {
    return cols_;
}
void S21Matrix::SetRows(int rows) {
    rows_ = rows;
}
void S21Matrix::SetCols(int cols) {
    cols_ = cols;
}

void S21Matrix::PrintMatrix() {
    using namespace std;
    print_line(cols_);
    for (int i = 0; i < rows_; ++i) {
        cout << "|";
        for (int j = 0; j < cols_; ++j) {
            printf("%8.2lf", matrix_[i][j]);
            if (j != cols_ - 1)
                cout << " ";
        }
        cout << "|\n";
    }
    print_line(cols_);
}

void print_line(int n) {
    int k = n * 9 + 1;
    if (n != 0) {
        for (int i = 0; i < k; i++) {
            printf("-");
        }
        printf("\n");
    }
}
