#include "sbwShape.h"


SBWActor* SBWShape::createPlane(const Ogre::String& name, const char* material, const Ogre::Vector3& position , const Ogre::Real& width, const Ogre::Real& height, const int& mass){
	
	SBWActor* actor = new SBWActor();
	Ogre::Plane plane(position,0);

	Ogre::MeshManager::getSingleton().createPlane(name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
		plane, width, height, 20, 20, true, 1, 5,5, Ogre::Vector3(0.0f,0.0f,1.0f));

	Ogre::SceneManager *mSceneMgr = SBW::getSingletonPtr()->getSceneManager();

	actor->entity = mSceneMgr->createEntity(Ogre::String("Entity")+Ogre::String(name),Ogre::String(name));
	actor->sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::String("Node")+Ogre::String(name));
	actor->sceneNode->attachObject	(actor->entity);

	actor->collisionShape = new btStaticPlaneShape(btVector3(0,1,0),1);
	btTransform tr;
	tr.setIdentity();
	tr.setOrigin(btVector3(0.0f,-1.0f,0.0f));

	actor->defaultMotionState = new btDefaultMotionState(tr);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,actor->defaultMotionState,actor->collisionShape,btVector3(0,0,0));
	actor->rigidBody = new btRigidBody(rigidBodyCI);

	SBW::getSingletonPtr()->getWorld()->addRigidBody(actor->rigidBody);

	actor->entity->setMaterialName(material);

	return actor;


}

SBWActor* SBWShape::createCube(const Ogre::String& name, const char* material, const Ogre::Vector3& postion, const Ogre::Real& size, const int& mass){

	SBWActor* actor = new SBWActor();

	Ogre::SceneManager *mSceneMgr = SBW::getSingletonPtr()->getSceneManager();

	actor->entity = mSceneMgr->createEntity(Ogre::String("Entity")+Ogre::String(name), "cubo.mesh");
	
	actor->sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::String("Node")+Ogre::String(name));
	actor->sceneNode->attachObject(actor->entity);
	actor->sceneNode->scale(Ogre::Vector3(size,size,size));
	actor->sceneNode->setPosition(postion);

	actor->collisionShape = new btBoxShape(btVector3(1.0f,1.0f,1.0f));
	actor->collisionShape->setLocalScaling(SBWConvert::toBullet(actor->sceneNode->getScale()));
	

	actor->defaultMotionState = new SBWMotionState(btTransform(btQuaternion(0.0,0.0,0.0,1.0),SBWConvert::toBullet(actor->sceneNode->getPosition())),actor->sceneNode);
	
	btVector3 fallInertia(0,0,0);
	actor->collisionShape->calculateLocalInertia(mass,fallInertia);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,actor->defaultMotionState,actor->collisionShape,fallInertia);
	actor->rigidBody = new btRigidBody(rigidBodyCI);

	SBW::getSingletonPtr()->getWorld()->addRigidBody(actor->rigidBody);

	actor->entity->setMaterialName(material);

	return actor;

}

SBWActor* SBWShape::createSphere(const Ogre::String& name, const char* material, const Ogre::Vector3& postion, const Ogre::Real& size, const int& mass){

	SBWActor* actor = new SBWActor();

	Ogre::SceneManager *mSceneMgr = SBW::getSingletonPtr()->getSceneManager();

	actor->entity = mSceneMgr->createEntity(Ogre::String("Entity")+Ogre::String(name),"sphere.mesh");
	
	actor->sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::String("Node")+Ogre::String(name));
	actor->sceneNode->attachObject(actor->entity);
	actor->sceneNode->scale(Ogre::Vector3(size,size,size));
	actor->sceneNode->setPosition(postion);

	actor->collisionShape = new btSphereShape(size);
	actor->collisionShape->setLocalScaling(SBWConvert::toBullet(actor->sceneNode->getScale()));
	

	actor->defaultMotionState = new SBWMotionState(btTransform(btQuaternion(0.0,0.0,0.0,1.0),SBWConvert::toBullet(actor->sceneNode->getPosition())),actor->sceneNode);
	
	btVector3 fallInertia(0,0,0);
	actor->collisionShape->calculateLocalInertia(mass,fallInertia);

	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,actor->defaultMotionState,actor->collisionShape,fallInertia);
	rigidBodyCI.m_friction = 10.5f;
	actor->rigidBody = new btRigidBody(rigidBodyCI);

	SBW::getSingletonPtr()->getWorld()->addRigidBody(actor->rigidBody);

	actor->entity->setMaterialName(material);

	return actor;

}