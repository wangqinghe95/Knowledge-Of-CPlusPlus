# Ubuntu Compile && Install Qt

## Background

在编译一个想要使用 serialbus 的 qt 模块时，使用命令行下载的 qt 找不到对应的模块，不确定是下载的 qt 不完整还是需要额外单独下载。索性直接下载 qt 源码直接整编。

## OS
ubuntu22

## Prerequisition

```
sudo apt install vim make g++ gcc
```

## Compile && Install

1. download source code

~/Downloads is the general downloaded directory

```
cd ~/Downloads
wget https://mirrors.aliyun.com/qt/archive/qt/5.15/5.15.2/single/qt-everywhere-src-5.15.2.tar.xz
```

2. unpress to the specific folder

unpack the source code to this folder

```
tar -xf qt-everywhere-src-5.15.2.tar.xz -C ./
```

3. touch build configuration file

```
cd qt-everywhere-src-5.15.2
mkdir build
cd build
vim buid.sh
```

copy following to the build.sh

```
../configure \
-verbose \
-opensource \
-release \
-shared \
-confirm-license \
-make libs \
-nomake tests \
-nomake examples \
-skip qtmacextras \
-skip qtandroidextras \
-skip qtlocation    \
-no-opengl \
-xplatform linux-g++-64 \
-prefix /opt/qt-x86-64
```

+ xplatform: platform version, is a file name in the qtbase/mskapce directory.
+ prefix: installation address, modified as needed.

4. execute build.sh

```
chmod 777 build.sh
./build.sh
```

5. execute compile

```
gmake -j$(nproc)
```

6. execute install

```
make install
```

7. check

```
cd /opt/qt-x86-64/bin
./qmake --version
```

## Notes:

+ if you want to install qt and just use it in own computer, you can execute shell command
```
sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qtcreator
```


## Question

Q: In the process of executing build.sh and executing compile, there will be an error that show "error: ‘numeric_limits’ is not a member of ‘std’"
A: Add "#include<limits>" to the error reporting file

Q: Dependency file is missing(need)

A: install as needed

```
sudo apt-get build-dep
sudo apt-get qtbase5-dev
sudo apt-get install libxcb-xinerama0-dev
sudo apt-get install '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev
sudo apt-get install flex bison gperf libicu-dev libxslt-dev ruby
sudo apt-get install libssl-dev libxcursor-dev libxcomposite-dev libxdamage-dev libxrandr-dev libdbus-1-dev libfontconfig1-dev libcap-dev libxtst-dev libpulse-dev libudev-dev libpci-dev libnss3-dev libasound2-dev libxss-dev libegl1-mesa-dev gperf bison
sudo apt-get install libasound2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
sudo apt install libclang-6.0-dev llvm-6.0
```

Q: qt.qpa.plugin: Could not find the Qt platform plugin "xcb" in ""
A: // todo