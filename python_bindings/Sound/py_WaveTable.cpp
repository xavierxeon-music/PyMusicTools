#include <pybind11/pybind11.h>

#include <Sound/StandardTable.h>
#include <Sound/WaveTable.h>

class PyStepTable : public WaveTable::StepTable
{
public:
   using StepTable::StepTable; // inherit constructor

   float valueByAngle(const float& angle) const override
   {
      PYBIND11_OVERRIDE_PURE(
         float,        // Return type
         StepTable,    // Parent class
         valueByAngle, // Name of function in C++ (must match Python name)
         angle         // Argument(s)
      );
   }
};

void init_WaveTable(pybind11::module_& module)
{
   //py::object pet = (py::object) py::module_::import("basic").attr("Pet");
   pybind11::module_ waveTable = module.def_submodule("WaveTable");

   pybind11::class_<WaveTable::Oscilator, Abstract::Oscilator> tableOscilator(waveTable, "Oscilator");
   tableOscilator.def(pybind11::init<>());
   tableOscilator.def_property("phase", &WaveTable::Oscilator::getPhase, &WaveTable::Oscilator::setPhase);
   tableOscilator.def_property("frequency", &WaveTable::Oscilator::getFrequency, &WaveTable::Oscilator::setFrequency);
   tableOscilator.def_property("amplitude", &WaveTable::Oscilator::getAmplitude, &WaveTable::Oscilator::setAmplitude);
   tableOscilator.def("init", &WaveTable::Oscilator::init);
   tableOscilator.def("setCycleDuration", &WaveTable::Oscilator::setCycleDuration);

   pybind11::class_<Standard::Waveform> waveform(waveTable, "Waveform");
   waveform.def_static("getName", &Standard::Waveform::getName);

   pybind11::enum_<Standard::Waveform::Shape> shape(waveform, "Shape");
   shape.value("Sine", Standard::Waveform::Sine);
   shape.value("Saw", Standard::Waveform::Saw);
   shape.value("Square", Standard::Waveform::Square);
   shape.value("SlopeUp", Standard::Waveform::SlopeUp);
   shape.value("SlopeDown", Standard::Waveform::SlopeDown);
   shape.export_values();

   pybind11::class_<WaveTable::AbstractTable>(waveTable, "AbstractTable");

   pybind11::class_<Standard::Table, WaveTable::AbstractTable> table(waveTable, "StandardTable");
   table.def(pybind11::init<>());
   table.def("setWaveform", &Standard::Table::setWaveform);

   pybind11::class_<WaveTable::StepTable, PyStepTable> stepTable(waveTable, "StepTable");
   stepTable.def(pybind11::init<const float>(), pybind11::arg("maxAngle") = 2.0f * Maths::pi);
   stepTable.def("getMaxAngle", &WaveTable::StepTable::getMaxAngle);
   stepTable.def("valueByAngle", &WaveTable::StepTable::valueByAngle);
}