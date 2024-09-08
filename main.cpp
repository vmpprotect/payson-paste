#include "includes.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "asdf.hpp"
#include "Windows.h"
#include <sapi.h>

std::string name = skCrypt("payson1337").decrypt(); // Application Name
std::string ownerid = skCrypt("RRMW917rnj").decrypt(); // Owner ID
std::string secret = skCrypt("4ceea7f8f25d6da3772b5b25a621c286f7a76870e8d7794f469aa86df673684d").decrypt(); // Application Secret
std::string version = skCrypt("1.0").decrypt(); // Application Version
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting
std::string path = skCrypt("github.com.paysonism").decrypt(); // (OPTIONAL) see tutorial here https://www.youtube.com/watch?v=I9rxt821gMk&t=1s

KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url, path);


void Speak(const std::wstring& text) {
    // Initialize COM library
    if (FAILED(::CoInitialize(nullptr))) {
        std::cerr << "Failed to initialize COM library." << std::endl;
        return;
    }

    ISpVoice* pVoice = nullptr;

    // Create the voice instance
    HRESULT hr = ::CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
    if (SUCCEEDED(hr)) {
        // Speak the text
        pVoice->Speak(text.c_str(), SPF_IS_XML, nullptr);
        // Release the voice instance
        pVoice->Release();
    }
    else {
        std::cerr << "Failed to create voice instance." << std::endl;
    }

    // Uninitialize COM library
    ::CoUninitialize();
}

void main() {
    KeyAuthApp.init();
    SetConsoleTitleA(skCrypt("Payson Slotted - Made By github.com/paysonism").decrypt());

    system("color 5");
    std::cout << skCrypt("\n Payson Slotted - Made By Payson").decrypt();

    Sleep(3000);
    system("cls");

    std::cout << "\n Payson Slotted\n\n Key > ";
    std::string key;
    std::cin >> key;
    //KeyAuthApp.license(key);
    KeyAuthApp.response.success = true;

    if (KeyAuthApp.response.success)
    {
        system("cls");
        system("color E");
        std::cout << skCrypt("\n [+] Launch Fortnite...").decrypt();
        while (game_wnd == 0) {
            Sleep(1);
            mem::process_id = mem::find_process(L"FortniteClient-Win64-Shipping.exe");
            game_wnd = get_process_wnd(mem::process_id);
            Sleep(1);
        }
        system(skCrypt("cls").decrypt());

        if (!librarys::init()) {
            std::cout << skCrypt("\n Failed to initialize libraries.").decrypt();
            Sleep(3000);
            exit(0);
        }

        if (!input::init()) {
            std::cout << skCrypt("\n Failed to initialize input libraries.").decrypt();
            Sleep(3000);
            exit(0);
        }

        if (!gui::init()) {
            std::cout << skCrypt("\n Failed to initialize ImGui.").decrypt();
            Sleep(3000);
            exit(0);
        }

        if (!mem::find_driver()) {
            std::cout << skCrypt("\n Driver not found. Please reload the driver and try again.").decrypt();
            // Speak failure message
            Speak(L"Please load the driver.");
            Sleep(3000);
            exit(0);
        }
        else {
            // Speak success message
            Speak(L"Driver Loaded Successfully. Now Loading Payson Slotted.");
        }

        // PaysonDRV::FetchCR3();
        virtualaddy = mem::find_image();
        if (!virtualaddy) {
            std::cout << skCrypt("\n Failed to get base address. Please contact support.").decrypt();
            Sleep(3000);
            exit(0);
        }

        pml4 = mem::pml4();

        system("color 5");
        std::cout << skCrypt("\n Base > ").decrypt() << virtualaddy << "\n";
        std::cout << skCrypt("\n PML4 > ").decrypt() << pml4 << "\n";

        create_overlay();
        directx_init();
        render_loop();
    }
    else {
        system("cls");

        MessageBoxA(NULL, "Incorrect Key or HWID Mismatched", "Error", NULL);
    }
}
