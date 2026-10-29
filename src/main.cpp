#include <iostream>
#include <fmt/core.h>
#include "ContentProviderFactory.hpp"

int main()
{
	auto providers = Provider::ContentProviderFactory::createProviders();

	for(auto& provider : providers) {
		provider->fetchContent();
	}

	return 0;
}
