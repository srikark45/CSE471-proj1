#include "stdafx.h"
#include "AR.h"

CAR::CAR()
{
	duration = 0.1;
	attack = 0.05;
	release = 0.05l;

}

CAR::~CAR()
{

}

void CAR::Start()
{
	time = 0;
	source->SetSampleRate(GetSampleRate());
	source->Start();
	
}

bool CAR::Generate()
{
    source->Generate();

    if (time < attack)
    {
        m_frame[0] = source->Frame(0) * time / attack;
        m_frame[1] = source->Frame(1) * time / attack;
    }
    else if (time > duration - release)
    {
        m_frame[0] = source->Frame(0) * (duration - time) / release;
        m_frame[1] = source->Frame(1) * (duration - time) / release;
    }
    else
    {
        m_frame[0] = source->Frame(0);
        m_frame[1] = source->Frame(1);
    }

    time = GetSamplePeriod() + time;

    return time < duration;
}
