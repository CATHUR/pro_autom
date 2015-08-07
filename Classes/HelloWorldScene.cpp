#include "HelloWorldScene.h"
#include "instruct.h"
#include"level01.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto menu_bg =Sprite::create("menu_bk.png");
	menu_bg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	
	float ScaleTimes = visibleSize.height /menu_bg->getContentSize().height;//¼ÆËãËõ·Å±¶Êý
     menu_bg->setScale(ScaleTimes); 
	this->addChild(menu_bg);
	MenuItemImage *intruduction=MenuItemImage::create("intruduction.png","intruduction1.png",this,menu_selector(HelloWorld::onintruduction));
	intruduction ->setPosition(menu_bg->getContentSize().width/4,menu_bg->getContentSize().height/5);
	intruduction->setScale(0.5f);
	
	MenuItemImage *start=MenuItemImage::create("start.png","start1.png",this,menu_selector(HelloWorld::onstart));
	start ->setPosition(menu_bg->getContentSize().width*1/2,menu_bg->getContentSize().height/5);
	start->setScale(0.5f);
	
	MenuItemImage *esc=MenuItemImage::create("esc.png","esc1.png",this,menu_selector(HelloWorld::onesc));
	esc ->setPosition(menu_bg->getContentSize().width*3/4,menu_bg->getContentSize().height/5);
	esc->setScale(0.5f);
	
	CCMenu *menu =CCMenu::create(intruduction,start,esc,NULL);
	menu->setPosition(0,0);
	menu_bg->addChild(menu,1);
    return true;
}
void  HelloWorld::onintruduction(Ref* pSender){
	Director::getInstance()->sharedDirector()->replaceScene(instruct::createScene());

}
void HelloWorld::onstart(Ref* pSender){
	Director::getInstance()->sharedDirector()->replaceScene(hospital::createScene());
	

}
void HelloWorld::onesc(Ref* pSender){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

