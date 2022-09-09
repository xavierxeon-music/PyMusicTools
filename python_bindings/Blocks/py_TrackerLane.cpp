#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/TrackerLane.h>

void init_TrackerLane(pybind11::module_& module)
{
   pybind11::class_<Tracker::Lane> tracker_lane(module, "Lane");
   tracker_lane.def(pybind11::init<>());
   

   // autogen start
   tracker_lane.def("resize", &Tracker::Lane::resize);
   tracker_lane.def("getName", &Tracker::Lane::getName);
   tracker_lane.def("setName", &Tracker::Lane::setName);
   tracker_lane.def("getSegmentValue", &Tracker::Lane::getSegmentValue);
   tracker_lane.def("resetSegment", &Tracker::Lane::resetSegment);
   tracker_lane.def("getSegmentStartValue", &Tracker::Lane::getSegmentStartValue);
   tracker_lane.def("hasSegmentStartValue", &Tracker::Lane::hasSegmentStartValue);
   tracker_lane.def("setSegmentStartValue", &Tracker::Lane::setSegmentStartValue);
   tracker_lane.def("getSegmentEndValue", &Tracker::Lane::getSegmentEndValue);
   tracker_lane.def("hasSegmentEndValue", &Tracker::Lane::hasSegmentEndValue);
   tracker_lane.def("setSegmentEndValue", &Tracker::Lane::setSegmentEndValue);
   tracker_lane.def("hasSegmentValues", &Tracker::Lane::hasSegmentValues);
   tracker_lane.def("isSegmentSteady", &Tracker::Lane::isSegmentSteady);
   tracker_lane.def("setSegmentSteady", &Tracker::Lane::setSegmentSteady);
   // autogen end
}

