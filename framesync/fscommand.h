//************************************************************************
// author:  guoyong@skyunion.net
// created: 2018/01/16
// desc:    
//************************************************************************
#pragma once

class FSEntity;
class FSWorld;
class FSCommand
{
public:
  FSCommand(FSWorld* world);
  virtual ~FSCommand();

  void DoCommand();

  virtual void OnHandleEntity(FSEntity* entity);

};