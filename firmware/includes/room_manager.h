#pragma once
#include <vector>
#include "room.h"
class RoomManager{
public:
 void add(const Room&);
 Room& current();
 void next();
 void previous();
 const std::vector<Room>& rooms() const;
private:
 std::vector<Room> rooms_;
 size_t current_{0};
};
