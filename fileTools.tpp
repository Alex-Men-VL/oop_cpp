template <typename TS>
TS setFileName(TS &name) {
    TS path("../source/");
    path += name;
    return path;
}

template <typename TS>
TS getInputFileName() {
    char *iFileName = new char[20];
    std::cout << "Enter the name of the input file: ";
    std::cin >> iFileName;
    TS inputFileName(iFileName);
    inputFileName = setFileName(inputFileName);
    return inputFileName;
}

template <typename TS>
TS getOutputFileName(){
    char *oFileName = new char[20];
    std::cout << "Enter the name of the output file: ";
    std::cin >> oFileName;
    TS outputFileName(oFileName);
    outputFileName = setFileName(outputFileName);
    return outputFileName;
}

template <typename T, typename TP, typename TS>
void setPersonsFromFile(T inputFileName, TP **persons) {
    std::ifstream inputFile;
    TS firstName("");
    TS lastName("");
    TS dateYear("");

    inputFile.open(inputFileName);
    if (!inputFile) {
        throw ERROR_FILE_NOT_OPEN;
    }

    int count;
    inputFile >> count;

    int personNumber = 0;
    while (personNumber != count) {
        persons[personNumber] = new TP();
        inputFile >> lastName >> firstName >> dateYear;
        persons[personNumber]->setPerson(lastName, firstName, dateYear);
        personNumber++;
    }
}

template <typename TS>
void setPersonsCountFromFile(TS inputFileName, int &count) {
    std::ifstream inputFile;

    inputFile.open(inputFileName);
    if (!inputFile) {
        throw ERROR_FILE_NOT_OPEN;
    }
    inputFile >> count;
    if (count < 1) {
        throw ERROR_NOT_CORRECT_PERSON_COUNT;
    }
}

template <typename TP, typename TS>
void checkInput(const int pCount, TP **persons) {
    TS totalYear = getCurrentYear<TS>();
    int delta = 100;
    TS minYear = getCurrentYear<TS>(delta);

    for (int pNumber = 0; pNumber < pCount; pNumber++) {
        char lastNameFirstLetter = persons[pNumber]->getLastName()[0];
        if (!isupper(lastNameFirstLetter)) {
            throw ERROR_FL_LN_NOT_CAPITAL;
        }
        char firstNameFirstLetter = persons[pNumber]->getFirstName()[0];
        if (!isupper(firstNameFirstLetter)) {
            throw ERROR_FL_FN_NOT_CAPITAL;
        }
        int lastNameLen = persons[pNumber]->getLastNameLen();
        if (lastNameLen < 3 || lastNameLen > 20) {
            throw ERROR_NOT_CORRECT_LN;
        }

        int firstNameLen = persons[pNumber]->getFirstNameLen();
        if (firstNameLen < 2 || firstNameLen > 10) {
            throw ERROR_NOT_CORRECT_FN;
        }

        int dateYearLen = persons[pNumber]->getDateYearLen();
        if (dateYearLen != 4) {
            throw ERROR_NOT_CORRECT_DY;
        }

        TS year = persons[pNumber]->getDateYear();

        if (year > totalYear || year < minYear) {
            throw ERROR_YEAR;
        }
        for (int digitNumber = 0; digitNumber < dateYearLen; digitNumber++) {
            char digit = year[digitNumber];
            if (digitNumber == 0 && digit == '0') {
                throw ERROR_NOT_CORRECT_DY;
            }
            if (!(digit >= '0' && digit <= '9')) {
                throw ERROR_NOT_CORRECT_DY;
            }
        }
    }
}

template <typename TS>
void clearOutputFile(TS outputFileName) {
    std::ofstream outputFile;
    outputFile.open(outputFileName, std::ofstream::out | std::ofstream::trunc);
    outputFile.close();
}

template <typename TS, typename TP>
void printPersonsInFile(TS outputFileName, const int pCount, TP **persons) {
    std::ofstream outputFile;

    outputFile.open(outputFileName, std::ios::app);
    if (!outputFile) {
        throw ERROR_FILE_NOT_OPEN;
    }
    outputFile << pCount << "\n";
    for (int i = 0; i < pCount; i++) {
        outputFile << persons[i]->getLastName() << " ";
        outputFile << persons[i]->getFirstName() << " ";
        outputFile << persons[i]->getDateYear() << "\n";
    }
}

template <typename TS>
TS getCurrentYear(int delta) {
    time_t seconds = time(NULL);
    tm* time = localtime(&seconds);
    int tYear = time->tm_year + 1900;
    tYear -= delta;

    char *str = new char[5];
    str[0] = tYear / 1000 + '0';
    str[1] = tYear / 100 % 10 + '0';
    str[2] = tYear / 10 % 10 + '0';
    str[3] = tYear % 10 + '0';
    str[4] = '\0';
    TS totalYear(str);
    return totalYear;
}
