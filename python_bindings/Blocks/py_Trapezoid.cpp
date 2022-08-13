#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/Trapezoid.h>

void init_Trapezoid(pybind11::module_& module)
{
   pybind11::class_<Trapezoid> trapezoid(module, "Trapezoid");
   trapezoid.def(pybind11::init<>());
   

   // autogen start
   pybind11::enum_<Trapezoid::Stage> stage(module, "TrapezoidStage");
   stage.value("Wait", Trapezoid::Stage::Wait);
   stage.value("Rise", Trapezoid::Stage::Rise);
   stage.value("High", Trapezoid::Stage::High);
   stage.value("Fall", Trapezoid::Stage::Fall);
   stage.value("Low", Trapezoid::Stage::Low);
   stage.export_values();
   
   pybind11::enum_<Trapezoid::Bound> bound(module, "TrapezoidBound");
   bound.value("Min", Trapezoid::Bound::Min);
   bound.value("Max", Trapezoid::Bound::Max);
   bound.export_values();
   
   trapezoid.def_static("stageName", &Trapezoid::stageName);
   trapezoid.def("init", &Trapezoid::init);
   trapezoid.def("clockTick", &Trapezoid::clockTick);
   trapezoid.def("clockReset", &Trapezoid::clockReset);
   trapezoid.def("getCurrentStage", &Trapezoid::getCurrentStage);
   trapezoid.def("getCurrentStagePercentage", &Trapezoid::getCurrentStagePercentage);
   trapezoid.def("getCurrentValue", &Trapezoid::getCurrentValue);
   trapezoid.def("getStageLength", &Trapezoid::getStageLength);
   trapezoid.def("setStageLength", &Trapezoid::setStageLength);
   trapezoid.def("changeStageLength", &Trapezoid::changeStageLength);
   trapezoid.def("getStepSize", &Trapezoid::getStepSize);
   trapezoid.def("setStepSize", &Trapezoid::setStepSize);
   trapezoid.def("changeStepSize", &Trapezoid::changeStepSize);
   trapezoid.def("getBound", &Trapezoid::getBound);
   trapezoid.def("setBound", &Trapezoid::setBound);
   trapezoid.def("changeBound", &Trapezoid::changeBound);
   trapezoid.def("isValid", &Trapezoid::isValid);
   // autogen end
}

