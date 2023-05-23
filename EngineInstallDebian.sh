# only run this script if the engine hasn't been installed on the local machine, this does not need to be ran if you are using the engine by copying source
# this script will install the following if it has not been installed: gcc, g++, rust, KobiWare Engine headers, OpenGL, GLUT
[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"

echo "Installing KobiWare Engine"

#check for git, if not install
FILE=/usr/bin/git
if test -f "$FILE"; then
    echo "Git is installed."
    echo "Checking for GCC-12 installation."
else
    echo "Git is not installed."
    echo "Installing Git"
    sudo apt -y install git
    git --version
    echo "Checking for GCC-12 installation."
fi

#check for gcc, if not install
FILE=/usr/bin/gcc-12
if test -f "$FILE"; then
    echo "GCC-12 is installed."
    echo "Checking for G++ installation."
else
    echo "GCC-12 is not installed."
    echo "Installing GCC-12"
    sudo apt -y install build-essential
    gcc --version
    echo "Checking for G++ installation."
fi

#check for g++, if not install
FILE=/usr/bin/g++-11
if test -f "$FILE"; then
    echo "G++ is installed."
    echo "Checking for KobiWare Engine headers."
else
    echo "G++ is not installed."
    echo "Install G++"
    sudo apt -y install g++-11
    g++ --version
    echo "Checking for KobiWare Engine headers."
fi

#check for engine headers, if not install
FILE=/usr/include/KobiWare
if test -d "$FILE"; then
    echo "Engine headers are installed."
    echo "Checking for OpenGL installation."
else
    echo "KobiWare Engine Headers are not installed."
    echo "Installing KobiWare Engine Headers."
    sudo mkdir /home/KobiWare
    git clone https://github.com/Pyro569/KobiWare-Engine-Plus-Plus /home/KobiWare
    mv -v /home/KobiWare/Engine/ /home/KobiWare/KobiWare
    sudo mv /home/KobiWare/KobiWare /usr/include/KobiWare
    sudo rm -r /home/KobiWare
    echo "Checking for OpenGL installation."
fi

#check for OpenGL, if not install
FILE=/usr/include/GL
if test -d "$FILE"; then
    echo "OpenGL is installed."
else
    echo "OpenGL is not installed."
    echo "Installing OpenGL."
    sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
    
fi