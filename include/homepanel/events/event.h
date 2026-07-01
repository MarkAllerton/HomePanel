#pragma once

namespace homepanel
{

  struct TouchPressedEvent
  {
      int x;
      int y;
  };

  struct TouchReleasedEvent
  {
      int x;
      int y;
  };

  struct ButtonPressedEvent
  {
      int button;
  };

  struct ButtonReleasedEvent
  {
      int button;
  };

  struct ScreenChangedEvent
  {
      int screenId;
  };

}  // namespace homepanel
