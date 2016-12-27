#ifndef TESTAPP_H
#define TESTAPP_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

#include "ITestApp.h"

namespace android{

class TestApp : public BnTestApp {
public:
	TestApp();
	~TestApp();
	virtual int hello();
};

};

#endif


