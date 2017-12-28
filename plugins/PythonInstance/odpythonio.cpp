#include "odpythonio.h"
#include <sstream>
#include <locale>
#include <codecvt>
#include <Windows.h>

void OdPythonIO::write(std::string const & str)
{
    OutputDebugString("PythonIO::write() called");
    m_outputs.push_back(str);
}

void OdPythonIO::write_wide(std::wstring const & w_str)
{
    OutputDebugString("PythonIO::write_wide() called");
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;
    std::string str = converter.to_bytes(w_str);
    m_outputs.push_back(str);
}

std::string OdPythonIO::get_output()
{
    OutputDebugString("PythonIO::get_output() called");
    std::stringstream ss;
    ss << "";
    
    for (auto& v : m_outputs)
    {
	ss << v;
    }

    auto return_value = ss.str();
    m_outputs.clear();
    return return_value;
}

OdPythonIO::string_buffer OdPythonIO::m_outputs{};
