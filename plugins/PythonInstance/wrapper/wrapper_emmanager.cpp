#include "wrapper_emmanager.h"
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

    bool loadIfNotFullyLoaded(const MultiID& mid, TaskRunner*  tr= nullptr)
    {
	return EM::EMM().loadIfNotFullyLoaded(mid, tr);
    }

    EM::EMObject* getObject(const EM::ObjectID& eobj)
    {
	return EM::EMM().getObject(eobj);
    }

    bool getSurfaceData(const MultiID key, EM::SurfaceIOData& sd, uiString& errmsg)
    {
	return EM::EMM().getSurfaceData(key, sd, errmsg);
    }
};

bool Wrapper_emmanager::register_class(boost::python::object& main_namespace)
{
    namespace py = boost::python;

    main_namespace["EMM"] = py::class_<Access_EMM>("EM", py::init<>())
		.def("size", &Access_EMM::size);

    return true;
}