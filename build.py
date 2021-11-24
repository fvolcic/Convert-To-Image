import os

os.system("g++ -o3 -std=c++17 -o ImageProcessor src/main.cpp src/specialvector.cpp src/options.cpp src/parse_from_image.cpp src/parse_to_image.cpp")