#include "room_manager.h"
void RoomManager::add(const Room&r){rooms_.push_back(r);}
Room& RoomManager::current(){return rooms_.at(current_);}
void RoomManager::next(){if(!rooms_.empty()) current_=(current_+1)%rooms_.size();}
void RoomManager::previous(){if(!rooms_.empty()) current_=(current_+rooms_.size()-1)%rooms_.size();}
const std::vector<Room>& RoomManager::rooms() const{return rooms_;}
