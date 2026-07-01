#include "homepanel/events/event_bus.h"

namespace homepanel
{

  EventBus::DispatchGuard::DispatchGuard(EventBus& bus) : m_bus(bus)
  {
    ++m_bus.m_publishDepth;
  }

  EventBus::DispatchGuard::~DispatchGuard()
  {
    --m_bus.m_publishDepth;

    if (m_bus.m_publishDepth == 0)
    {
      m_bus.compact();
    }
  }

  void EventBus::unsubscribe(const std::type_index& type, size_t id)
  {
    auto it = m_handlers.find(type);

    if (it != m_handlers.end())
    {
      it->second->deactivate(id);

      if (m_publishDepth == 0)
      {
        compact();
      }
    }
  }

  void EventBus::compact()
  {
    for (auto& [_, list] : m_handlers)
    {
      list->compact();
    }

    std::erase_if(m_handlers, [](const auto& pair) {
      return pair.second->empty();
    });
  }

}  // namespace homepanel
