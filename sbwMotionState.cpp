#include "sbwMotionState.h"
#include <iostream>


    SBWMotionState::SBWMotionState(const btTransform &initialpos, Ogre::SceneNode *node) {
        mVisibleobj = node;
        mPos1 = initialpos;
    }

    SBWMotionState::~SBWMotionState() {
    }

    void SBWMotionState::setNode(Ogre::SceneNode *node) {
        mVisibleobj = node;
    }

    void SBWMotionState::getWorldTransform(btTransform &worldTrans) const {
        worldTrans = mPos1;
    }

    void SBWMotionState::setWorldTransform(const btTransform &worldTrans) {
        if(NULL == mVisibleobj)
            return; 

        btQuaternion rot = worldTrans.getRotation();
        mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
        btVector3 pos = worldTrans.getOrigin();
        mVisibleobj->setPosition(pos.x(), pos.y(), pos.z());

    }

