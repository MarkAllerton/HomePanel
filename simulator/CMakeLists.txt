add_executable(homepanel_sim 
               main.cpp 
               ../src/events/event_bus.cpp
               ../src/events/subscription.cpp
               ../src/engine/engine.cpp)

target_include_directories(homepanel_sim PRIVATE ../include)
