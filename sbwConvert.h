#ifndef SBWCONVERT_H_
#define SBWCONVERT_H_

#include "sbwGlobal.h"


class SBWConvert{
public:
	/***
	* BULLET TO OGRE
	***/
	inline static Ogre::Real toOgre(const btScalar& btscalar){
		return Ogre::Real(static_cast<float>(btscalar));
	}
	inline static Ogre::Vector3 toOgre(const btVector3& btvector3){
		return Ogre::Vector3(btvector3.x(),btvector3.y(),btvector3.z());
	}
	inline static Ogre::Vector4 toOgre(const btVector4& btvector4){
		return Ogre::Vector4(btvector4.w(),btvector4.x(),btvector4.y(),btvector4.z());
	}

	inline static Ogre::Quaternion toOgre(const btQuaternion& btquaternion){
		return Ogre::Quaternion(btquaternion.w(),btquaternion.x(),btquaternion.y(),btquaternion.z());
	}
	
	/*****
	* OGRE TO BULLET
	*/
	inline static btScalar toBullet(const Ogre::Real real){
		return btScalar(static_cast<float>(real));
	}
	inline static btVector3 toBullet(const Ogre::Vector3 vector3){
		return btVector3(vector3.x,vector3.y,vector3.z);
	}
	inline static btVector4 toBullet(const Ogre::Vector4 vector4){
		return btVector4(vector4.w,vector4.x,vector4.y,vector4.z);
	}
	inline static btQuaternion toBullet(const Ogre::Quaternion quaternion){
		return btQuaternion(quaternion.x,quaternion.y,quaternion.z,quaternion.w);
	}


};




#endif