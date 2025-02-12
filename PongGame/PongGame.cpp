// PongGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>


typedef void (*EngineInitFunc)();
typedef void (*EngineUpdateFunc)(float);
typedef void (*EngineShutdownFunc)();

int main()
{
    // Load the DLL
    HMODULE engineDLL = LoadLibraryA("EngineCore.dll");
    if (!engineDLL)
    {
        std::cerr << "Failed to load engine DLL!" << std::endl;
        return -1;
    }

    EngineInitFunc init = reinterpret_cast<EngineInitFunc>(GetProcAddress(engineDLL, "Engine_Init"));
    EngineUpdateFunc update = reinterpret_cast<EngineUpdateFunc>(GetProcAddress(engineDLL, "Engine_Update"));
    EngineShutdownFunc shutdown = reinterpret_cast<EngineShutdownFunc>(GetProcAddress(engineDLL, "Engine_Shutdown"));

    if (!init || !update || !shutdown)
    {
        std::cerr << "Failed to retrieve engine function pointers." << std::endl;
        FreeLibrary(engineDLL);
        return -1;
    }


    init();

    for (int i = 0; i < 100; ++i)
    {
        update(0.016f);
        Sleep(16);
    }

    shutdown();

    FreeLibrary(engineDLL);
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
