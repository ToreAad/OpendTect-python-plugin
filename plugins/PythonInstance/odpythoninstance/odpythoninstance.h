#pragma once
#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB
#include <boost/python.hpp>

#include "wrapper/wrapper.h"

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

    template<typename T>
    static void register_class()
    {
	class_registry.push_back(std::make_unique<T>());
	class_registry.back()->register_class(main_namespace);
    }

private:
    static boost::python::object main_module;
    static boost::python::object main_namespace;

    static OdPythonIO odPythonIO;
    static std::vector<std::unique_ptr<Wrapper>> class_registry;
};