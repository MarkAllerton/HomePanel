#pragma once

#include <string>
#include <variant>

namespace homepanel
{

  using EntityValue = std::variant<bool, int, float, std::string>;

  class Entity
  {
    public:
      std::string id;

      std::string name;

      EntityValue value;
  };

}  // namespace homepanel
