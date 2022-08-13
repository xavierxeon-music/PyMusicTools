#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <Sound/SoundMesh.h>

void init_SoundMesh(pybind11::module_& module)
{
   pybind11::class_<SoundMesh> soundmesh(module, "SoundMesh");
   soundmesh.def(pybind11::init<>());

   pybind11::class_<SoundMesh::Point> soundmesh_point(soundmesh, "Point");
   soundmesh_point.def(pybind11::init<>());

   pybind11::class_<SoundMesh::Grid> soundmesh_grid(soundmesh, "Grid");
   soundmesh_grid.def(pybind11::init<const uint16_t&>());

   pybind11::class_<SoundMesh::Grid::PointF> soundmesh_grid_pointf(soundmesh_grid, "PointF");
   soundmesh_grid_pointf.def(pybind11::init<>());

   pybind11::class_<SoundMesh::Table> soundmesh_table(soundmesh, "Table");
   soundmesh_table.def(pybind11::init<const uint64_t&>());

   // autogen start
   // autogen end
}
