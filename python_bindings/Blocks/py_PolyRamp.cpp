#include <pybind11/pybind11.h>

#include <Blocks/PolyRamp.h>

void init_PolyRamp(pybind11::module_& module)
{
   pybind11::class_<PolyRamp> polyramp(module, "PolyRamp");
   polyramp.def(pybind11::init<>());

   // autogen start
   pybind11::enum_<PolyRamp::LengthStatus> lengthstatus(polyramp, "LengthStatus");
   lengthstatus.value("Kept", PolyRamp::LengthStatus::Kept);
   lengthstatus.value("Changed", PolyRamp::LengthStatus::Changed);
   lengthstatus.value("Error", PolyRamp::LengthStatus::Error);
   lengthstatus.export_values();
   
   polyramp.def("clear", &PolyRamp::clear);
   polyramp.def("clockTick", &PolyRamp::clockTick);
   polyramp.def("clockReset", &PolyRamp::clockReset);
   polyramp.def("getCurrentStageIndex", &PolyRamp::getCurrentStageIndex);
   polyramp.def("getCurrentStagePercentage", &PolyRamp::getCurrentStagePercentage);
   polyramp.def("getCurrentValue", &PolyRamp::getCurrentValue);
   polyramp.def("isValid", &PolyRamp::isValid);
   polyramp.def("getStepSize", &PolyRamp::getStepSize);
   polyramp.def("setStepSize", &PolyRamp::setStepSize);
   polyramp.def("changeStepSize", &PolyRamp::changeStepSize);
   polyramp.def("getLength", &PolyRamp::getLength);
   polyramp.def("setLength", &PolyRamp::setLength);
   polyramp.def("trimLength", &PolyRamp::trimLength);
   polyramp.def("getStageCount", &PolyRamp::getStageCount);
   polyramp.def("addStage", &PolyRamp::addStage);
   polyramp.def("moveStage", &PolyRamp::moveStage);
   polyramp.def("removeStage", &PolyRamp::removeStage);
   polyramp.def("getStageStartHeight", &PolyRamp::getStageStartHeight);
   polyramp.def("setStageStartHeight", &PolyRamp::setStageStartHeight);
   polyramp.def("getStageEndHeight", &PolyRamp::getStageEndHeight);
   polyramp.def("setStageEndHeight", &PolyRamp::setStageEndHeight);
   polyramp.def("getStageLength", &PolyRamp::getStageLength);
   polyramp.def("setStageLength", &PolyRamp::setStageLength);
   polyramp.def("isLooping", &PolyRamp::isLooping);
   polyramp.def("setLooping", &PolyRamp::setLooping);
   // autogen end
}

