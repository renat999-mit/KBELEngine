#pragma once

#include <string>

namespace KBEL
{

class Application
{
public:

  Application() = default;
  virtual ~Application() = default;

  virtual void onInit() = 0;
  virtual void run() = 0;
  virtual void onShutdown() = 0;

  std::string getName() const { return appName_; }

private:

  std::string appName_;

};

} // end namespace KBEL
