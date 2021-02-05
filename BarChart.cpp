//
// Created by mateu on 2/5/2021.
//

#include "BarChart.h"

// FIXME: move me to ppm
void draw_rect(ppm &obraz, unsigned start_x, unsigned start_y, unsigned size_x,
               unsigned size_y, const pixelRGB &color) {

    for (unsigned x = start_x; x < start_x + size_x; x++) {
        for (unsigned y = start_y; y < start_y + size_y; y++) {
            obraz(x, y) = color;
        }
    }
}

ppm &&BarChart::export_to_ppm(unsigned size_x, unsigned size_y,
                              const std::string &path) {

    ppm *obraz = new ppm(size_x, size_y, pixelRGB(255, 255, 255));

    unsigned max = 0;
    for (unsigned row = 0; row < data_.number_of_rows(); row++) {
        max = std::stol(data_(1, row)) > max ? std::stol(data_(1, row)) : max;
    }

    if (max == 0) {
        throw std::invalid_argument("recived csv with no data");
    }

    /// @note rzutowanie tutaj nic nie robi jest tylko po to zeby wizualnie pokazac
    /// ze wykonujemy dzielenie calkowite
    unsigned skala_x = (unsigned) size_x / (unsigned) data_.number_of_rows();
    unsigned skala_y = (unsigned) size_y / (unsigned) max;

    for (unsigned row = 0; row < data_.number_of_rows(); row++) {
        draw_rect(*obraz, row * skala_x, 0, skala_x,
                  std::stol(data_(1, row)) * skala_y, pixelRGB(111, 0, 0));
    }

    /// @note we can move the value here bcs the created obj could not ever be used after
    /// i am just 80% sure tho
    /// i could always just return the reference
    return std::move(*obraz);
}
