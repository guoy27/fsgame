#include "fsmove_command.h"
#include "fsscene.h"
#include "fsentity.h"


FSMoveCommand::FSMoveCommand(uint64_t entity_id, uint64_t x, uint64_t y):entity_id_(entity_id),x_(x),y_(y)
{

}

FSMoveCommand::~FSMoveCommand()
{

}

void FSMoveCommand::Init()
{
}

void FSMoveCommand::Release()
{

}

void FSMoveCommand::HandleCommand(FSScene* scene)
{
  if (!scene)
  {
    return;
  }
  auto entity = scene->GetEntity(entity_id_);
  if (entity)
  {
    entity->SetMoveDir(x_, y_);
  }
}
