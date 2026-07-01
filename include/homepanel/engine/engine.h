#pragma once

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
  };

}  // namespace homepanel