Letra is a text editor.

# Building 
Letra depends on GNU Readline. Most systems will come installed with this
library by default. If you do not have it installed, check your
system's documentation.

In order to build Letra run:

    make

# Keybinds
Letra supports multiple keybind sets. In order to use vim keyindings put this:

    set -o vi

Into your `~/.bashrc`.

You can also do the same for emacs keyindings.

# Scripting
Letra supports scripting for its various commands. For example, the script:

    echo 'e file.txt 
    c5
    line 5
    w 
    q' | letra

Would change line 5 directly from the command line to 'line 5'.

# External Commands
Letra can call commands from your system's enviroment directly. This, for
example, allows you to build and run your programs without leaving the editing
enviroment. This makes the "build-run-edit" cycle very intuitive. To call an
external command simply prefix it with the `!` operator when in command mode.

# Quick Start guide
Letra comes with a manpage which covers all of its commands and features. A
guide is also available in docs/guide.txt


