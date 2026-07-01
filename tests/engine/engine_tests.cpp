#include <gtest/gtest.h>

#include "homepanel/engine/engine.h"

namespace homepanel::tests
{

  TEST(EngineTests, CanBeConstructed)
  {
    EXPECT_NO_THROW({ Engine engine; });
  }

  TEST(EngineTests, InitializeDoesNotThrow)
  {
    Engine engine;

    EXPECT_NO_THROW({ engine.initialize(); });
  }

  TEST(EngineTests, ShutdownDoesNotThrow)
  {
    Engine engine;

    engine.initialize();

    EXPECT_NO_THROW({ engine.shutdown(); });
  }

  TEST(EngineTests, RunDoesNotThrow)
  {
    Engine engine;

    engine.initialize();

    EXPECT_NO_THROW({ engine.run(); });
  }

  TEST(EngineTests, CanBeInitializedMultipleTimes)
  {
    Engine engine;

    EXPECT_NO_THROW({
      engine.initialize();
      engine.shutdown();

      engine.initialize();
      engine.shutdown();
    });
  }

}  // namespace homepanel::tests