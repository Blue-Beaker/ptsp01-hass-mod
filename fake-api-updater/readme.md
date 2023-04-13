本配置文件用于给邦讯玩儿插排(PTSP01)进行OTA更新自定义文件
首先将需要更新的固件放在此目录下，命名为mod.bin(其他名称也可，需修改mod.json)，此mod.bin默认为官方3492固件
修改mod.json,第一个size修改为mod.bin的字节大小，第一个md5值改为mod.bin的md5校验值
将seaing_reverse配置文件中的"路径"替换为此目录绝对路径，然后放入Nginx的sites-enabled配置文件夹
运行Nginx,在路由器设置hosts: `[运行Nginx机器ip] api.seaing.net`
然后打开app检查更新，出现 "自定义固件更新器正常工作 按更新以刷入修改固件"后刷入即可
如刷入错误固件可导致无法启动，需要拆机解决。
