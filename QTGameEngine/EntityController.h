#pragma once
#include "QTHeaders.h"
#include "Entity.h"


namespace QTGameEngine
{
	class EntityController
	{
	public:
		EntityController();
		EntityController(Entity* entity);

		//move entity
		void moveEntity();

	private:
		Entity* _entity;
	};
}