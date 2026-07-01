#pragma once

class ServiceRegistry
{
  public:
    EventBus& eventBus();
    Model& model();
    Renderer& renderer();
    Navigation& navigation();
    Platform& platform();
    PluginManager& plugins();
};
