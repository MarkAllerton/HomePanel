#pragma once

#include <string>
#include <vector>

#include "homepanel/model/entity.h"

namespace homepanel
{

  class Device
  {
    public:
      std::string name;

      std::vector<Entity> entities;
  };
}  // namespace homepanel