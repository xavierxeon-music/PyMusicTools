#include <pybind11/pybind11.h>

#include <Sound/SampleOscilator.h>

void init_SampleOscilator(pybind11::module_& module)
{
   pybind11::class_<Sample::Oscilator> sampleoscilator(module, "SampleOscilator");
   sampleoscilator.def(pybind11::init<>());

   // autogen start
   // autogen end
}
