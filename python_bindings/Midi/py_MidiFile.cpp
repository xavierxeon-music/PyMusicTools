#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Midi/MidiFile.h>

void init_MidiFile(pybind11::module_& module)
{
   pybind11::class_<Midi::File> midi_file(module, "File");
   midi_file.def(pybind11::init<>());
   

   // autogen start
   midi_file.def_static("load", &Midi::File::load);
   midi_file.def_static("save", &Midi::File::save);
   // autogen end
}

