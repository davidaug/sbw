#include "sbw.h"

SBW* SBW::SBWptr = NULL;

SBW::SBW()
{
}

void SBW::createWorld()
{
	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

	solver = new btSequentialImpulseConstraintSolver;

	sbwWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);

	sbwWorld->setGravity(btVector3(0.0f,-9.8f,0.0f));
}

SBW* SBW::getSingletonPtr()
{
	if(!SBWptr)
		SBWptr = new SBW();

	return SBWptr;
}

void SBW::unload()
{

	delete SBWptr;

}

SBW::~SBW()
{
	delete SBWptr;
}