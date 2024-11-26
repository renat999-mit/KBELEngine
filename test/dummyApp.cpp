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


// Forward declaration of the engine's main function
extern int KBELmain(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    // Forward call to the engine's main function
    return KBELmain(argc, argv);
}
