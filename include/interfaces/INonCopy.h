#pragma once

//
//	NonCopyable Class
//

class INonCopy
{
protected:
	INonCopy() {}
	~INonCopy() {}

private:
	INonCopy(const INonCopy& other);
	const INonCopy& operator = (const INonCopy& other);
};