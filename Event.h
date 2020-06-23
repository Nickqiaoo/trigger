#pragma once

class Event {
   public:
    Event();
    ~Event();
    int32_t GetId();

   private:
    int32_t event_id_;
};

class LoginEvent : public Event{
    public:
    LoginEvent();
    ~LoginEvent();
    private:
    int32_t login_stamp_;
};


