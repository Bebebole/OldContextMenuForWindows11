#include <iostream>
#include <vector>
#include <cstdlib>  
#include "WinReg.hpp"

void disableNewContextMenu() {
    winreg::RegKey key;
    std::wstring KEY_PATH = L"SOFTWARE\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32";
    winreg::RegResult result = key.TryOpen(HKEY_CURRENT_USER, KEY_PATH);

    if (result) {
        std::wcout << KEY_PATH << L" already exists. Skipping...\n";
    } else {
        std::wcout << L"Creating " << KEY_PATH << L"...\n";
        key.Create(HKEY_CURRENT_USER, KEY_PATH);
    }

    std::cout << "Setting InprocServer32's default value to an empty string...\n";
    key.SetStringValue(L"", L"");
    std::cout << "Done !\n";
}

int main() {
    disableNewContextMenu();
    system("pause");
    return 0;
}