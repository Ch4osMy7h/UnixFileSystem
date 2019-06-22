//
// Created by 林智超 on 2019-06-16.
//

#ifndef UNIXFILESYSTEM_CONST_H
#define UNIXFILESYSTEM_CONST_H

// dir
#define MODE_DIR	01000					//目录标识
#define MODE_FILE	00000					//文件标识
#define FILE_DEF_PERMISSION 0664			//文件默认权限
#define DIR_DEFAULT_PERMISSION	0755			//目录默认权限
#define FILE_BUFFER 10000					// 10K， 文件buffer

#define BLOCK_SIZE	512						// 512B size
#define INODE_SIZE	128						// sizeof(inode)

//不知道开的合不合理
#define MAX_NAME_SIZE 28					//最大名字长度，长度要小于这个大小

#define INODE_NUM	640						//inode最多64个文件
#define BLOCK_NUM	10240					//10240 * 512B = 5120KB
#define BLOCKS_PER_GROUP 64				//空闲块堆栈大小，t一个空闲堆栈最多能存多少个磁盘块地址

//image

#define IMAGEFILENAME	"data.img"			//虚拟磁盘文件名


#define Superblock_StartAddr 0															//超级块 偏移地址,占一个磁盘块
#define InodeBitmap_StartAddr 1*BLOCK_SIZE												//inode位图 偏移地址，占两个磁盘块，最多监控 1024 个inode的状态
#define BlockBitmap_StartAddr InodeBitmap_StartAddr + 2*BLOCK_SIZE							//block位图 偏移地址，占二十个磁盘块，最多监控 10240 个磁盘块（5120KB）的状态
#define Inode_StartAddr BlockBitmap_StartAddr + 20*BLOCK_SIZE							//inode节点区 偏移地址，占 INODE_NUM/(BLOCK_SIZE/INODE_SIZE) 个磁盘块
#define Block_StartAddr Inode_StartAddr + INODE_NUM/(BLOCK_SIZE/INODE_SIZE) * BLOCK_SIZE	//block数据区 偏移地址 ，占 INODE_NUM 个磁盘块
#define Sum_Size Block_StartAddr + BLOCK_NUM * BLOCK_SIZE									//虚拟磁盘文件大小

//单个文件最大大小 10直接 + 1 间接 + 1二级间接
#define File_Max_Size 10*BLOCK_SIZE + BLOCK_SIZE/sizeof(int) * BLOCK_SIZE + (BLOCK_SIZE/sizeof(int))*(BLOCK_SIZE/sizeof(int)) * BLOCK_SIZE

//用户

#define ROOT_DIR_ADDR Inode_StartAddr
#define HOSTNAME "chaosmyth"


#endif //UNIXFILESYSTEM_CONST_H
