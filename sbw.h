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
	bool firstExec;
	
	/*BULLET WORLD OBJECTS */
	btDiscreteDynamicsWorld* sbwWorld;
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;

	/*OGRE WORLD OBJECTS*/
//	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
//	virtual bool frameEnded(const Ogre::FrameEvent& evt);

public:
	void createWorld();
	void unload();
	static SBW* getSingletonPtr();

};

#endif