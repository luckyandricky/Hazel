# Hazel
gmae engine

## 1 dll动态链接库的配置

## 2 编写 EntryPoint 程序入口点

## 3 log第三方库的使用，spdlog C++ logging library  

​    https://github.com/gabime/spdlog

**Create stdout/stderr logger object**

```C
	spdlog::set_pattern("%^[%T] %n: %v%$");
	s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
	s_CoreLogger->->error("...");

```

## 4 premake

轻量级跨平台构架系统Premake

命令行实用程序

主流的可以跨平台，支持C++的构建系统

- Cmake
- Scons
- Premake



## 5 event system



## 6 Precompiled

