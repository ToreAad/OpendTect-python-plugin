#pragma once
#include "wrapper.h"

class Wrapper_objectid : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};