#include "homepanel/events/subscription.h"

namespace homepanel
{

  Subscription::Subscription(std::function<void()> unsubscribe)
      : m_unsubscribe(std::move(unsubscribe))
  {
  }

  Subscription::~Subscription() { reset(); }

  Subscription::Subscription(Subscription&& other) noexcept
      : m_unsubscribe(std::move(other.m_unsubscribe))
  {
    other.m_unsubscribe = nullptr;
  }

  Subscription& Subscription::operator=(Subscription&& other) noexcept
  {
    if (this != &other)
    {
      reset();

      m_unsubscribe       = std::move(other.m_unsubscribe);

      other.m_unsubscribe = nullptr;
    }

    return *this;
  }

  void Subscription::reset()
  {
    if (m_unsubscribe)
    {
      m_unsubscribe();
      m_unsubscribe = nullptr;
    }
  }

}  // namespace homepanel
