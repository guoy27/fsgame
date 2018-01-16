set(framesync_files
  ${SOURCE_DIR}/framesync/fsworld.h
  ${SOURCE_DIR}/framesync/fsworld.cpp
  ${SOURCE_DIR}/framesync/fsscene.h
  ${SOURCE_DIR}/framesync/fsscene.cpp
  ${SOURCE_DIR}/framesync/fsentity.h
  ${SOURCE_DIR}/framesync/fsentity.cpp
  ${SOURCE_DIR}/framesync/fscommand.h
  ${SOURCE_DIR}/framesync/fscommand.cpp
  ${SOURCE_DIR}/framesync/fslogic.h
  ${SOURCE_DIR}/framesync/fslogic.cpp
  
)

add_library(framesync ${SHARED_OR_STATIC}
  ${framesync_files})
#target_link_libraries(FSCommon ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(framesync PUBLIC ${SOURCE_DIR}/framesync)
target_include_directories(framesync PRIVATE ${SOURCE_DIR}/common)

set_target_properties(framesync PROPERTIES
    OUTPUT_NAME ${LIB_PREFIX}framesync
    DEBUG_POSTFIX "${DEBUG_POSTFIX}")

if(BUILD_TEST)
  set(libframesync_test_files
    ${SOURCE_DIR}/framesync/test/test_libframesync.cpp
  )

  add_executable(test_libframesync ${libframesync_test_files})
  target_link_libraries(test_libframesync commom framesync)
endif()