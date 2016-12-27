#include <cutils/log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "TestApp.h"

using namespace android;


int main(){
	ALOGD("STARTING SERVER");
	sp<ProcessState> proc(ProcessState::self());

	ALOGD("START THREADPOOL");
	ProcessState::self()->startThreadPool();
	ALOGD("ADD SERVICE TEST APP");
	defaultServiceManager()->addService(String16("test.app"), new TestApp);
	ALOGD("JOIN THREAD POOL");
	IPCThreadState::self()->joinThreadPool();
	ALOGD("RETURN SUCCESS");
	return 0;
}

