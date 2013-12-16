#include "sbwActor.h"


SBWActor::SBWActor()
{

}

SBWActor::~SBWActor()
{
	SBW::getSingletonPtr()->getWorld()->removeRigidBody(rigidBody);
	
	delete entity;
	delete sceneNode;

	delete collisionShape;
	delete defaultMotionState;
	delete rigidBody;

}


Ogre::SceneNode* SBWActor::getSceneNodePtr(){
	return this->sceneNode;
}


Ogre::Entity* SBWActor::getEntityPtr(){
	return this->entity;
}

btRigidBody* SBWActor::getRigidBody()
{

	return this->rigidBody;

}

btCollisionShape* SBWActor::getCollisionShape()
{
	return this->collisionShape;
}