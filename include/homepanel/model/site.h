#pragma once

#include <vector>

#include "homepanel/model/location.h"

namespace homepanel
{

  class Site
  {
    public:
      std::vector<Location>& locations() { return m_locations; }

    private:
      std::vector<Location> m_locations;
  };

}  // namespace homepanel
