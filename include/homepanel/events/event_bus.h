#pragma once

#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

#include "subscription.h"

namespace homepanel
{

  class EventBus
  {
    public:
      EventBus()  = default;
      ~EventBus() = default;

      template <typename Event>
      using Handler = std::function<void(const Event&)>;

      template <typename Event>
      Subscription subscribe(Handler<Event> handler);

      template <typename Event>
      void publish(const Event& event);

    private:
      struct IHandlerList
      {
          virtual ~IHandlerList()            = default;

          virtual void deactivate(size_t id) = 0;
          virtual void compact()             = 0;
          virtual bool empty() const         = 0;
      };

      template <typename Event>
      struct HandlerEntry
      {
          size_t id;
          bool active = true;
          Handler<Event> handler;
      };

      template <typename Event>
      struct HandlerList : IHandlerList
      {
          std::vector<HandlerEntry<Event>> handlers;

          void deactivate(size_t id) override
          {
            for (auto& h : handlers)
            {
              if (h.id == id)
              {
                h.active = false;
                return;
              }
            }
          }

          void compact() override
          {
            std::erase_if(handlers, [](const auto& h) { return !h.active; });
          }

          bool empty() const override { return handlers.empty(); }
      };

      void unsubscribe(const std::type_index& type, size_t id);

      void compact();

      class DispatchGuard
      {
        public:
          explicit DispatchGuard(EventBus& bus);
          ~DispatchGuard();

        private:
          EventBus& m_bus;
      };

      std::unordered_map<std::type_index, std::unique_ptr<IHandlerList>>
          m_handlers;

      size_t m_nextSubscriptionId = 1;
      size_t m_publishDepth       = 0;
      size_t subscriberCount() const;
      size_t eventTypeCount() const;
  };

}  // namespace homepanel

#include "EventBus.inl"
