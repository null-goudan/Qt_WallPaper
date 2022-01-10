# Qt_WallPaper
## QT 实现 桌面壁纸软件 包括桌面挂件（二刺螈）

### main.cpp 主程序
### mainwindow 挂件主窗口

    mainwinodw.h
    mainwindow.cpp
    继承自 QMainWindow
    
    也实现了任务栏托盘管理
![_(V~WM2@_BBKV$ET_(2V408](https://user-images.githubusercontent.com/74131166/148762370-a94ce9ff-52de-47b8-ba4c-1732cf3f5769.png)

### settingwidget 设置窗口

    settingwidget.h
    settingwidget.cpp
    继承自 QWidget
    
![image](https://user-images.githubusercontent.com/74131166/148762433-156b884e-4697-48e4-9693-e678d80dc424.png)
    #### 桌面壁纸设置窗口
![image](https://user-images.githubusercontent.com/74131166/148762509-20779c56-515b-412c-9567-9b7901650571.png)
![image](https://user-images.githubusercontent.com/74131166/148762565-44b27b53-7631-4a02-8726-b3e4b70238d3.png)
![image](https://user-images.githubusercontent.com/74131166/148762590-620ae57e-f5c1-47d0-adea-9428c795fd56.png)
    挂件调换
### desktopwidget 桌面壁纸

    desktopwidget.h
    desktopwidget.cpp
   
    继承自 QLabel
    理论上是接受git格式的动态桌面
    
![image](https://user-images.githubusercontent.com/74131166/148762790-c12b4b6a-6f47-4716-873e-5e76b0f5cf90.png)

    
### finddektophwnd 
    
    为了寻找Windows桌面句柄 稍微用了一些WindowsAPI内容找到然后设置desktopwidget父句柄实现的壁纸设置
### eventfilterobject
    
    事件过滤对象，给mainwindow 还有 settingwidget安装事件过滤器达到实现无边框窗口拖动的效果
