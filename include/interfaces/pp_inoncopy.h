#ifndef PP_INTERFACES_INONCOPY
#define PP_INTERFACES_INONCOPY

#include <pp_platform.h>

namespace PP
{
	class INonCopy
	{
	private:
		INonCopy() = default;
		INonCopy(const INonCopy& other) = delete;
		const INonCopy& operator = (const INonCopy& other) = delete;
	};
}

#endif