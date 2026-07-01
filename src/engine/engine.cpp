#include "homepanel/engine/engine.h"

#include <iostream>

namespace homepanel
{

  Engine::Engine()
  {
    std::cout << "Engine instatiated, yay\n";
    m_eventBus = std::make_unique<EventBus>();
    int x      = 0;
    int y      = 10;
  }

  Engine::~Engine() = default;

  void Engine::initialize() {}

  void Engine::shutdown() {}

  void Engine::run() {}

}  // namespace homepanel
