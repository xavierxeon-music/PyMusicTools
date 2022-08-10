#include <pybind11/pybind11.h>

#include <Midi/MidiCommon.h>

void init_MidiCommon(pybind11::module_& module)
{
   pybind11::module_& midicommon = module;

   // autogen start
   pybind11::enum_<Midi::Event> event(midicommon, "MidiEvent");
   event.value("Unknown", Midi::Event::Unknown);
   event.value("NoteOn", Midi::Event::NoteOn);
   event.value("PolyKeyPressure", Midi::Event::PolyKeyPressure);
   event.value("ControlChange", Midi::Event::ControlChange);
   event.value("ProgrammChange", Midi::Event::ProgrammChange);
   event.value("ChannelPressure", Midi::Event::ChannelPressure);
   event.value("PitchBend", Midi::Event::PitchBend);
   event.value("TimeCode", Midi::Event::TimeCode);
   event.value("SongPositionPointer", Midi::Event::SongPositionPointer);
   event.value("SongSelect", Midi::Event::SongSelect);
   event.value("TuneRequest", Midi::Event::TuneRequest);
   event.value("SysExEnd", Midi::Event::SysExEnd);
   event.value("UndefinedA", Midi::Event::UndefinedA);
   event.value("Start", Midi::Event::Start);
   event.value("Continue", Midi::Event::Continue);
   event.value("Stop", Midi::Event::Stop);
   event.value("UndefinedB", Midi::Event::UndefinedB);
   event.value("ActiveSensinig", Midi::Event::ActiveSensinig);
   event.value("Reset", Midi::Event::Reset);
   event.value("Meta", Midi::Event::Meta);
   event.export_values();
   
   pybind11::enum_<Midi::MetaEvent> metaevent(midicommon, "MidiMetaEvent");
   metaevent.value("MetaUnkown", Midi::MetaEvent::MetaUnkown);
   metaevent.value("Text", Midi::MetaEvent::Text);
   metaevent.value("Copyright", Midi::MetaEvent::Copyright);
   metaevent.value("TrackName", Midi::MetaEvent::TrackName);
   metaevent.value("InstrumentName", Midi::MetaEvent::InstrumentName);
   metaevent.value("Lyric", Midi::MetaEvent::Lyric);
   metaevent.value("Marker", Midi::MetaEvent::Marker);
   metaevent.value("CuePoint", Midi::MetaEvent::CuePoint);
   metaevent.value("ChannelPrefix", Midi::MetaEvent::ChannelPrefix);
   metaevent.value("MidiPort", Midi::MetaEvent::MidiPort);
   metaevent.value("EndOfTrack", Midi::MetaEvent::EndOfTrack);
   metaevent.value("LiveTag", Midi::MetaEvent::LiveTag);
   metaevent.value("Tempo", Midi::MetaEvent::Tempo);
   metaevent.value("SMPTEOffset", Midi::MetaEvent::SMPTEOffset);
   metaevent.value("TimeSignature", Midi::MetaEvent::TimeSignature);
   metaevent.value("KeySignature", Midi::MetaEvent::KeySignature);
   metaevent.export_values();
   
   pybind11::enum_<Midi::ControllerMessage> controllermessage(midicommon, "MidiControllerMessage");
   controllermessage.value("BankSelect", Midi::ControllerMessage::BankSelect);
   controllermessage.value("ModWheel", Midi::ControllerMessage::ModWheel);
   controllermessage.value("BreathController", Midi::ControllerMessage::BreathController);
   controllermessage.value("FootController", Midi::ControllerMessage::FootController);
   controllermessage.value("PortamentoTime", Midi::ControllerMessage::PortamentoTime);
   controllermessage.value("ChannelVolume", Midi::ControllerMessage::ChannelVolume);
   controllermessage.value("Balance", Midi::ControllerMessage::Balance);
   controllermessage.value("Pan", Midi::ControllerMessage::Pan);
   controllermessage.value("ExpressionController", Midi::ControllerMessage::ExpressionController);
   controllermessage.value("EffectControl1", Midi::ControllerMessage::EffectControl1);
   controllermessage.value("EffectControl2", Midi::ControllerMessage::EffectControl2);
   controllermessage.value("RememberBlock", Midi::ControllerMessage::RememberBlock);
   controllermessage.value("RememberApply", Midi::ControllerMessage::RememberApply);
   controllermessage.value("RememberRequest", Midi::ControllerMessage::RememberRequest);
   controllermessage.value("DataInit", Midi::ControllerMessage::DataInit);
   controllermessage.value("DataBlock", Midi::ControllerMessage::DataBlock);
   controllermessage.value("DataApply", Midi::ControllerMessage::DataApply);
   controllermessage.value("Undefined08", Midi::ControllerMessage::Undefined08);
   controllermessage.value("Undefined09", Midi::ControllerMessage::Undefined09);
   controllermessage.value("Undefined10", Midi::ControllerMessage::Undefined10);
   controllermessage.value("Undefined11", Midi::ControllerMessage::Undefined11);
   controllermessage.value("Undefined12", Midi::ControllerMessage::Undefined12);
   controllermessage.value("Portamento", Midi::ControllerMessage::Portamento);
   controllermessage.value("Sostenuto", Midi::ControllerMessage::Sostenuto);
   controllermessage.value("SoftPedal", Midi::ControllerMessage::SoftPedal);
   controllermessage.value("LegatoSwitch", Midi::ControllerMessage::LegatoSwitch);
   controllermessage.value("User02", Midi::ControllerMessage::User02);
   controllermessage.value("User03", Midi::ControllerMessage::User03);
   controllermessage.value("User04", Midi::ControllerMessage::User04);
   controllermessage.value("User05", Midi::ControllerMessage::User05);
   controllermessage.value("User06", Midi::ControllerMessage::User06);
   controllermessage.value("User07", Midi::ControllerMessage::User07);
   controllermessage.value("User08", Midi::ControllerMessage::User08);
   controllermessage.value("User09", Midi::ControllerMessage::User09);
   controllermessage.value("User10", Midi::ControllerMessage::User10);
   controllermessage.value("User11", Midi::ControllerMessage::User11);
   controllermessage.value("User12", Midi::ControllerMessage::User12);
   controllermessage.value("User13", Midi::ControllerMessage::User13);
   controllermessage.value("User14", Midi::ControllerMessage::User14);
   controllermessage.value("User15", Midi::ControllerMessage::User15);
   controllermessage.value("User16", Midi::ControllerMessage::User16);
   controllermessage.value("User17", Midi::ControllerMessage::User17);
   controllermessage.value("User18", Midi::ControllerMessage::User18);
   controllermessage.value("ResetAllControlers", Midi::ControllerMessage::ResetAllControlers);
   controllermessage.value("AllNotesOff", Midi::ControllerMessage::AllNotesOff);
   controllermessage.export_values();
   
   pybind11::enum_<Midi::Playback> playback(midicommon, "MidiPlayback");
   playback.value("Start", Midi::Playback::Start);
   playback.value("Continue", Midi::Playback::Continue);
   playback.value("Stop", Midi::Playback::Stop);
   playback.export_values();
   
   // autogen end
}
