#ifndef CUHKSZ_CONTAINERS_VECTOR
#define CUHKSZ_CONTAINERS_VECTOR

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "utils/error.h"

namespace cuhksz {

template <typename ValueType>
class Vector {
public:
    typedef typename std::vector<ValueType> stlVector;
    Vector();
    explicit Vector(int n, ValueType value = ValueType());
    Vector(std::initializer_list<ValueType> init);
    Vector(stlVector& stlVector2);

    ~Vector();

    const ValueType& get(int index) const;
    ValueType& get(int index);

    ValueType& first();
	const ValueType& first() const;

	ValueType& last();
	const ValueType& last() const;


    ValueType& operator [](int index);
    const ValueType& operator [](int index) const;


    bool isEmpty() const;


    int size() const;

    void clear();

    void insert(int index, const ValueType& value);

    void erase(int index);

    void set(int index, const ValueType& value);

    void push(const ValueType& value);

    ValueType pop();

    stlVector toStlVector() {
        return vec;
    }

    operator stlVector() { return vec; };

    bool operator ==(const Vector& v2);
    bool operator !=(const Vector& v2);
    bool operator <(const Vector& v2);
    bool operator <=(const Vector& v2);
    bool operator >(const Vector& v2);
    bool operator >=(const Vector& v2);

    typedef typename std::vector<ValueType>::iterator iterator;
    typedef typename std::vector<ValueType>::const_iterator const_iterator;

    iterator begin() {
      return vec.begin();
    }
    const_iterator begin() const {
      return vec.begin();
    }

    iterator end() {
      return vec.end();
    }

    const_iterator end() const {
      return vec.end();
    }




private:
    std::vector<ValueType> vec;
    void boundaryCheck(int index) const;
    void emptyCheck() const;
};

template <typename ValueType>
Vector<ValueType>::Vector() {
    //do nothing
}

template <typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value) {
    vec.resize(n, value);
}

template <typename ValueType>
Vector<ValueType>::Vector(std::initializer_list<ValueType> init) {
    vec = init;
}

template <typename ValueType>
Vector<ValueType>::Vector(stlVector& stlVector2) {
    vec = stlVector2;
}


template <typename ValueType>
Vector<ValueType>::~Vector() {
    //do nothing
}

template <typename ValueType>
const ValueType& Vector<ValueType>::get(int index) const {
    boundaryCheck(index);
    return vec.at(index);
}

template <typename ValueType>
ValueType& Vector<ValueType>::get(int index) {
    boundaryCheck(index);
    return vec.at(index);
}

template <typename ValueType>
ValueType& Vector<ValueType>::first() {
	emptyCheck();
	return vec.front();
}

template <typename ValueType>
const ValueType& Vector<ValueType>::first() const {
	emptyCheck();
	return vec.front();
}

template <typename ValueType>
ValueType& Vector<ValueType>::last() {
	emptyCheck();
	return vec.back();
}

template <typename ValueType>
const ValueType& Vector<ValueType>::last() const {
	emptyCheck();
	return vec.back();
}

template <typename ValueType>
ValueType& Vector<ValueType>::operator [](int index) {
    boundaryCheck(index);
    return vec.at(index);
}

template <typename ValueType>
const ValueType& Vector<ValueType>::operator [](int index) const {
    boundaryCheck(index);
    return vec.at(index);
}

template <typename ValueType>
bool Vector<ValueType>::isEmpty() const {
    return vec.empty();
}

template <typename ValueType>
int Vector<ValueType>::size() const {
    return vec.size();
}

template <typename ValueType>
void Vector<ValueType>::clear() {
    vec.clear();
}

template <typename ValueType>
void Vector<ValueType>::insert(int index, const ValueType& value) {
    if (index != 0) boundaryCheck(index);
    auto iterator = vec.begin();
    std::advance(iterator, index);
    vec.insert(iterator, value);
}

template <typename ValueType>
void Vector<ValueType>::erase(int index) {
    boundaryCheck(index);
    auto iterator = vec.begin();
    std::advance(iterator, index);
    vec.erase(iterator);
}

template <typename ValueType>
void Vector<ValueType>::set(int index, const ValueType& value) {
    boundaryCheck(index);
    vec[index] = value;
}

template <typename ValueType>
void Vector<ValueType>::push(const ValueType& value) {
    vec.push_back(value);
}

template <typename ValueType>
ValueType Vector<ValueType>::pop() {
    emptyCheck();
    ValueType lastElement = vec.back();
    vec.pop_back();
    return lastElement;
}

template <typename ValueType>
bool Vector<ValueType>::operator ==(const Vector& v2) {
    return vec == v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator !=(const Vector& v2) {
  return vec != v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator <(const Vector& v2) {
  return vec < v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator <=(const Vector& v2) {
  return vec <= v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator >(const Vector& v2) {
  return vec > v2.vec;
}

template <typename ValueType>
bool Vector<ValueType>::operator >=(const Vector& v2) {
  return vec >= v2.vec;
}

template <typename ValueType>
void Vector<ValueType>::boundaryCheck(int index) const {
	if (index < 0 || index >= vec.size()) {
		error("The index out of range!");
	}
}

template <typename ValueType>
void Vector<ValueType>::emptyCheck() const {
	if (vec.empty()) {
		error("The vector is empty!");
	}
}

template <typename ValueType>
std::ostream & operator <<(std::ostream& os, const Vector<ValueType>& vec) {
    std::stringstream ss;
    auto outVector = vec;
    std::copy(outVector.begin(), --outVector.end(), std::ostream_iterator<ValueType>(ss, ", "));
    return os << '{' << ss.str() << vec.last() << '}' << std::endl;
}

template <typename ValueType>
std::istream & operator >>(std::istream & is, Vector<ValueType>& vec) {
  char ch;
  is >> ch;
  if (ch != '{') {
    std::cerr << "Error: The first character of a vector should be '{'" << '\n';
    return is;
  }
  vec.clear();
  is >> ch;
  if (ch != '}') {
    is.unget();
    while (true) {
      ValueType value;
      is >> value;
      vec.push(value);
      is >> ch;
      if (ch == '}') {
        break;
      } else if (ch != ','){
        std::cerr << "Error: Unexpected character " << ch << " when input a s" << '\n';
        return is;
      }
    }
  }
  return is;
}

} // end namespace cuhksz

#endif //CUHKSZ_CONTAINERS_VECTOR
