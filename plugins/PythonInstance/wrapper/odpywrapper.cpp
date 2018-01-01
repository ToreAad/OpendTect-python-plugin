#include "odpywrapper.h"
#include "survinfo.h"
#include "emmanager.h"
#include "emobject.h"


namespace EM
{
    class SurfaceIOData;
    class SurfaceIODataSelection;
}

class API_objectID
{
public:
    API_objectID()
    {

    }

    API_objectID(EM::ObjectID obj)
	: m_obj{obj}
    {

    }
    
    int get_value()
    {
	return static_cast<int>(m_obj);
    }

    EM::ObjectID get()
    {
	return m_obj;
    }

private:
    EM::ObjectID m_obj = -1;
};

class API_EMObject
{
public:
    API_EMObject(){};

    API_EMObject(EM::EMObject* obj)
	:m_obj{obj}
    {};

    std::string name() const
    {
	return std::string(m_obj->name().getCStr());
    }

private:
    EM::EMObject* m_obj = nullptr;
};

class Access_EMM
{
public:
    Access_EMM(){};
    ~Access_EMM(){};

    int size()
    {
	return EM::EMM().size();
    }

    API_objectID objectID(int idx)
    {
	return API_objectID(EM::EMM().objectID(idx));
    }

    API_EMObject getObject(API_objectID idx)
    {
	return API_EMObject(EM::EMM().getObject(idx.get()));
    }
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

    
    py::class_<API_EMObject>("API_EMObject", py::init<>())
	.def("__call__", &API_EMObject::name)
	.def("name", &API_EMObject::name);
    
    py::class_<API_objectID>("API_objectID", py::init<int>())
	.def("__call__", &API_objectID::get_value);

    main_namespace["EMM"] = py::class_<Access_EMM>("EM", py::init<>())
	.def("size", &Access_EMM::size)
	.def("objectID", &Access_EMM::objectID)
	.def("getObject", &Access_EMM::getObject);

    main_namespace["SI"] = py::class_<Access_SI>("SI", py::init<>())
	.def("has2D", &Access_SI::has2D)
	.def("has3D", &Access_SI::has3D);

    return true;
}