#pragma once

//******************************************************
// Includes
//******************************************************

#include "EventHandler.h"

//******************************************************
// Classes
//******************************************************

class ValueUpdateBase
{
protected:
    void HandleValueUpdate()
    {
        EventArgs e;

        for (EventHandler eventHandler : ValueUpdate)
        {
            eventHandler(e);
        }
        OnValueUpdate(e);
    }

    virtual void OnValueUpdate(EventArgs e) {}

public:
    EventHandlerList ValueUpdate;

    ValueUpdateBase() {}
};