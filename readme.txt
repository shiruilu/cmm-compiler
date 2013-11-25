编译：
make

清除垃圾（方便发布或重新编译）：
make clean （普通清理）
make realclean （完全清理）

运行：
1.词法语法
./syntax_test.sh （屏幕输出语法错误提示）
测试文件位置 tests/syntax/*.cmm

2.语义
./seman_test.sh (屏幕输出语义错误提示)
测试文件位置 tests/seman/*.cmm

3.中间代码及优化
./ir_test.sh (输出到文件)
测试文件位置 tests/ir/*.cmm
输出文件（未优化） tests/ir/out_files/*.cmm.ir
输出文件(优化后)   tests/ir/out_files/*_o.cmm.ir

4.目标代码
./goal_test.sh (输出到文件)
测试文件位置 tests/goal/*.cmm
输出文件 tests/goal/out_files/*.s
模拟器运行汇编代码 spim -file XXX.s

