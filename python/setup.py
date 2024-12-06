from setuptools import setup, Extension
import sys

# Path to the pybind11 module (adjust according to your pybind11 installation location)
pybind11_include = "C:/Users/wasay/AppData/Local/Programs/Python/Python313/Lib/site-packages/pybind11/include"

# Define the extension module
ext_modules = [
    Extension(
        'graph_module',  # Name of the Python module
        sources=[  # List of source files
            "C:/Users/wasay/OneDrive/Documents/Navigation Routing System/cpp/graph_pybind.cpp",  # Python bindings
            "C:/Users/wasay/OneDrive/Documents/Navigation Routing System/cpp/graph.cpp"  # Core graph implementation (if needed)
        ],
        include_dirs=[  # Include directories for header files
            pybind11_include,
            "C:/Users/wasay/OneDrive/Documents/Navigation Routing System/cpp"  # Include the directory with graph.cpp
        ],
        language="c++",  # Specify the language is C++
    )
]

# Run the setup function
setup(
    name="graph_module",  # Name of your Python package
    version="0.1",  # Version of the package
    ext_modules=ext_modules,  # Extension modules to compile
)
