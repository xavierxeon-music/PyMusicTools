#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Music/Tempo.h>

void init_Tempo(pybind11::module_& module)
{
   pybind11::class_<Tempo> tempo(module, "Tempo");
   tempo.def(pybind11::init<>());
   

   // autogen start
   pybind11::enum_<Tempo::Division> division(module, "TempoDivision");
   division.value("Sixteenth", Tempo::Division::Sixteenth);
   division.value("Eigth", Tempo::Division::Eigth);
   division.value("Quarter", Tempo::Division::Quarter);
   division.value("Bar", Tempo::Division::Bar);
   division.export_values();
   
   pybind11::enum_<Tempo::RunState> runstate(module, "TempoRunState");
   runstate.value("Reset", Tempo::RunState::Reset);
   runstate.value("Off", Tempo::RunState::Off);
   runstate.value("FirstTick", Tempo::RunState::FirstTick);
   runstate.value("Running", Tempo::RunState::Running);
   runstate.export_values();
   
   tempo.def_static("getName", &Tempo::getName);
   tempo.def("getRunState", &Tempo::getRunState);
   tempo.def("isRunningOrFirstTick", &Tempo::isRunningOrFirstTick);
   tempo.def("getBeatsPerMinute", &Tempo::getBeatsPerMinute);
   tempo.def("getCounter", &Tempo::getCounter);
   tempo.def("getPercentage", &Tempo::getPercentage);
   tempo.def("advance", &Tempo::advance);
   tempo.def("clockTick", &Tempo::clockTick);
   tempo.def("clockReset", &Tempo::clockReset);
   // autogen end
}

