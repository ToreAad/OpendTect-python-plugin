#pragma once
#include "wrapper.h"

class Wrapper_multiid : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};