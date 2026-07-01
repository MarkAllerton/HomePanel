#pragma once

#include "homepanel/events/event_bus.h"

namespace homepanel
{

  class Engine
  {
    public:
      Engine();
      ~Engine();

      void initialize();
      void shutdown();
      void run();

    private:
      std::unique_ptr<EventBus> m_eventBus;
  };

}  // namespace homepanel