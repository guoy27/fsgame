//************************************************************************
// author:  guoyong@skyunion.net
// created: 2017/11/23
// desc:    
//************************************************************************
#pragma once
#include <vector>

class FSScene;
class FSEntity
{
public:
  FSEntity(uint64_t entity_id, int64_t x,int64_t y);
  virtual ~FSEntity();

  virtual void Init() {}
  virtual void Release() {}
  void SetStartFrame(uint64_t frame);
  void SetEndFrame(uint64_t frame);

  virtual void MoveForward(FSScene* scene);

  uint64_t GetEntityID()const;

  void SetMoveDir(int64_t x, int64_t y);

private:
  uint64_t entity_id_;

  int64_t cur_pos_x_;
  int64_t cur_pos_y_;

  int64_t move_x_;
  int64_t move_y_;

  int64_t start_frame_;
  int64_t end_frame_;
};