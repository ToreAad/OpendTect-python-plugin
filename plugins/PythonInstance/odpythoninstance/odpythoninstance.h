#pragma once
#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB
#include <boost/python.hpp>

#include "wrapper/odpywrapper.h"

#include "pythoninstancemod.h"
#include "odpythoninstance/odpythonio.h"
#include <string>
#include <vector>
#include <memory>

class OdPythonInstance
{
    mODTextTranslationClass(OdPython);

public:
    OdPythonInstance();
    ~OdPythonInstance(){};

    std::string get_result();
    bool do_command(const char*);

    static void initialize_class();

    static void register_odpywrapper()
    {
	Odpywrapper::register_class(main_namespace);
    }

private:
    static boost::python::object main_module;
    static boost::python::object main_namespace;

    static OdPythonIO odPythonIO;
};