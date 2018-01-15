#include "log.h"
#include <iostream>
#include <cstdarg>
#include <stdio.h>
const uint32_t MAX_LOG_BUFF_SIZE = 1024;

namespace Common
{
  Log::Log()
  {
    sbuffer_ = new char[MAX_LOG_BUFF_SIZE];
  }

  Log::~Log()
  {
    delete[] sbuffer_;
  }

  void Log::LogInfo(const char* srcfile, int srcline, const char* fmt, ...)
  {
    if (srcfile == nullptr || fmt == nullptr)
    {
      return;
    }

    std::lock_guard<std::mutex> guard(log_mutex_);

    va_list arg;
    va_start(arg, fmt);
    int ret = vsnprintf_s(sbuffer_, sizeof(sbuffer_) - 1, _TRUNCATE, fmt, arg);
    va_end(arg);

    if (ret < 0)
    {
      return;
    }

    ret = sprintf_s(
      sbuffer_ + ret, sizeof(sbuffer_) - ret, " %s, %d", srcfile, srcline);
    if (ret < 0)
    {
      return;
    }
    printf(sbuffer_);
  }

}
