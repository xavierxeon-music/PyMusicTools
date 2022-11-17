#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Abstract/AbstractSegmentCrawler.h>

void init_AbstractSegmentCrawler(pybind11::module_& module)
{
   pybind11::class_<Abstract::SegmentCrawler> abstract_segmentcrawler(module, "SegmentCrawler");
   abstract_segmentcrawler.def(pybind11::init<>());
   

   // autogen start
   abstract_segmentcrawler.def("clear", &Abstract::SegmentCrawler::clear);
   abstract_segmentcrawler.def("update", &Abstract::SegmentCrawler::update);
   abstract_segmentcrawler.def("clockTick", &Abstract::SegmentCrawler::clockTick);
   abstract_segmentcrawler.def("clockReset", &Abstract::SegmentCrawler::clockReset);
   abstract_segmentcrawler.def("getDefaultDivision", &Abstract::SegmentCrawler::getDefaultDivision);
   abstract_segmentcrawler.def("getSegmentCount", &Abstract::SegmentCrawler::getSegmentCount);
   abstract_segmentcrawler.def("getSegmentLength", &Abstract::SegmentCrawler::getSegmentLength);
   abstract_segmentcrawler.def("isLooping", &Abstract::SegmentCrawler::isLooping);
   abstract_segmentcrawler.def("setLooping", &Abstract::SegmentCrawler::setLooping);
   abstract_segmentcrawler.def("getCurrentSegmentIndex", &Abstract::SegmentCrawler::getCurrentSegmentIndex);
   abstract_segmentcrawler.def("getCurrentSegmentTick", &Abstract::SegmentCrawler::getCurrentSegmentTick);
   abstract_segmentcrawler.def("setCurrentSegmentIndex", &Abstract::SegmentCrawler::setCurrentSegmentIndex);
   abstract_segmentcrawler.def("getCurrentSegmentPrecentage", &Abstract::SegmentCrawler::getCurrentSegmentPrecentage);
   // autogen end
}

