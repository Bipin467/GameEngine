#pragma once
template <typename T>
struct Array {
private:
	unsigned int m_Size;
	T* m_Value;
public:
	Array(unsigned int size);
	operator T*();
	unsigned int Size();
	~Array();
};

template<typename T>
inline Array<T>::Array(unsigned int size)
	:m_Size(size)
{
	m_Value = new T[size];
}

template<typename T>
Array<T>::operator T*()
{
	return m_Value;
}

template<typename T>
unsigned int Array<T>::Size()
{
	return m_Size;
}

template<typename T>
Array<T>::~Array()
{
	delete m_Value;
}
