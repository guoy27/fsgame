//************************************************************************
// author:  guoyong@skyunion.net
// created: 2018/01/16
// desc:    
//************************************************************************
#pragma once

class FSCommand;
class FSWorld;
class FSEntity
{
public:
  FSEntity(FSWorld* world);
  virtual ~FSEntity();

  void MoveOn();
  void DoCommand(FSCommand* command);
  void Reset();
  void Backup();

private:
  FSWorld* world_;
};