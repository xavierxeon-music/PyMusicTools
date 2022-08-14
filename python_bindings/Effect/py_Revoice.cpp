#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Effect/Revoice.h>

void init_Revoice(pybind11::module_& module)
{
   pybind11::class_<Revoice> revoice(module, "Revoice");
   revoice.def(pybind11::init<>());
   

   // autogen start
   revoice.def("getNumberOfVoices", &Revoice::getNumberOfVoices);
   revoice.def("setNumberOfVoices", &Revoice::setNumberOfVoices);
   revoice.def("setSampleRate", &Revoice::setSampleRate);
   revoice.def("convert", &Revoice::convert);
   // autogen end
}

