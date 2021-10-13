# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(./array DIR_LIB_SRCS)
aux_source_directory(./dynamic DIR_LIB_SRCS)
aux_source_directory(./stack DIR_LIB_SRCS)
# 生成链接库
add_library (src SHARED ${DIR_LIB_SRCS})