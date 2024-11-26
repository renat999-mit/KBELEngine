#include "Application/Application.h"
#include <iostream>

using namespace KBEL;

class DummyApp : public Application
{
public:

  typedef Application BaseType;
  DummyApp(std::string appName = "DummyApp")
  : BaseType(appName)
  {}

  void onInit() override
  {
    std::cout << "Initializing DummyApp" << std::endl;
  }

  void run() override
  {
    std::cout << "Running DummyApp" << std::endl;
  }

  void onShutdown() override
  {
    std::cout << "Exiting DummyApp" << std::endl;
  }

};

std::shared_ptr<DummyApp> createApplication()
{
  return std::make_shared<DummyApp>();
};

