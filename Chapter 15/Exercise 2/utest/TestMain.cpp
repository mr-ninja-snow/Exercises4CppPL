#include <vector>
#include <algorithm>

#include "CppUTest/TestHarness.h"
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupportPlugin.h>

int main(int ac, const char** av)
{
	MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
	MockSupportPlugin mockPlugin;
	TestRegistry::getCurrentRegistry()->installPlugin( &mockPlugin );
	return CommandLineTestRunner::RunAllTests(ac, av);
}

