#pragma once

//******************************************************
// Includes
//******************************************************

#include "NameBase.h"

//******************************************************
// Classes
//******************************************************

class Channel;

class Action : public NameBase
{
public:
    Action() {}
    Action(const String &name) : NameBase(name) {}

    virtual void operator ()(Channel *channel) = 0;
};