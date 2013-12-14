#ifndef SBWMOTIONSTATE_H_
#define SBWMOTIONSTATE_H_

#include "sbwGlobal.h"

class SBWMotionState : public btMotionState {
public:
    SBWMotionState(const btTransform &initialpos, Ogre::SceneNode *node);
    virtual ~SBWMotionState();
    void setNode(Ogre::SceneNode *node);
    virtual void getWorldTransform(btTransform &worldTrans) const;
    virtual void setWorldTransform(const btTransform &worldTrans);

protected:
    Ogre::SceneNode *mVisibleobj;
    btTransform mPos1;
};

#endif