#pragma once
#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB
#include <boost/python.hpp>

class Odpywrapper
{
public:
    static bool register_class(boost::python::object&);
};