#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/Sample.h>

void init_Sample(pybind11::module_& module)
{
   pybind11::class_<Sample> sample(module, "Sample");
   sample.def(pybind11::init<>());

   pybind11::class_<Sample::Meta> sample_meta(sample, "Meta");
   sample_meta.def(pybind11::init<>());

   // autogen start
   // autogen end
}
