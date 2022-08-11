#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Tools/SevenBit.h>

class PySevenBit
{
public:
   static std::string encode(const Bytes& input)
   {
      const Bytes base64 = SevenBit::encode(input);

      std::string output(base64.begin(), base64.end());
      return output;
   }

   static Bytes decode(const std::string& input)
   {
      Bytes base64(input.size(), 0);
      std::memcpy(base64.data(), input.data(), input.size());

      Bytes output = SevenBit::decode(base64);
      return output;
   }
};

void init_SevenBit(pybind11::module_& module)
{
   pybind11::class_<PySevenBit> sevenbit(module, "SevenBit");
   sevenbit.def_static("encode", &PySevenBit::encode);
   sevenbit.def_static("decode", &PySevenBit::decode);
}
