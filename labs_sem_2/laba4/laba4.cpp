#include <iostream>
#include <cmath>

template <typename T, int N, int M>
class Matrix 
{
    //T matrix[N][M];
    T all[N * M];
    int n = N;
    int m = M;
public:
    T matrix[N][M];
    Matrix() {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                matrix[i][j] = 0;
                all[cnt] = 0;
                cnt++;
            }
        }
    }
    Matrix(int* number)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                matrix[i][j] = *(number+cnt);
                all[cnt] = *(number + cnt);
                cnt++;
            }
        }
    }
    Matrix(Matrix& other) : Matrix(other.all)
    {
    }
    T Determinant()
        //считает определитель путем суммирования 
        //произведений элементов первой строки на их алгебраические дополнения
    {
        if (this->m != this->n)
        {
            std::cout << "Not equel number of elements in row and string";
            exit(12);
        }
        int i = 0;
        int j = 0;
        int k = 0;
        int p = this->n;
        T sum = 0;
        T tempMult = 1;
        T tempMult2 = 1;
        while (i != this->n)
        {
            tempMult =  pow(-1,i) * this->matrix[0][i];
            if (p - 1 > 0) {
                while (j != (this->n))
                {
                    if (j == i)
                    {
                        if (i == this->n-1) 
                        {
                            break;
                        }
                        j++;
                    }
                    if (p - 2 > 0)
                    {
                        if (k == i|| k ==j)
                        {
                            k++;
                        }
                        if (k == j || k == i)
                        {
                            k++;
                        }
                        tempMult2 = pow((-1),(j > k)) * this->matrix[1][j] * this->matrix[2][k];
                        sum+=tempMult*tempMult2;
                    }
                    else {
                        tempMult *= this->matrix[1][j];
                        sum += tempMult;
                    }
                    k = 0;
                    j++;
                }
            }
            else {
                sum += tempMult;
            }
            j = 0;
            i++;
        }
        return sum;
    }
    Matrix& operator+=(const Matrix& other) 
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j) 
            {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix& other) 
    {
        Matrix temp = *this;
        temp += other;
        return temp;
    }
    Matrix operator*(const Matrix& other)
    {
        if (other.m != this->n)
        {
            std::cout << "Not equel number of elements in row and string";
            exit(13);
        }
        Matrix temp;
        int cnt = 0;
        for(int i = 0; i < N; ++i)
        {
            for (int k = 0; k < other.m; ++k)
            {
                for (int j = 0; j < other.n; ++j)
                {
                    temp.matrix[i][k] += this->matrix[i][j] * other.matrix[j][k];
                    temp.all[cnt] += this->matrix[i][j] * other.matrix[j][k];
                }
                cnt += 1;
            }
        }
        return temp;
    }
    Matrix& operator*=(const Matrix& other)
    {
        Matrix temp;
        temp = *this * other;
        *this = temp;
        return *this;
    }
    Matrix& operator++(int)
    {
        Matrix temp = *this;
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                this->matrix[i][j]++;
                this->all[cnt]++;
            }
            cnt++;
        }
        return temp;
    }
    Matrix& operator++() 
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                this->matrix[i][j]++;
                this->all[cnt]++;
            }
            cnt++;
        }
        return *this;
    }
    T& operator()(int indN, int indM)
    {
        return this->matrix[indN][indM];
    }
};
template <typename T, int N, int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T,N,M>& A)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            out << A.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return out;
}
template <typename T, int N, int M>
std::istream& operator>>(std::istream& in, Matrix<T, N, M>& A)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            in >> A.matrix[i][j];
        }
    }
    return in;
}
int main()
{
    int a[9] = { 1,1,1,1,1,1,1,1,1 };
    int b[4] = { 5,2,3,4 };
    Matrix <int, 3, 3> A(a);
    Matrix <int, 2, 2> B(b);
    std::cout << A;
    std::cout << B;
    Matrix <int, 2, 2> C;
    int det = B.Determinant();
    std::cout << A << det << " "<< B(0, 0);
    return 0;
}