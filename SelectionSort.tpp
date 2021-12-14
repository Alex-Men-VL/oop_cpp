template <class TP>
void sortPersons(const int pCount, TP** persons) {
    TP* tmp;
    size_t minNumber = 0;
    for (size_t tNumber = 0; tNumber < pCount; tNumber++) {
        minNumber = tNumber;
        for (size_t nNumber = tNumber + 1; nNumber < pCount; nNumber++) {
            minNumber = (persons[nNumber]->isLess(persons[minNumber])) ? nNumber : minNumber;
        }
        if (tNumber != minNumber) {
            tmp = persons[tNumber];
            persons[tNumber] = persons[minNumber];
            persons[minNumber] = tmp;
        }
    }
}
