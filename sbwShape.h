#ifndef SBWSHAPE_H_
#define SBWSHAPE_H_

#pragma once

#include "sbwGlobal.h"
#include "sbwConvert.h"
#include "sbw.h"
#include "sbwActor.h"



class SBWClass SBWShape : SBWActor{
public:
	static SBWActor* createPlane(const char* name, const char* material, const Ogre::Vector3& position , const Ogre::Real& width, const Ogre::Real& height, const int& mass);
	static SBWActor* createCube(const char* name, const char* material, const Ogre::Vector3& postion, const Ogre::Real& size, const int& mass);

};




#endif