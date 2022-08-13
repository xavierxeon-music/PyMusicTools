#include <pybind11/pybind11.h>

#include <Sound/Spectrum.h>

void init_Spectrum(pybind11::module_& module)
{
   pybind11::class_<Spectrum> spectrum(module, "Spectrum");
   spectrum.def(pybind11::init<>());
   

   // autogen start
   // autogen end
}

