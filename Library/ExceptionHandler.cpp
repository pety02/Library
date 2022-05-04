#include <iostream>

static class ExceptionHandler
{
private:
public:
	static void handleExceptionPtr(std::exception_ptr eptr)
	{
		try {
			if (eptr) {
				std::rethrow_exception(eptr);
			}
		}
		catch (const std::exception& e) {
			std::cout << "Caught exception \"" << e.what() << "\"\n";
		}
	}
};