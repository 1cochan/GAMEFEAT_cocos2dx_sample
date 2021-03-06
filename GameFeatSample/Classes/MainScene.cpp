//
//  MainScene.cpp
//  GameFeatSample
//
//  Created by 中村 慎司 on 2013/09/04.
//
//

#include "MainScene.h"
#include "SubScene.h"
#include "NativeBridge.h"

using namespace cocos2d;
using namespace std;

CCScene* MainScene::scene()
{
    CCScene* scene = CCScene::create();
    MainScene* layer = MainScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MainScene::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    //GameFeat起動
    CCMenuItemImage* gamefeatButton = CCMenuItemImage::create("GameFeatButton1.png", "GameFeatButton2.png", this, menu_selector(MainScene::pushMenu));
    gamefeatButton->setPosition(ccp(size.width/2, size.height*2/3));
    gamefeatButton->setTag(tag_gamefeat);
    
    //画面移動
    CCMenuItemImage* nextButton = CCMenuItemImage::create("bGameFeat1.png", "bGameFeat2.png", this, menu_selector(MainScene::pushMenu));
    nextButton->setPosition(ccp(size.width/2, size.height/2));
    nextButton->setTag(tag_next);
    
    CCMenu* menu = CCMenu::create(gamefeatButton,nextButton,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    //アイコン型GameFeat表示
    NativeBridge::showIconGameFeat();
    
    return true;
}

/**
 * メニュー
 */
void MainScene::pushMenu(CCObject* pSender)
{
    int tag = ((CCMenuItem *)(pSender))->getTag();
    
    //オファーウォール型GameFeat表示
    if (tag == tag_gamefeat)
    {
        NativeBridge::showGameFeat();
    }
    //全画面型GameFeat表示画面へ遷移
    else if (tag == tag_next)
    {
        
        //アイコン型GameFeat削除
        NativeBridge::hideIconGameFeat();
        
        CCScene* scene = SubScene::scene();
        CCDirector::sharedDirector()->replaceScene(scene);
    }
}