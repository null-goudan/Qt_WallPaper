# Qt_WallPaper
## QT 实现 桌面壁纸软件 包括桌面挂件（二刺螈）

### main.cpp 主程序
### mainwindow 挂件主窗口
    · mainwinodw.h
    · mainwindow.cpp
    继承自 QMainWindow
    
### settingwidget 设置窗口
    · settingwidget.h
    · settingwidget.cpp
    继承自 QWidget
### desktopwidget 桌面壁纸
    · desktopwidget.h
    · desktopwidget.cpp
    继承自 QLabel
### finddektophwnd 为了寻找Windows桌面句柄 稍微用了一些WindowsAPI内容找到然后设置desktopwidget父句柄实现的壁纸设置
### eventfilterobject
    事件过滤对象，给mainwindow 还有 settingwidget安装事件过滤器达到实现无边框窗口拖动的效果
