#include "homepanel/engine/engine.h"
namespace homepanel
{
  Engine::initialize()
  {
    m_services.platform().initialize();
    m_services.renderer().initialize();

    // Later:
    // plugins.initialize();
  }
}  // namespace homepanel
