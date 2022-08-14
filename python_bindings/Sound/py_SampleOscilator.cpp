#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/SampleOscilator.h>

void init_SampleOscilator(pybind11::module_& module)
{
   pybind11::class_<Sample::Oscilator> sample_oscilator(module, "SampleOscilator");
   sample_oscilator.def(pybind11::init<>());
   

   // autogen start
   sample_oscilator.def("getMeta", &Sample::Oscilator::getMeta);
   sample_oscilator.def("getSamplePlayhead", &Sample::Oscilator::getSamplePlayhead);
   sample_oscilator.def("getPlaybackSpeed", &Sample::Oscilator::getPlaybackSpeed);
   sample_oscilator.def("start", &Sample::Oscilator::start);
   sample_oscilator.def("pause", &Sample::Oscilator::pause);
   sample_oscilator.def("reset", &Sample::Oscilator::reset);
   sample_oscilator.def("isLooping", &Sample::Oscilator::isLooping);
   sample_oscilator.def("setLooping", &Sample::Oscilator::setLooping);
   sample_oscilator.def("setFrequency", &Sample::Oscilator::setFrequency);
   sample_oscilator.def("init", &Sample::Oscilator::init);
   sample_oscilator.def("createSound", &Sample::Oscilator::createSound);
   sample_oscilator.def("getSound", &Sample::Oscilator::getSound);
   // autogen end
}

