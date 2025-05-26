spack load gcc@13.3.0 glew glm glfw mesa-glu libx11 libxrandr libxi libxinerama libxcursor libxxf86vm

export CC=$(spack location -i gcc)/bin/gcc
export CXX=$(spack location -i gcc)/bin/g++
