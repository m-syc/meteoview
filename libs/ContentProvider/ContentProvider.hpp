#ifndef _CONTENT_PROVIDER
#define _CONTENT_PROVIDER

#include "CfgReader.hpp"

class ContentProvider {
    friend class ContentProviderFactory;
public:
    ContentProvider() {};
    virtual ~ContentProvider() {};
    virtual void fetchContent() = 0;
private:
    ContentProvider& instance(CfgReader &cfg) = delete;
    std::string name = "";
};

#endif /* _CONTENT_PROVIDER */
