#ifndef IND_7_OOP_PERSON_H
#define IND_7_OOP_PERSON_H

#include "String.h"

template <class T>
class Person : public T {
    T m_firstName;
    T m_lastName;
    T m_dateYear;
    bool m_hasNamesake;
public:
    Person();

    void operator delete(void *);
    void* operator new(size_t);

    T getFirstName() const;
    T getLastName() const;
    T getDateYear() const;
    bool getNamesake() const;

    int getFirstNameLen() const;
    int getLastNameLen() const;
    int getDateYearLen() const;

    void setPerson(const T&, const T&, const T&);
    void setNamesake();

    bool isLess(const Person<T>*) const;
    bool isSameLastNames(const Person<T>*) const;
    bool isSameFirstNames(const Person<T>*) const;
};

#include "Person.tpp"

#endif //IND_7_OOP_PERSON_H
