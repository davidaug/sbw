#include "sbw.h"

SBW* SBW::SBWptr = NULL;

SBW::SBW()
{
	firstExec = false;
}

void SBW::createWorld()
{
	Ogre::LogManager::getSingletonPtr()->logMessage("INITIALIZING SBW WORLD");

	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

	solver = new btSequentialImpulseConstraintSolver;

	sbwWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);

	sbwWorld->setGravity(btVector3(0.0f,-9.8f,0.0f));

	Ogre::Root::getSingletonPtr()->addFrameListener(this);

	Ogre::LogManager::getSingletonPtr()->logMessage("WORLD INITIALIZED");
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

bool SBW::frameRenderingQueued(const Ogre::FrameEvent& evt){


	sbwWorld->stepSimulation(evt.timeSinceLastFrame,6);

	if(!firstExec)
	{
		firstExec = true;
		Ogre::LogManager::getSingletonPtr()->logMessage("FRAMELISTENER OK!");
	}
	
    return true;

}