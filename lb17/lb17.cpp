/*6. Сделать реализацию отсортирванного массива sorted_array
с фиксированной capacity (не растет) на шаблонах. При добавлении 
элемента массив остается отсортированным. Для реализации с Point 
использовать перегрузку оператора меньше.
sorted_array(size_t capacity)
push (бросает исключения при превышении capacity)
size
operator[]
at (бросает исключения)
erase(size_t i) (бросает исключения)
*/
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
template <typename T>
class MyArray
{
private:
	T* array;
	//size_t size;
	T capacity;
public:
	MyArray();
	~MyArray();
	MyArray(const MyArray& a);
	MyArray& operator=(const MyArray& v);
	MyArray& operator[](size_t index);
	void sorted_array(size_t capacity);
	void push();
	void at();
	void erase(size_t i);
	void set(T a);
	void get();
};
template <typename T>
MyArray<T>::MyArray() 
{
	//size = 0;
	capacity = 0;
	array = new T[capacity];
	//array[0] = 0;
}

template <typename T>
MyArray<T>::~MyArray()
{
	//array[0] = {};
	delete[] array;
	capacity = 0;
}

template <typename T>
MyArray<T>::MyArray(const MyArray& a)
{
	
	capacity = a.capacity;
	array = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		array[i] = a.array[i];
	}
}

template <typename T>
MyArray<T>& MyArray<T>:: operator=(const MyArray& v)
{
	if (this == v)
	{
		return *this;
	}
	size = v.size;
	capacity = v.capacity;
	array = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		array[i] = v.array[i];
	}
	return *this;
}


template <typename T>
void MyArray<T>::sorted_array(size_t capacity)
{
	int k, j;
	for (int i = 1; i < capacity; i++)
	{
		k = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > k)
		{
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = k;
	}
}

template <typename T>
void MyArray<T>::push()
{
	int b;
	cout << "New element: ";
	cin >> b;


		array[capacity] = b;
		capacity++;

		//cout << "" << a << ","<< L<< x[L-1];
		for (int i = capacity - 1; i > 0; i--)
		{
			int d = array[i - 1];
			array[i - 1] = array[i];
			array[i] = d;
		}
		cout << "Array with added element:";	

		sorted_array(capacity);	
		get();
}

template <typename T>
void MyArray<T>::erase(size_t i)
{
	if (i > capacity || i < 0) 
	{
		at();
	}
	else
	{	
		for (int j = i; j < capacity - 1; j++)		//!!!!
		{
			array[j] = array[j + 1];	
		}
		capacity--;
		get();			
	}
	
}

template <typename T>
void MyArray<T>::at() 
{
	cout << "ERROR";
}

template <typename T>
void MyArray<T>::get()
{
	cout << "\n";
	for (int i = 0; i < capacity; i++)
	{
		cout << " "<< array[i] ;
	}
	cout << endl; cout << endl;
}

template<typename T>
MyArray<T>& MyArray<T>::operator[](size_t index)
{
	return array[index];
}

template <typename T>
void MyArray<T>::set(T a)
{
	array[capacity] = a;
	capacity++;
	sorted_array(capacity);
}

int main()
{
	MyArray <int> d;

	d.set(1);
	d.set(12);
	d.set(4);
	d.set(4);
	d.set(0);
	d.set(-156);

	cout << "\nArray: ";
	d.get();

	d.push();

	int index = 0;
	cout << "index del: ";
	cin >> index;
	
	d.erase(index);
	
	

	return 0;
}