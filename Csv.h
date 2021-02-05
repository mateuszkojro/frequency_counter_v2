#ifndef FREQUENCY_COUNTER_V2_CSV_H
#define FREQUENCY_COUNTER_V2_CSV_H

/**
	@Autor: Mateusz Kojro
	@details: Prosta implementacja obslugi plikow Csv (Zapisywanie, Odczytywanie, Dostep do danych)
	@date: 27.01.2021
	Zmiany:
		- 29.01: usuwam nie potrzebne elementy z poprzedniej implementacji
		- 2.02: dodaje dodatkowe komentarze
*/

#include <string>
#include <vector>
#include <stdexcept>

class Csv {
public:
    struct Config {
        /**
         * @brief separator beetwen subsequnet columns
         */
        wchar_t separator = L',';
        /**
         * @brief does first row consist of headers
         */
        bool has_headers = false;
        /**
         * @brief are the values surrounded with quotes
         */
        bool has_quotes = false;
        /**
         * @brief nuber of columns
         */
        unsigned number_of_columns = 0;
    };

public:
    Csv() = default;
    ~Csv() = default;
    Csv &operator=(const Csv &) = default;
    Csv(const Csv &) = default;
    Csv(const std::vector<std::wstring> &, const Config &);

public:
    /**
     * @brief reads csv formated file
     */
    void read_csv(const std::string &);

    /**
     * @brief exports data to csv formated file
     */
    void export_csv(const std::string &);
    unsigned number_of_columns() const;
    unsigned number_of_rows();

    /**
     * @brief acces element of given coordianates
     * @param x - column counted from 0
     * @param y - row counted from 0
     * @return reference to elelment on position x, y
     */
    std::wstring &operator()(unsigned, unsigned);

    const std::vector<std::wstring> &get_data() const;
    const Config &get_config() const;
    void set_config(const Config &config);

private:
    std::vector<std::wstring> data_;
    Config config_;

};


#endif//FREQUENCY_COUNTER_V2_CSV_H
