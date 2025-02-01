//
// Created by YuzukiTsuru on 2021/2/11.
//

#ifndef WORLDJS_WORLDNATIVEFUN_H
#define WORLDJS_WORLDNATIVEFUN_H

#include <iostream>
#include <emscripten.h>

#include "WorldJS.h"
#include "Converter.h"

class WorldNativeFun
{
public:
    // DIO Wrapper
    static emscripten::val Dio_JS(int x_ptr, int x_length, int fs, double frame_period);

    // Harvest
    static emscripten::val Harvest_JS(int x_ptr, int x_length, int fs, double frame_period);

    // CheapTrick
    static emscripten::val
    CheapTrick_JS(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fs);

    // D4C
    static emscripten::val
    D4C_JS(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fft_size, int fs);

    // Synthesis
    static emscripten::val
    Synthesis_JS(int f0_ptr, int f0_length, const int spectrogram_ptr, const int aperiodicity_ptr,
                 int fft_size, int fs, const double frame_period);
};

#endif // WORLDJS_WORLDNATIVEFUN_H
