cmake_minimum_required(VERSION 4.2)
project(GoblinQuest)

set(CMAKE_CXX_STANDARD 14)

include_directories(GoblinQuest)

add_executable(GoblinQuest
        GoblinQuest/Difficulty.h
        GoblinQuest/EventLoop.cpp
        GoblinQuest/EventLoop.h
        GoblinQuest/GoblinQuest.cpp
        GoblinQuest/Hero.cpp
        GoblinQuest/Hero.h
        GoblinQuest/Level.cpp
        GoblinQuest/level.h
        GoblinQuest/Level1.cpp
        GoblinQuest/Level1.h
        GoblinQuest/Level2.cpp
        GoblinQuest/Level2.h
        GoblinQuest/Monster.cpp
        GoblinQuest/Monster.h
        GoblinQuest/Stats.h
        GoblinQuest/Terminal.cpp
        GoblinQuest/Terminal.h
        GoblinQuest/Troop.h)
