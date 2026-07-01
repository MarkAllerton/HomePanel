#pragma once

class Plugin
{
  public:
    virtual ~Plugin() = default;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
};
