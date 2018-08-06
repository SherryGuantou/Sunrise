#include"AppDelegate.h"

#include"ui/MainScene.h"
#include"logic/ConsoleManager.h"
#include"logic/Game.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 768);

void AppDelegate::initGLContextAttrs() {
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	//Director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("Sunrise", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
		//glview = GLViewImpl::createWithFullScreen("DreamingWorld");
#else
		glview = GLViewImpl::create("Sunrise");
#endif
		director->setOpenGLView(glview);
	}

	//Set FPS
	director->setDisplayStats(true);
	director->setAnimationInterval(1.0f / 60);

	//Close the debug information
	director->setDisplayStats(false);

	//Set the design resolution and scale
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
	auto frameSize = glview->getFrameSize();
	director->setContentScaleFactor(MIN(frameSize.width / designResolutionSize.width, frameSize.height / designResolutionSize.height));

	//Init the Singleton Class
	GET(Game)Get();
	GET(ConsoleManager)Get();

	//Run
	director->runWithScene(MainScene::create());

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();
}