#include "random.h"

FSRandom::FSRandom(uint64_t random_seed):random_seed_(random_seed)
{

}

FSRandom::FSRandom(): random_seed_(1)
{

}

FSRandom::~FSRandom()
{

}

void FSRandom::SetSeed(uint64_t random_seed)
{
  random_seed_ = random_seed;
  rand_times_ = 0;
}

void FSRandom::Init()
{
  rand_times_ = 0;
}

void FSRandom::Release()
{
  random_seed_ = 1;
  rand_times_ = 0;
}

uint64_t FSRandom::GetRandomValue()
{
  uint64_t rand_value = rand_times_ + random_seed_;
  ++rand_times_;
  return rand_value;
}
