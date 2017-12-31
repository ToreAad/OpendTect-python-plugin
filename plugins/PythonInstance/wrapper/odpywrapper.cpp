#include "odpywrapper.h"
#include "survinfo.h"
#include "emmanager.h"


namespace EM
{
    class EMObject;
    class SurfaceIOData;
    class SurfaceIODataSelection;
}

class Access_EMM
{
public:
    Access_EMM(){};
    ~Access_EMM(){};

    int size()
    {
	return EM::EMM().size();
    }

    EM::ObjectID objectID(int idx)
    {
	return EM::EMM().objectID(idx);
    }

    bool objectExists(const EM::EMObject* emobj)
    {
	return EM::EMM().objectExists(emobj);
    }

    bool loadIfNotFullyLoaded(const MultiID& mid, TaskRunner*  tr = nullptr)
    {
	return EM::EMM().loadIfNotFullyLoaded(mid, tr);
    }

 //   EM::EMObject* getObject(const EM::ObjectID& eobj)
 //   {
	//return EM::EMM().getObject(eobj);
 //   }

};

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

bool Odpywrapper::register_class(boost::python::object& main_namespace)
{
    namespace py = boost::python;

    main_namespace["EMM"] = py::class_<Access_EMM>("EM", py::init<>())
	.def("size", &Access_EMM::size)
	.def("objectID", &Access_EMM::objectID);
	//.def("getObject", &Access_EMM::getObject);

    main_namespace["SI"] = py::class_<Access_SI>("SI", py::init<>())
	.def("has2D", &Access_SI::has2D)
	.def("has3D", &Access_SI::has3D);

    return true;
}