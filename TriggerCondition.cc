#include "TriggerCondition.h"

void TriggerCondition::CondtionCallback(Event* event){
    if(Judge(event)){
        callback_(event);
    }
}
