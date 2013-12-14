#include "sbwActor.h"


SBWActor::SBWActor()
{

}

Ogre::SceneNode* SBWActor::getSceneNodePtr(){
	return this->sceneNode;
}


Ogre::Entity* SBWActor::getEntityPtr(){
	return this->entity;
}

void SBWActor::addForce(const Ogre::Vector3& force)
{

	this->rigidBody->setLinearVelocity(SBWConvert::toBullet(force));

}