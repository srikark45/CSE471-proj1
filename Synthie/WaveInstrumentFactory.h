#pragma once
#include "WaveInstrument.h"
#include "audio/DirSoundSource.h"
#include <vector>

class CWaveInstrumentFactory
{
public:
    CWaveInstrumentFactory(void);
    ~CWaveInstrumentFactory(void);

    void SetNote(CNote* note);
    bool LoadFile(const char* filename);
    CWaveInstrument* CreateInstrument();

private:
    std::vector<short> m_wave;
};