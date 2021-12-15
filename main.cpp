#include "fileTools.h"
#include "functions.h"
#include "selectionSort.h"

const char* ERROR_NOT_CORRECT_ARGUMENT = "Provide the number 1 or 2 as a command line argument";

template <typename T, typename TP, typename TS>
int getSolution(T inputFileName, T outputFileName) {
    int personsCount = 0;
    try {
        setPersonsCountFromFile<T>(inputFileName, personsCount);
    } catch (const char* error) {
        std::cerr << error << std::endl;
        return -1;
    }
    TP *persons[personsCount];

    try {
        setPersonsFromFile<T, TP, TS>(inputFileName, persons);
        checkInput<TP, TS>(personsCount, persons);
    } catch (const char* error) {
        std::cerr << error << std::endl;
        return -1;
    }

    sortPersons<TP>(personsCount, persons);

    clearOutputFile<T>(outputFileName);
    try {
        printPersonsInFile<T, TP>(outputFileName, personsCount, persons);
    } catch (const char* error) {
        std::cerr << error << std::endl;
        return -1;
    }


    int diffLastNamesCount = getDifLastNamesNumber<TP>(personsCount, persons);
    std::cout << "\nThe number of different surnames in the file: " << diffLastNamesCount << std::endl;

    int namesakesCount = getNamesakesNumber<TP>(personsCount, persons);
    std::cout << "Number of persons with matching last names and first names: " << namesakesCount << std::endl;
    return 0;
}

int main(int argc, char *argv[]) {
    float taskNumber = 0;
    if (argc != 2) {
        std::cerr << ERROR_NOT_CORRECT_ARGUMENT << std::endl;
        return 1;
    } else {
        taskNumber = std::stof(argv[1]);
    }

    if (taskNumber == 2) {
        std::cout << "Using own String class\n" << std::endl;

        String iFileName;
        String oFileName;
        iFileName = getInputFileName<String>();
        oFileName = getOutputFileName<String>();
        const char* inputFileName = iFileName.getStr();
        const char* outputFileName = oFileName.getStr();
        return getSolution<const char*, Person<String>, String>(inputFileName, outputFileName);
    } else if (taskNumber == 1) {
        std::cout << "Using the string class from STL\n" << std::endl;

        std::string inputFileName;
        std::string outputFileName;
        inputFileName = getInputFileName<std::string>();
        outputFileName = getOutputFileName<std::string>();
        return getSolution<std::string, Person<std::string>, std::string>(inputFileName, outputFileName);
    } else {
        std::cerr << ERROR_NOT_CORRECT_ARGUMENT << std::endl;
        return -1;
    }
}
