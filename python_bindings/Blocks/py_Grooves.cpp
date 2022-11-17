#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/Grooves.h>

void init_Grooves(pybind11::module_& module)
{
   pybind11::class_<Grooves> grooves(module, "Grooves");
   grooves.def(pybind11::init<>());
   

   // autogen start
   grooves.def("getSpikes", &Grooves::getSpikes);
   grooves.def("getBeat", &Grooves::getBeat);
   grooves.def("hasBeat", &Grooves::hasBeat);
   grooves.def("setBeat", &Grooves::setBeat);
   grooves.def("resetBeat", &Grooves::resetBeat);
   grooves.def("getState", &Grooves::getState);
   grooves.def("hasState", &Grooves::hasState);
   grooves.def("setState", &Grooves::setState);
   grooves.def("resetState", &Grooves::resetState);
   // autogen end
}

