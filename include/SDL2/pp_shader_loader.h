#ifndef PP_SHADER_LOADER
#define PP_SHADER_LOADER

#include <pp_types.h>

#include <string>

namespace PP
{
	class ShaderProgram
	{
	public:
		ShaderProgram();
		ShaderProgram(const std::string& vsfile, const std::string& fsfile);
		virtual ~ShaderProgram();

		void bind() const;
		void isBind() const;
		void unbind() const;


	private:
		uint m_program_id;
	};
}

#endif
