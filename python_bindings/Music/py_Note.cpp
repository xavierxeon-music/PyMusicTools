#include <pybind11/pybind11.h>

#include <Music/Note.h>

void init_Note(pybind11::module_ &module)
{
   pybind11::class_<Note> note(module, "Note");
   note.def_static("fromVoltage", &Note::fromVoltage);
   note.def_static("fromMidi", &Note::fromMidi);
   note.def_static("fromFrequency", &Note::fromFrequency);
   note.def_readonly("name", &Note::name);
   note.def_readonly("frequency", &Note::frequency);
   note.def_readonly("voltage", &Note::voltage);
   note.def_readonly("midiValue", &Note::midiValue);

   note.def_readonly_static("zeroNote", &Note::zeroNote);
   note.def_readonly_static("availableNotes", &Note::availableNotes);
   note.def_readonly_static("maxNoteIndex", &Note::maxNoteIndex);
}