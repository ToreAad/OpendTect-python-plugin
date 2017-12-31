#include "wrapper_survinfo.h"
#include "survinfo.h"

class Access_SI
{
public:
    Access_SI(){};
    ~Access_SI(){};

    bool has2D()
    {
	return SI().has2D();
    }

    bool has3D()
    {
	return SI().has3D();
    }

};

bool Wrapper_survinfo::register_class(boost::python::object& main_namespace)
{
    namespace py = boost::python;

    main_namespace["SI"] = py::class_<Access_SI>("SI", py::init<>())
	.def("has2D", &Access_SI::has2D)
	.def("has3D", &Access_SI::has3D);

    return true;
}