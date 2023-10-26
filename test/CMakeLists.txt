# 寻找Qt5库
find_package(Qt5 COMPONENTS Core Gui REQUIRED)


add_executable(test-user test_user.cpp)
target_link_libraries(test-user
PUBLIC
    Data
    Qt5::Core
    Qt5::Gui
)

add_executable(test-order test_order.cpp)
target_link_libraries(test-order
PUBLIC
    Data
    Qt5::Core
    Qt5::Gui
)

add_executable(test-mkdir test_mkdir.cpp)
target_link_libraries(test-mkdir
PUBLIC
    Qt5::Core
    Qt5::Gui
)

add_executable(test-add test_add.cpp)
target_link_libraries(test-add
PUBLIC
    Qt5::Core
    Qt5::Gui
)