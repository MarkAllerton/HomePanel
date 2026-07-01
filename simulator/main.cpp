#include <iostream>

#include "homepanel/engine/engine.h"
#include "homepanel/events/event.h"

int main()
{
  homepanel::Engine e;
  e.initialize();
  std::cout << "HomePanel Engine v0.1.0\n";

  // Template test code

  homepanel::EventBus bus;

  auto sub1 = bus.subscribe<homepanel::TouchPressedEvent>(
      [](const homepanel::TouchPressedEvent& e) {
        std::cout << "Touch: " << e.x << ", " << e.y << '\n';
      }
  );

  auto sub2 = bus.subscribe<homepanel::ButtonPressedEvent>(
      [](const homepanel::ButtonPressedEvent& e) {
        std::cout << "Button handler #1: " << e.button << '\n';
      }
  );

  auto sub3 = bus.subscribe<homepanel::ButtonPressedEvent>(
      [](const homepanel::ButtonPressedEvent& e) {
        std::cout << "Button handler #2: " << e.button << '\n';
      }
  );

  bus.publish(homepanel::TouchPressedEvent{10, 20});

  bus.publish(homepanel::ButtonPressedEvent{3});

  sub2.reset();

  bus.publish(homepanel::ButtonPressedEvent{7});
}
