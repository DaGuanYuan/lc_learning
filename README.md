# lc_learning

#### Description
Wonder wonder odyssey...

#### Catalog
1.  Non-DP & DP
2.  Coding Interviews: Questions, Analysis and Solutions
3.  LeetCode 101

#### Instructions
if u wanna run the code in this repo, first, compile them using g++ instead of gcc. It's significant since some libs is not supported in glibc. If u use gcc, compilation will be terminated and fatal errors may happen.
Note: plz remember to include head files in DataStructure. Otherwise some link errors may occur. 
eg: Coding_interviews/Q9/Q9.cc

```
g++ Coding_interviews/Q9/Q9.cc DataStructure/* -o exec
```
Then, u can run the code:)

```
./exec(for binary files)
or
source exec(for other files)
```

Tips: using sed to modificate includePath in batches if needed
eg1: modifying "iostream" to <iostream> under current path

```
sed -i "s/\"iostream\"/<iostream>/g" `grep \"iostream\" -rl ./`
```
eg2: modifying includePath from "./repo/lc_learning/DataStructure/BinaryTree.h" to "../../DataStructure/BinaryTree.h"

```
sed -i "s/.\/repo\/lc_learning\/DataStructure\/BinaryTree.h/..\/..\/DataStructure\/BinaryTree.h/g" `grep ..\/..\/DataStructure\/BinaryTree.h -rl ./`
```
Note: Do not forget using ESCAPE CHARACTER to transform " and / to \" and \/

For some reasons, all .cpp files in this repo were written by .cc files. If you have to use .cpp files, you can rename these files by

```
rename 's/\.cc/\.cpp/' $PWD/*.cc
```
Command "rename" is based on perl. If u never use perl before, plz confirm that perl has been installed,

```
which perl
```
If terminal returns

```
/usr/bin/perl
```
Congratulations! Otherwise, u should download perl and rename first.(eg, Ubuntu OS)

```
sudo apt-get install perl
sudo apt-get install rename
```
In fact, u can also use rename.ul, which is supported by C:)

```
rename.ul .cc .cpp $PWD/*.cc 
```

####  Declaration
The code in this repo is all written by Q_shan, for the purpose of learning and training.
