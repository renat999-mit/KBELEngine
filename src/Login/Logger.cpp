#include "Logger.h"

namespace KBEL
{

Logger::Logger(const bool& logToFile, const std::string& fileName, const bool& verbose)
: verbose_(verbose)
{
  if (logToFile)
    setLogFile(fileName);

  std::string logMessage = "Initializing KBELEngine...";
  registerLog(logMessage, INFO);
}

Logger::~Logger()
{
  std::string logMessage = "Exiting KBELEngine...";
  registerLog(logMessage, INFO);
}

void Logger::registerLog(const std::string& logMessage, const EventCategory category)
{
  std::string categoryLabel;
  switch (category)
  {
    case INFO: categoryLabel = "[INFO]"; break;
    case WARNING: categoryLabel = "[WARNING]"; break;
    case ERROR: categoryLabel = "[ERROR]"; break;
    case DEBUG: categoryLabel = "[DEBUG]"; break;
  }

  std::string outputMessage = getTimeInfo() + " " + categoryLabel  + ": " + logMessage;

  if (verbose_)
  {
    if(category == ERROR)
      std::cerr << outputMessage << std::endl;
    else
      std::cout << outputMessage << std::endl;
  }

  if (logFile_.is_open())
    logFile_ << outputMessage << std::endl;
}

void Logger::setLogFile(const std::string& fileName)
{
  logFile_.open(fileName, std::ios::out | std::ios::app); // open file in write + append mode
  if (!logFile_.is_open())
  {
    std::cerr << "Error opening file to write log information. File name: " << fileName << std::endl;
    std::terminate();
  }
}

std::string Logger::getTimeInfo() const
{
  // get current time: first relative to system clock and then converted to time_t
  std::chrono::time_point nowReference = std::chrono::system_clock::now();
  std::time_t nowTime = std::chrono::system_clock::to_time_t(nowReference);

  char buffer[26];
  ctime_r(&nowTime, buffer); // write the time into buffer in format: e.g. Wed Nov 29 14:33:20 2023\n

  buffer[24] = '\0';

  return std::string(buffer);
}


} //end namespace KBEL