#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/Sample.h>

void init_Sample(pybind11::module_& module)
{
   pybind11::class_<Sample> sample(module, "Sample");
   sample.def(pybind11::init<>());

   pybind11::class_<Sample::Meta> sample_meta(sample, "SampleMeta");
   sample_meta.def(pybind11::init<>());
   sample_meta.def_readwrite("noOfChannels", &Sample::Meta::noOfChannels);
   sample_meta.def_readwrite("sampleRate", &Sample::Meta::sampleRate);
   sample_meta.def_readwrite("numberOfSamples", &Sample::Meta::numberOfSamples);

   // autogen start
   sample.def_static("load", &Sample::load);
   sample.def_static("save", &Sample::save);
   sample.def_static("interlace", &Sample::interlace);
   sample.def_static("deinterlace", &Sample::deinterlace);
   // autogen end
}
