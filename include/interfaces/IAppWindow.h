#pragma once

#include <pp_platform.h>
#include <Renderer.h>
#include <INonCopy.h>
#include <pp_types.h>

namespace WindowMode
{
	enum class Type
	{
		FULLSCREEN,
		WINDOWED_FULLSCREEN,
		WINDOWED,
		NUM_MODES
	};
}

class IAppWindow : INonCopy
{
public:
	virtual ~IAppWindow() {}

	virtual void Init() = 0;
	virtual void Resize() = 0;
	virtual void MoveTo() = 0;
	virtual void Focus() = 0;
	virtual void Minimalize() = 0;
	virtual void Maximalize() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void ToggleMode(WindowMode::Type) = 0;
	virtual void ToggleCursor() = 0;
	//virtual void SetTitle(cstring t);
	virtual void Destroy() = 0;
	virtual void SwapBuffers() = 0;
	virtual void Run() = 0;
	
	virtual bool IsRunning() = 0;
	virtual bool IsHidden() = 0;
	virtual bool IsMaximized() = 0;
	virtual bool IsMinimized() = 0;

	virtual void SetRenderer(IRenderer* r) = 0;

	virtual void*				GetWindowHandle() const = 0;
	virtual WindowMode::Type	GetMode() const = 0;
	virtual const Rect			GetClientBounds() = 0;


public:
	static const size_t	DEF_WINDOW_WIDTH = 1280;
	static const size_t	DEF_WINDOW_HEIGHT = 720;

protected:
	IRenderer*	m_renderer;
};
