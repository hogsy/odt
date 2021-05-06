project(ODTViewer)

add_executable(ODTViewer
        ../Baron/GroupFile.cpp  ../Baron/GroupFile.h
        ../Baron/Level.cpp      ../Baron/Level.h
        viewer.cpp)

target_link_libraries(ODTViewer glut)
