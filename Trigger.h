#pragma once

#include <unordered_map>
#include <vector>
#include <functional>

class Event;
class TriggerCondition;

class Trigger {
   public:
    Trigger();
    ~Trigger();

    void RegisterEventTrigger(int32_t eventId, int32_t triggerId);
    void RegisterTriggerCondition(int32_t triggerId, TriggerCondition* condition);
    void TriggerEvent(Event* event);

   private:
    std::unordered_map<int32_t, std::vector<int32_t>> cond_map_;
    std::unordered_map<int32_t, std::vector<TriggerCondition*>> trigger_map_;
};