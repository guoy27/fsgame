set(commom_files
  ${SOURCE_DIR}/common/log/log.h
  ${SOURCE_DIR}/common/log/log.cpp
  ${SOURCE_DIR}/common/random/random.h
  ${SOURCE_DIR}/common/random/random.cpp
)

add_library(commom ${SHARED_OR_STATIC}
  ${commom_files})
#target_link_libraries(FSCommon ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(commom PUBLIC ${SOURCE_DIR}/commom)

set_target_properties(commom PROPERTIES
    OUTPUT_NAME ${LIB_PREFIX}commom
    DEBUG_POSTFIX "${DEBUG_POSTFIX}")


if(MSVC AND BUILD_SHARED_LIBS)
  target_compile_definitions(commom
    PUBLIC  USE_DLLS
    PRIVATE LIB_EXPORTS)
endif()

if(BUILD_TEST)
	set(libcommon_test_files
	  ${SOURCE_DIR}/common/test/test_libcommon.cpp
	)

  add_executable(test_libcommon ${libcommon_test_files})
  target_link_libraries(test_libcommon commom)

endif()