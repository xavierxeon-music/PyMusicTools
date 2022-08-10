#include <pybind11/pybind11.h>

#include <Abstract/AbstractSoundSource.h>

class PySoundSource : public Abstract::SoundSource
{
public:
   using SoundSource::SoundSource; // inherit constructor

   float createSound() override
   {
      PYBIND11_OVERRIDE_PURE(
         float,                 // Return type
         Abstract::SoundSource, // Parent class
         createSound,           // Name of function in C++ (must match Python name)
         // LEAVE COMMA IN PREVIOUS LINE!
      );
   }
};

void init_AbstractSoundSource(pybind11::module_& module)
{
   pybind11::class_<Abstract::SoundSource, PySoundSource> abstractSoundSource(module, "AbstractSoundSource");
   abstractSoundSource.def(pybind11::init<>());
   abstractSoundSource.def("createSound", &Abstract::SoundSource::createSound);
}