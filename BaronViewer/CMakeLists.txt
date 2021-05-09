project(BaronViewer)

add_executable(BaronViewer
        ../Baron/GroupFile.cpp

        BaronViewer.cpp
        EventReceiver.cpp)

target_link_libraries(BaronViewer Irrlicht)
