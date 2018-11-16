#include <iostream>
#include "rgb.h"

using namespace std;

void process_image_parallel(struct rgb *input_image,
    unsigned char *output_image,
    size_t rows,
    size_t cols)
{
    size_t r, c;

    #pragma omp parallel for collapse(2) schedule(dynamic) default(none) private(r, c) shared(input_image, output_image, rows, cols)
    for(r = 0; r < rows; r++)
    {
        for(c = 0; c < cols; c++)
        {
            size_t index = r * cols + c;
            struct rgb pixel = input_image[index];

            float channel = .299f * pixel.red 
                + .587f * pixel.green
                + .114f * pixel.blue;

            output_image[index] = channel;
        }
    }
}