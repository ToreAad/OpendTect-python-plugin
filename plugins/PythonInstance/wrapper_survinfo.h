#pragma once
#include "wrapper.h"

//namespace boost{
//    namespace python{
//	class object;
//    }
//}

class Wrapper_survinfo : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};