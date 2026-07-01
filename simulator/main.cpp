#include <iostream>

#include "homepanel/engine/engine.h"
int main()
{
  homepanel::Engine e;
  e.initialize();
  std::cout << "HomePanel Engine v0.1.0\n";
}
