#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/SampleOscilator.h>

void init_SampleOscilator(pybind11::module_& module)
{
   pybind11::class_<Sample> sample(module, "Sample");
   sample.def(pybind11::init<>());
   

   // autogen start
   sample.def("Oscilator", &Sample::Oscilator);
   sample.def("getMeta", &Sample::getMeta);
   sample.def("getSamplePlayhead", &Sample::getSamplePlayhead);
   sample.def("getPlaybackSpeed", &Sample::getPlaybackSpeed);
   sample.def("start", &Sample::start);
   sample.def("pause", &Sample::pause);
   sample.def("reset", &Sample::reset);
   sample.def("isLooping", &Sample::isLooping);
   sample.def("setLooping", &Sample::setLooping);
   sample.def("setFrequency", &Sample::setFrequency);
   sample.def("init", &Sample::init);
   sample.def("createSound", &Sample::createSound);
   sample.def("getSound", &Sample::getSound);
   // autogen end
}

