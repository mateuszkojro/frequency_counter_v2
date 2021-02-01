//
// Created by mateusz on 2/2/2021.
//
//

#ifndef FREQUENCY_COUNTER_V2_FREQCOUNTER_H
#define FREQUENCY_COUNTER_V2_FREQCOUNTER_H

#include <unordered_map>

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

    CountedValues get_count();

protected:
    CountedValues data_;
};

template<class Type>
std::unordered_map<Type, unsigned> BaseFreqCounter<Type>::get_count() {
    return data_;
}


template<class Type>
class FreqCounter
        : BaseFreqCounter<Type> {


public:


};


#endif //FREQUENCY_COUNTER_V2_FREQCOUNTER_H
