#include <pybind11/pybind11.h>

#include <Blocks/Sequencer.h>

void init_Sequencer(pybind11::module_& module)
{
   pybind11::class_<Sequencer> sequencer(module, "Sequencer");
   sequencer.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Info> sequencer_info(sequencer, "SequencerInfo");
   sequencer_info.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Track> sequencer_track(sequencer, "SequencerTrack");
   sequencer_track.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Track::Header> sequencer_track_header(sequencer_track, "SequencerTrackHeader");
   sequencer_track_header.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Track::NoteEvent> sequencer_track_noteevent(sequencer_track, "SequencerTrackNoteEvent");
   sequencer_track_noteevent.def(pybind11::init<>());
   

   // autogen start
   sequencer.def("compileInfo", &Sequencer::compileInfo);
   sequencer.def("getTrackList", &Sequencer::getTrackList);
   sequencer.def("compileBarCounter", &Sequencer::compileBarCounter);
   sequencer.def("fromTick", &Sequencer::fromTick);
   sequencer.def("toTick", &Sequencer::toTick);
   // autogen end
}

