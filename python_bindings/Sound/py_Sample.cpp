#include <pybind11/pybind11.h>

#include <Sound/Sample.h>

void init_Sample(pybind11::module_& module)
{
   pybind11::class_<Sample> sample(module, "Sample");
   sample.def(pybind11::init<>());
   
   pybind11::class_<Sample::Meta> sample_meta(sample, "Sample::Meta");
   sample_meta.def(pybind11::init<>());
   

   // autogen start
   sample.def_static("load", &Sample::load);
   sample.def_static("save", &Sample::save);
   sample.def_static("interlace", &Sample::interlace);
   sample.def_static("deinterlace", &Sample::deinterlace);
   // autogen end
}

