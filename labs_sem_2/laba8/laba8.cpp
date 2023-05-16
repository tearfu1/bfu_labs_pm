#include <iostream>

template <typename T>
struct Stack
{
private:
	T* BP=nullptr;
	T* SP=nullptr;
	int m_size=0;
	int m_maxsize=0;
public:
	Stack(const int& absoluteSize)
	{
		try 
		{
			BP = new T[absoluteSize];
			SP = BP - 1;
			m_maxsize = absoluteSize;
		}
		catch (const std::bad_alloc& e) 
		{
			std::cout << "Allocation failed: " << e.what() << std::endl;
			exit(1);
		}
		
	}
	int size()
	{
		return m_size;
	}
	bool empty()
	{
		return SP == BP-1 || SP==nullptr;
	}
	bool full()
	{
		return m_size == m_maxsize;
	}
	void push(const T& input)
	{
		try
		{
			if (this->full())
			{
				throw "overflow error";
			}
			SP++;
			*SP = input;
			m_size++;
		}
		catch (const char* error) {
			std::cerr << error << std::endl;
			
		}
	}
	T pop()
	{
		try
		{
			if (this->empty())
			{
				throw "out of range";
			}
			T temp = *SP;
			this->SP--;
			this->m_size--;
			return temp;
		}
		catch (const char* error) {
			std::cerr << error << std::endl;
			
		}
	}
	T top()
	{
		try
		{
			if (this->empty())
			{
				throw "logic error";
			}
			return *SP;
		}
		catch (const char* error) {
			std::cerr << error << std::endl;
			exit(4);
		}
	}
	~Stack()
	{
		delete[] BP;
	}
};

int main() {

	Stack <int> stack(2);
	std::cout << stack.size()<<" "<<stack.top() << std::endl;
	int a = stack.pop();
	stack.push(5);
	stack.push(1);
	stack.push(1);
	std::cout << stack.size() << " " << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << " " << stack.top() << std::endl;
	return 0;
}
