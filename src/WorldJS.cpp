//
// Created by YuzukiTsuru on 2019/7/14.
//
#include <utility>

#include "WorldJS.h"

//-----------------------------------------------------------------------------
// The JavaScript API in C++
//----------------------------------------------------------------------------_

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Dio(int x_ptr, int x_length, int fs, double frame_period)
{
    return WorldNativeFun::Dio_JS(x_ptr, x_length, fs, frame_period);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Harvest(int x_ptr, int x_length, int fs, double frame_period)
{
    return WorldNativeFun::Harvest_JS(x_ptr, x_length, fs, frame_period);
}

EMSCRIPTEN_KEEPALIVE emscripten::val
WorldJS::CheapTrick(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fs)
{
    return WorldNativeFun::CheapTrick_JS(x_ptr, x_length, f0_ptr, f0_length, time_axis_ptr, fs);
}

EMSCRIPTEN_KEEPALIVE emscripten::val
WorldJS::D4C(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fft_size, int fs,double threshold)
{
    return WorldNativeFun::D4C_JS(x_ptr, x_length, f0_ptr, f0_length, time_axis_ptr, fft_size, fs,threshold);
}

EMSCRIPTEN_KEEPALIVE emscripten::val
WorldJS::Synthesis(int f0_ptr, int f0_length, const int spectrogram_ptr, const int aperiodicity_ptr,
                 int fft_size, int fs, const double frame_period)
{
    return WorldNativeFun::Synthesis_JS(f0_ptr, f0_length, spectrogram_ptr, aperiodicity_ptr, fft_size, fs, frame_period);
}

EMSCRIPTEN_KEEPALIVE void WorldJS::DisplayInformation(int fs, int nbit, int x_length)
{
    WorldNativeIO::DisplayInformation(fs, nbit, x_length);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::GetInformation(int fs, int nbit, int x_length)
{
    return WorldNativeIO::GetInformation(fs, nbit, x_length);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::WavRead(const std::string &filename)
{
    return WorldNativeIO::WavRead_JS(filename);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::WavWrite(emscripten::val y_val, int fs, const std::string &filename)
{
    return WorldNativeIO::WavWrite_JS(std::move(y_val), fs, filename);
}

EMSCRIPTEN_KEEPALIVE void WorldJS::DisplayInformationVal(emscripten::val x)
{
    WorldJSWrapper::DisplayInformationVal(std::move(x));
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::GetInformationVal(const emscripten::val &x)
{
    return WorldJSWrapper::GetInformationVal(x);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Wav2World(const std::string &fileName)
{
    return WorldJSWrapper::W2World(fileName);
}

//-----------------------------------------------------------------------------
// The JavaScript API bind for C++
//-----------------------------------------------------------------------------
EMSCRIPTEN_BINDINGS(WorldJS)
{
    emscripten::class_<WorldJS>("WorldJS")
        .constructor<>()
        .class_function("DisplayInformation", &WorldJS::DisplayInformation)
        .class_function("WavRead", &WorldJS::WavRead)
        .class_function("GetInformation", &WorldJS::GetInformation)
        .class_function("WavWrite", &WorldJS::WavWrite)
        .class_function("Dio", &WorldJS::Dio)
        .class_function("Harvest", &WorldJS::Harvest)
        .class_function("CheapTrick", &WorldJS::CheapTrick)
        .class_function("D4C", &WorldJS::D4C)
        .class_function("Synthesis", &WorldJS::Synthesis)
        .class_function("DisplayInformationVal", &WorldJS::DisplayInformationVal)
        .class_function("GetInformationVal", &WorldJS::GetInformationVal)
        .class_function("Wav2World", &WorldJS::Wav2World);
}
