#pragma once

//******************************************************
// Includes
//******************************************************

#include "NameBase.h"

//******************************************************
// Classes
//******************************************************

#ifdef EPS32

class Service : public NameBase
{
private:
    // handle to store our created task
    mutable xTaskHandle taskHandle;
    mutable uint32_t stackDepth;
    mutable UBaseType_t priority;
    mutable int coreId;

    static void taskFunctionWrapper(void *parameter);

protected:
    virtual void TaskFunction() = 0;

public:
    Service(const String& name, uint32_t stackDepth, UBaseType_t priority, int coreId);
    virtual ~Service();

    virtual bool Start() const;
    virtual bool Stop() const;
};

#endif