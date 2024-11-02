#include <iostream>
#include <fmt/core.h>
#include "ContentProviderFactory.hpp"

int main()
{
	auto providers = ContentProviderFactory::createProviders();

	for(auto& [service, provider] : providers) {
		fmt::print("Fetch service {}\n", getServiceName(service));
		provider->fetchContent();
	}

	std::cout << "Hello world!" << std::endl;
	fmt::print("Hello from fmt\n");

	return 0;
}
