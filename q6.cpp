#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

void display(Term a[]) {
    int n = a[0].val;
    cout << "Row Col Val\n";
    for(int i=1;i<=n;i++)
        cout << a[i].row << "   " << a[i].col << "   " << a[i].val << endl;
}

void transpose(Term a[], Term b[]) {
    int n = a[0].val, k = 1;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;
    for(int i=0;i<a[0].col;i++) {
        for(int j=1;j<=n;j++) {
            if(a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

void add(Term a[], Term b[], Term c[]) {
    if(a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n";
        return;
    }
    int n1=a[0].val, n2=b[0].val, i=1, j=1, k=1;
    c[0].row=a[0].row;
    c[0].col=a[0].col;
    while(i<=n1 && j<=n2) {
        if(a[i].row==b[j].row && a[i].col==b[j].col) {
            c[k].row=a[i].row;
            c[k].col=a[i].col;
            c[k].val=a[i].val+b[j].val;
            i++; j++; k++;
        } else if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col))
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<=n1) c[k++]=a[i++];
    while(j<=n2) c[k++]=b[j++];
    c[0].val=k-1;
}

void multiply(Term a[], Term b[], Term c[]) {
    if(a[0].col != b[0].row) {
        cout << "Multiplication not possible\n";
        return;
    }
    Term bt[100];
    transpose(b, bt);
    int k=1;
    c[0].row=a[0].row;
    c[0].col=b[0].col;
    for(int i=1;i<=a[0].row;i++) {
        for(int j=1;j<=b[0].col;j++) {
            int sum=0;
            for(int x=1;x<=a[0].val;x++) {
                if(a[x].row==i) {
                    for(int y=1;y<=bt[0].val;y++) {
                        if(bt[y].row==j && bt[y].col==a[x].col)
                            sum+=a[x].val*bt[y].val;
                    }
                }
            }
            if(sum!=0) {
                c[k].row=i;
                c[k].col=j;
                c[k].val=sum;
                k++;
            }
        }
    }
    c[0].val=k-1;
}

int main() {
    Term a[100], b[100], c[100];
    int r, col, n;
    cout << "Enter rows, cols, non-zero elements for A: ";
    cin >> r >> col >> n;
    a[0].row=r; a[0].col=col; a[0].val=n;
    for(int i=1;i<=n;i++) cin >> a[i].row >> a[i].col >> a[i].val;

    cout << "Enter rows, cols, non-zero elements for B: ";
    cin >> r >> col >> n;
    b[0].row=r; b[0].col=col; b[0].val=n;
    for(int i=1;i<=n;i++) cin >> b[i].row >> b[i].col >> b[i].val;

    cout << "\nMatrix A:\n"; display(a);
    cout << "\nMatrix B:\n"; display(b);

    Term t[100];
    transpose(a, t);
    cout << "\nTranspose of A:\n"; display(t);

    add(a, b, c);
    cout << "\nA + B:\n"; display(c);

    multiply(a, b, c);
    cout << "\nA * B:\n"; display(c);

    return 0;
}