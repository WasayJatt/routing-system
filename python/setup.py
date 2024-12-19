from setuptools import setup, Extension
import pybind11

extension = Extension(
    name='graph_module',
    sources=[
        'cpp/graph.cpp',          # Include your C++ source files
        'cpp/graph_pybind.cpp',   # Include the Pybind wrapper file
    ],
    include_dirs=[
        'cpp',                    # Add any necessary directories
        pybind11.get_include(),   # Pybind11 includes
    ],
    language='c++',
)

setup(
    name='graph_module',
    ext_modules=[extension],
)
