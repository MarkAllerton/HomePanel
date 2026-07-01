#pragma once

class EventBus
{
  public:
    template <typename TEvent>
    void publish(const TEvent&);

    template <typename TEvent>
    void subscribe(...);
};