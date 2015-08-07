#include "cocos2d.h"

class hospital:public cocos2d::Layer{
public:
	 static cocos2d::Scene* createScene();
    virtual bool init();
	CREATE_FUNC(hospital);


};