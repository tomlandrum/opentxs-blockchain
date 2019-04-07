#[[
// clang-format off
]]#
# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_HOME_DIRECTORY}/include
)

set(MODULE_NAME opentxs-blockchain)


if(NOT OT_BUNDLED_OPENTXS_BLOCKCHAIN)
  find_package(opentxs-proto REQUIRED)

  set(ENV{PKG_CONFIG_PATH} "/usr/local/lib/pkgconfig/:$ENV{PKG_CONFIG_PATH}")
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(LIB_BITCOIN REQUIRED libbitcoin-system) 

  file(GLOB cxx-sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
  file(GLOB cxx-headers "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

  add_library(${MODULE_NAME} SHARED
  ${cxx-sources}
  ${cxx-headers})

  add_library(${MODULE_NAME}_static STATIC
  ${cxx-sources}
  ${cxx-headers})

  target_link_libraries(${MODULE_NAME}
    PUBLIC
    PRIVATE
  )

  target_link_libraries(${MODULE_NAME}_static
    PUBLIC
    PRIVATE
  )
  
  target_link_libraries(${MODULE_NAME} PUBLIC ${LIBBITCOIN_LIBRARIES})

  set_target_properties(${MODULE_NAME} PROPERTIES OUTPUT_NAME ${MODULE_NAME})
  set_target_properties(${MODULE_NAME}_static PROPERTIES OUTPUT_NAME ${MODULE_NAME})
  target_link_libraries(${MODULE_NAME} PRIVATE ${OPENTXS_PROTO_LIBRARIES})
  target_include_directories(${MODULE_NAME} PUBLIC ${OPENTXS_PROTO_INCLUDE_DIRS})

  install(TARGETS ${MODULE_NAME} ${MODULE_NAME}_static
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT ${MODULE_NAME}-targets
          COMPONENT main)
endif()
#[[
// clang-format on
]]#
