#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Music/Note.h>

void init_Note(pybind11::module_& module)
{
   pybind11::class_<Note> note(module, "Note");
   note.def(pybind11::init<>());
   

   // autogen start
   pybind11::enum_<Note::Value> value(module, "NoteValue");
   value.value("C", Note::Value::C);
   value.value("Cs", Note::Value::Cs);
   value.value("D", Note::Value::D);
   value.value("Ds", Note::Value::Ds);
   value.value("E", Note::Value::E);
   value.value("F", Note::Value::F);
   value.value("Fs", Note::Value::Fs);
   value.value("G", Note::Value::G);
   value.value("Gs", Note::Value::Gs);
   value.value("A", Note::Value::A);
   value.value("As", Note::Value::As);
   value.value("B", Note::Value::B);
   value.value("Invalid", Note::Value::Invalid);
   value.export_values();
   
   note.def_readonly_static("zeroNote", &Note::zeroNote);
   note.def_readonly_static("availableNotes", &Note::availableNotes);
   note.def_readonly_static("maxNoteIndex", &Note::maxNoteIndex);
   note.def_readonly("name", &Note::name);
   note.def_readonly("value", &Note::value);
   note.def_readonly("octave", &Note::octave);
   note.def_readonly("frequency", &Note::frequency);
   note.def_readonly("voltage", &Note::voltage);
   note.def_readonly("midiValue", &Note::midiValue);
   
   note.def_static("fromVoltage", &Note::fromVoltage);
   note.def_static("fromMidi", &Note::fromMidi);
   note.def_static("fromFrequency", &Note::fromFrequency);
   // autogen end
}

