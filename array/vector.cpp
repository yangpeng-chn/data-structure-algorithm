// ref http://stackoverflow.com/questions/5159061/implementation-of-vector-in-c

#include <iostream>
#include <string>
using namespace std;

template <class T>
class CVector{
private:
	T *mp_data;
	size_t m_size;
	size_t m_capacity;
	void resize(size_t capacity);
public:
	CVector();
    CVector(size_t size);
    CVector(size_t size, const T & val);
    CVector(const CVector<T> & obj);   
	~CVector();

	size_t size() const;
	size_t capacity() const;
	bool is_empty() const;
	T & at(size_t idx);
	void push(T val);
	void insert(size_t idx, T val);
	void prepend(T val);
	void Delete(size_t idx);
	void remove(T val);
	T pop();
	int find(T val);
	T & operator[](size_t idx);
	CVector<T> & operator=(const CVector<T> &);
	void print();
};

template <class T>
CVector<T>::CVector(){
	m_size = 0;
	m_capacity = 0;
	mp_data = nullptr;
}

template <class T>
CVector<T>::CVector(size_t size){
	m_size = size;
	m_capacity = size;
	mp_data = new T[size];
}

template<>
CVector<int>::CVector(size_t size){
	cout << "in";
	m_size = size;
	m_capacity = size;
	mp_data = new int[size];
	for (int i = 0; i < m_size; ++i)
	{
		mp_data[i] = 0; //or
		//*(mp_data + i) = 0
	}
}


template <class T>
CVector<T>::CVector(size_t size, const T & val){
	m_size = size;
	m_capacity = size;
	mp_data = new T[size];
	for (int i = 0; i < size; ++i)
	{
		mp_data[i] = val;
	}
}

template <class T>
CVector<T>::CVector(const CVector<T> & obj){
	m_size = obj.size;
	m_capacity = obj.size;
	mp_data = new T[obj.size];
	for (int i = 0; i < m_size; ++i)
	{
		mp_data[i] = obj.mp_data[i];
	}
}

template <class T>
CVector<T>::~CVector(){
	delete []mp_data;
}

template <class T>
size_t CVector<T>::size() const{
	return m_size;
}

template <class T>
size_t CVector<T>::capacity() const{
	return m_capacity;
}

template <class T>
bool CVector<T>::is_empty() const{
	return m_size > 0? false : true;
}

template <class T>
T &CVector<T>::at(size_t idx){ //try, catch for practice
	try {
		if (idx >= m_size){
		   throw "Out of range \n";
		}
	}
	catch (const char* err ) {
		cout << err;
		exit(-1);
	}
	return mp_data[idx]; 
}

template <class T>
void CVector<T>::resize(size_t capacity){
	T *newDataPtr = new T[capacity];
	size_t size = capacity > m_size? m_size : capacity; //select smaller one
	for (int i = 0; i < size; ++i)
	{
		newDataPtr[i] = mp_data[i];
	}
	m_capacity = capacity;
	delete []mp_data;
	mp_data = newDataPtr;
}

template <class T>
void CVector<T>::push(T val){
	if (m_size >= m_capacity) //need create and copy old data
		resize(m_capacity*2);
	mp_data[m_size++] = val;
}

template <class T>
T CVector<T>::pop(){
	if (m_size == 0)
	{
		cout << "Nothing to pop" << endl;
		exit(-1);
	}
	return mp_data[--m_size];
}

template <class T>
void CVector<T>::insert(size_t idx, T val){
	if (idx < 0 || idx >= m_size)
	{
		cout << "Out of bound" << endl;
		exit(-1);
	}
	if (m_size >= m_capacity) //need create and copy old data
		resize(m_capacity*2);
	for (int i = m_size; i > idx; --i)
	{
		mp_data[i] = mp_data[i-1];
	}
	mp_data[idx] = val;
	m_size++;
}

template <class T>
void CVector<T>::prepend(T val){
	insert(0, val);
}

template <class T>
void CVector<T>::Delete(size_t idx){
	if (idx < 0 || idx >= m_size)
	{
		cout << "Out of bound" << endl;
		exit(-1);
	}
	
	for (int i = idx; i < m_size - 1; ++i)
	{
		mp_data[i] = mp_data[i+1];
	}
	m_size--;
}

template <class T>
void CVector<T>::remove(T val){
	for (int i = 0; i < m_size; ++i)
	{
		if (mp_data[i] == val)
		{
			Delete(i);
			i--;
		}
	}
}

template <class T>
int CVector<T>::find(T val){
	for (int i = 0; i < m_size; ++i)
	{
		if(mp_data[i] == val)
			return i;
	}
	return -1;
}

template<class T>
T & CVector<T>::operator[](size_t idx){
	if (idx >= m_size)
	{
		cout << "Out of range" << endl;
		exit(-1);
	}
	return mp_data[idx];
}

template<class T>
CVector<T> & CVector<T>::operator = (const CVector<T> & obj)
{
    delete[] mp_data;
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    mp_data = new T [m_size];
    for (size_t i = 0; i < m_size; i++)
        mp_data[i] = obj.mp_data[i];
    return *this;
}

template <class T>
void CVector<T>::print(){
	for (int i = 0; i < m_size; ++i)
	{
		cout << i << ": " << mp_data[i] << endl;
	}
}

int main(){
	CVector<int> vec(5, 0);
	vec.push(1);
	cout << "size:" << vec.size() << endl;
	cout << "capacity:" << vec.capacity() << endl;
	cout << "at(5):" << vec.at(5) << endl;
	cout << "[5]:" << vec[5] << endl;
	cout << "find 1, idx:" << vec.find(1) << endl;
	CVector<int> vec1;
	vec1 = vec;
	vec1.print();
	vec.Delete(3);
	vec.remove(0);
	vec.print();
	vec.pop();
}