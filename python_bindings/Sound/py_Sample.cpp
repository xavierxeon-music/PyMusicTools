#include <pybind11/pybind11.h>

#include <Sound/Sample.h>

void init_Sample(pybind11::module_& module)
{
   pybind11::class_<Sample> sample(module, "Sample");

   pybind11::class_<Sample::Meta> meta(sample, "Meta");
   meta.def(pybind11::init<>());

   sample.def_static("load", &Sample::load);
   sample.def_static("save", &Sample::save);

   pybind11::class_<Sample::Oscilator> oscilator(module, "Oscilator");
   oscilator.def(pybind11::init<const bool>(), pybind11::arg("buffered") = true);
   oscilator.def("getMeta", &Sample::Oscilator::getMeta);
   oscilator.def("getSamplePlayhead", &Sample::Oscilator::getSamplePlayhead);
   oscilator.def("getPlaybackSpeed", &Sample::Oscilator::getPlaybackSpeed);
   oscilator.def("start", &Sample::Oscilator::start);
   oscilator.def("pause", &Sample::Oscilator::pause);
   oscilator.def("reset", &Sample::Oscilator::reset);
   oscilator.def("isLooping", &Sample::Oscilator::isLooping);
   oscilator.def("setLooping", &Sample::Oscilator::setLooping);
   oscilator.def("setFrequency", &Sample::Oscilator::setFrequency);
   oscilator.def("init", &Sample::Oscilator::init);
   oscilator.def("createSound", &Sample::Oscilator::createSound);
   oscilator.def("rightSound", &Sample::Oscilator::rightSound);
}