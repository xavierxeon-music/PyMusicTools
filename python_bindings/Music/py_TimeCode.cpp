#include <pybind11/pybind11.h>

#include <Music/TimeCode.h>

void init_TimeCode(pybind11::module_ &module)
{
   pybind11::class_<TimeCode> timeCode(module, "TimeCode");
   timeCode.def(pybind11::init<>());
   timeCode.def(pybind11::init<TimeCode::Duration, uint8_t, uint8_t>());
   timeCode.def("text", &TimeCode::text);
   timeCode.def("toDuration", &TimeCode::toDuration);
   timeCode.def_readonly("bar", &TimeCode::bar);
   timeCode.def_readonly("quarter", &TimeCode::quarter);
   timeCode.def_readonly("tick", &TimeCode::tick);
}