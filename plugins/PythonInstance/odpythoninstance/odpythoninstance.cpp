#include "odpythoninstance.h"
#include "odpythonio.h"
#include <string>

OdPythonInstance::OdPythonInstance()
{

}

std::string OdPythonInstance::get_result()
{
    return odPythonIO.get_output();
}

bool OdPythonInstance::do_command(const char* cmd)
{
    namespace py = boost::python;
    try
    {
	auto command_result = py::exec(cmd, main_namespace, main_namespace);
	return 0;
    }
    catch (py::error_already_set const&)
    {
	PyErr_Print();
	return -1;
    }
}

void OdPythonInstance::initialize_class()
{
    namespace py = boost::python;
    Py_Initialize();

    main_module = py::import("__main__");
    main_namespace = main_module.attr("__dict__");

    main_namespace["PythonIO"] = py::class_<OdPythonIO>("PythonIO", py::init<>())
	.def("write", &OdPythonIO::write)
	.def("write", &OdPythonIO::write_wide);


    py::import("sys").attr("stderr") = odPythonIO;
    py::import("sys").attr("stdout") = odPythonIO;

    register_odpywrapper();
}

boost::python::object OdPythonInstance::main_module;
boost::python::object OdPythonInstance::main_namespace;
OdPythonIO OdPythonInstance::odPythonIO;
//std::vector<std::unique_ptr<Wrapper>> OdPythonInstance::class_registry;