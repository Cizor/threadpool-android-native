#define LOG_TAG "TestApp"

#include <sys/wait.h>
#include <unistd.h>

#include <cutils/log.h>
#include <binder/BinderService.h>


#include "TestApp.h"

namespace android{
	TestApp::TestApp(){
		ALOGD("Constructor");
	}
	TestApp::~TestApp(){
		ALOGD("Destructor");
	}
	int TestApp::hello(){
		return 45;
	}

};

