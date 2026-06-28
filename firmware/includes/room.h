#pragma once
#include <string>
struct Room{
 std::string name;
 float temperature{};
 float humidity{};
 bool occupied{};
 bool climate_on{};
};
