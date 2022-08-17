#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Blocks/Sequencer.h>

void init_Sequencer(pybind11::module_& module)
{
   pybind11::class_<Sequencer> sequencer(module, "Sequencer");
   sequencer.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Info> sequencer_info(sequencer, "Info");
   sequencer_info.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Track> sequencer_track(sequencer, "Track");
   sequencer_track.def(pybind11::init<>());
   
   pybind11::class_<Sequencer::Track::NoteEvent> sequencer_track_noteevent(sequencer_track, "NoteEvent");
   sequencer_track_noteevent.def(pybind11::init<>());
   

   // autogen start
   sequencer_info.def_readwrite("maxTick", &Sequencer::Info::maxTick);
   sequencer_info.def_readwrite("barCounter", &Sequencer::Info::barCounter);
   sequencer_info.def_readwrite("bpm", &Sequencer::Info::bpm);
   sequencer_info.def_readwrite("minutes", &Sequencer::Info::minutes);
   sequencer_info.def_readwrite("seconds", &Sequencer::Info::seconds);
   
   sequencer_track_noteevent.def_readwrite("channel", &Sequencer::Track::NoteEvent::channel);
   sequencer_track_noteevent.def_readwrite("key", &Sequencer::Track::NoteEvent::key);
   sequencer_track_noteevent.def_readwrite("velocity", &Sequencer::Track::NoteEvent::velocity);
   sequencer_track_noteevent.def_readwrite("on", &Sequencer::Track::NoteEvent::on);
   
   sequencer_track.def_readwrite("maxTick", &Sequencer::Track::maxTick);
   sequencer_track.def_readwrite("name", &Sequencer::Track::name);
   sequencer_track.def_readwrite("isMonophonic", &Sequencer::Track::isMonophonic);
   sequencer_track.def_readwrite("noteOnEventMap", &Sequencer::Track::noteOnEventMap);
   sequencer_track.def_readwrite("noteOffEventMap", &Sequencer::Track::noteOffEventMap);
   
   sequencer.def("compileInfo", &Sequencer::compileInfo);
   sequencer.def("getTrackList", &Sequencer::getTrackList);
   sequencer.def("compileBarCounter", &Sequencer::compileBarCounter);
   sequencer.def("fromTick", &Sequencer::fromTick);
   sequencer.def("toTick", &Sequencer::toTick);
   // autogen end
}

