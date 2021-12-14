#ifndef IND_7_OOP_FILETOOLS_H
#define IND_7_OOP_FILETOOLS_H

#include <fstream>
#include <string>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <time.h>
#include "classes/Person.h"

const char* ERROR_FILE_NOT_OPEN= "File not found";

const char* ERROR_NOT_CORRECT_PERSON_COUNT = "The number of entries in the file must be a natural number";
const char* ERROR_FL_LN_NOT_CAPITAL = "The last name must begin with a capital letter";
const char* ERROR_FL_FN_NOT_CAPITAL = "The first name must begin with a capital letter";

const char* ERROR_NOT_CORRECT_LN = "The last name must be no shorter than 3 and no longer than 20 letters";
const char* ERROR_NOT_CORRECT_FN = "The first name must be no shorter than 2 and no longer than 10 letters";
const char* ERROR_NOT_CORRECT_DY = "The year of birth must be a four-digit number";
const char* ERROR_YEAR = "Incorrect year. The age cannot be negative and is more than 100 years old";

template <typename TS>
TS setFileName(TS &);
template <typename TS>
TS getInputFileName();
template <typename TS>
TS getOutputFileName();

template <typename T, typename TP, typename TS>
void setPersonsFromFile(T, TP **);
template <typename TS>
void setPersonsCountFromFile(TS, int &);
template <typename TP, typename TS>
void checkInput(int, TP **);
template <typename TS>
void clearOutputFile(TS);
template <typename TS, typename TP>
void printPersonsInFile(TS, int, TP **);
template <typename TS>
TS getCurrentYear(int delta = 0);

#include "fileTools.tpp"

#endif //IND_7_OOP_FILETOOLS_H
