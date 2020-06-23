#pragma once

#include <functional>

class Event;
typedef std::function<void(Event*)> ConditionCb;

class TriggerCondition {
   public:
    TriggerCondition();
    ~TriggerCondition();

    void CondtionCallback(Event*);
   private:
    virtual bool Judge(Event*) = 0;
   private:
    int32_t trigger_id_;
    ConditionCb callback_;
};

//累计value1天在value2-value3时间内在线
class AccumulateDuringOnlineTime : public TriggerCondition {
   public:
    AccumulateDuringOnlineTime();
    ~AccumulateDuringOnlineTime();

   private:
    virtual bool Judge(Event*);
   private:
    int32_t value1_;
    int32_t value2_;
    int32_t value3_;
};