#include <pybind11/pybind11.h>

#include <Sound/SampleOscilator.h>

void init_SampleOscilator(pybind11::module_& module)
{
   pybind11::class_<Sample::Oscilator> sampleoscilator(module, "SampleOscilator");
   sampleoscilator.def(pybind11::init<>());

   // autogen start
   sampleoscilator.def("getMeta", &Sample::Oscilator::getMeta);
   sampleoscilator.def("getSamplePlayhead", &Sample::Oscilator::getSamplePlayhead);
   sampleoscilator.def("getPlaybackSpeed", &Sample::Oscilator::getPlaybackSpeed);
   sampleoscilator.def("start", &Sample::Oscilator::start);
   sampleoscilator.def("pause", &Sample::Oscilator::pause);
   sampleoscilator.def("reset", &Sample::Oscilator::reset);
   sampleoscilator.def("isLooping", &Sample::Oscilator::isLooping);
   sampleoscilator.def("setLooping", &Sample::Oscilator::setLooping);
   sampleoscilator.def("setFrequency", &Sample::Oscilator::setFrequency);
   sampleoscilator.def("init", &Sample::Oscilator::init);
   sampleoscilator.def("createSound", &Sample::Oscilator::createSound);
   sampleoscilator.def("getSound", &Sample::Oscilator::getSound);
   // autogen end
}
