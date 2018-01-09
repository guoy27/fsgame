//************************************************************************
// author:  guoyong@skyunion.net
// created: 2017/11/23
// desc:    
//************************************************************************
#pragma once

class FSScene;
class FSCommand
{
public:
  FSCommand() {}
  virtual ~FSCommand() {}

  virtual void Init() {};
  virtual void Release() {};

  virtual void HandleCommand(FSScene* scene) = 0;
private:

};