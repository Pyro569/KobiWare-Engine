//rust imports

//druid gui system imports
use druid::widget::{Button, ControllerHost, Flex, Label, Padding};
use druid::{AppLauncher, EventCtx, LocalizedString, PlatformError, Widget, WidgetExt, WindowDesc};

fn main() -> Result<(), PlatformError> {
    let main_window = WindowDesc::new(ui_builder())
        .window_size((600.0, 400.0))
        .title("KobiWare Engine Install Manager");
    let data = 0_u32;
    AppLauncher::with_window(main_window)
        .log_to_console()
        .launch(data)
}

fn ui_builder() -> impl Widget<u32> {
    // The label text will be computed dynamically based on the current locale and count
    let installText =
        LocalizedString::new("Use the buttons to install and/or update the KobiWare Engine");
    let installLabel = Label::new(installText).padding(5.0).center();

    let debianButton: Padding<u32, ControllerHost<Button<u32>, druid::widget::Click<u32>>> =
        Button::new("Install Engine (Debian)")
            .on_click(|_ctx, data, _env| install_debian())
            .padding(5.0);
    let updateDebian: Padding<u32, ControllerHost<Button<u32>, druid::widget::Click<u32>>> =
        Button::new("Update Engine (Debian)")
            .on_click(|_ctx, data, _env| update_debian())
            .padding(10.0);
    Flex::column()
        .with_child(installLabel)
        .with_child(debianButton)
        .with_child(updateDebian)
}

fn update_debian() {
    let (code, output, error) = run_script::run_script!(
        r#"gnome-terminal -- /bin/sh -c '
        sudo rm -r /usr/include/KobiWare
        sudo git clone https://github.com/Pyro569/KobiWare-Engine-Plus-Plus /home/KobiWare
        sudo mv -v /home/KobiWare/Engine/ /home/KobiWare/KobiWare
        sudo mv /home/KobiWare/KobiWare /usr/include/KobiWare
        sudo rm -r /home/KobiWare; sleep 10; exec bash'"#
    )
    .unwrap();
}

fn install_debian() {
    let (code, output, error) = run_script::run_script!(
        r#"gnome-terminal -- /bin/sh -c 'echo test; echo "Installing KobiWare Engine"

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
    sudo git clone https://github.com/Pyro569/KobiWare-Engine-Plus-Plus /home/KobiWare
    sudo mv -v /home/KobiWare/Engine/ /home/KobiWare/KobiWare
    sudo mv /home/KobiWare/KobiWare /usr/include/KobiWare
    echo "Checking for OpenGL installation."
fi

#check for OpenGL, if not install
FILE=/usr/include/GL
if test -d "$FILE"; then
    echo "OpenGL is installed."
    echo "Checking for VS Code installation."
else
    echo "OpenGL is not installed."
    echo "Installing OpenGL."
    sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
    echo "Checking for VS Code installation."
fi

#check for vs code, if not install
FILE=/snap/bin/code
FILE2=/snap/bin/code
if test -f "$FILE" || test -f "$FILE2"; then
    echo "VS Code is installed."
    echo "Opening VS Code and example game"
else
    echo "VS Code is not installed."
    echo "Installing VS Code"
    sudo snap install --classic code
    echo "Opening VS Code and example game"
fi

#create easy setup for getting started
FILE=/home/KobiWare
if test -d "$FILE"; then
    mkdir ~/Documents/KobiWare-Engine
    cp /home/KobiWare/Game.cpp ~/Documents/KobiWare-Engine
    cp /home/KobiWare/buildgame.sh ~/Documents/KobiWare-Engine
    mkdir ~/Documents/KobiWare-Engine/build
    chmod +x ~/Documents/KobiWare-Engine/buildgame.sh
    code ~/Documents/KobiWare-Engine/Game.cpp
    sudo rm -r /home/KobiWare
else
    sudo git clone https://github.com/Pyro569/KobiWare-Engine-Plus-Plus /home/KobiWare
    mkdir ~/Documents/KobiWare-Engine
    cp /home/KobiWare/Game.cpp ~/Documents/KobiWare-Engine
    cp /home/KobiWare/buildgame.sh ~/Documents/KobiWare-Engine
    mkdir ~/Documents/KobiWare-Engine/build
    chmod +x ~/Documents/KobiWare-Engine/buildgame.sh
    code ~/Documents/KobiWare-Engine/Game.cpp
    sudo rm -r /home/KobiWare
fi

exit; echo KobiWare Engine Installed; exec bash'"#
    )
    .unwrap();
}
