cmake_minimum_required(VERSION 3.15)
project(DS)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)

#顺序表
add_executable(static_list list/seqlist/static_list.cpp)
add_executable(dynamic_list list/seqlist/dynamic_list.cpp)

#链表
add_executable(LinkListWithHead list/linklist/LinkListWithHead.cpp)
add_executable(LinkListWithoutHead list/linklist/LinkListWithoutHead.cpp)
add_executable(DLinkList list/linklist/DLinkList.cpp)
add_executable(CycleLinkList list/linklist/CycleLinkList.cpp)
add_executable(CycleDLinkList list/linklist/CycleDLinkList.cpp)

