#pragma once
#include <iostream>
#include <cstdio>
template<class T>
size_t BinSearch(T* arr, const size_t size, const T& key)
{
	if (!arr) return 0;
	int l = 0, mid, r = size - 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (key < arr[mid]) r = mid - 1;
		else if (key > arr[mid]) l = mid + 1;
		else return mid;		
	}
	return l;
}

template<class T>
class OrderedVector {
private:
	T* _ptr;
	size_t _size;
public:	

	OrderedVector() : _ptr(nullptr), _size(0) {} 
	
	explicit OrderedVector(T* newPtr, size_t size) : _ptr(newPtr), _size(size) {} 
	
	explicit OrderedVector(const size_t size): _ptr(new T[size]), _size(size) {}
	
	OrderedVector(const OrderedVector<T>& newVector) : _ptr(new T[newVector._size]), _size(newVector._size) {
		for (int i = 0; i < _size; ++i) {
			_ptr[i] = newVector._ptr[i];
		}
	}

	OrderedVector(OrderedVector<T>&& newVector) noexcept : _ptr(newVector._ptr), _size(newVector._size) {
		newVector._ptr = nullptr;
		newVector._size = 0;
	}

	~OrderedVector() {
		delete[] _ptr;
		_ptr = nullptr;
		_size = 0;
	}

	size_t size() {
		return _size;
	}

	void Print() {		
		std::cout << "Your vector:\n";
		for (int i = 0; i < _size; ++i) {
			std::cout << _ptr[i] << std::endl;
		}
	}

	//void push_back(const T& value) {
	//	if (_size == 0) {
	//		_ptr = new T[1];
	//		_ptr[0] = value;
	//		++_size;			
	//	}
	//	if (_size == 1) {
	//		T* tmp = _ptr[0];
	//		auto index = BinSearch()
	//	}
	//	/*T* tmp = new T[_size + 1];
	//	for (int i = 0; i < _size; ++i) {
	//		tmp[i] = _ptr[i];
	//	}
	//	delete[] _ptr;
	//	tmp[_size] = value;
	//	_ptr = tmp;*/
	//}	

	bool Insert(const T& value)	{
		if (_size == 0) {
			_ptr = new T[1];
			_ptr[0] = value;
			++_size;
			return true;
		}
		if (_size == 1) {
			auto tmp = _ptr[0];
			std::size_t ind = BinSearch(_ptr, _size, value);
			delete[] _ptr;
			_ptr = new T[2];
			if (ind == 1) {
				_ptr[0] = tmp;
				_ptr[1] = value;
				++_size;
				return true;
			}
			else {
				_ptr[0] = value;
				_ptr[1] = tmp;
				++_size;
				return true;
			}
		}
		else {
			std::size_t ind = BinSearch(_ptr, _size, value);
			T* newArr = new T[_size + 1];
			for (std::size_t i = 0; i < ind; ++i) {
				newArr[i] = _ptr[i];
			}
			newArr[ind] = value;
			for (std::size_t i = ind + 1; i < _size + 1; ++i) {
				newArr[i] = _ptr[i - 1];
			}
			delete[] _ptr;
			_ptr = newArr;
			++_size;
			return true;
		}
		return false;
	}

	bool Contains(const T& key) {
		if (_size == 0) return false;
		if (_size == 1) {
			if (_ptr[0] = key) 
				return true;
			return false;
		}		
		auto ind = BinSearch(_ptr, _size, key);
		if (ind == _size) 
			return false;
		else {
			if (_ptr[ind] == key) return true;
			return false;
		}
	}

	bool Remove(const T& key) {
		if (_size == 0) return false;
		if (_size == 1)
		{
			if (_ptr[0] == key) {
				delete[] _ptr;
				_ptr = nullptr;
				--_size;
				return true;
			}
			return false;
		}
		else {
			auto ind = BinSearch(_ptr, _size, key);
			if (ind == _size) return false;
			else 
			{
				if (_ptr[ind] == key) 
				{
					T* tmp = new T[_size - 1];
					for (auto i = 0; i < ind; ++i) tmp[i] = _ptr[i];					
					for (auto i = ind + 1; i < _size; ++i) tmp[i-1] = _ptr[i];
					delete[] _ptr;
					_ptr = tmp;
					--_size;
				}
				return false;
			}
		}
	}

	void clear() {
		delete _ptr;
		_ptr = nullptr;
		_size = 0;
	}


	T& operator[](size_t idx) {
		return _ptr[idx];
	}
};

//template<class T>
//void Random_Filling(OrderedVector<T>& v, int size) {
//	for (int i = 0; i < size; ++i) {
//		v.push_back(i);
//	}
//	for (int i = 0; i < v.size(); ++i) {
//		std::swap(v[i], v[rand() % (v.size() - i) + i]);
//	}
//}