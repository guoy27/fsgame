//************************************************************************
// author:  guoyong@skyunion.net
// created: 2018/01/03
// desc:    log
//************************************************************************
#pragma once
#include <mutex>

class LogHandler
{
public:
  LogHandler();
  ~LogHandler();

  void LogInfo(const char* srcfile, int srcline, const char* fmt, ...);

  static LogHandler sLogHandler;
protected:

private:

  std::mutex log_mutex_;

  char*      sbuffer_;
};

#define LOG(fmt, ...) \
  sLogHandler.LogInfo(__FILE__, __LINE__, fmt, __VA_ARGS__)
