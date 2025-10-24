#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;
    int matrix[n][n];
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> matrix[i][j];

    cout << "\nDiagonal Matrix (non-zero only on main diagonal):\n";
    int diag[n];
    for(int i=0;i<n;i++)
        diag[i] = matrix[i][i];
    for(int i=0;i<n;i++)
        cout << diag[i] << " ";
    cout << endl;

    cout << "\nTri-diagonal Matrix (elements on main, upper and lower diagonals):\n";
    int tri[3*n - 2];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i==j+1 || i+1==j)
                tri[k++] = matrix[i][j];
        }
    }
    for(int i=0;i<k;i++)
        cout << tri[i] << " ";
    cout << endl;

    cout << "\nLower Triangular Matrix (i >= j):\n";
    int lower[(n*(n+1))/2];
    k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            lower[k++] = matrix[i][j];
    }
    for(int i=0;i<k;i++)
        cout << lower[i] << " ";
    cout << endl;

    cout << "\nUpper Triangular Matrix (i <= j):\n";
    int upper[(n*(n+1))/2];
    k=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            upper[k++] = matrix[i][j];
    }
    for(int i=0;i<k;i++)
        cout << upper[i] << " ";
    cout << endl;

    cout << "\nSymmetric Matrix (store only lower triangle):\n";
    int sym[(n*(n+1))/2];
    k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            sym[k++] = matrix[i][j];
    }
    for(int i=0;i<k;i++)
        cout << sym[i] << " ";
    cout << endl;

    return 0;
}