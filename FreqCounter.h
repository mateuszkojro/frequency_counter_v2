//
// Created by mateusz on 2/2/2021.
//
//

#ifndef FREQUENCY_COUNTER_V2_FREQCOUNTER_H
#define FREQUENCY_COUNTER_V2_FREQCOUNTER_H

#include <unordered_map>
#include <string>

typedef std::string Csv;

// Dzieki utworzeniu klasy bazowej
// moge tworzyc w bardziej elegancki sposob
// specjalizacje klasy FreqCounter
template<class Type>
class BaseFreqCounter {
public:
    using CountedValues = std::unordered_map<Type, unsigned>;

public:
    BaseFreqCounter() = default;

    ~BaseFreqCounter() = default;

    BaseFreqCounter &operator=(const BaseFreqCounter &) = default;

    BaseFreqCounter(const BaseFreqCounter &) = default;

public:
    void add_data(Type);

    Csv export_to_csv(std::wstring (*transformer)(Type) = std::to_wstring);

    // policzone wartosci zwracamy jako mape
    // gdzie klucz to element a wartosc to liczba powtorzen
    CountedValues get_count();

protected:
    CountedValues data_;
};

template<class Type>
std::unordered_map<Type, unsigned> BaseFreqCounter<Type>::get_count() {
    return data_;
}

template<class Type>
void BaseFreqCounter<Type>::add_data(Type new_record) {
    // std::unorderd map gwarantuje ze jezeli typ wartosci
    // jest int to bedzie on mial wartosc 0
    ++data_[new_record];
}

template<class Type>
Csv BaseFreqCounter<Type>::export_to_csv(std::wstring (*transformer)(Type)) {
    // ustawiamy wlasnosci naszego obiektu Csv
    Csv::Config;
    config.number_of_columns = 2;

    std::vector<std::wstring> converted;
    for (auto &field : data_) {
        converted.push_back(transformer(field.first));
        converted.push_back(std::to_wstring(field.second));
    }
    return converted;
}


template<class Type>
class FreqCounter
        : BaseFreqCounter<Type> {
public:
};


#endif //FREQUENCY_COUNTER_V2_FREQCOUNTER_H
