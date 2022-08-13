#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Effect/Revoice.h>

void init_Revoice(pybind11::module_& module)
{
   pybind11::class_<Revoice> revoice(module, "Revoice");
   revoice.def(pybind11::init<>());
   

   // autogen start
   None.def("Revoice", &None::Revoice);
   None.def("getNumberOfVoices", &None::getNumberOfVoices);
   None.def("setNumberOfVoices", &None::setNumberOfVoices);
   None.def("setSampleRate", &None::setSampleRate);
   None.def("convert", &None::convert);
   // autogen end
}

