#include "level01.h"
USING_NS_CC;

Scene* hospital::createScene(){
	   auto scene = Scene::create();
	   auto layer = hospital::create();

    scene->addChild(layer);

    return scene;
}
bool hospital::init(){
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto menu_bg =Sprite::create("yiyuanbk.png");
	menu_bg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	float ScaleTimes = visibleSize.height /menu_bg->getContentSize().height;//¼ÆËãËõ·Å±¶Êı
     menu_bg->setScale(ScaleTimes); 
	this->addChild(menu_bg);


	return true;


}