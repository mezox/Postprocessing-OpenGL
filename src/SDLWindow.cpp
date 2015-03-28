#include <SDLWindow.h>
#include <SDLTimer.h>

#include <iostream>

#include <GL/glew.h>
#include <GL/GL.h>

#include <Graphics\Color.h>
#include <GLRenderer.h>
#include <Loader.h>

#include <GLShader.h>
#include <GLShaderProgram.h>

/// <summary>
/// Initializes a new instance of the <see cref="SDLAppWindow"/> class.
/// </summary>
SDLAppWindow::SDLAppWindow()
{
	//m_params = nullptr;

	m_running = false;
	m_fullscreen = false;
	m_cursor_hidden = false;
	m_win_handler = nullptr;
	m_gl_context = nullptr;
	m_win_mode = WindowMode::Type::WINDOWED;
	m_win_flags = 0;

	m_mouse_state = new SDLMouseState();
	m_key_state = new SDLKeyState();

	m_renderer = nullptr;
}

/// <summary>
/// Constructor of SDL Window.
/// </summary>
/// <param name="params">Parameters of SDL window, loaded from file</param>
/// <returns></returns>
SDLAppWindow::SDLAppWindow(const SDL::WIN_PARAMS& params)
{
	m_running = false;
	m_fullscreen = false;
	m_cursor_hidden = false;
	m_win_handler = nullptr;
	m_gl_context = nullptr;
	m_params = params;
	m_win_mode = WindowMode::Type::WINDOWED;
	m_win_flags = 0;
}

/// <summary>
/// Finalizes an instance of the <see cref="SDLAppWindow"/> class.
/// </summary>
SDLAppWindow::~SDLAppWindow()
{
	m_win_handler = nullptr;
	m_gl_context = nullptr;
	m_renderer = nullptr;
}

/// <summary>
/// Initializes SDL Window & GLEW.
/// </summary>
/// <returns></returns>
void SDLAppWindow::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
	{
		std::cout << "SDL failed to initialize %s\n";
	}

	cstring title = "SDL Window";

	m_win_handler = SDL_CreateWindow(
		title.c_str(),
		m_params.x <= 0 ? SDL_WINDOWPOS_CENTERED : m_params.x,
		m_params.y <= 0 ? SDL_WINDOWPOS_CENTERED : m_params.y,
		DEF_WINDOW_WIDTH,
		DEF_WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
		);

	if (!m_win_handler)
	{
		SDL_Quit();
		std::cerr << "Failed to create SDL Window!\n";
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	m_gl_context = SDL_GL_CreateContext(m_win_handler);

	if (!m_gl_context)
	{
		std::cerr << "Failed to create GL Context!\n";
		return;
	}

	m_win_flags = SDL_GetWindowFlags(m_win_handler);

	m_renderer = new GLRenderer();
	m_renderer->Init();
	m_renderer->SetClearColor(Colors::Aquamarine);

	Rect r = GetClientBounds();
	glViewport(0, 0, r.m_w, r.m_h);

}

const Rect SDLAppWindow::GetClientBounds()
{
	Rect r;
	SDL_GetWindowPosition(m_win_handler, (int*)&r.m_x,(int*)&r.m_y);
	SDL_GetWindowSize(m_win_handler, (int*)&r.m_w, (int*)&r.m_h);

	return r;
}

void SDLAppWindow::Resize()
{
	// TODO
}

void SDLAppWindow::MoveTo()
{
	// TODO
}

void SDLAppWindow::Focus()
{
	// TODO
}

void SDLAppWindow::Show()
{
	// TODO
}

void SDLAppWindow::Minimalize()
{
	// TODO
}

void SDLAppWindow::Maximalize()
{
	// TODO
}

void SDLAppWindow::Hide()
{
	// TODO
}

void SDLAppWindow::ToggleMode(WindowMode::Type mode)
{
	switch (mode)
	{
	case WindowMode::Type::FULLSCREEN:
		SDL_SetWindowFullscreen(m_win_handler, SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	case WindowMode::Type::WINDOWED:
		SDL_SetWindowFullscreen(m_win_handler, 0);
		break;
	case WindowMode::Type::WINDOWED_FULLSCREEN:
		SDL_MaximizeWindow(m_win_handler);
		break;

	default:
		break;
	}
}

/// <summary>
/// Sets the application title.
/// </summary>
/// <param name="t">The t.</param>
/*void SDLAppWindow::SetTitle(cstring t)
{
	m_title = t;
}*/

/// <summary>
/// Toggles the cursor.
/// </summary>
void SDLAppWindow::ToggleCursor()
{
	m_cursor_hidden = !m_cursor_hidden;

	if (m_cursor_hidden)
		SDL_ShowCursor(0);
	else
		SDL_ShowCursor(1);
}

/// <summary>
/// Destroys window, deletes OpenGL context and terminates SDL.
/// </summary>
void SDLAppWindow::Destroy()
{
	m_running = false;
	SDL_GL_DeleteContext(m_gl_context);
	SDL_Quit();
}

/// <summary>
/// Swaps front and back render buffers.
/// </summary>
void SDLAppWindow::SwapBuffers()
{
	SDL_GL_SwapWindow(m_win_handler);
}

/// <summary>
/// Starts Window events loop, also starts application timer.
/// </summary>
void SDLAppWindow::Run()
{
	SDLTimer timer;

	//Loader* loader = new Loader();

	static const GLfloat g_vertex_buffer_data[] = {
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


	//Model* model = loader->LoadToVAO(vertices);

	GLShader* vs = new GLShader("Shaders/test.vs");
	GLShader* fs = new GLShader("Shaders/test.fs");

	GLShaderProgram* prg = new GLShaderProgram();
	prg->AttachShader(vs);
	prg->AttachShader(fs);
	prg->Create();

	timer.Start();
	m_running = true;
	while (m_running)
	{
		timer.Tick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				Destroy();
				break;
			
			case SDL_KEYDOWN:
				m_key_state->KeyDown(event.key.keysym.scancode);
				break;

			case SDL_KEYUP:
				m_key_state->KeyUp(event.key.keysym.scancode);
				break;

			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				m_mouse_state->MouseEvent(event.button);
				break;

			case SDL_MOUSEMOTION:
				m_mouse_state->MouseMove(event.motion.x, event.motion.y);
				break;
			}
		}

		m_renderer->ClearBuffer(RENDERER::CLEAR::COLOR_DEPTH_BUFFER);



		prg->Bind();
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

		glDisableVertexAttribArray(0);
		prg->Unbind();

		
		
		

		m_mouse_state->Update();
		m_key_state->Update();

		SwapBuffers();
	}

	//delete loader;
}


/// <summary>
/// Determines whether this instance is running.
/// </summary>
/// <returns></returns>
bool SDLAppWindow::IsRunning()
{
	return m_running;
}

/// <summary>
/// Determines whether this instance is hidden.
/// </summary>
/// <returns></returns>
bool SDLAppWindow::IsHidden()
{
	if (m_win_flags & SDL_WINDOW_HIDDEN)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Determines whether this instance is maximized.
/// </summary>
/// <returns></returns>
bool SDLAppWindow::IsMaximized()
{
	if (m_win_flags & SDL_WINDOW_MAXIMIZED)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Determines whether this instance is minimized.
/// </summary>
/// <returns></returns>
bool SDLAppWindow::IsMinimized()
{
	if (m_win_flags & SDL_WINDOW_MINIMIZED)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Gets the window handle.
/// </summary>
/// <returns></returns>
void* SDLAppWindow::GetWindowHandle() const
{
	return m_win_handler;
}

/// <summary>
/// Gets the mode.
/// </summary>
/// <returns></returns>
WindowMode::Type SDLAppWindow::GetMode() const
{
	return m_win_mode;
}

/// <summary>
/// Assign renderer to SDL window.
/// </summary>
/// <param name="r">The Renderer.</param>
void SDLAppWindow::SetRenderer(IRenderer * r)
{
	m_renderer = r;
}
