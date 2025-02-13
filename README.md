FusionEngine

A modular, hybrid game engine with multithreading, hot reload, and a robust logging system built in C++20. The engine supports dynamic DLL reloading for rapid iteration and features an ECS-based core paired with an OO layer for high-level functionality.
Features

    Hybrid Architecture: (Work In Progress) Combines ECS for performance-critical systems and OO for high-level game logic. 
    Hot Reload: (TODO) Dynamically reload DLLs to update game logic without restarting the engine.
    Multithreading: (TODO) Separate threads for rendering, physics, and game logic.
    Modern C++: (Work in Progress) Utilizes C++20 features including std::format and std::string_view.
    Logging System: (Work in Progress) Thread-safe logging with configurable log levels for real-time debugging.

Repository Structure

/Engine
  /Core         (WIP)- Engine core and ECS implementation
  /Systems      (TODO)- Rendering, physics, and other subsystems
  /Editor       (TODO)- (Optional) Qt-based editor for scene management
/Games
  /Pong         (TODO)- Sample game demonstrating engine usage

Getting Started

    Requirements: Visual Studio 2022 with C++20 support and CMake.
