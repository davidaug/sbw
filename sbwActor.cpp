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

SBWActor::SBWActor(Ogre::Entity* entity,const Ogre::Vector3& initPos, const Ogre::Vector3& scale, int mass)
{
	this->entity = entity;

	this->sceneNode = SBW::getSingletonPtr()->getSceneManager()->getRootSceneNode()->createChildSceneNode("nova");
	this->sceneNode->attachObject(this->entity);
	this->sceneNode->setPosition(initPos);
	this->sceneNode->scale(scale);

	SBWCook *cook = new SBWCook();
	Ogre::MeshPtr ptr = this->entity->getMesh();

	this->collisionShape = cook->getConvexHullShape(ptr.getPointer(),scale,initPos,this->sceneNode->getOrientation());

	this->defaultMotionState = new SBWMotionState(btTransform(btQuaternion(0.0,0.0,0.0,1.0),SBWConvert::toBullet(this->sceneNode->getPosition())),this->sceneNode);
	
	btVector3 fallInertia(0,0,0);
	this->collisionShape->calculateLocalInertia(mass,fallInertia);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,this->defaultMotionState,this->collisionShape,fallInertia);
	rigidBodyCI.m_friction = 10.5f;
	this->rigidBody = new btRigidBody(rigidBodyCI);

	SBW::getSingletonPtr()->getWorld()->addRigidBody(this->rigidBody);

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

btMotionState* SBWActor::getMotionState()
{
	return this->defaultMotionState;
}