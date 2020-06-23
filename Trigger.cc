#include "Trigger.h"
#include "Event.h"
#include "TriggerCondition.h"

void Trigger::TriggerEvent(Event* event){
    auto condIter = cond_map_.find(event->GetId());
    if(condIter != cond_map_.end()){
        for(auto condId: condIter->second){
            auto triggerIter = trigger_map_.find(condId);
            if(triggerIter!=trigger_map_.end()){
                for(auto cond : triggerIter->second){
                    cond->CondtionCallback(event);
                }
            }
        }
    }
}
