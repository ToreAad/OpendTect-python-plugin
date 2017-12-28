#pragma once
#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB
#include <boost/python.hpp>
//namespace boost{
//    namespace python{
//	class object;
//    }
//}

class Wrapper
{
public:
    virtual bool register_class(boost::python::object&) = 0;
};