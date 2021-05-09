project(BaronViewer)

add_executable(BaronViewer
        ../Baron/GroupFile.cpp  ../Baron/GroupFile.h
        ../Baron/Level.cpp      ../Baron/Level.h
        BaronViewer.cpp
        EventReceiver.cpp)

target_link_libraries(BaronViewer Irrlicht)
