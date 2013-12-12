#ifndef SBW_S_B_W_H

#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

class SBW
{
private:
	static SBW* SBWptr;
	btDiscreteDynamicsWorld* sbwWorld;
	btBroadphaseInterface* broadphase;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btSequentialImpulseConstraintSolver* solver;


private:
	SBW();
	virtual ~SBW();

public:
	void createWorld();
	void unload();
	static SBW* getSingletonPtr();

};

#endif