//******************************************************
// Includes
//******************************************************

#include "Service.h"

#ifdef ESP32

//******************************************************
// Public Methods
//******************************************************

Service::Service(const String &name, uint32_t stackDepth, UBaseType_t priority, int coreId)
    : NameBase(name), taskHandle(NULL), stackDepth(stackDepth), priority(priority), coreId(coreId)
{
}

Service::~Service()
{
    Stop();
}

bool Service::Start() const
{
    if (taskHandle == NULL)
    {
        xTaskCreatePinnedToCore(taskFunctionWrapper, Name().c_str(), stackDepth, (void*)this, priority, &taskHandle, coreId);
    }

    return false;
}

bool Service::Stop() const
{
    if (taskHandle != NULL)
    {
        vTaskDelete(taskHandle);
        taskHandle = NULL;
    }
    return false;
}

//******************************************************
// Protected Methods
//******************************************************

//******************************************************
// Private Methods
//******************************************************

void Service::taskFunctionWrapper(void *parameter)
{
    Service* thisService = static_cast<Service*>(parameter);

    thisService->TaskFunction();

    vTaskDelete(thisService->taskHandle);
}

#endif // ESP32