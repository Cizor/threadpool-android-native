#ifndef ITESTAPP_H
#define ITESTAPP_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>


namespace android{

class ITestApp : public IInterface {
public:
	DECLARE_META_INTERFACE(TestApp);
	virtual int hello() = 0;
};

class BnTestApp : public BnInterface<ITestApp> {
public:
	enum {
		TRANSACTION_HELLO = IBinder::FIRST_CALL_TRANSACTION,
	};

	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flag = 0);
};

};

#endif
