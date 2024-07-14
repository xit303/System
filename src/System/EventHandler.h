#pragma once

//******************************************************
// Includes
//******************************************************

#include <functional>
#include <list>

//******************************************************
// Classes
//******************************************************

class EventArgs
{
public:
    bool Handled;

    EventArgs()
    {
        Handled = false;
    }
};

using EventHandler = std::function<void(EventArgs&)>;
using EventHandlerList = std::list<EventHandler>;