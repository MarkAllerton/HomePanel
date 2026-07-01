#pragma once

#include "homepanel/model/site.h"

namespace homepanel
{

  class Model
  {
    public:
      Site& site() { return m_site; }

    private:
      Site m_site;
  };

}  // namespace homepanel