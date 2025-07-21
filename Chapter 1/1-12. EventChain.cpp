#include "EventChain.h"
#include "Engine/World.h"

UEventChain::UEventChain()
{
}

void UEventChain::StartEventChain()
{
    if (EventSequence.Num() > 0)
    {
        ExecuteEvent(0);
    }
}
void UEventChain::AddEvent(float TimeDelay, FTimerDelegate TimerDelegate)
{
    // Adding a tuple with TimeDelay and TimerDelegate to the EventSequence
    EventSequence.Add({ TimeDelay, TimerDelegate });
}

void UEventChain::ExecuteEvent(int32 EventIndex)
{
    if (EventIndex < EventSequence.Num())
    {
        // Execute the event delegate
        EventSequence[EventIndex].Value.ExecuteIfBound();
        
        // Increment event index
        EventIndex++;
        
        // If there are more events, set a timer for the next one
        if (EventIndex < EventSequence.Num())
        {
            float NextDelay = EventSequence[EventIndex].Key;
            GetWorld()->GetTimerManager().SetTimer(EventTimerHandle, [this, EventIndex]()
            {
                ExecuteEvent(EventIndex);
            }, NextDelay, false);
        }
    }
}
