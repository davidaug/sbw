#ifndef SBWACTOR_H_
#define SBWACTOR_H_

#include "sbwGlobal.h"
#include "sbwConvert.h"
#include "sbwMotionState.h"
#include "sbw.h"
#include "sbwCook.h"



class SBWClass SBWActor{


public:
	Ogre::Entity* getEntityPtr();
	Ogre::SceneNode* getSceneNodePtr();
	btRigidBody* getRigidBody();
	btCollisionShape* getCollisionShape();
	btMotionState* getMotionState();

	SBWActor(Ogre::Entity* entity, const Ogre::Vector3& initPos, const Ogre::Vector3& scale, int mass);

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