#ifndef _CONTENT_PROVIDER
#define _CONTENT_PROVIDER

#include "CfgReader.hpp"

class ContentProvider {
public:
    ContentProvider() {};
    virtual ~ContentProvider() {};
    virtual void fetchContent() = 0;
    ContentProvider& instance(CfgReader &cfg) = delete;
private:
};

#endif /* _CONTENT_PROVIDER */
