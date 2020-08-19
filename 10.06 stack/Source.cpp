#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;
class StackIsEmptyEX : public exception
{
public:
	StackIsEmptyEX(const char* mes) : exception(mes)
	{	}
};
template <class T>
class Stack
{
private:
	int size;
	int topIndex;
	T* arr;
public:
	Stack():size(0), topIndex(0), arr(new T[this->size])
	{	}
	Stack(T size)
	{
		if (size < 0)
		{
			throw invalid_argument("Size is less than 0");
		}
		this->size = size;
		topIndex = this->size - 1;
		arr = new T[this->size];
	}
	void Push(T num)
	{
		if (num == 999)
		{
			throw exception("Number 999 cannot be added");
		}
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = num;
		size = size + 1;
		delete[] arr;
		arr = temp;
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			T* temp = new T[size - 1];
			int a = 0;
			for (int i = 0; i < size; i++)
			{
				if (i != size - 1)
				{
					temp[a] = arr[i];  a++;
				}
			}
			this->size = size - 1;
			this->topIndex = size;
			delete[] arr;
			arr = temp;
		}
		else
		{
			throw StackIsEmptyEX("Stack Empty!!");
		}
	}

	T Peek() const
	{
		if (!IsEmpty())
		{
			return arr[topIndex - 1];
		}
		else
		{
			throw StackIsEmptyEX("Stack empty");
		}
		return 0;
	}
	T GetCount() const
	{
		return topIndex;
	}
	bool IsEmpty() const
	{
		return topIndex == 0;
	}
	bool IsFull() const
	{
		return topIndex == this->size;
	}
	void Print() const
	{
		for (int i = 0; i < size; i++)
		{
			if (i + 1 == size)
			{
				cout << arr[i] << endl;
			}
			else
			{
				cout << arr[i] << ", ";
			}
		}
	}
	~Stack()
	{
		delete[] arr;
	}
};


int main()
{
	Stack<int> st;
	try
	{
		st.Push(12);
		st.Push(999);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Error" << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
		cout << "Error" << endl;
	}


	return 0;
}