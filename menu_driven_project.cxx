/*This C++ program uses templates and operator overloading 
to perform operations on Complex numbers, Sets, Arrays, and 
Matrices with different data types. It provides a menu-driven
 interface for arithmetic, searching, set operations, and 
 matrix operations.*/
/*
===== MAIN MENU =====
1.Complex
2.Set
3.Array
4.Matrix
5.Exit
Enter choice: 1

Enter data type (like int, double, float): int
Enter number of operands (max 4): 2

Enter complex number 1:
Enter real and imaginary: 2 3
Enter complex number 2:
Enter real and imaginary: 4 5

Operand 1: 2 + 3i
Operand 2: 4 + 5i

1.Add 2.Subtract 3.Multiply 4.Divide 5.Modulus
enter operation: 1

Result: 6 + 8i*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
class Complex {
public:
    T real, imag;

    friend istream& operator>>(istream &in, Complex<T> &c) {
    cout << "Enter real and imaginary: ";
    in >> c.real >> c.imag;
    return in;
}

friend ostream& operator<<(ostream &out, const Complex<T> &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}


    Complex(T r=0, T i=0) : real(r), imag(i) {}
    
    Complex operator+(Complex<T> c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex<T> c ) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(Complex<T> c) const {
        return Complex(real*c.real - imag*c.imag,
                       real*c.imag + imag*c.real);
    }

    Complex operator/(Complex<T> c) const {
        T denom = c.real*c.real + c.imag*c.imag;
        return Complex((real*c.real + imag*c.imag)/denom,
                       (imag*c.real - real*c.imag)/denom);
    }
   
    double modulus() const {
        return sqrt(real*real + imag*imag);
    }
};



template <typename T>
class ComplexManager {
public:
    void perform() {
        int n, op;
        cout << "Enter number of operands (max 4): ";
        cin >> n;

        if(n < 1 || n > 4) {
            cout << "Invalid input!\n";
            return;
        }

        vector<Complex<T>> operands;
        operands.resize(n);
        for(int i = 0; i < n; i++) {
            cout << "Enter complex number " << (i + 1) << ":\n";
            cin >> operands[i];
        }

        // Display operands for reference
        for(int i = 0; i < n; i++) {
            cout << "Operand " << (i + 1) << ": " << operands[i] << endl;
        }

        cout << "1.Add 2.Subtract 3.Multiply 4.Divide 5.Modulus\nenter operation: ";
        cin >> op;

        if(op == 5) {
            for(int i = 0; i < n; i++) {
                cout << "Modulus of operand " << (i + 1) << ": " << operands[i].modulus() << endl;
            }
            return;
        }

        Complex<T> result = operands[0];
        for(int i = 1; i < n; i++) {
            if(op == 1) result = result + operands[i];
            else if(op == 2) result = result - operands[i];
            else if(op == 3) result = result * operands[i];
            else if(op == 4) result = result / operands[i];
        }
        cout << "Result: " << result << endl;
    }
};

void runComplexMenu() {
    string o;
    cout << "Enter data type (like int, double, float): ";
    cin >> o;

    if(o == "int") {
        ComplexManager<int>().perform();
    } else if(o == "float") {
        ComplexManager<float>().perform();
    } else if(o == "double") {
        ComplexManager<double>().perform();
    } else {
        cout << "Unsupported type: " << o << "\n";
    }
}

template <typename T>
class Matrix {
public:
    int r, c;
    vector<vector<T>> A;

    Matrix(int rows = 0, int cols = 0) : r(rows), c(cols), A(rows   , vector<T>(cols)) {}
    void inputDimensions() {
        cout << "Enter rows and cols: ";
        cin >> r >> c;
        A = vector<vector<T>>(r, vector<T>(c));
    }

    friend istream& operator>>(istream &in, Matrix<T> &m) {
    
        cout << "Enter elements:\n";
        for(int i = 0; i < m.r; i++) {
            for(int j = 0; j < m.c; j++)
                in >> m.A[i][j];
        }
        return in;
    }

    friend ostream& operator<<(ostream &out, const Matrix<T> &m) {
        for(int i = 0; i < m.r; i++) {
            for(int j = 0; j < m.c; j++)
                out << m.A[i][j] << " ";
            out << '\n';
        }
        return out;
    }

    Matrix<T> operator+(const Matrix<T> &m) const {
        if(r != m.r || c != m.c) {
            cout << "Error: Cannot add matrices with different dimensions!\n";
            cout << "Matrix 1: " << r << "x" << c << ", Matrix 2: " << m.r << "x" << m.c << "\n";
            return Matrix<T>();
        }
        Matrix<T> result(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                result.A[i][j] = A[i][j] + m.A[i][j];   
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T> &m) const {
        if(r != m.r || c != m.c) {
            cout << "Error: Cannot subtract matrices with different dimensions!\n";
            cout << "Matrix 1: " << r << "x" << c << ", Matrix 2: " << m.r << "x" << m.c << "\n";
            return Matrix<T>();
        }
        Matrix<T> result(r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                result.A[i][j] = A[i][j] - m.A[i][j];
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &m) const {
        if(c != m.r) {
            cout << "Error: Cannot multiply matrices! Columns of Matrix 1 must equal rows of Matrix 2.\n";
            cout << "Matrix 1: " << r << "x" << c << ", Matrix 2: " << m.r << "x" << m.c << "\n";
            return Matrix<T>();
        }
        Matrix<T> result(r, m.c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < m.c; j++) {
                result.A[i][j] = T();
                for(int k = 0; k < c; k++)
                    result.A[i][j] += A[i][k] * m.A[k][j];
            }
        }
        return result;
    }

    Matrix<T> operator!() const {
        Matrix<T> result(c, r);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++)
                result.A[j][i] = A[i][j];
        }
        return result;
    }
};

// 🔹 Matrix Manager
template <typename T>
class MatrixManager {
public:
    bool perform() {
        int n;
        cout<<"enter the number of matrices to perform operations on (max 3): ";
        cin >> n;
        if(n < 1 || n > 3) {
            cout << "Invalid input!\n";
            return false;         
        }
        Matrix<T> result, temp;
        cout << "Enter first matrix number:\n";
        result.inputDimensions();
        cin >> result;

        // Display first matrix for reference
        cout << "First matrix:\n" << result << endl;

        cout << "1.Add 2.Sub 3.Mul 4.Transpose\nenter the operation to perform: ";
        int op; cin >> op;
        if(op == 4) {
            Matrix<T> transposed = !result;
            cout << "Transpose:\n" << transposed << endl;
            return true;
        }

        for(int i = 2; i <= n; i++) {
            cout << "Enter next matrix number:\n";
            temp.inputDimensions();
            cin >> temp;

            // Display next matrix for reference
            cout << "Matrix " << i << ":\n" << temp << endl;

            if(op == 1 || op == 2) {
                if(result.r != temp.r || result.c != temp.c) {
                    cout << "Error: Matrix dimensions must match for addition/subtraction.\n";
                    return false;
                }
            } else if(op == 3) {
                if(result.c != temp.r) {
                    cout << "Error: Matrix 1 columns must equal Matrix 2 rows for multiplication.\n";
                    return false;
                }
            }

            if(op == 1) {
                result = result + temp;
            } else if(op == 2) {
                result = result - temp;
            } else if(op == 3) {
                result = result * temp;
            }
        }

        cout << "Result:\n" << result << endl;
        return true;
    }
};

void runMatrixMenu() {
    string o;
    cout << "Enter matrix data type (int, float, double): ";
    cin >> o;

    if(o == "int") {
        MatrixManager<int>().perform();
    } else if(o == "float") {
        MatrixManager<float>().perform();
    } else if(o == "double") {
        MatrixManager<double>().perform();
    } else {
        cout << "Unsupported type: " << o << "\n";
    }
}

template <typename T>
class SetManager {
    vector<vector<T>> sets;

    bool contains(const vector<T> &s, const T &value) const {
        for(const T &x : s)
            if(x == value) return true;
        return false;
    }

    void insertUnique(vector<T> &s, const T &value) const {
        if(!contains(s, value))
            s.push_back(value);
    }

    void inputSet(vector<T> &s, int index) {
        int n;
        cout << "Enter size of set " << index << ": ";
        cin >> n;

        cout << "Enter elements:\n";
        for(int i = 0; i < n; i++) {
            T x;
            cin >> x;
            insertUnique(s, x);
        }
    }

    vector<T> unionSets(const vector<T> &a, const vector<T> &b) const {
        vector<T> result = a;
        for(const T &x : b)
            if(!contains(result, x))
                result.push_back(x);
        return result;
    }

    vector<T> intersectionSets(const vector<T> &a, const vector<T> &b) const {
        vector<T> result;
        for(const T &x : a)
            if(contains(b, x))
                insertUnique(result, x);
        return result;
    }

    vector<T> differenceSets(const vector<T> &a, const vector<T> &b) const {
        vector<T> result;
        for(const T &x : a)
            if(!contains(b, x))
                insertUnique(result, x);
        return result;
    }

public:
    void perform() {
        int n = 2;
        sets.assign(n, vector<T>());
        for(int i = 0; i < n; i++)
            inputSet(sets[i], i + 1);

        // Display sets for reference
        cout << "Set 1: ";
        for(const T &x : sets[0])
            cout << x << " ";
        cout << endl;

        cout << "Set 2: ";
        for(const T &x : sets[1])
            cout << x << " ";
        cout << endl;

        cout << "1.Union 2.Intersection 3.Difference\nenter the operation to perform: ";
        int op;
        cin >> op;
        if(op < 1 || op > 3) {
            cout << "Invalid operation!\n";
            return;
        }

        vector<T> result = sets[0];
        for(int i = 1; i < n; i++) {
            if(op == 1)
                result = unionSets(result, sets[i]);
            else if(op == 2)
                result = intersectionSets(result, sets[i]);
            else
                result = differenceSets(result, sets[i]);
        }

        cout << "Result: ";
        for(const T &x : result)
            cout << x << " ";
        cout << endl;
    }
};

void runSetMenu() {
    string o;
    cout << "Enter set data type (int, float, double): ";
    cin >> o;

    if(o == "int") {
        SetManager<int>().perform();
    } else if(o == "float") {
        SetManager<float>().perform();
    } else if(o == "double") {
        SetManager<double>().perform();
    } else {
        cout << "Unsupported type: " << o << "\n";
    }
}
// 🔹 Template Array Manager
template <typename T>
class ArrayManager {
    vector<T> a, b;
public:
    ArrayManager(int n = 0) {
        a.resize(n);
        b.resize(n);
    }

    void input(int n) {
        a.resize(n);
        b.resize(n);

        cout << "Enter first array:\n";
        for(int i=0;i<n;i++) cin >> a[i];

        cout << "Enter second array:\n";
        for(int i=0;i<n;i++) cin >> b[i];
    }

    void add() {
        cout << "Sum: ";
        for(int i=0;i<a.size();i++)
            cout << a[i] + b[i] << " ";
        cout << endl;
    }

    void search() {
        T key;
        cout << "Enter element to search: ";
        cin >> key;

        for(T x:a) {
            if(x==key) {
                cout << "Found\n";
                return;
            }
        }
        cout << "Not Found\n";
    }

    void indexAccess() {
        int arr_choice;
        cout << "Which array (1 or 2)? ";
        cin >> arr_choice;

        if(arr_choice != 1 && arr_choice != 2) {
            cout << "Invalid choice!\n";
            return;
        }

        int idx;
        cout << "Enter index: ";
        cin >> idx;

        const vector<T>& arr = (arr_choice == 1) ? a : b;
        if(idx >= 0 && idx < arr.size()) {
            cout << "Value: " << arr[idx] << endl;
        } else {
            cout << "Invalid index!\n";
        }
    }

    void perform() {
        int n;
        cout << "Enter size: ";
        cin >> n;

        input(n);

        // Display arrays for reference
        cout << "Array 1: ";
        for(const T &x : a)
            cout << x << " ";
        cout << endl;

        cout << "Array 2: ";
        for(const T &x : b)
            cout << x << " ";
        cout << endl;

        cout << "1.Add 2.Search 3.Index access\nenter operation: ";
        int op;
        cin >> op;

        if(op == 1) {
            add();
        } else if(op == 2) {
            search();
        } else if(op == 3) {
            indexAccess();
        } else {
            cout << "Invalid operation!\n";
        }
    }
};

void runArrayMenu() {
    string o;
    cout << "Enter array data type (int, float, double): ";
    cin >> o;

    if(o == "int") {
        ArrayManager<int>().perform();
    } else if(o == "float") {
        ArrayManager<float>().perform();
    } else if(o == "double") {
        ArrayManager<double>().perform();
    } else {
        cout << "Unsupported type: " << o << "\n";
    }
}
int main() {
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1.Complex\n2.Set\n3.Array\n4.Matrix\n5.Exit\n";
        cout << "Enter choice: ";       cin >> choice;                      
        switch(choice) {
            case 1: runComplexMenu(); break;
            case 2: runSetMenu(); break;
            case 3: runArrayMenu(); break;
            case 4: runMatrixMenu(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);
    return 0;
}