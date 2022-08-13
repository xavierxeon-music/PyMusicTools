#include <pybind11/pybind11.h>

#include <Tools/Counter.h>

void init_Counter(pybind11::module_& module)
{
   pybind11::class_<Counter> counter(module, "Counter");
   counter.def(pybind11::init<const uint64_t&>());

   // autogen start
   // autogen end
}
