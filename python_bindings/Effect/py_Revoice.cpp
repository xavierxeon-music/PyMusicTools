#include <pybind11/pybind11.h>

#include <Effect/Revoice.h>

void init_Revoice(pybind11::module_& module)
{
   pybind11::class_<Revoice> revoice(module, "Revoice");
   //revoice.def(pybind11::init<const uint8_t&, const Spectrum::Quality&>(), pybind11::arg("quality") = 16, pybind11::arg("quality") = Spectrum::Quality::Low);
   revoice.def(pybind11::init<const uint8_t&>(), pybind11::arg("quality") = 16);

   revoice.def("getNumberOfVoices", &Revoice::getNumberOfVoices);
   revoice.def("setNumberOfVoices", &Revoice::setNumberOfVoices);
   revoice.def("setSampleRate", &Revoice::setSampleRate);
   revoice.def("convert", &Revoice::convert);
}