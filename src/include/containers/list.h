#ifndef CUHKSZ_CONTAINERS_LIST
#define CUHKSZ_CONTAINERS_LIST

#include <list>
#include <iostream>
#include <cstdlib>

namespace cuhksz {

template <typename ValueType>
class list {
public:
	list(); //constructor
	explicit list(int n, ValueType value = ValueType());

	virtual ~list(); //deconstructor

	list& operator =(const list& list2);

	ValueType& first();
	const ValueType& first() const;

	ValueType& last();
	const ValueType& last() const;

	ValueType& operator [](int index);
	const ValueType& operator [](int index) const;

	bool isEmpty();

	int size() const;

	void clear();

	void insert(int index, ValueType& value);

	void erase(int index);


	void push(const ValueType& value);
	void push_front(const ValueType& value);

	ValueType pop();
	ValueType pop_front();

	void sort();

	void reverse();

	void merge(list& list2);

	bool operator ==(const list& list2);
	bool operator !=(const list& list2);
	bool operator <(const list& list2);
	bool operator <=(const list& list2);
	bool operator >(const list& list2);
	bool operator >=(const list& list2);

	typedef typename std::list<ValueType>::const_iterator const_iterator;

    const_iterator begin() const {
      return privateList.begin();
    }

    const_iterator end() const {
      return privateList.end();
    }

private:
	std::list<ValueType> privateList;
	void boundaryCheck(int index);
	void emptyCheck();

	}; //end list class

/*-------Implementation-------*/

template <typename ValueType>
list<ValueType>::list() {
	//do nothing
}

template <typename ValueType>
list<ValueType>::list(int n, ValueType value) {
	for (int i = 0; i < n; i++) {
		privateList.push_back(value);
	}
}

template <typename ValueType>
list<ValueType>::~list() {
	//do nothing
}

template <typename ValueType>
list<ValueType>& list<ValueType>::operator =(const list& list2) {
	privateList = list2.privateList;
}

template <typename ValueType>
ValueType& list<ValueType>::first() {
	emptyCheck();
	return privateList.front();
}

template <typename ValueType>
const ValueType& list<ValueType>::first() const {
	emptyCheck();	
	return privateList.front();
}

template <typename ValueType>
ValueType& list<ValueType>::last() {
	emptyCheck();
	return privateList.back();
}

template <typename ValueType>
const ValueType& list<ValueType>::last() const {
	emptyCheck();
	return privateList.back();
}

template <typename ValueType>
ValueType& list<ValueType>::operator [](int index) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	for (int i = 0; i != index; i++) {
		++iterator;
	}
	return *iterator;
}

template <typename ValueType>
const ValueType& list<ValueType>::operator [](int index) const {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	for (int i = 0; i != index; i++) {
		++iterator;
	}
	return *iterator;
}


template <typename ValueType>
bool list<ValueType>::isEmpty() {
	 return privateList.empty();
}

template <typename ValueType>
int list<ValueType>::size() const {
	return privateList.size();
}

template <typename ValueType>
void list<ValueType>::clear() {
	privateList.clear();
}

template <typename ValueType>
void list<ValueType>::insert(int index, ValueType& value) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
	std::advance(iterator, index);
	privateList.insert(iterator, value);
}

template <typename ValueType>
void list<ValueType>::erase(int index) {
	boundaryCheck(index);
	auto iterator = privateList.begin();
    std::advance(iterator, index);
    privateList.erase(iterator);
}

template <typename ValueType>
void list<ValueType>::push(const ValueType& value) {
	privateList.push_back(value);
}

template <typename ValueType>
void list<ValueType>::push_front(const ValueType& value) {
	privateList.push_front(value);
}

template <typename ValueType>
ValueType list<ValueType>::pop() {
	emptyCheck();
	ValueType lastElement = privateList.back();
    privateList.pop_back();
    return lastElement;
}

template <typename ValueType>
ValueType list<ValueType>::pop_front() {
	emptyCheck();
	firstElement = privateList.front();
	privateList.pop_front();
	return firstElement;
}

template <typename ValueType>
void list<ValueType>::sort() {
	privateList.sort();
}

template <typename ValueType>
void list<ValueType>::reverse() {
	privateList.reverse();
}

template <typename ValueType>
void list<ValueType>::merge(list& list2) {
	privateList.merge(list2.privateList);
}

template <typename ValueType>
bool list<ValueType>::operator ==(const list& list2) {
	return privateList == list2.privateList;
}

template <typename ValueType>
bool list<ValueType>::operator !=(const list& list2) {
	return privateList != list2.privateList;
}

template <typename ValueType>
bool list<ValueType>::operator <(const list& list2) {
	return privateList < list2.privateList;
}

template <typename ValueType>
bool list<ValueType>::operator <=(const list& list2) {
	return privateList <= list2.privateList;
}

template <typename ValueType>
bool list<ValueType>::operator >(const list& list2) {
	return privateList > list2.privateList;
}

template <typename ValueType>
bool list<ValueType>::operator >=(const list& list2) {
	return privateList >= list2.privateList;
}

void list<ValueType>::boundaryCheck(int index) {
	if (index >= privateList.size() or index < 0) {
		std::cout << "The index out of range!" << '\n';
		std::exit(EXIT_FAILURE);
	}
}

void list<ValueType>::emptyCheck() {
	if (privateList.empty()) {
		std::cout << "The list is empty!" << '\n';
		std::exit(EXIT_FAILURE);
	}
}

} //end namespace

#endif