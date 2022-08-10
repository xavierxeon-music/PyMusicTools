#include <pybind11/pybind11.h>

#include <Abstract/AbstractOscilator.h>

class PyOscilator : public Abstract::Oscilator
{
public:
   using Oscilator::Oscilator; // inherit constructor

   float createSound() override
   {
      PYBIND11_OVERRIDE_PURE(
         float,               // Return type
         Abstract::Oscilator, // Parent class
         createSound,         // Name of function in C++ (must match Python name)
         // LEAVE COMMA IN PREVIOUS LINE!
      );
   }
};

void init_AbstractOscilator(pybind11::module_& module)
{
   pybind11::class_<Abstract::Oscilator, PyOscilator> abstractOsclator(module, "AbstractOscilator");
   abstractOsclator.def(pybind11::init<>());
   abstractOsclator.def_static("frequencyFromCV", &Abstract::Oscilator::frequencyFromCV);
   abstractOsclator.def("createSound", &Abstract::SoundSource::createSound);
}