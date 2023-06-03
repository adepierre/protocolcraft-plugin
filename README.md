![Build status](https://github.com/adepierre/protocolcraft-plugin/actions/workflows/build.yml/badge.svg)
[![Discord](https://badgen.net/badge/icon/discord?icon=discord&label)](https://discord.gg/wECVsTbjA9)

Repository storing code to generate extension plugins for [protocolCraft](https://github.com/adepierre/Botcraft). They can be used to help dealing with custom payload packets sent by mods (see . You can check [SniffCraft](https://github.com/adepierre/SniffCraft) for an example usecase, or the [Botcraft mod support wiki page](https://github.com/adepierre/Botcraft/wiki/Mod-support) for details.

As the plugins can be compiled independantly from other libraries, don't expect this repo to be updated very often (except to add new plugins). But that doesn't mean plugins won't work with more recent ProtocolCraft versions. For example, the packets in vanilla-plugin haven't changed since Minecraft 1.13, i.e. July 18, 2018.

# Usage

Once compiled, the plugins must be placed next to your executable using protocolCraft under a ``protocolcraft_plugins`` folder in order to be found at runtime.

# Build

The code uses cmake build system and requires an internet connection at configuration time to download a few files from the [Botcraft repo](https://github.com/adepierre/Botcraft). For an offline configuration/build, make sure you manually download all the files listed [here](cmake/protocolcraft.cmake) and place them under a ``protocolCraft`` folder in your cmake build directory, keeping their relative paths identical to their URL.

```bash
git clone https://github.com/adepierre/protocolcraft-plugin.git
cd protocolcraft-plugin
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
```

Built plugins will be placed by default under a ``bin`` folder. To set a specific output destination, or to configure a plugin option, you can use cmake -D syntax. See each plugin readme to know which options (if any) they have.
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DPLUGINS_OUTPUT_DIR=/path/to/my/built/plugins ..
cmake --build . --config Release
```

# Create a new plugin

This repo architecture has been thought to simplify the process of creating a plugin, allowing anyone from the community to easily implement a new plugin for a given mod. Here are the steps to add a new one:
- fork this repository
- duplicate the [plugins/vanilla-plugin](plugins) folder and rename it
- add the new folder at the end of [plugins/CMakeLists.txt](plugins/CMakeLists.txt)
- create all your packets classes
- register them with the expected identifier in ONE cpp file (see [this](plugins/vanilla-plugin/src/register.cpp) for reference)
- edit your plugin CMakeLists.txt with your files/options/include folders, there are some edit sections setup in the [CMakeLists.txt](plugins/vanilla-plugin/CMakeLists.txt) to help you
- edit your plugin individual readme to give details on what it does
- create a PR with your new plugin

If the automatic build fails during artifact upload because you didn't have a latest release yet, go to \<your fork\>/releases/new and create a new release. The only important field is the tag name which must be ``latest`` and then go to \<your fork\>/actions/workflows to rerun the failed worfklow.
