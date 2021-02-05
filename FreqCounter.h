#ifndef FREQUENCY_COUNTER_V2_FREQCOUNTER_H
#define FREQUENCY_COUNTER_V2_FREQCOUNTER_H

#include <unordered_map>

#include "Csv.h"

/**
        @author: Mateusz Kojro
        @details: Klasa freq counter - liczenie czestotliwosci wystepowania obiektow
        @date: 27.01.2021
        @changes:
                - 29.01: usuwam nie potrzebne elementy z poprzedniej
                - 31.01: dodaje dodatkowe komentarze
                - 3.02: fixing small mistakes
*/

// Dzieki utworzeniu klasy bazowej
// moge tworzyc w bardziej elegancki sposob
// specjalizacje klasy FreqCounter
template<class Type>
class FreqCounter {
public:
    using CountedValues = std::unordered_map<Type, unsigned>;

public:
    FreqCounter() = default;
    ~FreqCounter() = default;
    FreqCounter &operator=(const FreqCounter &) = default;
    FreqCounter(const FreqCounter &) = default;

public:
    void add_data(Type);

    Csv export_to_csv(std::wstring (*transformer)(Type) = std::to_wstring);

    /**
     * @brief calculates the number of occureneces of given class element
     * @return std::unordered_map<Type T, unsigned num> where T is an element
     * and the num is number of occurences of that elelment
     */
    const std::unordered_map<Type, unsigned int> &get_count();

protected:
    CountedValues data_;
};

template<class Type>
const std::unordered_map<Type, unsigned int> &
FreqCounter<Type>::get_count() {
    return data_;
}

template<class Type>
void FreqCounter<Type>::add_data(Type new_record) {
    // std::unorderd map gwarantuje ze jezeli typ wartosci
    // jest int to bedzie on mial wartosc 0
    ++data_[new_record];
}

// FIXME: to kompletnie nie jest tak jak powinno
template<class Type>
Csv FreqCounter<Type>::export_to_csv(std::wstring (*transformer)(Type)) {
    // ustawiamy wlasnosci naszego obiektu Csv
    Csv::Config config;
    config.number_of_columns = 2;

    // zapisujemy policzone przez nas dane jako wektor ktory mozemy dac do konstruktora Csv
    std::vector<std::wstring> converted;
    for (auto &field : data_) {
        // zamieniamy pierwsze pole na string za pomoca podanej przez uzytkownika
        converted.push_back(transformer(field.first));
        // zamieniamy liczbe wystapien na string zeby moc z niej zrobic Csv
        converted.push_back(std::to_wstring(field.second));
    }

    // FIXME there is aa copy there i should try to avoid
    // return created Csv file
    return Csv(converted, config);
}


#endif// FREQUENCY_COUNTER_V2_FREQCOUNTER_H
