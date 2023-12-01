#pragma once
#include "Instrument.h"
#include "SineWave.h"
#include "AR.h"

#include "Note.h"

class CToneInstrument :
    public CInstrument
{
public:
    CToneInstrument();

    virtual void Start();
    virtual bool Generate();

    void SetNote(CNote* note);

    void SetFreq(double f) { m_sinewave.SetFreq(f); }
    void SetAmplitude(double a) { m_sinewave.SetAmplitude(a); }
    void SetDuration(double d) { m_duration = d; }

private:
    CSineWave   m_sinewave;
    double m_duration;
    double time;
    CAR         m_ar;

};

