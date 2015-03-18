#ifndef PP_INTERFACES_INONCOPY
#define PP_INTERFACES_INONCOPY

#include <pp_platform.h>

namespace PP
{
	class INonCopy
	{
	protected:
		INonCopy() {}
		~INonCopy() {}

	private:
		INonCopy(const INonCopy& other);
		const INonCopy& operator = (const INonCopy& other);
	};
}

#endif