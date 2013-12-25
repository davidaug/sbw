#ifndef SBWCOOK_H_
#define SBWCOOK_H_

#include "sbwGlobal.h"
#include "sbwConvert.h"

class SBWClass SBWCook{
private:
	btConvexHullShape *convexHullShape;
public:
	SBWCook();
	btConvexHullShape* getConvexHullShape(Ogre::Mesh *mesh,Ogre::Vector3 scale , Ogre::Vector3 position, Ogre::Quaternion orient);

};


#endif