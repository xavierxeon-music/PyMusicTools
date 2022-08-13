#include <pybind11/pybind11.h>

#include <Midi/MidiFile.h>

void init_MidiFile(pybind11::module_& module)
{
   pybind11::class_<Midi::File> midifile(module, "MidiFile");
   midifile.def(pybind11::init<>());
   

   // autogen start
   // autogen end
}

