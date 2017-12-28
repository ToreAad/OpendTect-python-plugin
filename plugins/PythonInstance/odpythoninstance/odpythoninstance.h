#pragma once
#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB
#include <boost/python.hpp>

#include "wrapper/wrapper_survinfo.h"

#include "pythoninstancemod.h"
#include "odpythoninstance/odpythonio.h"
#include <string>

class OdPythonInstance
{
    mODTextTranslationClass(OdPython);

public:
    OdPythonInstance();
    ~OdPythonInstance(){};

    std::string get_result();
    bool do_command(const char*);

    static void initialize_class();

private:
    static boost::python::object main_module;
    static boost::python::object main_namespace;

    static OdPythonIO odPythonIO;
    static Wrapper_survinfo ws;
};