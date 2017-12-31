#pragma once
#include "wrapper.h"

class Wrapper_emsurface : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};