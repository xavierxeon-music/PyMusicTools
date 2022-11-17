#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Utility/Spectrum.h>

void init_Spectrum(pybind11::module_& module)
{
   pybind11::class_<Spectrum> spectrum(module, "Spectrum");
   spectrum.def(pybind11::init<const Spectrum::Quality&>());

   // autogen start
   pybind11::enum_<Spectrum::Quality> quality(module, "SpectrumQuality");
   quality.value("Low", Spectrum::Quality::Low);
   quality.value("Medium", Spectrum::Quality::Medium);
   quality.value("High", Spectrum::Quality::High);
   quality.value("Ultra", Spectrum::Quality::Ultra);
   quality.export_values();
   
   spectrum.def("getQuality", &Spectrum::getQuality);
   spectrum.def("analyse", &Spectrum::analyse);
   spectrum.def_static("compileBufferSize", &Spectrum::compileBufferSize);
   // autogen end
}
