#include "String.h"

const char* ERROR_WRONG_INDEX = "Array: Wrong index";

String::String() {
    m_str = nullptr;
}

String::String(const char* str)
{
    size_t len = strlen(str);
    m_str = new char[len + 1];
    strncpy(m_str, str, len);
    m_str[len] = '\0';

}

String::String(const String &otherStr)
{
    size_t len = strlen(otherStr.m_str);
    m_str = new char[len + 1];
    strcpy(m_str, otherStr.m_str);

}

String::String(String &&otherStr) noexcept
{
    m_str = otherStr.m_str;
    otherStr.m_str = nullptr;  // we forbid erasing the data referenced by the pointer
}

String::~String() {
    delete[] m_str;
}

String &String::operator=(const String &otherStr) {
    if (&otherStr != this) {
        delete[] m_str;

        size_t len = strlen(otherStr.m_str);
        m_str = new char[len + 1];
        strcpy(m_str, otherStr.m_str);
    }
    return *this;
}

String &String::operator=(String &&otherStr) noexcept {
    if (&otherStr != this) {
        delete[] m_str;

        m_str = otherStr.m_str;
        otherStr.m_str = nullptr;  // we forbid erasing the data referenced by the pointer
    }
    return *this;
}

String String::operator+(const String &otherStr) {
    String newStr;

    size_t thisLength = strlen(m_str);
    size_t otherLength = strlen(otherStr.m_str);

    size_t len = thisLength + otherLength;

    newStr.m_str = new char[len + 1];
    strncpy(newStr.m_str, m_str, thisLength);
    strcat(newStr.m_str, otherStr.m_str);

    newStr.m_str[len] = '\0';
    return newStr;
}

void String::operator+=(const String &otherStr) {
    strcat(m_str, otherStr.m_str);
}

bool operator==(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) == 0;
}

bool operator!=(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) != 0;
}

bool operator>(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) > 0;
}

bool operator>=(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) >= 0;
}

bool operator<(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) < 0;
}

bool operator<=(const String &lStr, const String &rStr)
{
    return strcmp(lStr.m_str, rStr.m_str) <= 0;
}

const char& String::operator[](int index) {
    if (index >= 0 && index < strlen(m_str)) {
        return m_str[index];
    }
    throw ERROR_WRONG_INDEX;
}

std::ostream &operator<<(std::ostream &out, const String &str) {
    return out << str.m_str;
}

std::istream &operator>>(std::istream &in, String &str) {
    return in >> str.m_str;;
}

char* String::getStr() const {
    return this->m_str;
}

size_t String::length() const {
    size_t size = 0;
    for (; m_str[size] != 0; size++);
    return size;
}
