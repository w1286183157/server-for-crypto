RSA_DIR=../RsaCrypto/
HASH_DIR=../Hash/
FACTORY_DIR=../factory/
PROTO_DIR=../ProtoBuf/
MYSQL_DIR=../SqlOP/
TCP_DIR=../TcpSocket/
SER_DIR=../TcpServer/
SHM_DIR=../ShareMemory/

SRC=$(wildcard ./*.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRC))

TCP_SRC=$(wildcard $(TCP_DIR)*.cpp)
TCP_OBJ=$(patsubst %.cpp,%.o,$(TCP_SRC))

MYSQL_SRC=$(wildcard $(MYSQL_DIR)*.cpp)
MYSQL_OBJ=$(patsubst %.cpp,%.o,$(MYSQL_SRC))

SER_SRC=$(wildcard $(SER_DIR)*.cpp)
SER_OBJ=$(patsubst %.cpp,%.o,$(SER_SRC))

PROTO_SRC=$(wildcard $(PROTO_DIR)*.cc)
PROTO_OBJ=$(patsubst %.cc,%.o,$(PROTO_SRC))

RSA_SRC=$(wildcard $(RSA_DIR)*.cpp)
RSA_OBJ=$(patsubst %.cpp,%.o,$(RSA_SRC))

HASH_SRC=$(wildcard $(HASH_DIR)*.cpp)
HASH_OBJ=$(patsubst %.cpp,%.o,$(HASH_SRC))

FACTORY_SRC=$(wildcard $(FACTORY_DIR)*.cpp)
FACTORY_OBJ=$(patsubst %.cpp,%.o,$(FACTORY_SRC))

SHM_SRC=$(wildcard $(SHM_DIR)*.cpp)
SHM_OBJ=$(patsubst %.cpp,%.o,$(SHM_SRC))

LIBS=-lprotobuf -std=c++11 -lpthread  -ljsoncpp  -lssl -lcrypto  -lmysqlclient -I /usr/local/mysql/include -L /usr/local/mysql/lib

TARGET=server
CC=g++

$(TARGET):$(OBJS)  $(HASH_OBJ) $(PROTO_OBJ) $(RSA_OBJ) $(MYSQL_OBJ) $(TCP_OBJ) $(FACTORY_OBJ) $(SER_OBJ) $(SHM_OBJ)
	$(CC) $^ -o $@ $(LIBS) 
%.o: %.cpp
	$(CC) $< -c -o $@
$(FACTORY_DIR)%.o:$(FACTORY_DIR)%.cpp
	$(CC) $< -c -o $@  
$(PROTO_DIR)%.o:$(PROTO_DIR)%.cc
	$(CC) $< -c -o $@
$(RSA_DIR)%.o:$(RSA_DIR)%.cpp
	$(CC) $< -c -o $@  
$(HASH_DIR)%.o:$(HASH_DIR)%.cpp
	$(CC) $< -c -o $@  
$(TCP_DIR)%.o:$(TCP_DIR)%.cpp
	$(CC) $< -c -o $@  
$(SER_DIR)%.o:$(SER_DIR)%.cpp
	$(CC) $< -c -o $@  
$(MYSQL_DIR)%.o:$(MYSQL_DIR)%.cpp
	$(CC) $< -c -o $@  
$(SHM_DIR)%.o:$(SHM_DIR)%.cpp
	$(CC) $< -c -o $@  

.PHONY:clean
clean:
	rm -rf $(OBJS) $(PROTO_OBJ) $(RSA_OBJ) $(HASH_OBJ) $(FACTORY_OBJ) $(TCP_OBJ) $(SER_OBJ) $(SHM_OBJ)
