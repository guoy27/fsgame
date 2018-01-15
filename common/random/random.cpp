#include "random.h"

namespace Common
{
  Random::Random(uint64_t random_seed) :random_seed_(random_seed)
  {

  }

  Random::Random() : random_seed_(1)
  {

  }

  Random::~Random()
  {

  }

  void Random::SetSeed(uint64_t random_seed)
  {
    random_seed_ = random_seed;
    rand_times_ = 0;
  }

  void Random::Init()
  {
    rand_times_ = 0;
  }

  void Random::Release()
  {
    random_seed_ = 1;
    rand_times_ = 0;
  }

  uint64_t Random::GetRandomValue()
  {
    uint64_t rand_value = rand_times_ + random_seed_;
    ++rand_times_;
    return rand_value;
  }

}
