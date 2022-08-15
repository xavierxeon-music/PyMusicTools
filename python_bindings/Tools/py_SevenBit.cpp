#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Tools/SevenBit.h>

void init_SevenBit(pybind11::module_& module)
{
   pybind11::class_<SevenBit> sevenbit(module, "SevenBit");
   sevenbit.def(pybind11::init<>());
   

   // autogen start
   sevenbit.def_static("encode", &SevenBit::encode);
   sevenbit.def_static("decode", &SevenBit::decode);
   // autogen end
}

