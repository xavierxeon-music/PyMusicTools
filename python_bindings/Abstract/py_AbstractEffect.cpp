#include <pybind11/pybind11.h>

#include <Abstract/AbstractEffect.h>

class PyEffect : public Abstract::Effect
{
public:
   using Effect::Effect; // inherit constructor

   float changeSound(const float& in) override
   {
      PYBIND11_OVERRIDE_PURE(
         float,            // Return type
         Abstract::Effect, // Parent class
         createSound,      // Name of function in C++ (must match Python name)
         in                // Argument(s)
      );
   }
};

class PyBufferedEffect : public Abstract::BufferedEffect
{
public:
   using BufferedEffect::BufferedEffect; // inherit constructor

   Data proccessBuffer(const Data& input) override
   {
      PYBIND11_OVERRIDE_PURE(
         Data,                     // Return type
         Abstract::BufferedEffect, // Parent class
         proccessBuffer,           // Name of function in C++ (must match Python name)
         input                     // Argument(s)
      );
   }
};

void init_AbstractEffect(pybind11::module_& module)
{
   pybind11::class_<Abstract::Effect, PyEffect> abstractEffect(module, "AbstractEffect");
   abstractEffect.def(pybind11::init<>());
   abstractEffect.def("changeSound", &Abstract::Effect::changeSound);

   pybind11::class_<Abstract::BufferedEffect, PyBufferedEffect> abstractBufferedEffect(module, "AbstractBufferedEffect");
   abstractBufferedEffect.def(pybind11::init<const uint16_t&>());
   abstractBufferedEffect.def("proccessBuffer", &Abstract::BufferedEffect::proccessBuffer);
   abstractBufferedEffect.def("clear", &Abstract::BufferedEffect::clear);
}