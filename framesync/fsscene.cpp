#include "fsscene.h"
#include "fscommand.h"
#include "fsentity.h"

const uint64_t MAX_FRAME = 1000;
FSScene::FSScene()
{

}

FSScene::~FSScene()
{

}

void FSScene::Init(uint64_t random_seed)
{

}

void FSScene::Release()
{
  cur_frame_ = 0;

  for (auto& it : entities_)
  {
    delete it.second;
  }

  for (auto& it: commands_)
  {
    for (auto& command: it.second)
    {
      delete command;
    }
  }
  entities_.clear();
  commands_.clear();
}


void FSScene::Begin()
{
  cur_frame_ = 0;
  OnBegin();
}

void FSScene::MoveForward(uint64_t frame_count)
{
  for (int i=0;i<frame_count;++i)
  {
    ++cur_frame_;
    UpdateFrame();
    if (MAX_FRAME == cur_frame_)
    {
      End();
      break;
    }
  }
}

void FSScene::UpdateFrame()
{
  auto it = commands_.find(cur_frame_);
  if ( it != commands_.end())
  {
    for (auto& it : it->second)
    {
      it->HandleCommand(this);
    }
  }
  for (auto& it :entities_)
  {
    it.second->MoveForward(this);
  }
}

void FSScene::End()
{
  OnEnd();
}

bool FSScene::AddCommand(uint64_t frame, FSCommand* command)
{
  uint64_t real_frame = CheckFrame(frame);
  commands_[real_frame].push_back(command);
  return true;
}

bool FSScene::AddEntity(uint64_t frame, FSEntity* entity)
{
  if (entities_.find(entity->GetEntityID()) != entities_.end())
  {
    return false;
  }

  uint64_t real_frame = CheckFrame(frame);
  entity->SetStartFrame(real_frame);
  entities_[entity->GetEntityID()] = entity;
  return true;
}

FSEntity* FSScene::GetEntity(uint64_t entity_id)
{
  auto it = entities_.find(entity_id);
  if (it != entities_.end())
  {
    return it->second;
  }
  return nullptr;
}

void FSScene::RemoveEntity(uint64_t frame, uint64_t entity_id)
{
  auto it = entities_.find(entity_id);
  if (entities_.find(entity_id) != entities_.end())
  {
    return;
  }

  uint64_t real_frame = CheckFrame(frame);
  it->second->SetEndFrame(real_frame);
}

uint64_t FSScene::CheckFrame(uint64_t frame)
{
  if (frame == 0)
  {
    return cur_frame_ + 5;
  }
  else
  {
    return frame;
  }
}