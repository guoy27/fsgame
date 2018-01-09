//************************************************************************
// author:  guoyong@skyunion.net
// created: 2017/11/23
// desc:    
//************************************************************************
#pragma once
#include <map>
#include "fscommand.h"

class FSScene;
class FSMoveCommand : public FSCommand
{
public:
  FSMoveCommand(uint64_t entity_id, uint64_t x, uint64_t y);
  virtual ~FSMoveCommand();

  virtual void Init();
  virtual void Release();

  virtual void HandleCommand(FSScene* scene);
private:
  uint64_t entity_id_;
  uint64_t x_;
  uint64_t y_;

};