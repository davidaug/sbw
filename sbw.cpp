#include "sbw.h"
#include <iostream>

SBW* SBW::SBWptr = NULL;

SBW::SBW()
{

}

void SBW::createWorld(Ogre::SceneManager *mSceneMgr)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("INITIALIZING SBW WORLD");

	this->mSceneMgr = mSceneMgr;

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

	sbwWorld->stepSimulation(evt.timeSinceLastFrame);

    return true;

}

Ogre::SceneManager* SBW::getSceneManager()
{
	return this->mSceneMgr;
}

btDynamicsWorld* SBW::getWorld()
{
	return this->sbwWorld;
}