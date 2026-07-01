#pragma once

namespace homepanel
{

  template <typename Event>
  Subscription EventBus::subscribe(Handler<Event> handler)
  {
    auto type = std::type_index(typeid(Event));

    auto& ptr = m_handlers[type];

    if (!ptr)
    {
      ptr = std::make_unique<HandlerList<Event>>();
    }

    auto* list    = static_cast<HandlerList<Event>*>(ptr.get());

    const auto id = m_nextSubscriptionId++;

    list->handlers.push_back({id, true, std::move(handler)});

    return Subscription([this, type, id] { unsubscribe(type, id); });
  }

  template <typename Event>
  void EventBus::publish(const Event& event)
  {
    DispatchGuard guard(*this);

    auto it = m_handlers.find(typeid(Event));

    if (it == m_handlers.end()) return;

    auto* list = static_cast<HandlerList<Event>*>(it->second.get());

    for (auto& h : list->handlers)
    {
      if (h.active)
      {
        h.handler(event);
      }
    }
  }

}  // namespace homepanel
