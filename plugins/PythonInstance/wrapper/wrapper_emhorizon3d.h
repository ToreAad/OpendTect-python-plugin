#pragma once
#include "wrapper.h"

class Wrapper_emhorizon3d : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};