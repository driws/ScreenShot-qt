# ScreenShot-qt
taking screenshot and save images systematically using qt

做作业时要截Ansys结果图片，但是每次都用截图工具太麻烦，所以写这个小程序 ,界面解释如下

1. X1,Y1,X2,Y2为图片左上角和右下角图标
2. mx,my为鼠标位置，截图之前分别移到想截图片的左上角和右下角就知道位置了
3. 文件名，如果文本框里有文件名，则使用该文件名，如果没有，则统计文件夹中前缀为autosave的图片数n，将该图像保存autosaven
4. 删除文件夹，为删除当前目录下所有图片，所以删除的时候有提示