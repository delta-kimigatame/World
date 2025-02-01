#ifndef WORLDJS_WORLDJS_H
#define WORLDJS_WORLDJS_H
//-----------------------------------------------------------------------------
// WORLD core functions.
//-----------------------------------------------------------------------------
#include "world/d4c.h"
#include "world/dio.h"
#include "world/harvest.h"
#include "world/matlabfunctions.h"
#include "world/cheaptrick.h"
#include "world/stonemask.h"
#include "world/synthesis.h"
#include "world/synthesisrealtime.h"

//-----------------------------------------------------------------------------
// WORLD IO functions.
//-----------------------------------------------------------------------------
#include "audioio.h"

//-----------------------------------------------------------------------------
// WORLD JS functions.
//-----------------------------------------------------------------------------
#include "ErrorCode.h"
#include "Converter.h"
#include "Wav2World.h"
#include "WorldNativeIO.h"
#include "WorldNativeFun.h"
#include "WorldJSWrapper.h"

//-----------------------------------------------------------------------------
// emscripten functions.
//-----------------------------------------------------------------------------
#include <emscripten.h>
#include <emscripten/val.h>
#include <emscripten/bind.h>

class WorldJS
{
public:
    WorldJS() = default;

    ~WorldJS() = default;

    static EMSCRIPTEN_KEEPALIVE emscripten::val Dio(int x_ptr, int x_length, int fs, double frame_period);

    static EMSCRIPTEN_KEEPALIVE emscripten::val Harvest(int x_ptr, int x_length, int fs, double frame_period);

    static EMSCRIPTEN_KEEPALIVE emscripten::val
    CheapTrick(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fs);

    static EMSCRIPTEN_KEEPALIVE emscripten::val
    D4C(int x_ptr, int x_length, int f0_ptr, int f0_length, int time_axis_ptr, int fft_size, int fs,double threshold);

    static EMSCRIPTEN_KEEPALIVE emscripten::val
    Synthesis(int f0_ptr, int f0_length, const int spectrogram_ptr, const int aperiodicity_ptr,
                 int fft_size, int fs, const double frame_period);

    static EMSCRIPTEN_KEEPALIVE void DisplayInformation(int fs, int nbit, int x_length);

    static EMSCRIPTEN_KEEPALIVE emscripten::val GetInformation(int fs, int nbit, int x_length);

    static EMSCRIPTEN_KEEPALIVE emscripten::val WavRead(const std::string &filename);

    static EMSCRIPTEN_KEEPALIVE emscripten::val WavWrite(emscripten::val y_val, int fs, const std::string &filename);

    static EMSCRIPTEN_KEEPALIVE void DisplayInformationVal(emscripten::val x);

    static EMSCRIPTEN_KEEPALIVE emscripten::val GetInformationVal(const emscripten::val &x);

    static EMSCRIPTEN_KEEPALIVE emscripten::val Wav2World(const std::string &fileName);
};

#endif // WORLDJS_WORLDJS_H