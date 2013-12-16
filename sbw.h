#ifndef SBW_H
#define SBW_H

#include "sbwGlobal.h"


class SBWClass SBW : public Ogre::FrameListener
{
private:
	/* SBW OBJECTS */
	static SBW* SBWptr;
	SBW();
	virtual ~SBW();

	
	/*BULLET WORLD OBJECTS */
	btDiscreteDynamicsWorld* sbwWorld;
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;

	/*OGRE WORLD OBJECTS*/
	Ogre::SceneManager* mSceneMgr;

	
//	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
//	virtual bool frameEnded(const Ogre::FrameEvent& evt);

public:
	void createWorld(Ogre::SceneManager *mSceneMgr);
	Ogre::SceneManager* getSceneManager();
	void unload();
	static SBW* getSingletonPtr();
	btDynamicsWorld* getWorld();
};

#endif