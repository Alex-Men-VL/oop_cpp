#include "Person.h"

template<class T>
Person<T>::Person() :
    T(),
    m_firstName(T()),
    m_lastName(T()),
    m_dateYear(T()),
    m_hasNamesake(false) {
}

template<class T>
void Person<T>::operator delete(void *ptr) {
    free(ptr);
}

template<class T>
void *Person<T>::operator new(size_t size) {
    void * ptr;
    ptr = malloc(size);  // allocating memory

    if (!ptr) {
        std::bad_alloc ba;  // memory allocation error
        throw ba;
    } else {
        return ptr;
    }
}

template<class T>
T Person<T>::getFirstName() const {
    return this->m_firstName;
}

template<class T>
T Person<T>::getLastName() const {
    return this->m_lastName;
}

template<class T>
T Person<T>::getDateYear() const {
    return this->m_dateYear;
}

template<class T>
bool Person<T>::getNamesake() const {
    return this->m_hasNamesake;
}

template<class T>
int Person<T>::getFirstNameLen() const {
    return m_firstName.length();
}

template<class T>
int Person<T>::getLastNameLen() const {
    return m_lastName.length();
}

template<class T>
int Person<T>::getDateYearLen() const {
    return m_dateYear.length();
}

template<class T>
void Person<T>::setPerson(const T &lastName, const T &firstName, const T &dateYear) {
    m_firstName = firstName;
    m_lastName = lastName;
    m_dateYear = dateYear;
    m_hasNamesake = false;
}


template<class T>
void Person<T>::setNamesake() {
    m_hasNamesake = true;
}

template<class T>
bool Person<T>::isLess(const Person *otherPerson) const {

    if (this->m_lastName < otherPerson->m_lastName) {
        return true;
    } else if (this->m_lastName > otherPerson->m_lastName) {
        return false;
    }

    if (this->m_firstName < otherPerson->m_firstName) {
        return true;
    } else if (this->m_firstName > otherPerson->m_firstName) {
        return false;
    }

    if (this->m_dateYear < otherPerson->m_dateYear) {
        return true;
    } else if (this->m_dateYear > otherPerson->m_dateYear) {
        return false;
    }
    return false;
}

template<class T>
bool Person<T>::isSameLastNames(const Person<T> *otherPerson) const {
    return this->m_lastName == otherPerson->m_lastName;
}

template<class T>
bool Person<T>::isSameFirstNames(const Person<T> *otherPerson) const {
    return this->m_firstName == otherPerson->m_firstName;
}
