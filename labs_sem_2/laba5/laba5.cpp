#include <iostream>


template<typename T>
class vector
{
public:
    vector()
    {
        std::cout << "non bool";
    }
};
template<>
class vector<bool>
{
private:
    int m_cap = 8;//capacity
    int m_size = 0;//size
    int char_amount = 0;
    unsigned char* vec = new unsigned char[1];//dynamic massive
    
    void normSize(const int& sizeVec)
    {
        char_amount = ((sizeVec-1) / 8.f)+1;
        int minim = (sizeVec < m_size) * sizeVec + (sizeVec > m_size) * m_size;
        if ((sizeVec-1)/8 > (m_size-1)/8)
        {
            m_cap = char_amount + 8;
            unsigned char* temp = vec;
            vec = new unsigned char[char_amount];
            for (int i = 0; i < char_amount; ++i)
            {
                vec[i] = 0;
            }
            for (int i = 0; i < ceil(minim / 8.f); ++i)
            {
                vec[i] = temp[i];
            }
            delete[] temp;
        }
    }
    int outOfBounds(int index)
    {
        if (index >= m_size) {
            std::cout << "Error: Index is out of bounds";
            exit(EXIT_FAILURE);
        }
        return EXIT_SUCCESS;
    }
public:
    vector(const int& size, int* num = nullptr)
    {
        normSize(size);
        m_size = size;
        if (num == nullptr)
        {

        }
        else
        {
            int cnt = 0;
            int temp = 0;
            for (int i = 0; i < char_amount; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    temp = *(num + cnt) << j;
                    vec[i] = vec[i] | temp;
                    if (cnt == m_size - 1) {
                        break;
                    }
                    cnt++;
                }
            }
        }

    }
    void push_back(const bool& value)
    {
        normSize(m_size + 1);
        int tempPos = m_size % 8;
        m_size++;
        vec[char_amount - 1] |= value << (tempPos);
    }
    void indexChange(int index,int value)
    {
        outOfBounds(index);
        int tempPos = index % 8;
        value <<= tempPos;

        unsigned char toLeft = vec[index / 8];
        toLeft <<= (8-tempPos);
        toLeft >>= (8-tempPos);
        toLeft |= value;

        unsigned char toRight = vec[index / 8];
        toRight >>= (tempPos + 1);
        toRight <<= (tempPos + 1);
        toRight |= value;

        vec[index / 8] = toLeft | toRight;
    }
    void erase(const int& index)
    {
        outOfBounds(index);
        int tempPos = index % 8;

        unsigned char toRight = vec[index / 8];
        toRight >>= tempPos+1;
        toRight <<= tempPos;
        if (char_amount > vec[index / 8]) {
            int temp_last = vec[(index / 8) + 1] & 1;
            toRight |= temp_last << 7;
        }

        unsigned char toLeft = vec[index / 8];
        toLeft <<= (8 - tempPos);
        toLeft >>= (8 - tempPos);

        vec[index / 8] = toRight | toLeft;

        for (int i = 1; i < char_amount - (index / 8); ++i)
        {
            vec[(index / 8) + i] >>= 1;
            int temp = vec[(index / 8) + 1+i] & 1;
            vec[(index / 8) + i] |= temp << 7;
        }
        normSize(m_size - 1);
        m_size--;
    }
    void insert(const int& index, int value)
    {
        outOfBounds(index);
        normSize(m_size + 1);
        m_size++;
        for (int i = 1; i < char_amount - (index / 8); ++i)
        {
            vec[char_amount - i] <<= 1;
            int temp = (vec[char_amount - i - 1] & 128)>>7;
            vec[char_amount - i] |= temp;
        }

        int tempPos = index % 8;
        value <<= tempPos;
        
        unsigned char toRight = vec[index / 8];
        toRight >>= tempPos;
        toRight <<= (tempPos + 1);
        toRight |= value;
        
        unsigned char toLeft = vec[index / 8];
        toLeft <<= (8 - tempPos);
        toLeft >>= (8 - tempPos);
        toLeft |= value;

        vec[index / 8] = toRight | toLeft;
    }
    void print()
    {
        int cnt = 0;
        for (int i = 0; i < char_amount; ++i)
        {
            int temp = 1;
            while (true) {
                cnt++;
                if (vec[i] & temp) {
                    std::cout << "1";
                }
                else {
                    std::cout << "0";
                }
                if (temp == 128) {
                    std::cout << std::endl;
                    break;
                }
                if (cnt == m_size)
                {
                    break;
                }

                temp <<= 1;
            }
        }
    }
    int& size()
    {
        return m_size;
    }
    bool operator[](int index)
    {
        outOfBounds(index);
        int tempPos = index % 8;
        return (vec[index / 8] & (1 << tempPos)) >> tempPos;
    }
    ~vector() {
        delete[] vec;
    };
};


int main()
{
    int b[20] = { 1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1 };
    vector <bool> a(8, b);
    a.push_back(0);
    a.indexChange(1, 0);
    a.print();
    std::cout << a.size() << std::endl;
    //a.insert(2, 0);
    a.erase(8);
    std::cout << a.size() << std::endl;
    a.print();
    return 0;
}
