#include "odpython.h"

std::string OdPython::get_result()
{
    return odpythoninstance.get_result();
}

bool OdPython::do_command(const char* cmd)
{
    return odpythoninstance.do_command(cmd);
}

void OdPython::initialize_class()
{
    OdPythonInstance::initialize_class();
}