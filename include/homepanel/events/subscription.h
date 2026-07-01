#pragma once

#include <functional>

namespace homepanel
{

  class Subscription
  {
    public:
      Subscription() = default;

      explicit Subscription(std::function<void()> unsubscribe);

      ~Subscription();

      Subscription(const Subscription&)            = delete;
      Subscription& operator=(const Subscription&) = delete;

      Subscription(Subscription&& other) noexcept;
      Subscription& operator=(Subscription&& other) noexcept;

      void reset();

    private:
      std::function<void()> m_unsubscribe;
  };

}  // namespace homepanel
