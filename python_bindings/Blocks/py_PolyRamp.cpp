#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/PolyRamp.h>

void init_PolyRamp(pybind11::module_& module)
{
   pybind11::class_<PolyRamp> polyramp(module, "PolyRamp");
   polyramp.def(pybind11::init<>());
   

   // autogen start
   // autogen end
}

