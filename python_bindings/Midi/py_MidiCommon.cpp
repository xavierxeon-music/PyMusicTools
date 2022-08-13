#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Midi/MidiCommon.h>

void init_MidiCommon(pybind11::module_& module)
{
   pybind11::class_<Midi::Midi> module_midi_Midi(module_midi, "Midi");
   module_midi_Midi.def(pybind11::init<>());
   

   // autogen start
   // autogen end
}

