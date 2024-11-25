#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

namespace KBEL
{

class Logger
{
public:

  Logger(const bool& logToFile = false, const std::string& fileName = "logKBELEngine.out", const bool& verbose = true);

  enum EventCategory
  {
    INFO,
    WARNING,
    ERROR,
    DEBUG
  };

  void registerLog(const std::string& logMessage, EventCategory category); // event happens

private:

  void setLogFile(const std::string& fileName); // ability to set up a file in which the log info will be written
  std::string getTimeInfo() const; // time information for when the event occurs
  std::ofstream logFile_;
  const bool verbose_;
};

} // end namespace KBEL
