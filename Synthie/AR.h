#pragma once
#include "AudioNode.h"
class CAR :
    public CAudioNode
{
public:
    CAR();
    virtual ~CAR();

    void SetSource(CAudioNode *s) { source = s; }
    void SetDuration(double dur) { duration = dur; }
    void SetAttack(double att) { attack = att; }
    void SetRelease(double rel) { release = rel; }
    virtual void Start();
    virtual bool Generate();

private:

    CAudioNode* source;
    double attack;
    double release;
    double time;
    double duration;
};

