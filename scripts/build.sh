#!/bin/bash
EXECUTABLE_LINUX="build/dist/linux/cengine_linux"
EXECUTABLE_WINDOWS="build/dist/windows/cengine_windows.exe"

echo "=============================="
echo "       Cengine Build Tool      "
echo "=============================="
echo "1. Build the project"
echo "2. Remove build folder"
echo "3. Remove Linux executable"
echo "4. Remove Windows executable"
echo "5. Run the project (Linux)"
echo "6. Run the project (Windows - cross-compile)"
echo "7. Exit"
echo "=============================="
read -p "Select an option: " OPTION

case $OPTION in
    1)
        echo "Building the project..."
        cmake -S ../. -B ../build
        cmake --build ../build
        echo "Build completed."
        ;;
    2)
        echo "Removing the build folder..."
        rm -rf ../build
        echo "Build folder removed."
        ;;
    3)
        echo "Removing Linux executable..."
        rm -rf ../$EXECUTABLE_LINUX
        echo "Linux executable removed."
        ;;
    4)
        echo "Removing Windows executable..."
        rm -rf ../$EXECUTABLE_WINDOWS
        echo "Windows executable removed."
        ;;
    5)
        if [ -f "../$EXECUTABLE_LINUX" ]; then
            echo "Running the project on Linux..."
            ../$EXECUTABLE_LINUX
        else
            echo "The Linux executable does not exist. Did you build it?"
        fi
        ;;
    6)
        if [ -f "../$EXECUTABLE_WINDOWS" ]; then
            echo "Running the project on Windows (Cross-Compile)..."
            wine ../$EXECUTABLE_WINDOWS
        else
            echo "The Windows executable does not exist. Did you build it?"
        fi
        ;;
    7)
        echo "Exiting the script. Goodbye!"
        exit 0
        ;;
    *)
        echo "Invalid option. Please try again."
        ;;
esac

