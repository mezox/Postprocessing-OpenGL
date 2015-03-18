#ifndef PP_INTERFACES_APPWINDOW_H
#define PP_INTERFACES_APPWINDOW_H

#include <pp_platform.h>
#include <pp_inoncopy.h>

#include <string>

namespace PP
{
	class IAppWindow : INonCopy
	{
	public:
		virtual ~IAppWindow() {}


		virtual void	VInit() = 0;
		virtual void	VRun() = 0;
		virtual void	VSetFullscreen(bool flag) = 0;
		virtual void	VSetVisible(bool flag) = 0;
		virtual void	VSwapBuffers() = 0;
		virtual void	VClose() = 0;

		virtual const std::string&	VGetTitle() = 0;


		virtual bool	VIsRunning() = 0;
		virtual bool	VIsHidden() = 0;

	private:

	protected:

	};

}
#endif