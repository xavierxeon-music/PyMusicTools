#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Music/TimeCode.h>

void init_TimeCode(pybind11::module_& module)
{
   pybind11::class_<TimeCode> timecode(module, "TimeCode");
   timecode.def(pybind11::init<>());
   

   // autogen start
   timecode.def_readwrite("bar", &TimeCode::bar);
   timecode.def_readwrite("quarter", &TimeCode::quarter);
   timecode.def_readwrite("tick", &TimeCode::tick);
   
   timecode.def("text", &TimeCode::text);
   timecode.def("toDuration", &TimeCode::toDuration);
   // autogen end
}

