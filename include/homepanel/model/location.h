#pragma once

#include <string>
#include <vector>

#include "homepanel/model/device.h"

namespace homepanel
{

  class Location
  {
    public:
      std::string name;

      std::vector<Device> devices;
  };

}  // namespace homepanel
