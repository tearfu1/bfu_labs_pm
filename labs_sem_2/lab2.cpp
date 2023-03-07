#include <iostream>
#include <cstring>

class String
{
private:
	size_t m_size;
	char* m_str = nullptr;
private:
	size_t strlen(const char* start)
	{
		const char* end = start;
		for(;*end != '\0';++end);
		return end -start;
	}
public:
	String()=default;

	String(int c, size_t size) = delete;

	String(char c, size_t size) : m_size(size), m_str(new char[size+1])
	{
		std::fill(m_str,m_str+m_size,c);
		m_str[m_size] = 0;
	}
	String(char* str) : m_size(strlen(str)), m_str(new char[m_size])
	{
		std::copy(str,str + m_size,m_str);
		m_str[m_size] = 0;
	}
	String(const String& other) : String(other.m_str) 
	{
	}
	int find(char c)
	{
		for(int i = 0; i < m_size; ++i)
		{
			if (m_str[i] == c) return i;
		}
		return -1;
	}
	String& operator=(String temp)
	{
		std::swap(m_size, temp.m_size);
		std::swap(m_str,temp.m_str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		char* temp_m_str = new char[m_size + str.m_size];
		std::copy(m_str, m_str + m_size, temp_m_str);
		for(int i = 0; i < str.m_size;++i){
			temp_m_str[m_size+i] = str.m_str[i];
		}

		m_size += str.m_size;
		std::swap(m_str,temp_m_str);
		
		return *this;
	}
	String operator+(const String& other)
	{
		String temp = *this;
		temp+=other;
		return temp;
	}
	bool operator < (const String& other)
	{
		return std::strcmp(this->m_str, other.m_str) < 0;
    }

    bool operator > (const String& other) 
	{
		return std::strcmp(this->m_str, other.m_str) > 0;
    }

    bool operator == (const String& other) 
	{
		return std::strcmp(this->m_str, other.m_str) == 0;
    }

	size_t length()
	{
		return m_size;
	}
	char* c_str()
	{
		return m_str;
	}
	char& operator[](int index)
	{
		return m_str[index];
	}
char at(int index)
	{
		if(0 <= index && index < m_size)
		{
			return m_str[index];
		}
		return 0;
	}

	~String()
	{
		if(m_str != nullptr) delete[] m_str;
	}
	friend std::ostream& operator<<(std::ostream& out,const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);
};
	std::ostream& operator<<(std::ostream& out,const String& str)
	{
		for(int i = 0;i < str.m_size + 1; ++i)
		{
			out<<str.m_str[i];
		}
		return out;
		
	}
	std::istream& operator>>(std::istream& in, String& str)
	{
		str.m_size = 1;
		in>>str.m_str;
		while(str.m_str[str.m_size]){
			str.m_size++;
		}
		return in;
	}

int main()
{	
	return 0;
}

