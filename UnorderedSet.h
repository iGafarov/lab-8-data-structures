#pragma once
#include <iostream>
template<typename TKey, typename TKeyHash = std::hash<TKey>>
class UnorderedSet {
	struct Node {
		const TKey _key;
		Node* _next;
		Node(const TKey& key) :_key(key), _next(nullptr) {}
	};

	Node** _hashArr;
	const std::size_t _size;
	size_t _elCount;

	void clearList(int ind) {
		while (_hashArr[ind]) {
			auto tmp = _hashArr[ind];
			_hashArr[ind] = tmp->_next;
			delete tmp;
		}
		_hashArr[ind] = nullptr;
	}

	Node** Find(const TKey& key) {
		const auto i = TKeyHash()(key) % _size;
		auto node = _hashArr + i;
		while (*node) {//always safe
			if ((*node)->_key == key)return node;
			node = &((*node)->_next);
		}
		return node;
	}
public:

	std::size_t getSize()const {
		return _size;
	}

	std::size_t getElCount()const {
		return _elCount;
	}

	static const std::size_t DEFAULT_SIZE = 17;

	UnorderedSet(): _size(DEFAULT_SIZE) {
		_hashArr = new Node * [DEFAULT_SIZE];
		for (size_t i = 0; i < DEFAULT_SIZE; ++i)
			_hashArr[i] = nullptr;		
		//_size = DEFAULT_SIZE;
		_elCount = 0;
	}

	UnorderedSet(std::size_t size) :_hashArr(new Node* [size]), _size(size), _elCount(0) {
		for (std::size_t i = 0; i < size; ++i) {
			_hashArr[i] = nullptr;
		}
	}

	UnorderedSet(const UnorderedSet& rhs) = delete;

	UnorderedSet(UnorderedSet&& rhs) = delete;

	UnorderedSet& operator=(const UnorderedSet& rhs) = delete;

	UnorderedSet& operator=(UnorderedSet&& rhs) = delete;

	~UnorderedSet() {
		clear();
	}

	bool Insert(const TKey& key) {
		auto node = Find(key);
		if (*node == nullptr) {
			*node = new Node(key);
			++_elCount;
			return true;
		}
		else
			return false;
	}

	bool Remove(const TKey& key) {
		auto node = Find(key);
		if (!(*node))return false;
		else {
			auto tmp = *node;
			*node = (*node)->_next;
			delete tmp;
			return true;
		}		
	}

	bool Contains(const TKey& key) {
		return *Find(key) != nullptr;
	}

	void Print() {
		for (std::size_t i = 0; i < _size; ++i) {
			auto tmp = _hashArr[i];
			while (tmp) {
				std::cout << "(" << tmp->_value << "||" << tmp->_key << ")" << "->";
				tmp = tmp->_next;
			}
			std::cout << "nullptr";
			std::cout << "\n";
		}
		return;
	}

	void clear() {
		for (std::size_t i = 0; i < _size; ++i) {
			clearList(i);
		}
		delete[] _hashArr;
	}
};