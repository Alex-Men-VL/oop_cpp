template<typename TP>
int getDifLastNamesNumber(const int pCount, TP **persons) {
    int count = pCount;

    for (int tNumber= 0; tNumber< pCount; tNumber++) {
        for (int nNumber = tNumber+ 1; nNumber < pCount; nNumber++) {
            if (persons[tNumber]->isSameLastNames(persons[nNumber])) {
                count--;
                break;
            }
        }
    }
    return count;
}

template<typename TP>
int getNamesakesNumber(const int pCount, TP **persons) {
    int count = 0;

    for (int tNumber= 0; tNumber< pCount; tNumber++) {
        for (int nNumber = tNumber+ 1; nNumber < pCount; nNumber++) {
            bool isSameLastNames = persons[tNumber]->isSameLastNames(persons[nNumber]);
            bool isSameFirstNames = persons[tNumber]->isSameFirstNames(persons[nNumber]);
            bool personHasNamesake = persons[tNumber]->getNamesake();
            if (isSameLastNames && isSameFirstNames && personHasNamesake) {
                count++;
                persons[nNumber]->setNamesake();
                persons[tNumber]->setNamesake();  // Formality. Not needed for calculations
                break;
            } else if (isSameLastNames && isSameFirstNames) {
                count += 2;
                persons[nNumber]->setNamesake();
                persons[tNumber]->setNamesake();  // Formality. Not needed for calculations
                break;
            }
        }
    }
    return count;
}
