#pragma once
#include <string>
#include <deque>

class OdPythonIO
{
public:
    typedef std::deque<std::string> string_buffer;
    void write(std::string const&);
    void write_wide(std::wstring const &);
    static std::string get_output();

private:
    static string_buffer m_outputs;
};