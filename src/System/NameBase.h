#pragma once

//******************************************************
// Includes
//******************************************************

#include <Arduino.h>
#include <list>
#include <functional>

#include "EventHandler.h"

//******************************************************
// Classes
//******************************************************

class NameBase
{
private:
    String name;

    void HandleNameChanged()
    {
        EventArgs e;

        for (EventHandler eventHandler : NameChanged)
        {
            eventHandler(e);
        }
        OnNameChanged(e);
    }

protected:
    virtual void OnNameChanged(EventArgs e) {}

public:
    EventHandlerList NameChanged;

    const String &Name() const { return name; }
    void Name(const String &value)
    {
        if (name != value)
        {
            name = value;
            HandleNameChanged();
        }
    }

    NameBase() {}
    NameBase(const String &name) : name(name) {}
    NameBase(const NameBase &other) : name(other.name) {}
};