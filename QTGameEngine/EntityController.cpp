#include "EntityController.h"

using namespace QTGameEngine;

EntityController::EntityController()
	:_entity(nullptr)
{
	//empty
}

EntityController::EntityController(Entity * entity)
	: _entity(entity)
{
	//empty
}

void QTGameEngine::EntityController::moveEntity()
{
}
