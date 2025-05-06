project(ASCORE)

add_library(ASCORE SHARED
    src/ASCore.cpp
    include/ASCore.hpp
)

target_include_directories(ASCORE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (MSVC)
    target_compile_definitions(ASCORE PRIVATE ASCORE_EXPORTS)
endif()

include_directories("C:/opencv/build/include")
link_directories("C:/opencv/build/x64/vc16/lib")

# OpenCV 설치 경로
set(OpenCVLibDir "C:/opencv/build/x64/vc16/lib")


# Debug / Release 각각에 맞게 직접 경로 지정
target_link_libraries(ASCORE
    PRIVATE
    debug "${OpenCVLibDir}/opencv_world4110d.lib"
    optimized "${OpenCVLibDir}/opencv_world4110.lib"
)