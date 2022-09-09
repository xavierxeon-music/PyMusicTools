#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/TrackerProject.h>

void init_TrackerProject(pybind11::module_& module)
{
   pybind11::class_<Tracker::Project> tracker_project(module, "Project");
   tracker_project.def(pybind11::init<>());
   

   // autogen start
   tracker_project.def("clear", &Tracker::Project::clear);
   tracker_project.def("update", &Tracker::Project::update);
   tracker_project.def("clockTick", &Tracker::Project::clockTick);
   tracker_project.def("clockReset", &Tracker::Project::clockReset);
   tracker_project.def("getDivison", &Tracker::Project::getDivison);
   tracker_project.def("getSegmentCount", &Tracker::Project::getSegmentCount);
   tracker_project.def("getLaneCount", &Tracker::Project::getLaneCount);
   tracker_project.def("getLane", &Tracker::Project::getLane);
   tracker_project.def("isLooping", &Tracker::Project::isLooping);
   tracker_project.def("setLooping", &Tracker::Project::setLooping);
   tracker_project.def("getCurrentSegmentIndex", &Tracker::Project::getCurrentSegmentIndex);
   // autogen end
}

