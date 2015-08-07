#pragma once
#include "cocos2d\external\win32-specific\icon\include\iconv.h"
#pragma comment(lib,"libiconv.lib")

#include"cocos2d.h"
#include "HelloWorldScene.h"
class instruct:public cocos2d::Layer{
	public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(instruct);
	void onback(Ref*);


	void WStrToUTF8(std::string& dest, const std::wstring& src);
	std::string WStrToUTF8(const std::wstring& str);
};