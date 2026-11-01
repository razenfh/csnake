<div align="center">

# 🐍 csnake

**Classic Snake, right in your terminal.**
Written in pure C with `ncurses`. Tiny, fast, zero fluff.

![Language](https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white)
![Library](https://img.shields.io/badge/ncurses-TUI-4EAA25)
![Build](https://img.shields.io/badge/build-CMake-064F8C?logo=cmake&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey)

</div>

```
##################################################
#                                                #
#                   *                            #
#                                                #
#          ooo@                                  #
#                                                #
#                                                #
#                                                #
#                                                #
#                                                #
#                                                #
##################################################
                                      score: 3
```

## ✨ About

`csnake` is a small snake game that runs entirely in your terminal. It is built in C and uses `ncurses` for rendering and keyboard input, so it starts instantly and works over SSH, inside tmux, or on any machine with a terminal.

## 🚀 Quick start

### Requirements

- A C compiler (`gcc` or `clang`)
- [CMake](https://cmake.org/)
- `ncurses` development files

Install the dependencies for your system:

```bash
# Arch Linux
sudo pacman -S base-devel cmake ncurses

# Debian / Ubuntu
sudo apt install build-essential cmake libncurses-dev

# Fedora
sudo dnf install gcc cmake ncurses-devel

# macOS (Homebrew)
brew install cmake ncurses
```

### Build and run

```bash
git clone https://github.com/razenfh/csnake.git
cd csnake

cmake -B build
cmake --build build

./build/csnake
```

## 🎮 Controls

| Key | Action |
| --- | --- |
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Q` | Quit |

Keys work in both lower and upper case. The snake stays still until you press the first movement key.

## 🧩 How to play

1. A 3-second countdown starts the game.
2. Steer the snake (`@` is the head, `o` is the body) toward the apple `*`.
3. Every apple makes the snake longer and adds a point to your score.
4. The game ends when you hit a wall `#` or your own tail.
5. A game over screen shows your final score.

The playing field is 50×12 characters.

## 📁 Project structure

```
csnake/
├── src/             # game source code
├── CMakeLists.txt   # build configuration
├── .gitignore
└── README.md
```

## 🛠 Tech stack

- **Language:** C
- **UI:** [ncurses](https://invisible-island.net/ncurses/)
- **Build system:** CMake

## 🗺 Roadmap

- [ ] Arrow key support
- [ ] Block instant 180° turns
- [ ] Speed up as the score grows
- [ ] High score table
- [ ] Pause key
- [ ] Colors

## 🤝 Contributing

Ideas and pull requests are welcome.

1. Fork the repo
2. Create a branch: `git checkout -b feature/cool-thing`
3. Commit your changes: `git commit -m "Add cool thing"`
4. Push and open a pull request

## 📜 License

No license has been chosen yet. Add a `LICENSE` file (for example MIT) to let others use and contribute to the project.

---

<div align="center">

Made with C and a lot of ☕ by [razenfh](https://github.com/razenfh)

</div>
