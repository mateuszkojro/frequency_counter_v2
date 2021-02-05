//
// Created by mateu on 2/5/2021.
//

#ifndef FREQUENCY_COUNTER_V2_BARCHART_H
#define FREQUENCY_COUNTER_V2_BARCHART_H

#include "Csv.h"
#include "ppm/ppm.h"

class BarChart {
public:
    BarChart() = default;
    ~BarChart() = default;
    BarChart(const BarChart&) = default;
    BarChart& operator=(const BarChart&) = default;

    BarChart(Csv csv) : data_(csv){}
    ppm && export_to_ppm(unsigned size_x, unsigned size_y, const std::string &path);

private:
    Csv data_;
};

#endif // FREQUENCY_COUNTER_V2_BARCHART_H
