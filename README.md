# bmsdedi

A Direct3D11 wrapper to run Falcon BMS 4.35 without a video card.

Charm your neighbors! Impress your friends!
Run large multiplayer events on an AWS instance!

## Use

- Drop d3d11.dll in `Falcon BMS 4.35/Bin/x64` next to `Falcon BMS.exe`

- This strange thing appears:

  ![gui-screenshot](https://i.imgur.com/M0PurOX.png)

  Keep it in "Auto" to disable rendering automatically when you enter 3D
  and re-enable it when you leave 3D. The other options do what they say.

## Building

- Install [CMake](https://cmake.org/download/)
- Install [Ninja](https://github.com/ninja-build/ninja/releases)
- Install [llvm](https://releases.llvm.org/download.html)
- Add all of those to `PATH`
- Create a `build/` directory and from it, run `cmake .. -G Ninja`
- Run `ninja` to build a release build with debug symbols (`.pdb`)

TODO: Visual Studio project?

## Thanks

Many thanks to BibleClinger and his
[F4DXWrapper](https://github.com/BibleClinger/F4DXWrapper/)
for inspiring this tool and supporting community events
for the past several years!
