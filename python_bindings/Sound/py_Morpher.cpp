#include <pybind11/pybind11.h>

#include <Sound/WaveTableMorpher.h>

void init_Morpher(pybind11::module_& module)
{
   pybind11::class_<WaveTable::Morpher> morpher(module, "Morpher");
   morpher.def(pybind11::init<>());

   morpher.def("addTable", &WaveTable::Morpher::addTable);
   morpher.def("step", &WaveTable::Morpher::step);

   morpher.def("setMix", &WaveTable::Morpher::setMix);
   morpher.def("getMix", &WaveTable::Morpher::getMix);

   morpher.def("setLoop", &WaveTable::Morpher::setLoop);
   morpher.def("swap", &WaveTable::Morpher::swap);

   morpher.def("valueByAngle", &WaveTable::Morpher::valueByAngle);
}