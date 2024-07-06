#pragma once

//******************************************************
// Includes
//******************************************************

#include "EventHandler.h"

//******************************************************
// Classes
//******************************************************

class ValueChangedBase
{
protected:
    void HandleValueChanged()
    {
        EventArgs e;

        for (EventHandler eventHandler : ValueChanged)
        {
            eventHandler(e);
        }
        OnValueChanged(e);
    }

    virtual void OnValueChanged(EventArgs e) {}

public:
    EventHandlerList ValueChanged;

    ValueChangedBase() {}
};