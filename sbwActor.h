#ifndef SBWACTOR_H_
#define SBWACTOR_H_

#include "sbwGlobal.h"
#include "sbwConvert.h"
#include "sbwMotionState.h"
#include "sbw.h"



class SBWClass SBWActor{


public:
	Ogre::Entity* getEntityPtr();
	Ogre::SceneNode* getSceneNodePtr();
	btRigidBody* getRigidBody();
	btCollisionShape* getCollisionShape();

	virtual ~SBWActor();

	friend class SBWShape;


	
protected:
	SBWActor();

	Ogre::Entity* entity;
	Ogre::SceneNode* sceneNode;
	
	btCollisionShape* collisionShape;
	btRigidBody* rigidBody;
	btMotionState* defaultMotionState;
	
	
	

};



#endif