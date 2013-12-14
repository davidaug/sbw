#ifndef SBWACTOR_H_
#define SBWACTOR_H_

#include "sbwGlobal.h"
#include "sbwConvert.h"
#include "sbwMotionState.h"
#include "sbw.h"



class SBWClass SBWActor{
typedef int geometry;

public:
	Ogre::Entity* getEntityPtr();
	Ogre::SceneNode* getSceneNodePtr();
	void addForce(const Ogre::Vector3& force);

	enum { PLANE };

	friend class SBWShape;
	
protected:
	SBWActor();

	Ogre::Entity* entity;
	Ogre::SceneNode* sceneNode;

	btCollisionShape* collisionShape;
	btMotionState* defaultMotionState;
	btRigidBody* rigidBody;

};



#endif