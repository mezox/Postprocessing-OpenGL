#ifndef PP_INTERFACES_APPWINDOW_H
#define PP_INTERFACES_APPWINDOW_H

#include <pp_platform.h>
#include <pp_inoncopy.h>
#include <pp_types.h>

namespace PP
{
	class IAppWindow : INonCopy
	{
	public:
		virtual ~IAppWindow() {}

		virtual void		VInit() = 0;
		virtual void		VRun() = 0;
		virtual void		VSetFullscreen(bool flag) = 0;
		virtual void		VSetVisible(bool flag) = 0;
		virtual void		VSwapBuffers() = 0;
		virtual void		VToggleCursor() = 0;
		virtual void		VClose() = 0;

		virtual cstring&	VGetTitle() = 0;


		virtual bool		VIsRunning() = 0;
		virtual bool		VIsPaused() = 0;
		virtual bool		VIsHidden() = 0;

		static const size_t	DEF_WINDOW_WIDTH = 1280;
		static const size_t	DEF_WINDOW_HEIGHT = 720;

	private:

	protected:

	};
}
#endif