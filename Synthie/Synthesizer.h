#pragma once

#include <list> 
#include "Instrument.h"
#include "msxml2.h"
#include "Note.h"
#include <vector>
#include "OddSinesFactory.h"
#include "WaveInstrumentFactory.h"

using namespace std;

class CSynthesizer
{
public:
    CSynthesizer();

    void Start(void);

    bool Generate(double* frame);

    void Clear(void);

    void OpenScore(CString& filename);

    void XmlLoadScore(IXMLDOMNode* xml);

    void XmlLoadInstrument(IXMLDOMNode* xml);

    void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);

    //! Number of audio channels
    int GetNumChannels() { return m_channels; }

    //! Sample rate in samples per second
    double GetSampleRate() { return m_sampleRate; }

    //! Sample period in seconds (1/samplerate)
    double GetSamplePeriod() { return m_samplePeriod; }

    //! Set the number of channels
    void SetNumChannels(int n) { m_channels = n; }

    //! Set the sample rate
    void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

    //! Get the time since we started generating audio
    double GetTime() { return time; }

    double GetBpm() { return m_bpm; }

private:
    int		m_channels;
    double	m_sampleRate;
    double	m_samplePeriod;
    double time;
    std::list<CInstrument*>  m_instruments;
    double  m_bpm;                  //!< Beats per minute
    int     m_beatspermeasure;  //!< Beats per measure
    double  m_secperbeat;        //!< Seconds per beat
    std::vector<CNote> m_notes;
    int m_currentNote;          //!< The current note we are playing
    int m_measure;              //!< The current measure
    double m_beat;              //!< The current beat within the measure
    COddSinesFactory m_oddsinesfactory;
    CWaveInstrumentFactory m_waveinstfactory;
};

