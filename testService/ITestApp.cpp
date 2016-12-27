#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "ITestApp.h"

namespace android {

class BpTestApp: public BpInterface<ITestApp>{
public:
	BpTestApp(const sp<IBinder>& impl): BpInterface<ITestApp>(impl) {
	}
	virtual int hello(){
		Parcel data, reply;
		data.writeInterfaceToken(ITestApp::getInterfaceDescriptor());
		remote()->transact(BnTestApp::TRANSACTION_HELLO, data, &reply);
		return reply.readInt32();
	}
};

IMPLEMENT_META_INTERFACE(TestApp,"ITestApp");

status_t BnTestApp::onTransact(
		uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{

	switch(code){
		case TRANSACTION_HELLO:
		{
			CHECK_INTERFACE(ITestApp,data,reply);
			int32_t a = 0;
			a = hello();
			reply->readInt32(&a);
			return NO_ERROR;
		}
		default:
		{
			return BBinder::onTransact(code,data, reply,flags);
		}
	}
	return NO_ERROR;
};
};
