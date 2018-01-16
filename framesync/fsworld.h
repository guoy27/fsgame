//************************************************************************
// author:  guoyong@skyunion.net
// created: 2018/01/16
// desc:    
//************************************************************************
#pragma once
#include <map>
#include <list>

class FSCommand;
class FSEntity;

class FSWorld
{
public:
  FSWorld();
  virtual ~FSWorld();

  void Start();
  void MoveOn();
  void End();

  void RunToFrame(uint32_t frame);
  void BackToFrame(uint32_t frame);

  void AddCommand(FSCommand* command, uint32_t start_frame);
  void AddEntity(FSEntity* command, uint32_t start_frame);

  void Reset();
  void Backup();

  virtual void Release();
private:
  uint32_t cur_frame_;
  std::map<uint32_t, FSEntity*>  entities_;
  std::map<uint32_t, std::list<FSCommand*>> commands_;
};