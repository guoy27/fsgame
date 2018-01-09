#include "fsentity.h"

FSEntity::FSEntity(uint64_t entity_id, int64_t x, int64_t y)
                  :entity_id_(entity_id)
                  , cur_pos_x_(x)
                  , cur_pos_y_(y)
                  , start_frame_(0)
                  , end_frame_(0)
                  , move_x_(0)
                  , move_y_(0)
{

}

FSEntity::~FSEntity()
{

}

void FSEntity::SetStartFrame(uint64_t frame)
{
  start_frame_ = frame;
}

void FSEntity::SetEndFrame(uint64_t frame)
{
  end_frame_ = frame;
}

void FSEntity::MoveForward(FSScene* scene)
{
  if (move_x_!=0|| move_y_!=0)
  {
    cur_pos_x_ += move_x_;
    cur_pos_y_ += move_y_;
  }
}

uint64_t FSEntity::GetEntityID()const
{
  return entity_id_;
}

void FSEntity::SetMoveDir(int64_t x, int64_t y)
{
  move_x_ = x;
  move_y_ = y;
}
