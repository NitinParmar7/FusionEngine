FusionEngine

A modular, hybrid game engine with multithreading, hot reload, and a robust logging system built in C++20. The engine supports dynamic DLL reloading for rapid iteration and features an ECS-based core paired with an OO layer for high-level functionality.
Features

    Hybrid Architecture: Combines ECS for performance-critical systems and OO for high-level game logic.
    Hot Reload: Dynamically reload DLLs to update game logic without restarting the engine.
    Multithreading: Separate threads for rendering, physics, and game logic.
    Modern C++: Utilizes C++20 features including std::format and std::string_view.
    Logging System: Thread-safe logging with configurable log levels for real-time debugging.

Repository Structure

/Engine
  /Core         - Engine core and ECS implementation
  /Systems      - Rendering, physics, and other subsystems
  /Editor       - (Optional) Qt-based editor for scene management
/Games
  /Pong         - Sample game demonstrating engine usage

Getting Started

    Requirements: Visual Studio 2022 with C++20 support.
    Build the Engine Core: Open the solution and build the DLL project.
    Run the Host Application: Build and run the console app (e.g., Pong) to test engine initialization, update, and shutdown.
    Hot Reload: Modify the DLL source code, rebuild, and see changes take effect without restarting the host.
