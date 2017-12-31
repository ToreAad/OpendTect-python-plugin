#pragma once
#include "wrapper.h"

class Wrapper_emmanager : public Wrapper
{
public:
    bool register_class(boost::python::object&) override;
};