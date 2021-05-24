#include "process.hpp"

#include <iostream>
#include <fmt/format.h>
#include <Poco/Process.h>
#include <Poco/PipeStream.h>
#include <Poco/StreamCopier.h>

int main(int argc, char* argv[])
{
	if (argc == 1) // parent
	{
		Poco::Pipe outpipe;
		Poco::ProcessHandle ph = Poco::Process::launch(argv[0], { "child" }, 0, &outpipe, 0);
		Poco::PipeInputStream istr(outpipe);
		Poco::StreamCopier::copyStream(istr, std::cout);
	}
	else // child
	{
		std::cout << "this is a test\n";
	}

	return 0;
}
