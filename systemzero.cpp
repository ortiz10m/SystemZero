#include <iostream>
#include <fstream>   // For reading/writing files (Kernel communication)
#include <unistd.h>  // For OS direct calls (sync, getuid)
#include <cstdlib>   // For executing system processes (apt)

using namespace std;

// 1. Color definitions for terminal aesthetics
const string RED = "\033[0;31m";
const string GREEN = "\033[0;32m";
const string BLUE = "\033[0;34m";
const string NC = "\033[0m"; // No Color

// 2. Function to check for Root (Superuser) privileges
bool checkRoot() {
    // getuid() returns the user ID. In Linux, Root is ALWAYS 0.
    return (getuid() == 0);
}

// 3. Memory Optimization Module (Direct Kernel Interaction)
void optimizeMemory() {
    cout << BLUE << "\n[1/3] Intervening Kernel: Freeing RAM..." << NC << endl;
    
    // Native system call. Faster than the 'sync' bash command.
    sync(); 

    // In Linux, "everything is a file". Writing '3' to drop_caches clears RAM.
    ofstream dropCaches("/proc/sys/vm/drop_caches");
    
    if (dropCaches.is_open()) {
        dropCaches << "3";
        dropCaches.close();
        cout << GREEN << "Done! RAM Cache native wipe successful." << NC << endl;
    } else {
        cout << RED << "[ERROR] Critical failure: Cannot communicate with /proc/sys/vm." << NC << endl;
    }
}

// 4. Package Cleanup Module
void cleanPackages() {
    cout << BLUE << "\n[2/3] Purging orphaned dependencies and APT cache..." << NC << endl;
    
    // Using system() to call apt, routing output to /dev/null to keep terminal clean
    system("apt-get autoremove -y > /dev/null 2>&1");
    system("apt-get clean > /dev/null 2>&1");
    
    cout << GREEN << "Done! System junk purged." << NC << endl;
}

int main() {
    // Security check
    if (!checkRoot()) {
        cout << RED << "[ERROR] Access Denied. SystemZero requires direct hardware access. Run with 'sudo'." << NC << endl;
        return 1; // Exit with error code
    }

    // Minimalist UI
    cout << BLUE << "=======================================" << NC << endl;
    cout << GREEN << "    SYSTEM ZERO - C++ NATIVE CORE      " << NC << endl;
    cout << BLUE << "=======================================" << NC << endl;

    // Execution routine
    optimizeMemory();
    cleanPackages();

    cout << BLUE << "\n=======================================" << NC << endl;
    cout << GREEN << "    SYSTEM OPTIMIZED AND STABILIZED    " << NC << endl;
    cout << BLUE << "=======================================" << NC << endl;

    return 0; // Successful exit
}
