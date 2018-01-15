//************************************************************************
// author:  guoyong@skyunion.net
// created: 2017/11/22
// desc:    
//************************************************************************
#pragma once
#include <list>

namespace Common
{
  class Random
  {
  public:
    Random(uint64_t random_seed);
    Random();
    virtual ~Random();

    void SetSeed(uint64_t random_seed);

    virtual void Init();
    virtual void Release();

    uint64_t GetRandomValue();

  private:
    uint64_t random_seed_;
    uint64_t rand_times_;
  };

}
