#include <pybind11/pybind11.h>

#include <Midi/MidiFile.h>

void init_MidiFile(pybind11::module_& module)
{
   pybind11::class_<Midi::File> midifile(module, "MidiFile");
   midifile.def(pybind11::init<>());
   

   // autogen start
   midifile.def_static("load", &Midi::File::load);
   midifile.def_static("save", &Midi::File::save);
   // autogen end
}

