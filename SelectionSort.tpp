template <class TP>
void sortPersons(const int pCount, TP** persons) {
    TP* tmp;
    int minNumber = 0;
    for (int tNumber = 0; tNumber < pCount; tNumber++) {
        minNumber = tNumber;
        for (int nNumber = tNumber + 1; nNumber < pCount; nNumber++) {
            minNumber = (persons[nNumber]->isLess(persons[minNumber])) ? nNumber : minNumber;
        }
        if (tNumber != minNumber) {
            tmp = persons[tNumber];
            persons[tNumber] = persons[minNumber];
            persons[minNumber] = tmp;
        }
    }
}
