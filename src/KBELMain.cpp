#include <memory>
#include "Application/Application.h"
#include "Login/Logger.h"

using namespace KBEL;

extern std::shared_ptr<Application> createApplication();

/*

Usage mode for now:

./appExec --log-to-file <path> --log-to-terminal=true/false

*/

int KBELmain(int argc, char* argv[])
{

  // Parse command line arguments
  bool logToFile = false;
  std::string logFileName = "dummyName.txt";
  bool logToTerminal = true;
  for (int i = 1; i < argc; i++)
  {
    std::string arg = argv[i];
    if (arg == "--log-to-file" && i+1 < argc)
    {
      logToFile = true;
      logFileName = argv[i+1];
      i++;
    }
    else if (arg == "--log-to-terminal=true")
    {
      logToTerminal = true;
    }
    else if (arg == "--log-to-terminal=false")
    {
      logToTerminal = false;
    }
    else
    {
      std::cerr << "Command not found: " << arg << std::endl;
      return -1;
    }
  }

  Logger logger(logToFile, logFileName, logToTerminal);

  try
  {
    std::shared_ptr<Application> app = createApplication();
    if(!app)
    {
      std::string errMsg = "Failed to initialize application: " + app->getName();
      throw std::runtime_error(errMsg);
    }

    {
      std::string logMsg = "Loaded application: " + app->getName();
      logger.registerLog(logMsg, Logger::INFO);
    }

    app->onInit();
    app->run();
    app->onShutdown();

    {
      std::string logMsg = "Exited application: " + app->getName();
      logger.registerLog(logMsg, Logger::INFO);
    }

    return 0;
  }
  catch (const std::exception& except)
  {
    logger.registerLog(except.what(), Logger::ERROR);
    return -1;
  }
};
