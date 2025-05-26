cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------------------------
# INCLUDE DIRECTORIES
# ----------------------------------------------------
find_path(GLEW_INCLUDE_DIR GL/glew.h)
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h)
find_path(GLM_INCLUDE_DIR glm/glm.hpp)
find_path(GLU_INCLUDE_DIR GL/glu.h)
find_path(MESA_INCLUDE_DIR GL/gl.h)

include_directories(
    ${GLEW_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${GLU_INCLUDE_DIR}
    ${MESA_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# ----------------------------------------------------
# LIBRARIES
# ----------------------------------------------------
find_library(GLEW_LIBRARY GLEW)
find_library(GLFW_LIBRARY glfw3)  
find_library(GLU_LIBRARY GLU)
find_library(X11_LIBRARY X11)
find_library(XRANDR_LIBRARY Xrandr)
find_library(XI_LIBRARY Xi)
find_library(XINERAMA_LIBRARY Xinerama)
find_library(XCURSOR_LIBRARY Xcursor)
find_library(XXF86VM_LIBRARY Xxf86vm)
find_library(DL_LIBRARY dl)
find_library(PTHREAD_LIBRARY pthread)
find_library(M_LIBRARY m)

find_package(OpenGL REQUIRED)

# ----------------------------------------------------
# SOURCES
# ----------------------------------------------------
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.hpp)

# ----------------------------------------------------
# BUILD EXECUTABLE
# ----------------------------------------------------
add_executable(OpenGLProject ${SOURCES} ${HEADERS})

# ----------------------------------------------------
# LINK EVERYTHING
# ----------------------------------------------------
target_link_libraries(OpenGLProject
    ${GLEW_LIBRARY}
    ${GLFW_LIBRARY}
    ${GLU_LIBRARY}
    ${OPENGL_gl_LIBRARY}

    ${X11_LIBRARY}
    ${XRANDR_LIBRARY}
    ${XI_LIBRARY}
    ${XINERAMA_LIBRARY}
    ${XCURSOR_LIBRARY}
    ${XXF86VM_LIBRARY}

    ${PTHREAD_LIBRARY}
    ${DL_LIBRARY}
    ${M_LIBRARY}
)

# ----------------------------------------------------
# COPY SHADERS / ASSETS INTO BUILD DIRECTORY
# ----------------------------------------------------
file(COPY ${CMAKE_SOURCE_DIR}/assets
     DESTINATION ${CMAKE_BINARY_DIR})