PROJECT(components CXX)

FILE(GLOB COMP_SOURCES vfs/*.h vfs/*.hpp vfs/*.cpp
	archives/*.h archives/*.hpp archives/*.cpp
)

IF (WIN32)
	FILE(GLOB COMP_WIN32_SOURCES misc/*.h misc/*.hpp misc/*.cpp)
ENDIF (WIN32)

ADD_LIBRARY (components STATIC ${COMP_SOURCES} ${COMP_WIN32_SOURCES})

SET_TARGET_PROPERTIES(components PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS ON
)
