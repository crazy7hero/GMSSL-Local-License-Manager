# authorization
功能：只支持本地授权管理。
实现：使用gmssl库，支持sm2、sm3、sm4加密方式。
工具使用目标群体：没有HSM服务，只想通过文件管理方式进行授权。
运行环境：目前支持windows、linux（支持跨平台）。
开发：Qt  qtwidgets C++ Qt_5_15_2_MinGW_64
说明：需要什么环境，重新编译gmssl-master，替换代码中的libgmssl.so库就可以了。
运行包后期打包上传、如果有需要，私信我
