#### 运行调试（debugging）

launch.json文件是被用来配置VSCode debugging的文件。具体可配置项如下：

- program

  必需。调试器程序的路径

- symbolSearchPath

  可选。查找.pdb文件的目录，特别的，当需要匹配多个路径时，需要使用分号隔开。例如：

  ```
  "C:\\Symbols;C:\\Symbols2"
  ```

  > pdb，全称“程序数据库文件”（Program Database），存储程序的所有调试信息数据。.pdb文件主要会存储对应模块（dll或exe）内部的所有符号，以及符号对应的地址、文件名和行号。当我们调试的时候可能会需要，可以理解为调试时应用程序和源文件之间的桥梁。

- requireExactSource

  可选。用于告诉VSCode Windows调试器需要将当前源代码匹配.pdb文件

- additionalSOLibSearchPath

  可选。告知GDB（gcc debugger调试器）或LLDB搜索.so文件（动态链接库）的目录。同样，也需要用分号隔开多个路径。例如：

  ```
  "/User/dir1; /User/dir2"
  ```

- externalConsole

  可选。是否使用外部命令行（控制台）窗口输出结果

- avoidWindowsConsole Redirection

  可选。为了在Windows上支持VS Code的gdb集成终端，该扩展将控制台重定向命令添加到被调试进程的参数中，以使控制台输入和输出显示在集成终端中。将此选项设置为true将禁用它

- visualizerFile

  调试时使用的.natvis文件。详见：[`创建语言文件的自定义视图`](https://docs.microsoft.com/zh-cn/visualstudio/debugger/create-custom-views-of-native-objects?view=vs-2022)

- showDisplayString

  可选。当指定了visualizerFile时，showDisplayString 将启用显示字符串。 启用此选项可能会导致调试期间性能下降 。如：

  ```
  {
    "name": "C++ Launch (Windows)",
    "type": "cppvsdbg",
    "request": "launch",
    "program": "C:\\app1\\Debug\\app1.exe",
    "symbolSearchPath": "C:\\Symbols;C:\\SymbolDir2",
    "externalConsole": true,
    "logging": {
      "moduleLoad": false,
      "trace": true
    },
    "visualizerFile": "${workspaceFolder}/my.natvis",
    "showDisplayString": true
  }
  ```

- args

  运行时，需要传递给程序的命令行参数，需要使用JSON数组形式。如：

  ```
  // 普通传值
  args: ["arg1", "arg2"]
  
  // 需要转义字符时。结果为：{"arg1":true}
  ["{\\\"arg1\\\":true}"]
  ```

- cwd

  设置调试程序运行时的工作区目录

- environment

  程序运行的环境变量，如：

  ```
  {
    "name": "C++ Launch",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/a.out",
    "args": ["arg1", "arg2"],
    "environment": [{ "name": "config", "value": "Debug" }],
    "cwd": "${workspaceFolder}"
  }
  ```

  也可在程序目录下创建project.env文件，来指定所需环境变量，如：

  ```
  # project.env file
  
  # 
  MYENVRIONMENTPATH=C:\\Users\\USERNAME\\Project
  
  # Variables with spaces
  SPACED_OUT_PATH="C:\\This Has Spaces\\Project"
  ```

- MIMode

  指出VSCode要连接的调试器，必须是gdb或lldb

- miDebuggerPath

  调试器的路径（如gdb）。如：

  ```
  // 此时会从系统环境变量中去搜索gdb
  miDebuggerPath: "gdb"
  ```

  注意，一般Linux和Windows中使用GDB，OS X上使用LLDB

- miDebuggerArgs

  传递给调试器的额外参数

- stopAtEntry

  如果为true，启动调试后，将在入口函数处断点停止。

- stopAtConnect

  如果设置为 true，调试器应在连接到目标后停止。 如果设置为false，调试器将在连接后继续 

- setupCommands

  执行GDB或LLDB时的选项。如：

  ```
  "setupCommands": [
      {
          "description": "为 gdb 启用整齐打印",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
      },
      {
          "description": "将反汇编风格设置为 Intel",
          "text": "-gdb-set disassembly-flavor intel",
          "ignoreFailures": true
      }
  ]
  ```

- launchCompleteCommand

  在调试器完全设置后执行的命令，以使目标进程运行。 允许的值为“exec-run”、“exec-continue”、“None”。 默认值为“执行运行”。 如：

  ```
  {
    "name": "C++ Launch",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/a.out",
    "stopAtEntry": false,
    "customLaunchSetupCommands": [
      { "text": "target-run", "description": "run target", "ignoreFailures": false }
    ],
    "launchCompleteCommand": "exec-run",
    "linux": {
      "MIMode": "gdb",
      "miDebuggerPath": "/usr/bin/gdb"
    },
    "osx": {
      "MIMode": "lldb"
    },
    "windows": {
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\MinGw\\bin\\gdb.exe"
    }
  }
  ```

- request

  指示配置部分是用于启动程序还是附加到已运行的实例。

- type

  指出正在使用的基础调试器（C/C++预处理调试器）。可选项：

  - cppvsdbg：当调试器为Visual Studio Windows时
  - cppdbg：当调试器为GDB或LLDB时



完整launch.json内容如下：

```
{
  "configurations": [
    {
      "name": "(gdb) 启动",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\msys64\\mingw64\\bin\\gdb.exe",
      "preLaunchTask": "gcc",
      "setupCommands": [
        {
          "description": "为 gdb 启用整齐打印",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        },
        {
          "description": "将反汇编风格设置为 Intel",
          "text": "-gdb-set disassembly-flavor intel",
          "ignoreFailures": true
        }
      ]
    }
  ],
}
```



### 智能提示

完整c_cpp_properties.json内容：

```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceRoot}/**",
                "c:/msys64/mingw64/include/**",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0/x86_64-w64-mingw32",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0/backward",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/include",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/include-fixed",
                "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../x86_64-w64-mingw32/include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "__GNUC__=6",
                "__cdecl=__attribute__((__cdecl__))"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "C:/msys64/mingw64/bin/gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64",
            "browse": {
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": "",
                "path": [
                    "${workspaceRoot}/**",
                    "c:/msys64/mingw64/include/**",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0/x86_64-w64-mingw32",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include/c++/11.2.0/backward",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/include",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../include",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/include-fixed",
                    "C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/11.2.0/../../../../x86_64-w64-mingw32/include"
                ] 
            }
        }
    ],
    "version": 4
}
```



### 程序运行任务

tasks.json

```
{
	"version": "2.0.0",
	"command": "gcc",
	"args": [ 
		"-g",
		"${file}",
		"-o",
		"${fileBasenameNoExtension}.exe"
	], 
	"problemMatcher": {
		"owner": "cpp",
		"pattern": {
			"regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
			"file": 1,
			"line": 2,
			"column": 3,
			"severity": 4,
			"message": 5
		},
		"fileLocation": ["relative", "${workspaceFolder}"],
	}
}
```



[1]: https://code.visualstudio.com/docs/cpp/config-mingw	"Windows Debugging with MinGW64"
[2]: https://code.visualstudio.com/docs/editor/variables-reference	"variables-reference"
[3]: https://blog.csdn.net/ren648154292/article/details/111151724	"完整参考"

