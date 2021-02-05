
#include "Csv.h"

#include <fstream>
#include <string>
#include <vector>

Csv::Csv(const std::vector<std::wstring> &data, const Config &config) {
    config_ = config;
    data_ = data;
}

void Csv::export_csv(const std::string &path) {

    std::wfstream file;
    file.open(path, std::ios::out);

    // pozwala nam uniknac wielokrotnego sprawdzania w petli ustawien
    std::wstring maybe_quote = (config_.has_quotes) ? std::wstring(L"\"", 1) : L"";

    for (unsigned i = 0; i < data_.size(); i++) {

        // zapisujemy pole do pliku
        file << maybe_quote;
        file << data_[i];
        file << maybe_quote;

        // w standardowym pliku CSV nie powinno byc przecinka po ostatnim elemencie
        bool is_last_element = i == data_.size() - 1;
        if (!is_last_element) {
            file << L',';//config_.separator;
        }

        // standard pliow CSV wymaga braku znaku konca lini po ostatnim rzedzie
        bool is_end_of_row =
                i % config_.number_of_columns == config_.number_of_columns - 1;
        if (!is_last_element && is_end_of_row) {
            file << '\n';
        }
    }
}

void Csv::read_csv(const std::string &path) {

    std::wfstream file;
    file.open(path, std::ios::in);

    std::wstring value;
    int i = 0;
    while (file.good()) {
        // getline przyjmuje separator from config, jako separator kolejnych pol
        std::getline(file, value, config_.separator);
        // add to inside storage next value from a file
        data_.push_back(value);
        bool is_last_element_on_line = i % config_.number_of_columns;
        // z uwaagi na dzialanie getline musimy recznie usunac newline from the end of the line
        if (is_last_element_on_line) {
            wchar_t trash;
            file >> trash;
            i = 0;
        }
        i++;
    }
}

std::wstring &Csv::operator()(unsigned column, unsigned row) {
    // @vstd::vector.at() sprawdza za nas czy adres jest w zakresie jezeli
    // nie wyrzuca std::out_of_range rownanie dostepu pozwala nam symulowac
    // istnienie tablicy 2 wymiarowej
    return data_.at(column + row * config_.number_of_columns);
}

unsigned Csv::number_of_columns() const { return config_.number_of_columns; }

unsigned Csv::number_of_rows() {
    // liczba rekordow jest rowna liczbie wszystkich danych podzelonych przez ilosc kolumn do ktorych zapuisujemy
    if (config_.number_of_columns) throw std::runtime_error("Cannot get the number of rows when numbers of columns is 0");
    return (unsigned) data_.size() / (unsigned) config_.number_of_columns;
}

const Csv::Config &Csv::get_config() const {
    return config_;
}

void Csv::set_config(const Csv::Config &config) {
    config_ = config;
}

const std::vector<std::wstring> &Csv::get_data() const {
    return data_;
}
