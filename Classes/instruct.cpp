#include"cocos2d.h"
#include"instruct.h"
USING_NS_CC;
Scene* instruct::createScene()
{
   
    auto scene = Scene::create();
    
 
    auto layer = instruct::create();


    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool instruct::init()
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
	menu_bg->setScale(1.5);
	float ScaleTimes = visibleSize.height /menu_bg->getContentSize().height;//计算缩放倍数
     menu_bg->setScale(ScaleTimes); 
	this->addChild(menu_bg);

	CCLayerColor *jianjiebg=CCLayerColor::create(Color4B(127,127,127,100));
	//jianjiebg->setAnchorPoint(Vect( 0.5,0.5));
	jianjiebg ->ignoreAnchorPointForPosition(false);

	jianjiebg->setContentSize(CCSizeMake(visibleSize.width*4/5,visibleSize.height*3/5));
	jianjiebg->setPosition(visibleSize.width/2,visibleSize.height*8/13);
	this->addChild(jianjiebg);


	std::string text = WStrToUTF8(L"玩家通过点击左、右、上按钮令铝原子在场景中找寻可以通过反映结合而变身的辅助物品，并到达与变身要求相符合的传送门。因为化学结合过程不可逆转，而且一场景中可能包含多种辅助物品，可能会有多次反应，最终可能到达传送门时，变身情况与传送门要求不相符，则无法通过。");
	CCLabelTTF* jieshao = CCLabelTTF::create(text, "宋体", 30,CCSizeMake(jianjiebg->getContentSize().width-15,jianjiebg->getContentSize().height-20),kCCTextAlignmentLeft,TextVAlignment::TOP);
	jieshao ->setPosition(jianjiebg->getContentSize().width/2,jianjiebg->getContentSize().height/2);
	jianjiebg->addChild(jieshao, 1);  





	MenuItemImage *back=MenuItemImage::create("back.png","back1.png",this,menu_selector(instruct::onback));
	back ->setPosition(menu_bg->getContentSize().width*1/2,menu_bg->getContentSize().height/5);
	back->setScale(0.5f);
	CCMenu *menu =CCMenu::create(back,NULL);
	menu->setPosition(0,0);
	menu_bg->addChild(menu,1);


	return true;

}
void instruct::onback(Ref*){
	Director::getInstance()->sharedDirector()->replaceScene( HelloWorld::createScene());
}

inline void instruct::WStrToUTF8(std::string& dest, const std::wstring& src){
dest.clear();
for (size_t i = 0; i < src.size(); i++){
wchar_t w = src[i];
if (w <= 0x7f)
dest.push_back((char)w);
else if (w <= 0x7ff){
dest.push_back(0xc0 | ((w >> 6)& 0x1f));
dest.push_back(0x80| (w & 0x3f));
}
else if (w <= 0xffff){
dest.push_back(0xe0 | ((w >> 12)& 0x0f));
dest.push_back(0x80| ((w >> 6) & 0x3f));
dest.push_back(0x80| (w & 0x3f));
}
else if (sizeof(wchar_t) > 2 && w <= 0x10ffff){
dest.push_back(0xf0 | ((w >> 18)& 0x07)); // wchar_t 4-bytes situation
dest.push_back(0x80| ((w >> 12) & 0x3f));
dest.push_back(0x80| ((w >> 6) & 0x3f));
dest.push_back(0x80| (w & 0x3f));
}
else
dest.push_back('?');
}
}
//! simple warpper
inline std::string instruct::WStrToUTF8(const std::wstring& str){
std::string result;
WStrToUTF8(result, str);
return result;
}