#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Tools/FastRandom.h>

void init_FastRandom(pybind11::module_& module)
{
   pybind11::class_<FastRandom> fastrandom(module, "FastRandom");
   fastrandom.def(pybind11::init<const uint64_t&>());
   

   // autogen start
   fastrandom.def("reset", &FastRandom::reset);
   fastrandom.def("skip", &FastRandom::skip);
   fastrandom.def("value", &FastRandom::value);
   // autogen end
}

