#include <iostream>

class newV{
    private:
    //variables
    int m_memSize = 8;//memory size
    int m_currLen = 0;//elements in vector
    int* vec = new int[m_memSize];//dynamic massive
    //functions
    //change size
    void normSize(int sizeVec){
        while (sizeVec > m_memSize){
            m_memSize *= 2;
            int* temp = vec;
            vec = new int[m_memSize];
            for (int i = 0; i < m_currLen; ++i){
                vec[i] = temp[i];
            }
            delete[] temp;
        }
    }
    int outOfBounds(int index){
        if (index >= m_currLen){
            std::cout << "Error: Index is out of bounds";
            exit(EXIT_FAILURE);
        }
        return EXIT_SUCCESS;
    }
    public:
    newV(int sizeVec){
        normSize(sizeVec);
        m_currLen = sizeVec;
        for (int i = 0; i < m_currLen;++i){
        vec[i] =0;
        }
    }
    //1. add to end
    bool push_back(int userElem){
        normSize(m_currLen+1);
        vec[m_currLen] = userElem;
        m_currLen++;
    }
    //2. return vector size
    int size(){
        return m_currLen;
    }
    //3. return value by index
    int indexValue(int userIndex){
        outOfBounds(userIndex);
        return vec[userIndex];
    }
    //4. change value by index
    void indexChange(int userIndex, int userElem){
        outOfBounds(userIndex);
        vec[userIndex] = userElem;
    }
    //5. delete elem by index
    void indexDelete(int userIndex){
        outOfBounds(userIndex);
        int* temp = vec;
        vec = new int[m_memSize];
        for(int i = 0; i < m_currLen - 1; ++i){
            if(i < userIndex){
                vec[i] = temp[i];
            }
            else{
                vec[i] = temp[i+1];
            }
        }
        delete[] temp;
        m_currLen--;
    }
    //6. input element by index
    void indexInput(int userIndex,int userValue){
        outOfBounds(userIndex);
        m_currLen++;
        normSize(m_currLen);
        int* temp = vec;
        vec = new int[m_memSize];
        for(int i = 0; i < m_currLen; ++i){
            if(i < userIndex){
                vec[i] = temp[i];
            }
            else if(i == userIndex){
                vec[i] = userValue;
            }
            else{
                vec[i] = temp[i-1];
            }
        }
        delete[] temp;
    }
    ~newV(){
        delete[] vec;
    };
};

int main(){
    newV myVector = 8;
    //test value by index
    for(int i = 0;i < myVector.size();++i){
        myVector.indexChange(i,i);
    }
    for(int i = 0;i < myVector.size();++i){
        std::cout << myVector.indexValue(i) << " ";
    }
    std::cout << "| " << myVector.size() <<std::endl;
    //test change value by index
    myVector.indexChange(3,10);
    for(int i = 0;i < myVector.size();++i){
        std::cout << myVector.indexValue(i) << " ";
    }
    std::cout << "| " << myVector.size() <<std::endl;
    //test delete value by index
    myVector.indexDelete(3);
    for(int i = 0;i < myVector.size();++i){
        std::cout << myVector.indexValue(i) << " ";
    }
    std::cout << "| " << myVector.size() <<std::endl;
    //test input element by index
    myVector.indexInput(3,123);
    for(int i = 0;i < myVector.size();++i){
        std::cout << myVector.indexValue(i) << " ";
    }
    std::cout << "| " << myVector.size() <<std::endl;
    //test add element to add;
    myVector.push_back(10);
    for(int i = 0;i < myVector.size();++i){
        std::cout << myVector.indexValue(i) << " ";
    }
    std::cout << "| " << myVector.size() <<std::endl;
    return 0;
}
