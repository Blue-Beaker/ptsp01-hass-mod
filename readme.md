# 邦讯玩儿插排(PTSP01)改Homeassistant
 
拆机加单片机绕过密码启动使得Telnet无需密码，配合Homeassistant自定义集成使用。  

hardware_mod为使用stc8g单片机绕过密码启动示例，其中stc8g的串口接到插排主板串口上并从主板3.3v取电。  


## 绕过密码
在`Press the [f] key and hit [enter] to enter failsafe mode`信息出现后，向串口写入`f\r/etc/init.d/rcS S boot\r`，进入failsafe模式再启动系统服务，此时Telnet不需要密码。  
## Homeassistant自定义集成
https://github.com/Blue-Beaker/ptsp01-homeassistant  

## 其他资料

官方固件为官方固件，包含OTA固件和编程器固件。操作固件前注意备份自己的固件，闪存中保存有设备唯一识别信息。  
该文件夹下的backup.sh和restore.sh用于通过基于stm32-vserprog的高速烧录器备份恢复固件。  

fake-api-updater为自定义OTA更新器，用于OTA刷入自定义固件。目前没有可用的自定义固件。  

bangxunwulian.apk为官方app，官方api或已停止服务。  
