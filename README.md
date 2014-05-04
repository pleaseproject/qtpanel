# QtPanel

Migrated qtpanel to Qt5 by Leslie Zhai <xiang.zhai@i-soft.com.cn>

## ScreenShot

![ScreenShot](https://raw.github.com/xiangzhai/qtpanel/master/snapshot1.png)

## Build

### Dependence for AnthonOS

```
sudo apt-get install qt-5
```


### Dependence for iSoftLinux, ArchLinux

```
sudo pacman -S qt5-x11extras
```

### Qt4

```
mkdir build4
cd build4
cmake -DUSE_QT5=OFF ..
make
```


### Qt5

```
mkdir build
cd build
cmake ..
make
```
