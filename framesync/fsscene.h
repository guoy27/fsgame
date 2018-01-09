//************************************************************************
// author:  guoyong@skyunion.net
// created: 2017/11/22
// desc:    
//************************************************************************
#pragma once
#include <map>
#include <list>
#include "random/random.h"

class FSEntity;
class FSAction;
class FSCommand;

class FSScene
{
public:
  FSScene();
  virtual ~FSScene();

  void Init( uint64_t random_seed );
  void Release();

  void Begin();
  void MoveForward(uint64_t frame_count);
  void End();

  bool AddCommand(uint64_t frame, FSCommand* command);

  bool AddEntity(uint64_t frame,FSEntity* entity);
  FSEntity* GetEntity(uint64_t entity_id);
  void RemoveEntity(uint64_t frame,uint64_t entity_id);
protected:
  uint64_t CheckFrame(uint64_t frame);
private:

  void UpdateFrame();


  virtual void OnBegin() {};
  virtual void OnEnd() {};

  uint64_t cur_frame_;

  std::map<uint64_t, FSEntity*> entities_;
  std::map<uint64_t,std::list<FSCommand*>> commands_;


  FSRandom random_;
};